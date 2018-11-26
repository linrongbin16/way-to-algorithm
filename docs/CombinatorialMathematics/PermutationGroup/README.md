<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# PermutationGroup Group - 置换群

--------

#### 问题

包含$$ n $$个元素的排列$$ s = [x_0, x_1, x_2, \dots, x_{n-1} ] $$，元素范围为$$ [0, n-1] $$且互不相同。另一个包含$$ n $$个元素的数组$$ t = [y_0, y_1, y_2, \dots, y_{n-1} ] $$，元素范围也是$$ [0, n-1] $$且互不相同。且$$ s \neq t $$。

排列$$ s $$在数组$$ t $$上的置换操作为$$ s[t[i]] = s[i] $$（其中$$ i \in [0, n-1] $$），称$$ t $$是$$ s $$的置换准则。对$$ s $$中的所有元素按照数组$$ t $$的对应下标上的值进行置换称为一次置换操作。例如

$$
s = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
$$

在置换准则

$$
t = [3, 4, 2, 6, 1, 7, 0, 5, 9, 8]
$$

进行一次置换后得到

$$
s = [6, 4, 2, 0, 1, 7, 3, 5, 9, 8]
$$

求包含$$ n $$个元素的排列$$ s $$在置换准则$$ t $$下经过$$ k $$次置换操作后得到的排列。

#### 解法

显然暴力$$ k $$次循环的时间复杂度过高，不予采用。

对于上面例子的排列$$ s $$及置换准则$$ t $$

$$
\begin{matrix}
s = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] \\
t = [3, 4, 2, 6, 1, 7, 0, 5, 9, 8]
\end{matrix}
$$

$$ (1) $$ 对于第$$ 0 $$个元素，第$$ 1 $$次置换后$$ s[0] = 6 $$，即$$ s_1 = [6, 4, 2, 0, 1, 7, 3, 5, 9, 8] $$；

$$ (2) $$ 对于第$$ 0 $$个元素，第$$ 2 $$次置换后$$ s[0] = 3 $$，即$$ s_2 = [3, 1, 2, 6, 4, 5, 0, 7, 8, 9] $$；

$$ (3) $$ 对于第$$ 0 $$个元素，第$$ 3 $$次置换后$$ s[0] = 0 $$，即$$ s_3 = [0, 4, 2, 3, 1, 7, 6, 5, 9, 8] $$；

$$ (4) $$ 对于第$$ 0 $$个元素，第$$ 4 $$次置换后$$ s[0] = 6 $$，即$$ s_4 = [6, 1, 2, 0, 4, 5, 3, 7, 8, 9] $$；

第$$ 4 $$次置换后的$$ s_4[0] $$和第$$ 1 $$次置换后的$$ s_1[0] $$相同，即$$ s_4[0] = s_1[0] $$。可以看出置换操作存在周期性。本题例子中，第$$ 0 $$个元素$$ s[0] $$的置换周期为$$ 3 $$，即$$ s_{i+3}[0] = s_{i}[0] $$（其中$$ i \geq 0 $$）。

只要确定所有元素的置换周期，就可以跳过$$ k $$次暴力循环。设$$ m $$为包含$$ n $$个元素的排列$$ s $$上平均每个元素的置换周期，则该算法的时间复杂度为$$ O(n \times m) $$。

--------

#### 源码

[PermutationGroup.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/PermutationGroup.h)

[PermutationGroup.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/PermutationGroup.cpp)

#### 测试

[PermutationGroupTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/PermutationGroupTest.cpp)
