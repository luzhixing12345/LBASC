# LBASC

参考 [Let’s Build A Simple Interpreter](https://ruslanspivak.com/lsbasi-part1/)

非常适合入门编译原理,理论与实践结合,作者每篇文章中都提供了很好的可执行示例,并在结尾要求读者完成一个进阶小任务,并且会在下一篇中公布他的思路,我很喜欢这种形式

## 目录

- [part1](src/part1/README.md): 如何处理 `2+3`
- [part2](src/part2/README.md): 如何处理 ` 12 + 234 `
- [part3](src/part3/README.md): 如何处理 `12-2+8-1`,`12*2*9/3`
- [part4](src/part4/README.md): 如何使用 上下文无关文法(BNF) 处理 `12*2*9/3`
- [part5](src/part5/README.md): 如何处理 `12+2*9/3+1`
- [part6](src/part6/README.md): 如何处理 `(1+2)*(3+4)`
- [part7](src/part7/README.md): 如何使用 抽象语法树(AST) 处理 `(1+2)*(3+4)`
- [part8](src/part8/README.md): 如何处理 `--+-3+4`

## 运行与测试

笔者构建了一个Makefile文件和test.py脚本来辅助自动化测试,每一个阶段设计了一些测试用例`test-examples.txt`来检验

```bash
make part1
```
