
#include "interpreter.h"

Interpreter::Interpreter (const char*text) {
    text = text;
    pos = 0;
    current_char = text[pos];
    current_token = nullptr;
}

int Interpreter::expr() {

    current_token = get_next_token();
    int result = term();
    while (current_token->type!=EOF) {
        Token *token = current_token;
        if (token->type == OP_ADD) {
            eat(OP_ADD);
        }
    }
}