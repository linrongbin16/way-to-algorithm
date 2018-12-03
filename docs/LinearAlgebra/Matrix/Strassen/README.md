<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Strassen - Strassen算法

--------

#### 问题

用Strassen算法计算两个$$ n $$阶矩阵相乘$$ C = A \times B $$。

#### 解法

根据数学定义，计算两个$$ n $$阶矩阵相乘，由于$$ c_{ij} = \sum_{k=1}^{n} a_{ik} \cdot b_{kj} $$，计算$$ C $$中的一个元素的时间复杂度为$$ O(n) $$。$$ C $$中有$$ n^2 $$个元素，因此时间复杂度为$$ O(n^3) $$。Strassen算法的时间复杂度比平凡算法更低。

对于$$ n $$阶矩阵乘法$$ C = A \times B $$，设$$ n $$为偶数，则可以将$$ A, B, C $$三个矩阵划分为$$ 4 $$个$$ n/2 $$的矩阵，$$ C = A \times B $$转化为

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

上面计算中设两个$$ n $$阶矩阵相乘的时间复杂度为$$ T(n) $$，则$$ 8 $$次矩阵相乘的时间复杂度为$$ 8 \cdot T( \frac{n}{2} ) $$。$$ n $$阶方阵的加法需要分别计算$$ n^2 $$次两个元素之和，因此时间复杂度为$$ O(n^2) $$。由此可知

$$
T(n) = 8 \cdot T(\frac{n}{2}) + O(n^2)
$$

通过时间复杂度的推导方法，可以得出$$ T(n) = O(n^3) $$。因此分治法的时间复杂度与平凡算法相同。

Strassen算法在分治法基础上设置$$ 7 $$个中间矩阵，将上式转化为

$$
\begin{matrix}
p_1 = a \times f - a \times h = a \times (f - h)            \\
p_2 = a \times h + b \times h = (a + b) \times h            \\
p_3 = c \times e + d \times e = (c + d) \times e            \\
p_4 = d \times g - d \times e = d \times (g - e)            \\
p_5 = a \times e + a \times h + d \times e + d \times h = (a + d) \times (e + h)        \\
p_6 = b \times g + b \times h - d \times g - d \times h = (b - d) \times (g + h)        \\
p_7 = a \times e + a \times f - c \times e - c \times f = (a - c) \times (e + f)
\end{matrix}
$$

可得

$$
\begin{matrix}
r = p_5 + p_4 - p_2 + p_6   \\
s = p_1 + p_2               \\
t = p_3 + p_4               \\
u = p_1 + p_5 - p_3 - p_7
\end{matrix}
$$

这样计算矩阵相乘时，只需要计算$$ 7 $$次矩阵相乘运算，矩阵间的加减运算的时间复杂度仍然是$$ O(n^2) $$。即有

$$
T(n) = 7 \cdot T( \frac{n} {2} ) + O(n^2)
$$

最终推导可得，Strassen算法的时间复杂度为$$ O(n^{log_2 7}) \approx O(n^{2.81}) $$。

--------

#### 源码

[Strassen.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.h)

[Strassen.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.cpp)

#### 测试

[StrassenTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/StrassenTest.cpp)

