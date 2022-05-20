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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct FFS_set {
    std::vector<std::string> first_set;
    std::vector<std::string> follow_set;
};

int ffs(int argc, char *argv[], FFS_set &ffs_set);

#endif // TOOLS_FIRST_FOLLOW_SELECT_FFS_SET_H_
