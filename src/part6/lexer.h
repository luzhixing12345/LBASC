

#ifndef __SRC__PART6__LEXER_H
#define __SRC__PART6__LEXER_H

#include <iostream>
#ifndef __TOKEN_INIT__
#define SPACE ' '
#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'
#define LP '('
#define RP ')'
#endif

enum Type {INTEGER=100,OP_ADD,OP_SUB,OP_MULT,OP_DIV,OP_LP,OP_RP,END};

class Token {
public:
    Token(Type type,int value):type(type),value(value){};
    Token(Type type):type(type){};
    int value;
    Type type;
};

class Lexer {

private:
    std::string _text;
    int pos;
    char current_char;
    int length;

public:
    explicit Lexer(std::string &text);
    Token *getNextToken();
    int integer();
    void skip_whitespace();
    void advance();
    void error();
};



#endif // __SRC__PART6__LEXER_H
