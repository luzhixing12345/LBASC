
#include "lexer.h"
#include <cctype>


Lexer::Lexer(std::string &text) {
    _text = text;
    pos = 0;
    current_char = _text[pos];
    length = text.length();
}

Token *Lexer::getNextToken() {
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
        } else if (current_char == LP) {
            advance();
            token = new Token(OP_LP);
            return token;
        } else if (current_char == RP) {
            advance();
            token = new Token(OP_RP);
            return token;
        } else if (std::isdigit(current_char)) {
            token = new Token(INTEGER,integer());
            return token;
        }        
        else {
            error();
        }
    }
    token = new Token(END);
    return token;
}

int Lexer::integer() {
    int number = 0;
    while (pos != -1 && std::isdigit(current_char)) {
        number = number * 10 + current_char - '0';
        advance();
    }
    // printf("number = %d\n",number);
    return number;
}

void Lexer::skip_whitespace() {
    while (pos != -1 && current_char == SPACE) {
        advance();
    }
}

void Lexer::advance() {
    pos++;
    if (pos > length-1) {
        pos = -1;
    } else {
        current_char = _text[pos];
    }
}

void Lexer::error() {
    printf("[error]");
    exit(0);
}
