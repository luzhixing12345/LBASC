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

int main(int argc, char *argv[]) {

    FFS_set ffs_set;
    int signal = ffs(argc, argv, ffs_set);
    
    return 0;

}
