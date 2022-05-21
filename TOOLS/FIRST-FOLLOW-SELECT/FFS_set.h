/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic data structure for first and follow set
 *@author: Zhixing Lu
 *@date: 2022-05-21
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef TOOLS_FIRST_FOLLOW_SELECT_FFS_SET_H_
#define TOOLS_FIRST_FOLLOW_SELECT_FFS_SET_H_

#define INPUT_ERROR -1
#define SUCCESS 0
#define RUN_TIME_ERROR 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define Rule std::pair<char,std::string> // {A , abcd}
#define Set std::unordered_map<char, std::set<char>> // [A] -> {a,b,c,d}
#define EMPTY 'e'

struct FFS_set {
    Set first_set;
    Set follow_set;
    std::vector<std::pair<Rule,std::set<char>>> select_set;
};

struct RuleSet
{
    std::vector<char> non_terminal_set;
    std::vector<char> terminal_set;
    std::vector<Rule> rules;
};


int ffs(int argc, char *argv[], FFS_set &ffs_set);

void calculateFirstSet(RuleSet &rule_set, Set&first_set);

void calculateFollowSet(Set&first_set, RuleSet &rule_set, Set&follow_set);

void calculateSelectSet(Set&first_set,
                        Set&follow_set, 
                        RuleSet &rule_set, 
                        std::vector<std::pair<Rule,std::set<char>>>&select_set);

#endif // TOOLS_FIRST_FOLLOW_SELECT_FFS_SET_H_
