<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>

# Recursion - 递归

--------

#### 问题

序列$$ s $$有$$ n $$个成员$$ [x_1,x_2, \dots ,x_n] $$，每个成员可以选取$$ [1,2, \dots ,m] $$这$$ m $$种值。例如当$$ n = 5 $$，$$ m = 3 $$时，序列$$ s $$有如下排列组合：

$$

\begin{matrix}

[1,1,1,1,1] \\
[1,1,1,1,2] \\
[1,1,1,1,3] \\
[1,1,1,2,1] \\
\cdots

\end{matrix}

$$

求$$ s $$的所有排列组合。（与BruteForce问题一样）

#### 解法

BruteForce存在一个问题，外围for循环的数量是固定的，无法改变。因此我们用递归来解决这个问题。假设序列$$ s $$的长度从$$ 0 $$增长到$$ n $$。初始化时令序列为空$$ s = [] $$。

$$ (1) $$ 将序列$$ s $$的长度增加到$$ 1 $$，第$$ 1 $$个元素（唯一的元素）$$ x_1 $$有$$ m $$种选择，即长度为$$ 1 $$的序列$$ s $$有$$ m $$个排列组合：

$$

\begin{matrix}

[ 1_1 ]  \\
[ 2_1 ]  \\
\cdots   \\
[ m_1 ]

\end{matrix}

$$

$$ (2) $$ 将序列$$ s $$的长度增加到$$ 2 $$，得到$$ s = [x_1,x_2] $$，元素$$ x_2 $$的选择可以看作在第$$ (1) $$轮的每个选择的基础上继续选择。对于$$ [1_1] $$可以得到$$ m $$个排列组合：

$$

\begin{matrix}

[ 1_1,1_2 ]  \\
[ 1_1,2_1 ]  \\
\cdots       \\
[ 1_1,m_1 ]

\end{matrix}

$$

第$$ (2) $$轮操作后共有$$ m^2 $$个排列组合。重复$$ n $$次这样的操作，可以得到$$ m^n $$个排列组合。

实际编写代码中，在递归方程中传入一个参数$$ 0 \le prev \lt n $$，序列$$ s $$中的成员$$ x_{prev} $$可以取值$$ i \in [1,m] $$，然后$$ prev = prev+1 $$，继续考虑序列$$ s $$中的下一个成员$$ x_{prev+1} $$。这样直到当$$ n $$个成员都选择了一个值时，即产生序列$$ s $$的一种排列组合。通过递归可以退回上一个函数栈，从而让每个成员$$ x_{prev} $$都可以重新选择。

对于成员数量为$$ n $$，每个成员有$$ m $$种值的序列$$ s $$，遍历所有排列组合的时间复杂度$$ O(m^n) $$。

--------

#### 源码

[Recursion.h](../../../src/Search/Recursion.h)

[import, lang:"c_cpp"](../../../src/Search/Recursion.h)

[Recursion.cpp](../../../src/Search/Recursion.cpp)

[import, lang:"c_cpp"](../../../src/Search/Recursion.cpp)

#### 测试

[RecursionTest.cpp](../../../src/Search/RecursionTest.cpp)

[import, lang:"c_cpp"](../../../src/Search/RecursionTest.cpp)
