/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function to compile
 *@author: Zhixing Lu
 *@date: 2022-05-21
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include <iostream>
# include "FIRST-FOLLOW-SELECT\\FFS_set.cpp"

void test();

int main(int argc, char *argv[]) {

    //test();
    FFS_set ffs_set;
    ffs(argc, argv, ffs_set);
    return 0;
}



void test() {
    std::string str = "a -> b | c | d";
    clearSpace(str);
    std::cout << str << std::endl;
}