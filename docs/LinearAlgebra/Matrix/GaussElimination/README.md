<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Gauss Elimination - 高斯消元法

--------

#### 问题

用高斯消元法（Gauss Elimination）求拥有唯一解的线性方程组。

--------

#### 线性方程组

线性方程组

$$
\begin{cases}
a_{11} \times x_1 + a_{12} \times x_2 + \dots + a_{1m} \times x_m = b_1      \\
a_{21} \times x_1 + a_{22} \times x_2 + \dots + a_{2m} \times x_m = b_2      \\
\cdots   \\
a_{n1} \times x_1 + a_{n2} \times x_2 + \dots + a_{nm} \times x_m = b_n
\end{cases}
$$

可以表示为$$ n $$行$$ m $$列的矩阵$$ A $$，第$$ i $$行第$$ j $$列的元素为$$ a_{ij} $$。设$$ X = [x_1, x_2, \dots, x_m ] $$是线性方程组的解，$$ B = [b_1, b_2, \dots, b_n] $$是线性方程的右边一列系数向量。一般简写作$$ A \cdot X = B $$。

上面的线性方程组可以写成增广矩阵

$$
A =
\begin{bmatrix}
a_{11} &   a_{12} &   a_{13} &   \dots   &   a_{1m}     \\
a_{21} &   a_{22} &   a_{23} &   \dots   &   a_{2m}     \\
a_{31} &   a_{32} &   a_{33} &   \dots   &   a_{3m}     \\
 \quad &    \quad &   \dots  &  \quad   &   \quad       \\
a_{n1} &   a_{n2} &   a_{n3} &   \dots   &   a_{nm}
\end{bmatrix}

\quad

B =
\begin{bmatrix}
b_{1}   \\
b_{2}   \\
b_{3}   \\
\dots   \\
b_{n}
\end{bmatrix}
$$

$$
(A \mid B) =
\begin{bmatrix}
\begin{array} {c|c}
\begin{matrix}
a_{11} &   a_{12} &   a_{13} &   \dots   &   a_{1m}     \\
a_{21} &   a_{22} &   a_{23} &   \dots   &   a_{2m}     \\
a_{31} &   a_{32} &   a_{33} &   \dots   &   a_{3m}     \\
 \quad &    \quad &   \dots  &  \quad   &   \quad       \\
a_{n1} &   a_{n2} &   a_{n3} &   \dots   &   a_{nm}
\end{matrix}
&
\begin{matrix}
b_{1}   \\
b_{2}   \\
b_{3}   \\
\dots   \\
b_{n}
\end{matrix}
\end{array}
\end{bmatrix}
$$

增广矩阵的左边部分是线性方程组中的矩阵$$ A $$，右边部分是线性方程组中的系数向量$$ B $$。增广矩阵是一个$$ n \times (m+1) $$的矩阵。

高斯消元法的数学含义在于通过初等变化，将线性方程组对应的增广矩阵变化为只有$$ r $$行不全为$$ 0 $$的矩阵（其中$$ r $$为增广矩阵的秩），形如

$$

\begin{bmatrix}
\begin{array} {c|c}
\begin{matrix}
c_{11} &   c_{12} &   c_{13} &   \dots   &   c_{1r} &   \dots   &   c_{1m}     \\
0_{21} &   c_{22} &   c_{23} &   \dots   &   c_{2r} &   \dots   &   c_{2m}     \\
0_{31} &   0_{32} &   c_{33} &   \dots   &   c_{3r} &   \dots   &   c_{3m}     \\
 \quad &  \quad   &  \quad   &   \dots   &  \quad   &  \quad    &  \quad       \\
0_{r1} &   0_{r2} &   0_{r3} &   \dots   &   c_{rr} &   \dots   &   c_{rm}     \\
 \quad &  \quad   &  \quad   &   \dots   &  \quad   &  \quad    &  \quad       \\
0_{n1} &   0_{n2} &   0_{n3} &   \dots   &   0_{nr} &   \dots   &   0_{nm}
\end{matrix}
&
\begin{matrix}
b_{1}   \\
b_{2}   \\
b_{3}   \\
\dots   \\
b_{r}   \\
\dots   \\
0_{n}
\end{matrix}
\end{array}
\end{bmatrix}

$$

经过变换后，不全为$$ 0 $$的行有$$ r $$行，全为$$ 0 $$的行有$$ n - r $$行。当$$ r = n $$时，线性方程组有唯一解，否则有通解。

本问题只考虑$$ r = n $$时有唯一解的线性方程组的解法。

对于包含通解的$$ r \lt n $$的情况，非全$$ 0 $$的行可以用$$ $$


--------

#### 数学复习全书（2013年李永乐李正元考研数学 数学一） - 第二篇 线性代数

* https://book.douban.com/subject/21370697/

--------

#### 源码

[GaussElimination.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/GaussElimination.h)

[GaussElimination.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/GaussElimination.cpp)

#### 测试

[GaussEliminationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/GaussEliminationTest.cpp)
