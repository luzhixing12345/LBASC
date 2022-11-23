
#include <cstdio>
#include <iostream>
#include <string>
#include "interpreter.h"

int main() {
    std::string text;
    std::getline(std::cin,text);    
    Interpreter interpreter = Interpreter(text);
    int result = interpreter.expr();
    printf("%d",result);
    return 0;
}