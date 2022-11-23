/*
 *Copyright (c) 2022 All rights reserved
 *@description: interpreter head file
 *@author: Zhixing Lu
 *@date: 2022-11-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef SRC_PART3_INTERPRETER_H_
#define SRC_PART3_INTERPRETER_H_

#include <cctype>
#include <iostream>
#include <ctype.h>
#ifndef __TOKEN_INIT__
#define SPACE ' '
#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'
#endif

enum Type {INTEGER=100,OP_ADD,OP_SUB,OP_MULT,OP_DIV,END};

class Token {
public:
    Token(Type type, int value):type(type),value(value){};
    Token(Type type):type(type){};
    Type type;
    int value;
};

class Interpreter   {
private:
    int pos;               // 当前指针的位置
    char current_char;        // 当前字符
    Token *current_token;     // 当前的令牌(token)
    std::string text;
    int length;
public:
    explicit Interpreter(std::string &text);
    void advance();           // pos向后移动
    void skip_whitespace();   // 跳过空格
    Token *get_next_token();  // 获取下一个token
    void error();
    void eat(Type type);              // 将当前令牌类型与传递的令牌进行比较

    int integer();           // 获取连续数字的值
    int term();              // 获取术语
    int expr();              // 解析整个表达式

};





#endif // SRC_PART3_INTERPRETER_H_
