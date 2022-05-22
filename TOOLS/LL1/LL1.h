/*
 *Copyright (c) 2022 All rights reserved
 *@description: defination for LL1 grammar
 *@author: Zhixing Lu
 *@date: 2022-05-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef TOOLS_LL1_LL1_H_
#define TOOLS_LL1_LL1_H_

# include "../FIRST-FOLLOW-SELECT/FFS_set.h"

struct LL1_ACTION
{
    std::string residual_string;
    std::string analysis_stack;
    Rule analysis_action;
};


LL1_ACTION LL1_analyasis(std::string input_str, std::vector<std::pair<Rule,std::set<char>>> select_set);








#endif // TOOLS_LL1_LL1_H_
