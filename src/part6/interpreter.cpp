
#include "interpreter.h"

Interpreter::Interpreter(Lexer *lexer) {
    _lexer = lexer;
    current_token = _lexer->getNextToken();
}

int Interpreter::expr() {

    int result = term();
    Type type;
    while(current_token->type == OP_ADD || \
        current_token->type == OP_SUB) {
            type = current_token->type;
            if (type == OP_ADD) {
                eat(OP_ADD);
                result = result + term();
            } else if (type == OP_SUB) {
                eat(OP_SUB);
                result = result - term();
            }
        }
    return result;
}

int Interpreter::term() {

    int result = factor();
    Token *token;
    while(current_token->type == OP_MULT || \
        current_token->type == OP_DIV) {
            token = current_token;
            if (token->type == OP_MULT) {
                eat(OP_MULT);
                result = result * factor();
            } else if (token->type == OP_DIV) {
                eat(OP_DIV); 
                result = result / factor();
            }
        }
    return result;
}

int Interpreter::factor() {

    int result;
    Token* token  = current_token;
    if (token->type == OP_LP) {
        eat(OP_LP);
        result = expr();
        eat(OP_RP);
    } else if (token->type == OP_ADD) {
        eat(OP_ADD);
        result = factor();
    } else if (token->type == OP_SUB) {
        eat(OP_SUB);
        result = -factor();
    } else if (token->type == INTEGER) {
        result = token->value;
        eat(INTEGER);
    }   
    return result;
}

void Interpreter::eat(Type type) {
    if (current_token->type == type) {
        delete current_token;
        current_token = _lexer->getNextToken();
        // printf("current token = %d\n",current_token->type);
    } else {
        error();
    }
}

void Interpreter::error() {
    printf("[error]\n");
    exit(0);
}