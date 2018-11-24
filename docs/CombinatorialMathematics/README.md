# Chapter-6 Combination Mathematics
# 第6章 组合数学

--------

1. [FullPermutation 全排列](FullPermutation/)
2. [Combination 组合](Combination/)
3. [Permutation 排列](Permutation/)
4. [PermutationGroup 置换群](PermutationGroup/)
5. [Catalan 卡特兰数](Catalan/)

--------

#### 集合划分

集合$$ X $$的划分是$$ X $$的非空子集的集合，使得$$ X $$的所有元素都包含且只包含在这些子集中的一个。等价的说，集合$$ P $$是$$ X $$的划分，如果

$$ (1) $$ $$ P $$的所有成员都是$$ X $$的子集，且不是空集；

$$ (2) $$ $$ P $$的所有成员的并集即为$$ X $$；

$$ (3) $$ $$ P $$的任意两个成员的交集为空集；

集合$$ P $$中的成员也称为$$ X $$的一个部分。

例如集合

$$
X = [ 1,2,3,4,5,6 ]
$$

存在一个划分

$$
P = [ [1],[2,6],[3,4],[5] ]
$$

P的所有成员$$ [1], [2,6], [3,4], [5] $$都是$$ X $$的一个部分。

#### 加法原理

集合$$ X $$的元素数量等于$$ X $$的所有部分的元素数量之和，即$$ \| X \| = \| X_1 \| + \| X_2 \| + \dots + \| X_n \| $$。

#### 乘法原理

若集合$$ X $$中的所有元素都是由两个数字组成的序列，即序偶$$ (a,b) $$。其中第一个元素$$ a $$来自拥有$$ p $$个元素的集合$$ A $$，第二个元素$$ b $$来自拥有$$ q $$个元素的集合$$ B $$。则集合$$ X $$的元素数量为$$ \| X \| = p \times q $$。

#### 减法原理

设集合$$ Y $$包含集合$$ X $$，集合$$ X $$在$$ Y $$中的补集为$$ X' $$，则$$ \| X \| = \| Y \| - \| X' \| $$。

#### 除法原理

集合$$ X $$被划分为$$ p $$个部分，每个部分的元素数量都为$$ q $$，则$$ \| X \| = p \times q $$。

#### 组合

在包含$$ n $$个互不相同元素的集合$$ A $$中选出任意$$ m $$个元素（$$ m \leq n $$）组成集合$$ B $$。

集合没有顺序的概念，若对于$$ \forall x \in A $$，都有$$ \exists x \in B $$；同时对于$$ \forall y \in B $$，都有$$ \exists y \in A $$，则称$$ A =  B $$。

从$$ n $$个元素的集合中任意取出$$ m $$个元素能够组成的不同集合的数量为：

$$
C_m^n =
\bigl(
\begin{smallmatrix}
n \\
m
\end{smallmatrix}
\bigr)
= \frac{(P_m^n)}{m!} = \frac{n!}{m! \cdot (n-m)!}
$$

在二项式定理（https://en.wikipedia.org/wiki/Binomial_coefficient）中，二项式幂$$ (1+x)^n $$的多项式展开中$$ x^k $$（其中$$ k \in [0, n] $$）的系数即为$$ \bigl( \begin{smallmatrix} n \\ k \end{smallmatrix}\bigr) $$，等同于组合学中从$$ n $$个元素中选出$$ k $$个元素组成集合的所有组合数量。

例如对于$$ (x+1)^2 = 1x^0 + 2x^1 + x^2 $$，从$$ 2 $$个元素中选取$$ 1 $$个的组合数量为$$ 2 $$；选取$$ 2 $$个的组合数量为$$ 1 $$。

对于$$ (x+1)^3 = 1x^0 + 3x^1 + 3x^2 + x^3 $$，从$$ 3 $$个元素中选取$$ 1 $$个的组合数量为$$ 3 $$；选取$$ 2 $$个的组合数量为$$ 3 $$；选取$$ 3 $$个的组合数量为$$ 1 $$。

#### 排列

在包含$$ n $$个互不相同元素的集合$$ A $$中选出任意$$ m $$个元素（$$ m \leq n $$）组成排列$$ B $$。排列有顺序的概念，元素数量相等且所有位置上元素也相同的排列才相同。例如$$ s_1 = [1,2,3], s_2 = [3,2,1], s_3 = [2,3] $$是各不相同的排列。

从$$ n $$个元素中任意取出$$ m $$个元素组成的所有排列的数量为：

$$
P_m^n = \frac{n!}{(n-m)!}
$$

也写作

$$
A_m^n = \frac{n!}{(n-m)!}
$$

维基百科中特别提到中国大陆教材中写做$$ A_n^m $$。

特别的当$$ m = n $$时，称$$ P_n^n $$为全排列，$$ P_n^n = n! $$。

#### 阶乘

阶乘的定义为：

$$
n! =
\begin{cases}
1                                                                   & n = 0 \\
1 \times 2 \times 3 \times \dots \times n = \prod_{k = 1}^n k       & \forall n \gt 0
\end{cases}
$$

阶乘的递归定义为：

$$
n! =
\begin{cases}
1                       & n = 0 \\
(n-1)! \times n         & \forall n \gt 0
\end{cases}
$$

#### 数学符号表

* [https://en.wikipedia.org/wiki/List_of_mathematical_symbols](https://en.wikipedia.org/wiki/List_of_mathematical_symbols)

