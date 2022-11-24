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
from subprocess import Popen, PIPE, STDOUT

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
    
    elif part == 'part5':
        from src.part5.calc import test_interface
    
    elif part == 'part6':
        LANGUAGE = 'C++'
    # max_length = 0
    # for case in test_cases:
    #     max_length = max(max_length,len(case))
    # max_length = (max_length//5+1)*5
    
    for case in test_cases:
        case:str = case.replace("\n",'')
        if LANGUAGE == 'python':
            program_result = test_interface(case)
        else:
            p = Popen(f"./src/{part}/main",stdout=PIPE,stdin=PIPE,stderr=PIPE,encoding='utf8')
            program_output = p.communicate(input=case)[0]
            program_result = int(program_output)
        calc_result = int(eval(case))
        test_result = "pass" if program_result == calc_result else "fail"
        print('{:<25} = {:<5}({})'.format(case,program_result,test_result))