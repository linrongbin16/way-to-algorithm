# Chapter-8 Linear Algebra
# 第8章 线性代数

![Matrix.png](res/Matrix.png)

--------

1. Matrix 矩阵
    1. [Strassen Strassen算法](Matrix/Strassen/)
    2. [GaussElimination 高斯消元法](Matrix/GaussElimination/)
    3. [LUP LUP分解](Matrix/LUP/)
    4. [InverseMatrix 矩阵求逆](Matrix/InverseMatrix/)
2. LinearProgramming 线性规划
    1. [Simplex 单纯形算法](LinearProgramming/Simplex/)
    2. [Dinkelback Dinkelback算法](LinearProgramming/Dinkelback/)


--------

#### 行列式

$$ n $$阶行列式

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
a_{1j_{1}} a_{2j_{2}} \cdots a_{nj_{n}}
$$

的代数和。


#### 矩阵

矩阵（Matrix）：$$ n \times m $$个数字组成的$$ n $$行$$ m $$列的表格$$ A_{n,m} $$，第$$ i $$行第$$ j $$列的元素为$$ a_{i,j} $$，其中$$ 1 \leq i \leq n, 1 \leq j \leq m $$。

$$
A_{n,m} =
\begin{pmatrix}
a_{1,1} & a_{1,2} & \cdots & a_{1,m} \\
a_{2,1} & a_{2,2} & \cdots & a_{2,m} \\
\vdots  & \vdots  & \ddots & \vdots  \\
a_{n,1} & a_{n,2} & \cdots & a_{n,m}
\end{pmatrix}
$$

零矩阵：所有元素都为$$ 0 $$的矩阵。即$$ A_{n,m} $$中的任意元素$$ a_{i,j} = 0 $$。

矩阵相等：两矩阵相等$$ A = B $$，当且仅当$$ A $$和$$ B $$的行列数相同，且所有对应元素也相等。

$$ n $$阶矩阵：$$ n \times n $$的矩阵。

$$ n $$阶矩阵的主对角线：即矩阵$$ A_{n,n} $$上的元素$$ a_{i,i} $$，其中$$ 1 \leq i \leq n $$。

上三角矩阵：主对角线以下（不包括主对角线）元素都为$$ 0 $$的$$ n $$阶矩阵。

下三角矩阵：主对角线以上（不包括主对角线）元素都为$$ 0 $$的$$ n $$阶矩阵。

单位矩阵：$$ n $$阶矩阵中，主对角线上的元素都是$$ 1 $$，其余元素都是$$ 0 $$，称为$$ n $$阶单位矩阵，简写作$$ E $$。即$$ a_{i,i} = 1, a_{i,j} = 0 $$，其中$$ i \neq j $$。

$$
A_{n,n} =
\begin{pmatrix}
1_{1,1} & 0_{1,2} & \cdots & 0_{1,n} \\
0_{2,1} & 1_{2,2} & \cdots & 0_{2,n} \\
\vdots  & \vdots  & \ddots & \vdots  \\
0_{n,1} & 0_{n,2} & \cdots & 1_{n,n}
\end{pmatrix}
$$

转置矩阵：矩阵$$ A $$的转置矩阵是$$ m \times n $$的矩阵$$ AT $$，$$ AT $$中的任意元素$$ at_{j,i} = a_{i,j} $$。

对称矩阵：若$$ A $$的转置矩阵$$ AT = A $$，则称$$ A $$是对称矩阵。

反对称矩阵：若$$ A $$的转置矩阵$$ AT = -A $$，即$$ at_{j,i} = -a_{i,j} $$，则称$$ A $$为反对称矩阵。

对角矩阵：$$ n $$阶矩阵$$ A $$主对角线以外的其余元素都是$$ 0 $$，则A为对角矩阵。

#### 线性相关

线性有关/线性无关：矩阵中某一行无法通过其他行的加减乘除运算变换得到，则该行与其他行线性无关。反之若矩阵中的任意一行可以与其他行通过加减乘除转化为全$$ 0 $$，则称该行与其他行线性有关。

初等变换：矩阵中行之间的加减乘除运算称为初等变换。

矩阵的秩：矩阵中任意行或列之间线性无关的行数或列数即为矩阵的秩，记作$$ r $$。等价的说，经过有限次初等变换矩阵转化为最多包含全$$ 0 $$的行/列，最终非全$$ 0 $$的行/列的数量即为矩阵的秩。

//不全为0的行和列的数量即为矩阵的秩，经过初等变换不存在全0的行或列的矩阵称为满秩矩阵

逆矩阵：$$ n $$阶矩阵$$ A $$存在一个对应的$$ n $$阶矩阵$$ B $$，使得$$ A \times B = B \times A = E $$，则称$$ A $$是可逆矩阵，$$ B $$为$$ A $$的逆矩阵。

正定矩阵：设$$ A $$是$$ n $$阶矩阵，$$ x $$是任意$$ n $$维向量，$$ xt $$是$$ x $$的转置，若对于任意的$$ x \neq 0 $$都有$$ xt \times A \times x \gt 0 $$，则称$$ A $$是正定矩阵。

#### 矩阵运算

矩阵加减：能够进行加减运算的两矩阵必须有相等的行和列，$$ m \times n $$的矩阵$$ A + B = C $$，或$$ A - B = C $$。矩阵$$ C $$中的任意元素满足$$ c_{i,j} = a_{i,j} + b_{i,j} $$或$$ c_{i,j} = a_{i,j} - b_{i,j} $$。

矩阵数乘：矩阵$$ A $$与常数$$ c $$相乘得到矩阵$$ B = A \times c $$，矩阵$$ B $$中的任意元素满足$$ b_{i,j} = c \times a_{i,j} $$。

矩阵乘：能够进行乘运算的矩阵$$ A $$和$$ B $$必须$$ A $$的列与$$ B $$的行相等，即$$ A $$是$$ m \times s $$的矩阵，$$ B $$是$$ s \times n $$的矩阵，$$ A \times B = C $$得到的矩阵$$ C $$是$$ m \times n $$矩阵。矩阵$$ C $$中任意元素满足$$ c_{i,j} = a_{i,1} \times b_{1,j} + a_{i,2} \times b_{2,j} + \dots + a_{i,s} \times b_{s,j}  = \sum_{p=1}^{s} a_{i,p} \times b_{p,j} $$。

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

本问题只考虑$$ r = n $$时有唯一解的线性方程组的解法。

对于包含通解的$$ r \lt n $$的情况，非全$$ 0 $$的行可以用$$ $$


--------

#### 数学复习全书（2013年李永乐李正元考研数学 数学一） - 第二篇 线性代数

* https://book.douban.com/subject/21370697/

