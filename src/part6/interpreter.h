
#ifndef SRC_PART6_INTERPRETER_H_
#define SRC_PART6_INTERPRETER_H_


#include "lexer.h"

class Interpreter {

private:
    Lexer *_lexer;
    Token *current_token;

public:
    explicit Interpreter(Lexer *lexer);
    int expr();
    int term();
    int factor();
    void eat(Type type);
    void error();
    ~ Interpreter() {
        delete current_token;
    }
};




#endif // SRC_PART6_INTERPRETER_H_
