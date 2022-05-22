/*
 *Copyright (c) 2022 All rights reserved
 *@description: utils for compilation principle
 *@author: Zhixing Lu
 *@date: 2022-05-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef TOOLS_UTILS_H_
#define TOOLS_UTILS_H_ 

#include <iostream>
#include <vector>
#include <fstream>

#define INPUT_ERROR -1
#define SUCCESS 0
#define RUN_TIME_ERROR 1
#define EMPTY 'e'

static int read_grammer_lines(int argc, char *argv[], std::vector<std::string> &grammar_lines) {

    if (argc != 2) {
        std::cout << "Usage: main.exe grammar.txt" << std::endl;
        return INPUT_ERROR;
    }
    std::string grammar_file = argv[1];
    // read grammar file
    std::string line;
    std::ifstream grammar_file_stream;
    grammar_file_stream.open(grammar_file, std::ios::in);
    if (!grammar_file_stream.is_open()) {
        std::cout << "Error: cannot open grammar file" << std::endl;
        return RUN_TIME_ERROR;
    }
    while (std::getline(grammar_file_stream, line)) {
        grammar_lines.push_back(line);
    }
    grammar_file_stream.close();
    // test
    // for (auto &line : grammar_lines) {
    //     std::cout << line << std::endl;
    // }
    return SUCCESS;
}






#endif  // TOOLS_UTILS_H_ 
