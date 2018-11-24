<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Full Permutation - 全排列

--------

#### 问题

求包含$$ n $$个不同元素的集合$$ s = [x_0, x_1, x_2, \dots, x_{n-1} ] $$的全排列，其中任意两元素互不相同。

#### 解法

本文介绍Steinhaus-Johnson-Trotter算法求解集合的所有全排列。

$$ (1) $$ 初始化设集合为空$$ s = [] $$，其全排列只有$$ 1 $$个：

$$
\begin{matrix}
[]
\end{matrix}
$$

$$ (2) $$ 在第$$ (1) $$步基础上增加新元素$$ x_0 $$，可插入的位置唯一，得到$$ 1 $$个排列：

$$
\begin{matrix}
[x_0] \\
\end{matrix}
$$

$$ (3) $$ 在第$$ (2) $$步基础上增加新元素$$ x_1 $$，可插入的位置有$$ 2 $$个，得到$$ 2 $$个排列：

$$
\begin{matrix}
[x_0, x_1] \\
[x_1, x_0]
\end{matrix}
$$

$$ (4) $$ 在第$$ (3) $$步基础上增加新元素$$ x_2 $$，可插入的位置都有$$ 3 $$个，得到$$ 2 \times 3 = 6 $$个排列：

$$
\begin{matrix}
[x_0, x_1, x_2] \\
[x_0, x_2, x_1] \\
[x_2, x_1, x_0] \\
[x_1, x_0, x_2] \\
[x_2, x_0, x_1] \\
[x_1, x_2, x_0]
\end{matrix}
$$

可以看出在第$$ n $$步操作时新增元素$$ x_{n-1} $$，这时可以插入的位置有$$ n $$个，设第$$ n - 1 $$步插入后得到的排列数量为$$ f(n-1) $$，第$$ n $$步插入后得到的排列数量为$$ f(n) = f(n-1) \times n $$。

由此可得包含$$ n $$个元素的集合$$ s = [x_0, x_1, \dots, x_{n-1}] $$的全排列数量为

$$
f(n) = 
\begin{cases}
1                   &   n = 1   \\
f(n-1) \times n     & n \gt 1
\end{cases}
$$

求$$ n $$个元素的全排列，需要重复$$ n $$步找出所有排列，该算法的时间复杂度为$$ O(n!) $$。

--------

#### Steinhaus-Johnson-Trotter算法

* [https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm](https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm)

#### LeetCode

* leetcode 46: [website](https://leetcode.com/problems/permutations/#/description), [source.hpp](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/leetcode/leetcode46.cpp)
* leetcode 47: [website](https://leetcode.com/problems/permutations-ii/), [leetcode-47 source.hpp](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/attachment/leetcode-47.hpp)

--------

#### 源码

[FullPermutation.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.h)

[FullPermutation.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.cpp)

#### 测试

[FullPermutationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutationTest.cpp)

