
#include "interpreter.h"
#include <cctype>


Interpreter::Interpreter (std::string &text):text(text) {
    length = text.length();
    pos = 0;
    current_char = text[pos];
    current_token = get_next_token();
}

int Interpreter::expr() {
    int result = term();
    // std::cout << "result = " << result << std::endl;
    while (current_token->type!=END) {
        Type type = current_token->type;
        if (type == OP_ADD) {
            eat(OP_ADD);
            result = result + term();
        } else if (type == OP_SUB) {
            eat(OP_SUB);
            result = result - term();
        } else if (type == OP_MULT) {
            eat(OP_MULT);
            result = result * term();
        } else if (type == OP_DIV) {
            eat(OP_DIV);
            result = result / term();
        }
    }
    return result;
}

int Interpreter::term() {
    int value = current_token->value;
    // printf("called term: current char = %c pos = %d\n",current_char,pos);
    eat(INTEGER);
    return value;
}

void Interpreter::eat(Type type) {
    // printf("called eat: type = %d\n",type);
    if (current_token->type == type) {
        delete current_token;
        current_token = get_next_token();
        // printf("type = %d\n",current_token->type);
    } else {
        error();
    }
}

void Interpreter::error() {
    printf("%d %c\n",pos,current_char);
    exit(0);
}

Token* Interpreter::get_next_token() {
    while (pos!=-1) {
        if (current_char == SPACE) {
            skip_whitespace();
            continue;
        } else if (current_char == ADD) {
            advance();
            return new Token(OP_ADD);
        } else if (current_char == SUB) {
            advance();
            return  new Token(OP_SUB);
        } else if (current_char == MULT) {
            advance();
            return  new Token(OP_MULT);
        } else if (current_char == DIV) {
            advance();
            return  new Token(OP_DIV);
        } else if (std::isdigit(current_char)) {
            return  new Token(INTEGER,integer());
        }        
        else {
            // printf("current char = %c\n",current_char);
            error();
            return nullptr;
        }
    }
    return new Token(END);
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

