<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Recursion - 递归

--------

#### 问题

排列$$ s $$有$$ n $$个成员$$ [x_1,x_2, \dots ,x_n] $$，每个成员可以选取$$ [1,2, \dots ,m] $$这$$ m $$种值。例如当$$ n = 3, m = 3 $$时，排列$$ s $$有以下情况：

$$
\begin{matrix}
[1,1,1] \\
[2,1,1] \\
[1,2,1] \\
[1,1,2] \\
[2,2,1] \\
[2,1,2] \\
[1,2,2] \\
[2,2,2] \\
[3,1,1] \\
[1,3,1] \\
[1,1,3] \\
[3,3,1] \\
[3,1,3] \\
[1,3,3] \\
[3,3,3] \\
[2,3,1] \\
[3,2,1] \\
[2,1,3] \\
[3,1,2] \\
[1,2,3] \\
[1,3,2] \\
[2,2,3] \\
[2,3,2] \\
[3,2,2] \\
[3,3,2] \\
[3,2,3] \\
[2,3,3]
\end{matrix}
$$

给定$$ n, m $$的值，用Recursion求排列$$ s $$的所有情况。

#### 解法

BruteForce存在一个问题，外围for循环的数量固定，无法随着$$ n $$的改变而改变。递归可以解决这个问题。

假设排列$$ s $$的长度从$$ 0 $$增长到$$ n $$。初始化时令排列为空$$ s = [] $$。

$$ (1) $$ 将排列$$ s $$的长度增加到$$ 1 $$，第$$ 1 $$个元素（唯一的元素）$$ x_1 $$有$$ m $$种选择，即长度为$$ 1 $$的排列$$ s $$有$$ m $$个排列组合：

$$
\begin{matrix}
[ 1_1 ]  \\
[ 2_1 ]  \\
\cdots   \\
[ m_1 ]
\end{matrix}
$$

$$ (2) $$ 将排列$$ s $$的长度增加到$$ 2 $$，得到$$ s = [x_1,x_2] $$，元素$$ x_2 $$的选择可以看作在第$$ (1) $$步的每个选择的基础上继续选择。对于$$ [1_1] $$可以得到$$ m $$个排列组合：

$$
\begin{matrix}
[ 1_1,1_2 ]  \\
[ 1_1,2_2 ]  \\
\cdots       \\
[ 1_1,m_2 ]
\end{matrix}
$$

对于$$ [2_1] $$可以得到$$ m $$个排列组合：

$$
\begin{matrix}
[ 2_1,1_2 ]  \\
[ 2_1,2_2 ]  \\
\cdots       \\
[ 2_1,m_2 ]
\end{matrix}
$$

显然对于第$$ (1) $$步的$$ m $$个排列组合，每个都可以产生$$ m $$个排列组合，因此第$$ (2) $$步共有$$ m^2 $$个排列组合。第$$ (n) $$步后可以得到$$ m^n $$个排列组合。

根据乘法定理可知，对于成员数量为$$ n $$，每个成员有$$ m $$个值的排列$$ s $$，遍历所有排列组合的时间复杂度$$ O(m^n) $$。

--------

#### 源码

[Recursion.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/Recursion.h)

[Recursion.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/Recursion.cpp)

#### 测试

[RecursionTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/RecursionTest.cpp)
