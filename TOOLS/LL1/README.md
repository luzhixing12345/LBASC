# LL1文法

LL1文法的求解过程并不复杂,基于[FIRST-FOLLOW-SELECT集求解](../FIRST-FOLLOW-SELECT/README.md)得到SELECT集

再依次匹配分析栈就可以了,相关[博客](https://luzhixing12345.github.io/2022/04/28/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86/%E8%AF%AD%E6%B3%95%E5%88%86%E6%9E%90-%E4%B8%8B/)

## 使用方法

```bash
cd TOOLS/LL1
```

- 如果有 g++ 编译器那么可以自行编译

  ```bash
  g++ main.cpp LL1.cpp ../FIRST-FOLLOW-SELECT/FFS_set.cpp -o main.exe
  ```

- 如果没有也可以直接使用我编译过的 `main.exe`

