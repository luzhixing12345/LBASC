/*
 *Copyright (c) 2022 All rights reserved
 *@description: calculate the first and follow set of a grammar
 *@author: Zhixing Lu
 *@date: 2022-05-20
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/



#include "FFS_set.h"
#include <fstream>

void clearSpace(std::string &str) {
    // remove the space in the string
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

int ffs(int argc, char *argv[], FFS_set &ffs_set) {

    if (argc != 2) {
        std::cout << "Usage: main.exe grammar.txt" << std::endl;
        return 0;
    }
    std::string grammar_file = argv[1];
    // read grammar file
    std::vector<std::string> grammar_lines;
    std::string line;
    std::ifstream grammar_file_stream;
    grammar_file_stream.open(grammar_file, std::ios::in);
    if (!grammar_file_stream.is_open()) {
        std::cout << "Error: cannot open grammar file" << std::endl;
        return -1;
    }
    while (std::getline(grammar_file_stream, line)) {
        grammar_lines.push_back(line);
    }
    grammar_file_stream.close();
    // for (auto &line : grammar_lines) {
    //     std::cout << line << std::endl;
    // }
    // calculate first set
    std::vector<std::string> non_terminal_set;
    std::vector<std::pair<std::string,std::string>> rules;
    for (int i = 0; i < grammar_lines.size(); i++) {
        line = grammar_lines[i];
        // split from '->'
        std::string left_side = line.substr(0, line.find("->"));
        clearSpace(left_side);
        non_terminal_set.push_back(left_side);

        std::string right_side = line.substr(line.find("->") + 2);
        // split from '|'
        std::vector<std::string> right_side_rules;
        std::string right_side_rule;
        for (auto &c : right_side) {
            if (c == '|') {
                clearSpace(right_side_rule);
                right_side_rules.push_back(right_side_rule);
                right_side_rule = "";
            } else {
                right_side_rule += c;
            }
        }
        clearSpace(right_side_rule);
        right_side_rules.push_back(right_side_rule);

        for (auto &right_side_rule : right_side_rules) {
            rules.push_back(std::make_pair(left_side, right_side_rule));
        }

    }
    // test
    for (auto &rule : rules) {
        std::cout << rule.first << " -> " << rule.second << std::endl;
    }

    return 0;
}