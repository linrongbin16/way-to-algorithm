<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Strassen - Strassen算法

--------

#### 问题

用Strassen算法计算两个$$ n $$阶矩阵相乘$$ C = A \times B $$。

#### 行列式

$$ n $$阶行列式（Determinant）：

$$
\begin{vmatrix}
a_{11}  &   a_{12}  &   \cdots  &   a_{1n}  \\
a_{21}  &   a_{22}  &   \cdots  &   a_{2n}  \\
\vdots  &   \vdots  &           &   \vdots  \\
a_{n1}  &   a_{n2}  &   \cdots  &   a_{nn}
\end{vmatrix}
$$

表示$$ n $$个元素的乘积

$$
a_{1 j_{1}} a_{2 j_{2}} \cdots a_{n j_{n}}
$$

的代数和。其中$$ j_{1}, j_{2}, \dots, j_{n} $$是$$ 1, 2, \dots, n $$的一个排列。当$$ j_{1}, j_{2}, \dots, j_{n} $$是奇排列时该项带负号，当$$ j_{1}, j_{2}, \dots, j_{n} $$是偶排列时该项带正号。对于元素$$ a_{j_{p} j_{q}} $$下标的两个数字，若$$ 1 \leq p \lt q \leq n $$且$$ j_{p} \gt j_{q} $$则称这两个有序的数$$ [ j_{p}, j_{q} ] $$是逆序对。逆序对的数量称为逆序对数。若$$ a_{1 j_{1}} a_{2 j_{2}} \cdots a_{n j_{n}} $$中所有元素下标的逆序对数为偶数，则称排列$$ j_{1}, j_{2}, \dots, j_{n} $$为偶排列；否则为奇排列。

即

$$
\begin{vmatrix}
a_{11}  &   a_{12}  &   \cdots  &   a_{1n}  \\
a_{21}  &   a_{22}  &   \cdots  &   a_{2n}  \\
\vdots  &   \vdots  &    \quad  &   \vdots  \\
a_{n1}  &   a_{n2}  &   \cdots  &   a_{nn}
\end{vmatrix}

= \sum_{j_{1} j_{2} \cdots j_{n}} (-1)^{ \tau (j_{1} j_{2} \cdots j_{n}) } a_{1 j_{1}} a_{2 j_{2}} \cdots a_{n j_{n}}
$$

其中$$ \tau (j_{1} j_{2} \cdots j_{n}) $$是行列式的逆序数，$$ \sum_{j_{1} j_{2} \cdots j_{n}} $$表示对所有$$ n $$阶排列求和，该式称为$$ n $$阶行列式的完全展开式。

特别的$$ 2 $$阶行列式和$$ 3 $$阶行列式的完全展开式分别为

$$
\begin{vmatrix}
a   &   b   \\
c   &   d
\end{vmatrix}

=

a \cdot d - b \cdot c
$$

$$
\begin{vmatrix}
a_{11}   &   a_{12} &   a_{13}  \\
a_{21}   &   a_{22} &   a_{23}  \\
a_{31}   &   a_{32} &   a_{33}
\end{vmatrix}

=

a_{11} a_{22} a_{33} + a_{12} a_{23} a_{31} + a_{13} a_{21} a_{32} - a_{13} a_{22} a_{31} - a_{12} a_{21} a_{33} - a_{11} a_{23} a_{32}
$$

行列式操作和特性：

$$ (1) $$ 经过转置行列式的值不变，即$$ \begin{vmatrix} A^T \end{vmatrix} = \begin{vmatrix} A \end{vmatrix} $$。行列式的转置是将$$ A $$的行和列交换，得到$$ A^{T} $$，转置行列式的任意元素满足$$ a_{ij}^{t} = a_{ji} $$；例如

$$
A_{33} =
\begin{vmatrix}
a_{11}  &   a_{12}  &   a_{13}  \\
a_{21}  &   a_{22}  &   a_{23}  \\
a_{31}  &   a_{32}  &   a_{33}
\end{vmatrix}

\quad

A_{33}^{T} =
\begin{vmatrix}
a_{11}  &   a_{21}  &   a_{31}  \\
a_{12}  &   a_{22}  &   a_{32}  \\
a_{13}  &   a_{23}  &   a_{33}
\end{vmatrix}
$$

$$ (2) $$ 行列式中的任意两行/列交换位置，行列式的值不变；例如

$$
\begin{vmatrix}
a_{11}  &   a_{12}  &   a_{13}  \\
a_{21}  &   a_{22}  &   a_{23}  \\
a_{31}  &   a_{32}  &   a_{33}
\end{vmatrix}

=

\begin{vmatrix}
a_{21}  &   a_{22}  &   a_{23}  \\
a_{11}  &   a_{12}  &   a_{13}  \\
a_{31}  &   a_{32}  &   a_{33}
\end{vmatrix}

=

\begin{vmatrix}
a_{22}  &   a_{21}  &  a_{23}  \\
a_{12}  &   a_{11}  &  a_{13}  \\
a_{32}  &   a_{31}  &  a_{33}
\end{vmatrix}
$$

特别的，当两行/列相同时，该行列式的值为$$ 0 $$；

$$ (3) $$ 某行/列中所有元素若存在公因子$$ k $$，则可以将$$ k $$提到行列式外；例如

$$
\begin{vmatrix}
k \cdot a_{11}  &   k \cdot a_{12}  &   \cdots  &   k \cdot a_{1n}  \\
a_{21}  &   a_{22}  &   \cdots  &   a_{2n}  \\
\vdots  &   \vdots  &           &   \vdots  \\
a_{n1}  &   a_{n2}  &   \cdots  &   a_{nn}
\end{vmatrix}

=

k \cdot

\begin{vmatrix}
a_{11}  &   a_{12}  &   \cdots  &   a_{1n}  \\
a_{21}  &   a_{22}  &   \cdots  &   a_{2n}  \\
\vdots  &   \vdots  &           &   \vdots  \\
a_{n1}  &   a_{n2}  &   \cdots  &   a_{nn}
\end{vmatrix}
$$

特别的，某行/列的值全为$$ 0 $$，该行列式的值为$$ 0 $$；某两行/列的元素对应成比例，行列式的值为$$ 0 $$；

$$ (4) $$ 某行/列的每个元素是两个元素之和，则可以把行列式拆分为两个行列式之和；例如

$$
\begin{vmatrix}
a_{1} + b_1     &   a_{2} + b_2     &   a_{3} + b_3  \\
c_{1}   &   c_{2}   &   c_{3}  \\
d_{1}   &   d_{2}   &   d_{33}
\end{vmatrix}

=

\begin{vmatrix}
a_{1}   &   a_{2}   &   a_{3}   \\
c_{1}   &   c_{2}   &   c_{3}  \\
d_{1}   &   d_{2}   &   d_{33}
\end{vmatrix}

+

\begin{vmatrix}
b_{1}   &   b_{2}   &   b_{3}   \\
c_{1}   &   c_{2}   &   c_{3}  \\
d_{1}   &   d_{2}   &   d_{33}
\end{vmatrix}
$$

$$ (5) $$ 把某行/列的$$ k $$倍加到另一行/列上，行列式的值不变；例如

$$
\begin{vmatrix}
a_{1}   &   a_{2}   &   a_{3}   \\
b_{1}   &   b_{2}   &   b_{3}  \\
c_{1}   &   c_{2}   &   c_{33}
\end{vmatrix}

=

\begin{vmatrix}
a_{1}   &   a_{2}   &   a_{3}   \\
b_{1} + k \cdot a_{1}   &   b_{2} + k \cdot a_{2}   &   b_{3} + k \cdot a_{3}   \\
c_{1}   &   c_{2}   &   c_{33}
\end{vmatrix}
$$

#### 矩阵

矩阵（Matrix）：$$ n \times m $$个数字组成的$$ n $$行$$ m $$列的表格$$ A_{nm} $$

$$
A_{nm} =
\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1m} \\
a_{21} & a_{22} & \cdots & a_{2m} \\
\vdots  & \vdots  & \ddots & \vdots  \\
a_{n1} & a_{n2} & \cdots & a_{nm}
\end{bmatrix}
$$

其中第$$ i $$行第$$ j $$列的元素为$$ a_{ij} $$（$$ 1 \leq i \leq n, 1 \leq j \leq m $$）。特别的当$$ n = m $$时称矩阵$$ A $$为$$ n $$阶矩阵或$$ n $$阶方阵。

矩阵操作和特性：

$$ (1) $$ 零矩阵：所有元素都为$$ 0 $$的矩阵

$$
\begin{bmatrix}
0   &   0   & \cdots &  0   \\
0   &   0   & \cdots &  0   \\
\vdots  & \vdots  & \ddots & \vdots  \\
0   &   0   & \cdots &  0
\end{bmatrix}
$$

零矩阵记为$$ O $$。

$$ (2) $$ 若两矩阵$$ A_{nm} $$和$$ B_{st} $$的行和列数量相等，即$$ n = s, m = t $$，称。的两矩阵称为同型矩阵。若同型矩阵的所有对应元素也想等，则两矩阵相等。

$$ (3) $$ $$ n $$阶方阵$$ A $$构成的行列式称为$$ A $$的行列式，记作$$ \begin{vmatrix} A \end{vmatrix} $$。注意矩阵是一个表格，而行列式经过计算后是一个值。

$$ (4) $$ 矩阵加法：两个同型矩阵可以相加，即$$ C_{nm} = A_{nm} + B_{nm} $$，任意元素满足$$ c_{ij} = a_{ij} + b_{ij} $$（$$ 1 \leq i \leq n, 1 \leq j \leq m $$）。矩阵加法满足特性

$$
\begin{matrix}
A + B = B + A               \\
(A + B ) + C = A + (B + C)  \\
A + O = A, A - O = A
\end{matrix}
$$

$$ (5) $$ 矩阵数乘：矩阵与数可以相乘，即$$ B_{nm} = k \cdot A_{nm} $$，任意元素满足$$ b_{ij} = k \cdot a_{ij} $$（$$ 1 \leq i \leq n, 1 \leq j \leq m $$）。矩阵数乘满足特性

$$
\begin{matrix}
k(mA) = (km)A = m(kA)   \\
(k + m)A = kA + mA      \\
k(A + B) = kA + kB      \\
1 \cdot A = A           \\
0 \cdot A = O
\end{matrix}
$$

$$ (6) $$ 矩阵乘法：两个矩阵$$ A_{nm}, B_{st} $$相乘必须满足条件$$ m = s $$，即$$ C_{nt} = A_{nm} \times B_{st} $$（$$ m = s $$），任意元素满足$$ c_{ij} = \sum_{k=1}^{m} a_{ik} \cdot b_{kj} $$（$$ 1 \leq i \leq n, 1 \leq j \leq t, 1 \leq k \leq m $$）。特别的，若$$ A $$是$$ n $$阶方阵，则$$ k $$个矩阵$$ A $$相乘的结果记为$$ \prod_{i=1}^{k} A = A^{k} $$，称为$$ A $$的$$ k $$次幂。矩阵乘法满足特性

$$
\begin{matrix}
(AB)C = A(BC)           \\
A(B + C) = AB + AC      \\
(B + C)A = BA + CA
\end{matrix}
$$

注意一般情况下$$ AB \neq BA $$。

$$ (7) $$ 矩阵转置：将矩阵$$ A_{nm} $$的行和列交换得到矩阵$$ A_{mn}^{T} $$，任意元素满足$$ a_{ij}^{t} = a_{ji} $$。称$$ A_{mn}^{T} $$为$$ A $$的转置矩阵。矩阵转置满足特性

$$
\begin{matrix}
(A + B)^{T} = A^{T} + B^{T}     \\
(k \cdot A)^{T} = k \cdot A^{T} \\
(A \cdot B)^{T} = B^{T} \cdot A^{T}     \\
(A^{T})^{T} = A
\end{matrix}
$$

$$ (8) $$ 单位矩阵：$$ n $$阶矩阵中，主对角线上的元素都是$$ 1 $$，其余元素都是$$ 0 $$，称为$$ n $$阶单位矩阵，简写作$$ E $$，$$ E_{n} $$或$$ I $$。即$$ a_{ii} = 1, a_{ij} = 0 $$（其中$$ i \neq j $$）。

$$
A_{nn} =
\begin{bmatrix}
1_{11} & 0_{12} & \cdots & 0_{1n} \\
0_{21} & 1_{22} & \cdots & 0_{2n} \\
\vdots  & \vdots  & \ddots & \vdots  \\
0_{n1} & 0_{n2} & \cdots & 1_{nn}
\end{bmatrix}
$$

$$ (9) $$ 数量矩阵：数字$$ k $$与单位矩阵$$ E $$的积$$ k \cdot E $$称为数量矩阵。

$$ (10) $$ $$ n $$阶矩阵的主对角线：即矩阵$$ A_{nn} $$上的所有元素$$ a_{ii} $$（其中$$ 1 \leq i \leq n $$）。所有元素$$ a_{ii} $$连起来称为矩阵的对角线，其中的元素称为对角元素。

$$ (11) $$ 对角矩阵：非对角元素全为$$ 0 $$的$$ n $$阶方阵称为对角矩阵。

$$ (12) $$ 上/下三角矩阵：主对角线以下/上（不包括主对角线）元素都为$$ 0 $$的$$ n $$阶矩阵，即$$ a_{ij} = 0, i \gt j $$（上三角矩阵），$$ a_{ij} = 0, i \lt j $$（下三角矩阵）。

$$ (13) $$ 对称矩阵/反对称矩阵：满足$$ A^{T} = A $$（即$$ a_{ij}^{t} = a_{ji} $$）的矩阵为对称矩阵，满足$$ A^{T} = -A $$（即$$ a_{ij}^{t} = - a_{ji} $$）的矩阵称为反对称矩阵。

#### Strassen算法

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

#### 数学复习全书（2013年李永乐李正元考研数学 数学一） - 第二篇 线性代数

* https://book.douban.com/subject/21370697/

--------

#### 源码

[Strassen.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.h)

[Strassen.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.cpp)

#### 测试

[StrassenTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/StrassenTest.cpp)

