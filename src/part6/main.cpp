
#include "interpreter.h"
#include <cstdio>
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin,text);
    Lexer lexer = Lexer(text);
    Interpreter intepreter = Interpreter(&lexer);
    int result = intepreter.expr();
    printf("%d",result);
    return 0;
}