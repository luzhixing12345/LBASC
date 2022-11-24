'''
*Copyright (c) 2022 All rights reserved
*@description: to test the correctness of the code
*@author: Zhixing Lu
*@date: 2022-04-04
*@email: luzhixing12345@163.com
*@Github: luzhixing12345
'''

import argparse
import sys,os

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    part = sys.argv[1]
    with open(f'src/{part}/test-example.txt','r') as f:
        test_cases = f.readlines()
    
    LANGUAGE = 'python'    
    
    if part == 'part1':
        from src.part1.calc import test_interface
        
    elif part == 'part2':
        from src.part2.calc import test_interface
    
    elif part == 'part3':
        LANGUAGE = 'C++'
    
    elif part == 'part4':
        from src.part4.calc import test_interface
        
    for case in test_cases:
        case:str = case.replace("\n",'')
        if LANGUAGE == 'python':
            program_result = test_interface(case)
        else:
            program_result = int(os.popen(f"echo {case} | src/{part}/main").read())
        calc_result = eval(case)
        test_result = "pass" if program_result == calc_result else "fail"
        print('{:<15} = {:<5}({})'.format(case,program_result,test_result))