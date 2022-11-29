# LBASI

参考 [Let’s Build A Simple Interpreter](https://ruslanspivak.com/lsbasi-part1/)

非常适合入门编译原理,理论与实践结合,作者每篇文章中都提供了很好的可执行示例,并在结尾要求读者完成一个进阶小任务,并且会在下一篇中公布他的思路,我很喜欢这种形式

## 目录

- [part1](src/part1): 如何处理 `2+3`
- [part2](src/part2): 如何处理 ` 12 + 234 `
- [part3](src/part3): 如何处理 `12-2+8-1`,`12*2*9/3`
- [part4](src/part4): 如何使用 上下文无关文法(BNF) 处理 `12*2*9/3`
- [part5](src/part5): 如何处理 `12+2*9/3+1`
- [part6](src/part6): 如何处理 `(1+2)*(3+4)`
- [part7](src/part7): 如何使用 抽象语法树(AST) 处理 `(1+2)*(3+4)` 
- [part8](src/part8): 如何处理 `--+-3+4`
- [part9](src/part9): 编写 Pascal 语法基础编译器
- [part10](src/part10/): 完善语法,添加对应的AST节点
- [part11](src/part11/): 添加符号表, 属性表
- [part12](src/part12/): 添加过程声明,引出作用域
- [part13](src/part13/): 实现语义分析和静态语法检查
- [part14](src/part14/): 实现作用域
- [part15](src/part15/): 完善错误检查和异常抛出
- [part16](src/part16/): 添加过程调用的支持
- [part17](src/part17/): 调用堆栈和激活记录

## 运行与测试

笔者构建了一个Makefile文件和test.py脚本来辅助自动化测试

您可使用 `make <part>` 来自动化测试,比如

```bash
make part1
```
