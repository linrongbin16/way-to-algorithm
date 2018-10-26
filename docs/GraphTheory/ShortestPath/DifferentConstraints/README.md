<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Different Constraints - 差分约束

--------

#### 问题

差分约束是这样一类线性约束：

$$
\begin{cases}
x_1 - x_2 \leq 0    \\
x_1 - x_5 \leq -1   \\
x_2 - x_5 \leq 1    \\
-x_1 + x_3 \leq 5   \\
-x_1 + x_4 \leq 4   \\
-x_3 + x_4 \leq -1   \\
-x_3 + x_5 \leq -3  \\
-x_4 + x_5 \leq -3
\end{cases}
$$

上面的不等式可以转化为线性不等式：

$$
\begin{bmatrix}
1   &   -1  &   0   &   0   &   0   \\
1   &   0   &   0   &   0   &   -1  \\
0   &   1   &   0   &   0   &   -1  \\
-1  &   0   &   1   &   0   &   0   \\
-1  &   0   &   0   &   1   &   0   \\
0   &   0   &   -1  &   1   &   0   \\
0   &   0   &   -1  &   0   &   1   \\
0   &   0   &   0   &   -1  &   1
\end{bmatrix}

\cdot

\begin{bmatrix}
x_1     \\
x_2     \\
x_3     \\
x_4     \\
x_5
\end{bmatrix}

\leq

\begin{bmatrix}
 0  \\
-1  \\
 1  \\
 5  \\
 4  \\
-1  \\
-3  \\
-3
\end{bmatrix}
$$

进一步抽象为：

$$
A \cdot X \leq B
$$

矩阵$$ A = n \times m $$有$$ n $$行$$ m $$列，每一行有且仅有一个$$ 1 $$和一个$$ -1 $$，其余所有值都是$$ 0 $$。未解数矩阵$$ X = 1 \times m $$有$$ 1 $$行$$ m $$列，依次为$$ [x_1, x_2, \dots, x_m] $$。常熟矩阵$$ B = n \times 1 $$有$$ n $$行$$ 1 $$列，依次为$$ [b_1, b_2, \dots, b_n] $$。

第$$ k $$行不等式满足：

$$
x_i \cdot A(k,i) + x_j \cdot A(k,j) \leq b_k
$$

其中$$ 1 \leq k \leq n $$，$$ A(k,i), A(k,j) $$等于$$ 1 $$或$$ -1 $$，且$$ i,j \in [1,m] $$。

这样的线性不等式组称为差分约束。

对于上面的差分约束，存在一组解：

$$
X = [-5, -3, 0, -1, -4]
$$

对于任意常数$$ x $$，都有：

$$
X = [-5+x, -3+x, 0+x, -1+x, -4+x]
$$

即该差分约束的通解。

给定矩阵$$ A, X, B $$以及行数$$ n $$列数$$ m $$，求差分约束的解。

#### 解法


--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 24.Single-Source Shortest Paths - 24.3.DifferentConstraints's algorithm](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)


--------

#### 源码

[DifferentConstraints.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/DifferentConstraints.h)

[DifferentConstraints.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/DifferentConstraints.cpp)

#### 测试

[DifferentConstraintsTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/DifferentConstraintsTest.cpp)
