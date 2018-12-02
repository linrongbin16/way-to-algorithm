<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Strassen - Strassen算法

--------

#### 问题

用Strassen算法计算两个$$ n $$阶矩阵相乘$$ C = A \times B $$。

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

$$ 2 $$阶行列式和$$ 3 $$阶行列式的完全展开式分别为

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

#### 矩阵

矩阵（Matrix）：$$ n \times m $$个数字组成的$$ n $$行$$ m $$列的表格$$ A_{nm} $$，第$$ i $$行第$$ j $$列的元素为$$ a_{ij} $$，其中$$ 1 \leq i \leq n, 1 \leq j \leq m $$。

$$
A_{nm} =
\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1m} \\
a_{21} & a_{22} & \cdots & a_{2m} \\
\vdots  & \vdots  & \ddots & \vdots  \\
a_{n1} & a_{n2} & \cdots & a_{nm}
\end{bmatrix}
$$

零矩阵：所有元素都为$$ 0 $$的矩阵。即$$ A_{nm} $$中的任意元素$$ a_{ij} = 0 $$。

矩阵相等：两矩阵相等$$ A = B $$，当且仅当$$ A $$和$$ B $$的行列数相同，且所有对应元素也相等。

$$ n $$阶矩阵：$$ n \times n $$的矩阵。

$$ n $$阶矩阵的主对角线：即矩阵$$ A_{nn} $$上的元素$$ a_{ii} $$，其中$$ 1 \leq i \leq n $$。

上三角矩阵：主对角线以下（不包括主对角线）元素都为$$ 0 $$的$$ n $$阶矩阵。

下三角矩阵：主对角线以上（不包括主对角线）元素都为$$ 0 $$的$$ n $$阶矩阵。

单位矩阵：$$ n $$阶矩阵中，主对角线上的元素都是$$ 1 $$，其余元素都是$$ 0 $$，称为$$ n $$阶单位矩阵，简写作$$ E $$。即$$ a_{ii} = 1, a_{ij} = 0 $$，其中$$ i \neq j $$。

$$
A_{nn} =
\begin{bmatrix}
1_{11} & 0_{12} & \cdots & 0_{1n} \\
0_{21} & 1_{22} & \cdots & 0_{2n} \\
\vdots  & \vdots  & \ddots & \vdots  \\
0_{n1} & 0_{n2} & \cdots & 1_{nn}
\end{bmatrix}
$$

转置矩阵：矩阵$$ A $$的转置矩阵是$$ m \times n $$的矩阵$$ AT $$，$$ AT $$中的任意元素$$ at_{ji} = a_{ij} $$。

对称矩阵：若$$ A $$的转置矩阵$$ AT = A $$，则称$$ A $$是对称矩阵。

反对称矩阵：若$$ A $$的转置矩阵$$ AT = -A $$，即$$ at_{ji} = -a_{ij} $$，则称$$ A $$为反对称矩阵。

对角矩阵：$$ n $$阶矩阵$$ A $$主对角线以外的其余元素都是$$ 0 $$，则A为对角矩阵。

#### 线性相关

线性有关/线性无关：矩阵中某一行无法通过其他行的加减乘除运算变换得到，则该行与其他行线性无关。反之若矩阵中的任意一行可以与其他行通过加减乘除转化为全$$ 0 $$，则称该行与其他行线性有关。

初等变换：矩阵中行之间的加减乘除运算称为初等变换。

矩阵的秩：矩阵中任意行或列之间线性无关的行数或列数即为矩阵的秩，记作$$ r $$。等价的说，经过有限次初等变换矩阵转化为最多包含全$$ 0 $$的行/列，最终非全$$ 0 $$的行/列的数量即为矩阵的秩。

//不全为0的行和列的数量即为矩阵的秩，经过初等变换不存在全0的行或列的矩阵称为满秩矩阵

逆矩阵：$$ n $$阶矩阵$$ A $$存在一个对应的$$ n $$阶矩阵$$ B $$，使得$$ A \times B = B \times A = E $$，则称$$ A $$是可逆矩阵，$$ B $$为$$ A $$的逆矩阵。

正定矩阵：设$$ A $$是$$ n $$阶矩阵，$$ x $$是任意$$ n $$维向量，$$ xt $$是$$ x $$的转置，若对于任意的$$ x \neq 0 $$都有$$ xt \times A \times x \gt 0 $$，则称$$ A $$是正定矩阵。

#### 矩阵运算

矩阵加减：能够进行加减运算的两矩阵必须有相等的行和列，$$ m \times n $$的矩阵$$ A + B = C $$，或$$ A - B = C $$。矩阵$$ C $$中的任意元素满足$$ c_{ij} = a_{ij} + b_{ij} $$或$$ c_{ij} = a_{ij} - b_{ij} $$。

矩阵数乘：矩阵$$ A $$与常数$$ c $$相乘得到矩阵$$ B = A \times c $$，矩阵$$ B $$中的任意元素满足$$ b_{ij} = c \times a_{ij} $$。

矩阵乘：能够进行乘运算的矩阵$$ A $$和$$ B $$必须$$ A $$的列与$$ B $$的行相等，即$$ A $$是$$ m \times s $$的矩阵，$$ B $$是$$ s \times n $$的矩阵，$$ A \times B = C $$得到的矩阵$$ C $$是$$ m \times n $$矩阵。矩阵$$ C $$中任意元素满足$$ c_{ij} = a_{i1} \times b_{1j} + a_{i2} \times b_{2j} + \dots + a_{is} \times b_{sj}  = \sum_{p=1}^{s} a_{ip} \times b_{pj} $$。

#### Strassen算法

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
p_1 = a \times f - a \times h = a \times (f - h)            \\
p_2 = a \times h + b \times h = (a + b) \times h            \\
p_3 = c \times e + d \times e = (c + d) \times e            \\
p_4 = d \times g - d \times e = d \times (g - e)            \\
p_5 = a \times e + a \times h + d \times e + d \times h = (a + d) \times (e + h)        \\
p_6 = b \times g + b \times h - d \times g - d \times h = (b - d) \times (g + h)        \\
p_7 = a \times e + a \times f - c \times e - c \times f = (a - c) \times (e + f)
\end{matrix}
$$

又因为

$$
\begin{matrix}
r = p_5 + p_4 - p_2 + p_6   \\
s = p_1 + p_2               \\
t = p_3 + p_4               \\
u = p_1 + p_5 - p_3 - p_7
\end{matrix}
$$

显然通过特别的设置$$ p_1 $$到$$ p_7 $$这$$ 7 $$个中间矩阵，最终也可求出两矩阵的相乘结果。

从上式可以看出，进行一次矩阵乘法需要计算$$ 8 $$次子矩阵相乘，其时间复杂度为$$ O(n^3) $$。

//但Strassen算法只需要递归的计算7个子矩阵，使得时间复杂度下降到O(n^2.81)

//由此，添加了若干子矩阵的加减运算，但得到一个矩阵只需要进行7次子矩阵的相乘
//为了方便本文中只考虑n为偶数的矩阵相乘，若n为奇数则子矩阵的划分总是多出一行一列
//实际中该算法由于增加了过多的矩阵加减运算，其实际效率并不高

--------

#### 数学复习全书（2013年李永乐李正元考研数学 数学一） - 第二篇 线性代数

* https://book.douban.com/subject/21370697/

--------

#### 源码

[Strassen.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.h)

[Strassen.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/Strassen.cpp)

#### 测试

[StrassenTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/LinearAlgebra/Matrix/StrassenTest.cpp)

