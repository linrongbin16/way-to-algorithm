<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Gauss Elimination - 高斯消元法

--------

#### 问题

用高斯消元法（Gauss Elimination）求拥有唯一解的线性方程组。

#### 线性方程组

线性方程组

$$
\begin{cases}
a_{1,1} \times x_1 + a_{1,2} \times x_2 + \dots + a_{1,m} \times x_m = b_1      \\
a_{2,1} \times x_1 + a_{2,2} \times x_2 + \dots + a_{2,m} \times x_m = b_2      \\
\dots   \\
a_{n,1} \times x_1 + a_{n,2} \times x_2 + \dots + a_{n,m} \times x_m = b_n
\end{cases}
$$

可以表示为$$ n $$行$$ m $$列的矩阵$$ A $$，第$$ i $$行第$$ j $$列的元素为$$ a_{i,j} $$。设$$ X = [x_1, x_2, \dots, x_m ] $$是线性方程组的解，$$ B = [b_1, b_2, \dots, b_n] $$是线性方程的右边一列系数向量。一般简写作$$ A \cdot X = B $$。

上面的线性方程组可以写成增广矩阵

$$
A =
\begin{bmatrix}
a_{1,1} &   a_{1,2} &   a_{1,3} &   \dots   &   a_{1,m}     \\
a_{2,1} &   a_{2,2} &   a_{2,3} &   \dots   &   a_{2,m}     \\
a_{3,1} &   a_{3,2} &   a_{3,3} &   \dots   &   a_{3,m}     \\
        &           &   \dots   &           &               \\
a_{n,1} &   a_{n,2} &   a_{n,3} &   \dots   &   a_{n,m}
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
a_{1,1} &   a_{1,2} &   a_{1,3} &   \dots   &   a_{1,m}     \\
a_{2,1} &   a_{2,2} &   a_{2,3} &   \dots   &   a_{2,m}     \\
a_{3,1} &   a_{3,2} &   a_{3,3} &   \dots   &   a_{3,m}     \\
        &           &   \dots   &           &               \\
a_{n,1} &   a_{n,2} &   a_{n,3} &   \dots   &   a_{n,m}
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
c_{1,1} &   c_{1,2} &   c_{1,3} &   \dots   &   c_{1,r} &   \dots   &   c_{1,m}     \\
0_{2,1} &   c_{2,2} &   c_{2,3} &   \dots   &   c_{2,r} &   \dots   &   c_{2,m}     \\
0_{3,1} &   0_{3,2} &   c_{3,3} &   \dots   &   c_{3,r} &   \dots   &   c_{3,m}     \\
        &           &           &   \dots   &           &           &               \\
0_{r,1} &   0_{r,2} &   0_{r,3} &   \dots   &   c_{r,r} &   \dots   &   c_{r,m}     \\
        &           &           &   \dots   &           &           &               \\
0_{n,1} &   0_{n,2} &   0_{n,3} &   \dots   &   0_{n,r} &   \dots   &   0_{n,m}
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

--------

#### 数学复习全书（李永乐李正元考研数学 数学一）

* https://book.douban.com/subject/21370697/

--------

#### 源码

[GaussElimination.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/GaussElimination.h)

[GaussElimination.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/GaussElimination.cpp)

#### 测试

[GaussEliminationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/GaussEliminationTest.cpp)
