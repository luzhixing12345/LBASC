/*
 *Copyright (c) 2022 All rights reserved
 *@description: LL1 grammar implementation
 *@author: Zhixing Lu
 *@date: 2022-05-22
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include <stack>
#include "LL1.h"

int LL1_analyasis(std::string input_str,
                  RuleSet &rule_set,
                  SELECT_SET select_set, 
                  LL1_ACTION &ll1_action) {
    
    showLL1analysisTable(rule_set, select_set);

    input_str += "$"; // add end character
    std::stack<char> stk;

}



void showLL1analysisTable(RuleSet &rule_set, SELECT_SET &select_set) {

    int table_length = rule_set.terminal_set.size() + 2;
    int table_width = rule_set.non_terminal_set + 2;
    
}
