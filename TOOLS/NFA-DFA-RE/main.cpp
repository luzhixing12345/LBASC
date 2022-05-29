/*
 *Copyright (c) 2022 All rights reserved
 *@description: DFA-NFA-RE grammar implementation
 *@author: Zhixing Lu
 *@date: 2022-05-29
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include "utils.h"
# include "DFA.h"
# include "NFA.h"
# include "RE.h"

int main(int argc, char *argv[]) {
    std::vector<std::string> grammar_lines;

    int read_signal = read_grammar_lines(argc, argv, grammar_lines);
    if (read_signal != SUCCESS) {
        std::cout << "read file "<< argv[1] << " unsuccessfully";
        return 0;
    }
    std::cout << "read file "<< argv[1] << " successfully";
    return 0;
}