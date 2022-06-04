# 编译原理学习

本项目为编译原理的学习过程,作为大三下学期的一门专业课我并没有听懂老师讲课,所以打算自学.

## [通俗易懂好上手,构建一个简单的解释器(python)](https://ruslanspivak.com/lsbasi-part1/)

理论与实践结合,作者每篇文章中都提供了很好的可执行示例,并在结尾要求读者完成一个进阶小任务,并且会在下一篇中公布他的思路,我很喜欢这种形式

你将在每个阶段学习到:

- [part1](part1/README.md): 如何处理 `2+3`
- [part2](part2/README.md): 如何处理 ` 12 + 234 `
- [part3](part3/README.md): 如何处理 `12-2+8-1`,`12*2*9/3`
- [part4](part4/README.md): 如何使用 上下文无关文法(BNF) 处理 `12*2*9/3`
- [part5](part5/README.md): 如何处理 `12+2*9/3+1`
- [part6](part6/README.md): 如何处理 `(1+2)*(3+4)`
- [part7](part7/README.md): 如何使用 抽象语法树(AST) 处理 `(1+2)*(3+4)`
- [part8](part8/README.md): 如何处理 `--+-3+4`

我将我的解答放在了[LBASC](LBASC)中(part1-part17),同时为每一个阶段设计了一些测试用例`test-examples.txt`来检验

所有的Q&A部分都是我自己的找的,不保证正确性,学习之余了解下概念就好了

### 测试用例使用方法,特定见各部分对应的README文件中命令行输入

```bash
cd learning-part
```

```bash
#测试part1
python test.py part1
```

part3/6需要g++编译后执行

```bash
#测试part3
python test.py -c part3
```

每个part我都有在README部分写了如何测试代码运行方式

## [手把手教你构建C语言编译器](https://lotabout.me/2015/write-a-C-interpreter-0/)

号称用 4 个函数来实现了一个小的 C 语言编译器。它最让我震惊的是能够自举，即能自己编译自己。并且它用很少的代码就完成了一个功能相当完善的 C 语言编译器
