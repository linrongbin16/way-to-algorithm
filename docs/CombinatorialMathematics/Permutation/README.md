<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Permutation - 排列

--------

#### 问题

从包含$$ n $$个不同元素的数组$$ s = [ x_0, x_1, x_2, \dots , x_{n-1} ]$$中任意取$$ m $$个元素（$$ m \leq n $$），组成的所有排列。其中任意两元素互不相同。

#### 解法

在Full Permutation和Combination的基础上，从拥有$$ n $$个元素的$$ s $$中选取$$ m $$个元素，可得到$$ \frac{n!}{m! \cdot (n-m)!} $$个组合。遍历所有组合进行全排列，即为所求。

该算法的时间复杂度为$$ O(P_m^n) = O( \frac {n!} {(n-m)!} ) $$。

--------

#### 源码

[Permutation.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/Permutation.h)

[Permutation.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/Permutation.cpp)

#### 测试

[PermutationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/PermutationTest.cpp)
