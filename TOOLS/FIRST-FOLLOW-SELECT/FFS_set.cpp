/*
 *Copyright (c) 2022 All rights reserved
 *@description: calculate the first and follow and select set of a grammar
 *@author: Zhixing Lu
 *@date: 2022-05-20
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/



#include "FFS_set.h"
#include <fstream>

// remove the space in the string
void clearSpace(std::string &str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

// check if the char c is a terminal word
bool checkTerminal(char c, std::vector<char>&non_terminal_set) {
    for (char &s : non_terminal_set) {
        if (c == s) return false;
    }
    return true;
}

void showSet(std::vector<Rule>&rules, std::vector<char> &non_terminal_set, std::vector<char> &terminal_set) {
    // test
    std::cout << "rules:" << std::endl;
    for (auto &rule : rules) {
        std::cout << rule.first << " -> " << rule.second << std::endl;
    }
    std::cout << "terminal set: { ";
    for (auto &i : terminal_set) {
        std::cout<< i << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "non terminal set: { ";
    for (auto &i : non_terminal_set) {
        std::cout<< i << " ";
    }
    std::cout<< "}" << std::endl;

}

int ffs(int argc, char *argv[], FFS_set &ffs_set) {

    if (argc != 2) {
        std::cout << "Usage: main.exe grammar.txt" << std::endl;
        return INPUT_ERROR;
    }
    std::string grammar_file = argv[1];
    // read grammar file
    std::vector<std::string> grammar_lines;
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

    std::vector<char> non_terminal_set, terminal_set;
    std::vector<Rule> rules;
    for (int i = 0; i < grammar_lines.size(); i++) {
        line = grammar_lines[i];
        // split from '->'
        std::string left_side = line.substr(0, line.find("->"));
        clearSpace(left_side);

        char left_side_char;
        if (left_side.size() !=1) {
            std::cout<< "left side to be "<< left_side << std::endl;
            std::cout<< "non terminal word should be a single char "<< std::endl;
            return RUN_TIME_ERROR;
        } else {
            left_side_char = left_side[0];
        }
        // left side to be in non_terminal_set
        non_terminal_set.push_back(left_side_char);

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
            Rule t_rule;
            t_rule.first = left_side_char;
            t_rule.second = right_side_rule;
            rules.push_back(t_rule);
        }
    }

    // right side && not in left side to be in terminal_set
    for (auto &pair : rules) {
        for (char &c : pair.second) {
            if (checkTerminal(c, non_terminal_set)) {
                terminal_set.push_back(c);
            }
        }
    }
    RuleSet rule_set;
    rule_set.non_terminal_set = non_terminal_set;
    rule_set.terminal_set = terminal_set;
    rule_set.rules = rules;

    showSet(rules, non_terminal_set, terminal_set);

    // calculate first set
    calculateFirstSet(rule_set, ffs_set.first_set);

    for (auto &it : ffs_set.first_set) {
        std::cout << it.first << ":";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }

    // calcualte follow set
    //calculateFollowSet(ffs_set.first_set, rule_set, ffs_set.follow_set);

    // calcualte select set
    //calculateSelectSet(ffs_set.first_set, ffs_set.follow_set, rule_set, ffs_set.select_set);

    return 0;
}

void calculateFirstSet(RuleSet &rule_set, Set &first_set) {

    Set temp_set = first_set;
    for (Rule &rule : rule_set.rules) {
        char key = rule.first;
        std::string production = rule.second;
        if (checkTerminal(production[0], rule_set.non_terminal_set)) {
            // add if is a terminal word
            first_set[key].insert(production[0]);
        } else {
            for (char &word : production) {
                if (checkTerminal(word, rule_set.non_terminal_set)) {
                    first_set[key].insert(word);
                    break;
                } else {
                    for (auto &it : first_set[word]) first_set[key].insert(it);
                    if (first_set[word].count(EMPTY) == 0) break;
                }
            }
        }
    }
    if (temp_set == first_set) return;
    else calculateFirstSet(rule_set, first_set);
}
