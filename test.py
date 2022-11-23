'''
*Copyright (c) 2022 All rights reserved
*@description: to test the correctness of the code
*@author: Zhixing Lu
*@date: 2022-04-04
*@email: luzhixing12345@163.com
*@Github: luzhixing12345
'''

import argparse
import sys

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    part = sys.argv[1]
    with open(f'src/{part}/test-example.txt','r') as f:
        test_cases = f.readlines()
    if part == 'part1':
        from src.part1.calc import Interpreter
        
    elif part == 'part2':
        from src.part2.calc import Interpreter
        
    for case in test_cases:
        case:str = case.replace("\n",'')
        program_result = Interpreter(case).expr()
        calc_result = eval(case)
        test_result = "pass" if program_result == calc_result else "fail"
        print('{:<15} = {:<5}({})'.format(case,program_result,test_result))