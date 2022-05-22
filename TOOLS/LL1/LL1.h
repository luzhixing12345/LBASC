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
# include "../utils.h"

struct LL1_ACTION
{
    std::string residual_string;
    std::string analysis_stack;
    Rule analysis_action;
};


int LL1_analyasis(std::string &input_str, 
                  RuleSet &rule_set,
                  SELECT_SET &select_set, 
                  LL1_ACTION &ll1_action);


void showLL1analysisTable(RuleSet &rule_set, SELECT_SET &select_set);




#endif // TOOLS_LL1_LL1_H_
