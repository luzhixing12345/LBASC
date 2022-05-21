/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function to compile
 *@author: Zhixing Lu
 *@date: 2022-05-21
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include <iostream>
# include "FIRST-FOLLOW-SELECT/FFS_set.h"


void showFFS(FFS_set &ffs_set) {

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "FIRST SET: "<<std::endl;
    for (auto &it : ffs_set.first_set) {
        std::cout << it.first << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "FOLLOW SET: "<<std::endl;
    for (auto &it : ffs_set.follow_set) {
        std::cout << it.first << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "SELECT SET: "<<std::endl;
    for (auto &it : ffs_set.select_set) {
        std::string production = " -> " + it.first.second + ": ";
        production = it.first.first + production;
        std::cout << production;
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char *argv[]) {

    FFS_set ffs_set;
    int signal = ffs(argc, argv, ffs_set);
    
    if (signal == SUCCESS) {
        std::cout << "SUCCESS to calculate" << std::endl;
    } else if (signal == RUN_TIME_ERROR) {
        std::cout << "RUN_TIME_ERROR" << std::endl;
    } else if (signal == INPUT_ERROR) {
        std::cout << "INPUT_ERROR" << std::endl;
    } else {
        std::cout << "STANGE ERROR ???" << std::endl;
    }
    
    showFFS(ffs_set);
    return 0;

}
