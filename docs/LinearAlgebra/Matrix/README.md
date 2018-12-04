<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Section-1 Matrix 矩阵

--------

1. [Strassen Strassen算法](Strassen/)
2. [GaussElimination 高斯消元法](GaussElimination/)
3. [LUP LUP分解](LUP/)
4. [InverseMatrix 矩阵求逆](InverseMatrix/)

--------

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

#### 可逆矩阵

对于$$ n $$阶方阵$$ A $$，存在$$ n $$阶方阵$$ B $$使得

$$
AB = BA = E
$$

其中$$ E $$是单位矩阵，称$$ A $$是可逆矩阵或非奇异矩阵（反之不存在的矩阵为不可逆矩阵或奇异矩阵），$$ B $$是$$ A $$的逆矩阵，记作$$ A^{-1} = B $$。

#### 初等变换

对于矩阵$$ A $$

$$ (1) $$ 用非零常数$$ k $$（$$ k \neq 0 $$）乘$$ A $$的某行/列的每个元素；

$$ (2) $$ 互换$$ A $$的某两行/列；

$$ (3) $$ 将$$ A $$的某行/列元素的$$ k $$倍加到另一行/列；

上面三种操作是矩阵的三种初等变换，分别称为初等倍乘、初等互换、初等倍加行/列变换。

若矩阵$$ A $$经过有限次初等变化变成矩阵$$ B $$，则称$$ A $$和$$ B $$等价，记作$$ A \cong B $$。若$$ A \cong \begin{bmatrix} E_{r} & O \\ O & O \end{bmatrix} $$，则称后者为$$ A $$的等价标准形。

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

增广矩阵的左边部分是线性方程组中的矩阵$$ A $$，右边部分是线性方程组中的系数向量$$ B $$。增广矩阵是一个$$ n \times (m+1) $$的矩阵。

高斯消元法的数学含义在于通过初等变化，将线性方程组对应的增广矩阵变化为只有$$ r $$行不全为$$ 0 $$的矩阵（其中$$ r $$为增广矩阵的秩），形如

$$

\begin{bmatrix}
\begin{array} {c|c}
\begin{matrix}
c_{11} &   c_{12} &   c_{13} &   \dots   &   c_{1r} &   \dots   &   c_{1m}     \\
0_{21} &   c_{22} &   c_{23} &   \dots   &   c_{2r} &   \dots   &   c_{2m}     \\
0_{31} &   0_{32} &   c_{33} &   \dots   &   c_{3r} &   \dots   &   c_{3m}     \\
\dots       \\
0_{r1} &   0_{r2} &   0_{r3} &   \dots   &   c_{rr} &   \dots   &   c_{rm}     \\
\dots       \\
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

--------

#### 数学复习全书（2013年李永乐李正元考研数学 数学一） - 第二篇 线性代数

* https://book.douban.com/subject/21370697/
