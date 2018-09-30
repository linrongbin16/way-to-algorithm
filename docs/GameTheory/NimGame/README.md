<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Nim Game - 尼姆博弈

--------

#### 问题

$$ A $$和$$ B $$两人轮流从$$ n $$堆物品中取出一些物品，$$ n $$堆物品的数量分别为$$ [ s_{1}, s_{2}, s_{3} \dots s_{n} ] $$（所有物品数量都是正整数）。

每人每次从一堆物品中至少取$$ 1 $$个，多则不限，最后取光所有物品的人获胜。

给定$$ n $$和$$ [ s_{1}, s_{2}, s_{3} \dots s_{n} ] $$，当我方先手，我方和对方都是高手（在能赢的情况下一定能赢），求我方是否能赢。

#### 解法

$$ (1) $$ 当我方面临$$ [0, 7, 0] $$局势（有$$ 1 $$堆物品）时，我方必赢，因为我方可以一次把剩下一组的物品取光；

$$ (2) $$ 当我方面临$$ [0, 1, 1, 0, 0] $$局势（有$$ 2 $$堆物品且均剩$$ 1 $$个）时，我方必输，因为我方必然留给对方只剩$$ 1 $$堆物品的局势；

$$ (3) $$ 当我方面临$$ [0, 1, 1, 1, 0] $$局势（有$$ 3 $$堆物品且均剩$$ 1 $$个）时，我方必赢，因为我方必然留给对方只剩$$ 2 $$堆物品且均剩$$ 1 $$个的局势；

$$ (4) $$ 当我方面临$$ [3, 4, 5] $$局势时，暂时无法看出我方是否必赢；

$$
\cdots
$$

本问题背后的数学模型叫$$ Nim Sum $$，堆数组大小的二进制和，上面$$ 5 $$个局势可以转化为：

$$
\begin{matrix}
s_{1} = 0_{10} = 000_{2}    \\
s_{2} = 7_{10} = 111_{2}    \\
s_{3} = 0_{10} = 000_{2}    \\
nim_{1} = 0 \bigoplus 7 \bigoplus 0 = 1
\end{matrix}
$$

$$
\begin{matrix}
s_{1} = 0_{10} = 000_{2}    \\
s_{2} = 1_{10} = 001_{2}    \\
s_{3} = 1_{10} = 001_{2}    \\
s_{4} = 0_{10} = 000_{2}    \\
s_{5} = 0_{10} = 000_{2}    \\
nim_{2} = 0 \bigoplus 1 \bigoplus 1 \bigoplus 0 \bigoplus 0 = 0
\end{matrix}
$$

$$
\begin{matrix}
s_{1} = 0_{10} = 000_{2}    \\
s_{2} = 1_{10} = 001_{2}    \\
s_{3} = 1_{10} = 001_{2}    \\
s_{4} = 1_{10} = 001_{2}    \\
s_{5} = 0_{10} = 000_{2}    \\
nim_{3} = 0 \bigoplus 1 \bigoplus 1 \bigoplus 1 \bigoplus 0 = 1
\end{matrix}
$$

$$
\begin{matrix}
s_{1} = 3_{10} = 011_{2}    \\
s_{2} = 4_{10} = 100_{2}    \\
s_{3} = 5_{10} = 101_{2}    \\
nim_{4} = 3 \bigoplus 4 \bigoplus 5 = 2
\end{matrix}
$$

可以看出，当我方面临$$ \bigoplus_{i=1}^{n} s_{i} = s_{1} \bigoplus s_{2} \bigoplus \cdots \bigoplus s_{n} \ne 0 $$局势时必赢，否则必输。

该算法时间复杂度为$$ O(n) $$。

--------

#### Nim Sum

* http://www.math.ucla.edu/~radko/circles/lib/data/Handout-141-156.pdf
* https://plus.maths.org/content/play-win-nim
* http://samidavies.com/post/2016/03/09/games-intro.html
* https://paradise.caltech.edu/ist4/lectures/Bouton1901.pdf
* https://pdfs.semanticscholar.org/8ac7/c5d8d56847daafa73ad85ae2ad6f47149096.pdf
* https://www.researchgate.net/publication/220343088_The_game_of_End-Nim

--------

#### 源码

[NimGame.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GameTheory/NimGame.h)

[NimGame.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GameTheory/NimGame.cpp)

[import, lang:"c_cpp"](../../../src/GameTheory/NimGame.h)

[import, lang:"c_cpp"](../../../src/GameTheory/NimGame.cpp)

#### 测试

[NimGameTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GameTheory/NimGameTest.cpp)

[import, lang:"c_cpp"](../../../src/GameTheory/NimGameTest.cpp)
