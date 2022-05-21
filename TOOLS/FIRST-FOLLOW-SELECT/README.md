# LL1文法 求FIRST FOLLOW SELECT集

关于如何计算 求FIRST FOLLOW SELECT集的知识我整理在 [我的博客-编译原理](https://luzhixing12345.github.io/tags/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86/)上, 如果你对这部分知识尚不清楚可以去看一下

一些代码实现时的细节我也补充在注释里了, 有兴趣的话可以参考

## 使用方法

```bash
cd TOOLS/FIRST-FOLLOW-SELECT
```

- 如果有 g++ 编译器那么可以自行编译

  ```bash
  g++ main.cpp FFS_set.cpp -o main.exe
  ```

- 如果你没有也可以直接下载我编译过的[可执行文件]()

我在该文件夹下提供了一个示例文件 `grammar.txt`,执行

```bash
main.exe grammar.txt
```

```txt
SUCCESS to calculate
---------------------
FIRST SET:
T: , e
L: ( a
S: ( a
---------------------
FOLLOW SET:
T: $ )
S: $ ) ,
L: $ )
---------------------
SELECT SET:
S -> (L): (
S -> a: a
L -> ST: ( a
T -> ,ST: ,
T -> e: $ )
```

编写 `grammar.txt` 时需要注意以下几点:

- 由于空 $\epsilon$ 并不便于直接打出来,所以我使用了字符 `e` 作为等价替换

  如果你不想使用这个字符也可以修改[FFS_set.h](FFS_set.h) 中的 `#define EMPTY 'e'`

- 暂不支持 `S'`这种写法,暂不支持多字符的终结符/非终结符表示如 `id`,`expr`,请使用单个字符如 `P`,`a`

  > 不然处理起来太麻烦了...
  
- 空格我在程序中有做处理,`A -> (B)`与 `A-> ( B )`是等效的,无需担心

  > 只要不在 `->`中间加空格都无所谓

一个示例写法

```txt
S -> (L) | a
L -> ST
T -> ,ST | e
```
