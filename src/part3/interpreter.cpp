
#include "interpreter.h"
#include <cctype>
#include <cstdio>
#include <iterator>


Interpreter::Interpreter (std::string &text):text(text) {
    length = text.length();
    pos = 0;
    current_char = text[pos];
    current_token = nullptr;
}

int Interpreter::expr() {
    current_token = get_next_token();
    // printf("current char = %c\n",current_char);
    int result = term();
    // std::cout << "result = " << result << std::endl;
    while (current_token->type!=END) {
        Token *token = current_token;
        if (token->type == OP_ADD) {
            eat(OP_ADD);
            result = result + term();
        } else if (token->type == OP_SUB) {
            eat(OP_SUB);
            result = result - term();
        } else if (token->type == OP_MULT) {
            eat(OP_MULT);
            result = result * term();
        } else if (token->type == OP_DIV) {
            eat(OP_DIV);
            result = result / term();
        }
    }
    return result;
}

int Interpreter::term() {
    Token *token = current_token;
    // printf("called term: current char = %c pos = %d\n",current_char,pos);
    eat(INTEGER);
    return token->value;
}

void Interpreter::eat(Type type) {
    // printf("called eat: type = %d\n",type);
    if (current_token->type == type) {
        current_token = get_next_token();
    } else {
        error();
    }
}

void Interpreter::error() {
    printf("%d %c\n",pos,current_char);
    exit(0);
}

Token* Interpreter::get_next_token() {
    Token *token;
    while (pos!=-1) {
        if (current_char == SPACE) {
            skip_whitespace();
            continue;
        } else if (current_char == ADD) {
            advance();
            token = new Token(OP_ADD);
            return token;
        } else if (current_char == SUB) {
            advance();
            token = new Token(OP_SUB);
            return token;
        } else if (current_char == MULT) {
            advance();
            token = new Token(OP_MULT);
            return token;
        } else if (current_char == DIV) {
            advance();
            token = new Token(OP_DIV);
            return token;
        } else if (std::isdigit(current_char)) {
            token = new Token(INTEGER,integer());
            return token;
        }        
        else {
            // printf("current char = %c\n",current_char);
            error();
            return nullptr;
        }
    }
    token = new Token(END);
    return token;
}

void Interpreter::skip_whitespace() {
    while (pos!=-1 && current_char == SPACE) {
        advance();
    }
}

int Interpreter::integer() {
    int number = 0;
    while (pos!=-1 && std::isdigit(current_char)) {
        number = number * 10 + current_char-'0';
        advance();
    }
    // printf("integer get number = %d\n",number);
    return number;
}

void Interpreter::advance() {
    pos++;
    if (pos > length-1) {
        pos = -1;
    } else {
        current_char = text[pos];
    }
}

