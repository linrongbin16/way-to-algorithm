<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Strassen - Strassen算法

--------

#### 问题

用Strassen算法计算两个$$ n $$阶矩阵相乘$$ C = A \times B $$。

#### 解法

按照矩阵定义的普通数学方法计算两个$$ n $$阶矩阵相乘，需要$$ n $$次矩阵的行和列相乘，每次行和列相乘需要$$ n $$次乘法操作和$$ n - 1 $$次加法操作，时间复杂度为$$ O(n^2) $$。Strassen算法的时间复杂度比普通数学方法更低。

对于$$ n $$阶矩阵乘法$$ C = A \times B $$，设$$ n $$为偶数，则可以将$$ A, B, C $$三个矩阵划分为$$ 4 $$个$$ n/2 $$的矩阵，矩阵乘法可以转化为

$$
\begin{bmatrix}
r   &   s   \\
t   &   u
\end{bmatrix}

=

\begin{bmatrix}
a   &   b   \\
c   &   d
\end{bmatrix}

\times

\begin{bmatrix}
e   &   f   \\
g   &   h
\end{bmatrix}
$$

按照矩阵乘法计算方法可知

$$
\begin{matrix}
r = a \times e + b \times g     \\
s = a \times f + b \times h     \\
t = c \times e + d \times g     \\
u = c \times f + d \times h
\end{matrix}
$$

在上式基础上设置$$ 7 $$个中间矩阵，从$$ p_{1} $$到$$ p_{7} $$

$$
\begin{matrix}
p_1 = a \times f - a \times h = a \times (f - h)
p_2 = a \times h + b \times h = (a + b) \times h
p_3 = c \times e + d \times e = (c + d) \times e
p_4 = d \times g - d \times e = d \times (g - e)
p_5 = a \times e + a \times h + d \times e + d \times h = (a + d) \times (e + h)
p_6 = b \times g + b \times h - d \times g - d \times h = (b - d) \times (g + h)
p_7 = a \times e + a \times f - c \times e - c \times f = (a - c) \times (e + f)
\end{matrix}
$$

又因为

$$
\begin{matrix}
r = p_5 + p_4 - p_2 + p_6
s = p_1 + p_2
t = p_3 + p_4
u = p_1 + p_5 - p_3 - p_7
\end{matrix}
$$

显然通过特别的设置$$ p_1 $$到$$ p_7 $$这$$ 7 $$个中间矩阵，最终也可求出两矩阵的相乘结果。

从上式可以看出，进行一次矩阵乘法需要计算$$ 8 $$次子矩阵相乘，其时间复杂度为$$ O(n^3) $$。

//但Strassen算法只需要递归的计算7个子矩阵，使得时间复杂度下降到O(n^2.81)

//由此，添加了若干子矩阵的加减运算，但得到一个矩阵只需要进行7次子矩阵的相乘
//为了方便本文中只考虑n为偶数的矩阵相乘，若n为奇数则子矩阵的划分总是多出一行一列
//实际中该算法由于增加了过多的矩阵加减运算，其实际效率并不高
//
//本节引用了“数学复习全书(2013年李永乐李正元考研数学 数学一)”，作者“李永乐”“李正元”

--------

#### 源码

[Strassen.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.h)

[Strassen.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.cpp)

#### 测试

[StrassenTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/StrassenTest.cpp)

