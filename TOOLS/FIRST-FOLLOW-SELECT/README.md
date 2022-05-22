# 求FIRST FOLLOW SELECT集

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

- 如果没有也可以直接使用我编译过的 `main.exe`

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
S -> (L)  : (
S -> a    : a
L -> ST   : ( a
T -> ,ST  : ,
T -> e    : $ )
```

编写 `grammar.txt` 时需要注意以下几点:

- 由于空 $\epsilon$ 并不便于直接打出来,所以我使用了字符 `e` 作为等价替换

- 暂不支持 `S'`这种写法,暂不支持多字符的终结符/非终结符表示如 `id`,`expr`,请使用单个字符如 `P`,`a`

  > 不然处理起来太麻烦了...
  
- 空格我在程序中有做处理,`A -> (B)`与 `A-> ( B )`是等效的,无需担心

  > 只要不在 `->`中间加空格都无所谓

- 不要有空行

比如我想要求得的文法是

```txt
D -> TL
T -> int | char
L -> *L | L[] | L() | (L) |id
```

我可以写作如 `test.txt`中的形式, 执行 `main.exe test.txt`

```txt
D -> TL
T -> a | b
L -> *L | L[]|L()|(L)|c
```

结果为

```txt
SUCCESS to calculate
---------------------
FIRST SET:
D: a b
L: ( * c
T: a b
---------------------
FOLLOW SET:
L: $ ( ) [
D: $
T: $ ( * c
---------------------
SELECT SET:
D -> TL   : a b
T -> a    : a
T -> b    : b
L -> *L   : *
L -> L[]  : ( * c
L -> L()  : ( * c
L -> (L)  : (
L -> c    : c
```
