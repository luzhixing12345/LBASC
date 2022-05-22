/*
 *Copyright (c) 2022 All rights reserved
 *@description: ll1 grammar main function
 *@author: Zhixing Lu
 *@date: 2022-05-22
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include <iomanip>
# include "LL1.h"

void showLL1action(LL1_ACTION &ll1_action) {

}


int main(int argc, char *argv[]) {
    FFS_set ffs_set;
    std::vector<std::string> grammar_lines;
    int read_signal = read_grammer_lines(argc, argv, grammar_lines);
    if (read_signal != SUCCESS) {
        std::cout << "read file "<< argv[1] << " unsuccessfully";
        return 0;
    }
    
    int signal = ffs(grammar_lines, ffs_set);

    signalCheck(signal, "ffs set");

    std::cout << std::endl << "Please input the string: >";
    std::string input_str;
    std::cin >> input_str;

    LL1_ACTION ll1_action;
    RuleSet rule_set;
    getRuleSet(grammar_lines, rule_set);
    signal = LL1_analyasis(input_str, rule_set, ffs_set.select_set, ll1_action);
    signalCheck(signal, "LL1 analysis action");

    showLL1action(ll1_action);
    return 0;
}
