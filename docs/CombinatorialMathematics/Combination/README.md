<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Combination - 组合

--------

#### 问题

从包含$$ n $$个元素的集合$$ s = [x_0, x_1, x_2, \dots ,x_{n-1} ] $$中任意取$$ m $$个元素（$$ m \leq n $$）组成组合，求所有组合。集合$$ s $$中任意两元素互不相同。

#### 解法

设置集合$$ c = [ c_0, c_1, c_2, \dots , c_{m-1} ] $$表示集合$$ s $$的选择，$$ c_i = 1 $$表示选择数字$$ x_i $$，$$ c_i = 0 $$表示不选择数字$$ x_i $$。比如集合$$ s = [ x_0, x_1, x_2, \dots, x_{n-1} ] $$中取出组合

$$
[x_0, x_1, x_2]
$$

等价于集合

$$
c = [1_0, 1_1, 1_2, 0_3, \dots, 0_{n-1} ]
$$

即元素$$ [ c_0, c_1, c_2 ] $$为$$ 1 $$，元素$$ [ c_3, \dots, c_{n-1} ] $$为$$ 0 $$。

可以看出，包含$$ n $$个元素的集合$$ s = [x_0, x_1, x_2, \dots, x_{n-1} ] $$中取出$$ m $$个元素的所有组合，可以转化为求有$$ i $$个$$ 1 $$，$$ m - i $$个$$ 0 $$的集合$$ c $$的唯一全排列，其中$$ 0 \leq i \leq m $$。

$$ (1) $$ 从集合$$ s $$中取出$$ 0 $$个元素作为组合，即$$ c $$中有$$ 0 $$个$$ 1 $$，$$ m $$个$$ 0 $$，唯一全排列有$$ C_0^m = 1 $$个

$$
[]
$$

$$ (2) $$ 从集合$$ s $$中取出$$ 1 $$个元素作为组合。则$$ c $$中有$$ 1 $$个$$ 1 $$，$$ m-1 $$个$$ 0 $$，唯一全排列有$$ C_1^m = m $$个

$$
\begin{array}{lcr}
[ 1_0, 0_1, 0_2, \dots , 0_{n-1} ]  \\
[ 0_0, 1_1, 0_2, \dots , 0_{n-1} ]  \\
[ 0_0, 0_1, 1_2, \dots , 0_{n-1} ]  \\
\cdots      \\
[ 0_0, 0_1, 0_2, \dots , 1_{n-1} ]
\end{array}
$$

$$ (3) $$ 从集合$$ s $$中取出$$ 2 $$个元素作为组合，则$$ c $$中有$$ 2 $$个$$ 1 $$，$$ m-2 $$个$$ 0 $$，唯一全排列有$$ C_2^m = m $$个。

只要求出所有唯一全排列，即可反向求出对应的组合。

包含$$ n $$个元素中选出$$ m $$个元素的所有组合，需要重复$$ m + 1 $$次，每次求有$$ i $$个$$ 1 $$，$$ m - i $$个$$ 0 $$的集合$$ c $$的唯一全排列，其中$$ i \in [0, m] $$。根据全排列反向得到组合，算法结束。第$$ i $$步求唯一全排列的时间复杂度为$$ O(i!) $$，该算法的时间复杂度为$$ O(C_m^n) = O(\frac{n!}{m! \cdot (n-m)!}) $$。

#### StackOverflow - algorithm-to-return-all-combinations-of-k-elements-from-n

* http://stackoverflow.com/questions/127704/algorithm-to-return-all-combinations-of-k-elements-from-n

#### 二项式系数

* https://en.wikipedia.org/wiki/Binomial_coefficient

#### Chase’s Twiddle - Algorithm 382: Combinations of M out of N Objects:

* http://dl.acm.org/citation.cfm?id=362502
* http://www.netlib.no/netlib/toms/382

#### Buckles - Algorithm 515: Generation of a Vector from the Lexicographical Index:

* http://dl.acm.org/citation.cfm?id=355739

* https://www.researchgate.net/profile/Bill_Buckles/publication/220492658_Algorithm_515_Generation_of_x_Vector_from_the_Lexicographical_Index_G6/links/5716d7ad08ae497c1a5706ec.pdf

#### Remark on algorithm 515: Generation of a vector from the lexicographical index combinations

* http://dl.acm.org/citation.cfm?id=1236470

--------

#### 源码

[Combination.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/Combination.h)

[Combination.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/Combination.cpp)

#### 测试

[CombinationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/CombinationTest.cpp)
