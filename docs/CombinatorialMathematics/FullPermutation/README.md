<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Full Permutation - 全排列

--------

#### 问题

求拥有$$ n $$个不同元素的数组$$ s = [x_0, x_1, x_2, \dots, x_{n-1} ] $$的全排列，其中任意两元素互不相同。

#### 解法

本文介绍Steinhaus-Johnson-Trotter算法求解数组的所有全排列。

$$ (1) $$ 初始化设数组为空$$ s = [] $$，其全排列只有$$ 1 $$个：

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

由此可得包含$$ n $$个元素的数组$$ s = [x_0, x_1, \dots, x_{n-1}] $$的全排列数量为

$$
f(n) = 
\begin{cases}
1                   &   n = 1   \\
f(n-1) \times n     & n \gt 1
\end{cases}
$$

求$$ n $$个元素的全排列，需要重复$$ n $$步找出所有排列，该算法的时间复杂度为$$ O(n!) $$。

#### 唯一全排列

若数组$$ s = [ x_0, x_1, x_2, \dots , x_{n-1} ] $$中存在重复的元素，按照上述算法可能得到重复的排列。比如$$ s = [1, 2, 3_1, 3_2 ]$$的全排列为：

$$
\begin{matrix}
[3_2, 3_1, 1, 2] \\
[3_1, 3_2, 1, 2] \\
[3_1, 1, 3_2, 2] \\
[3_1, 1, 2, 3_2] \\
[3_2, 1, 3_1, 2] \\
[1, 3_2, 3_1, 2] \\
[1, 3_1, 3_2, 2] \\
[1, 3_1, 2, 3_2] \\
[3_2, 1, 2, 3_1] \\
[1, 3_2, 2, 3_1] \\
[1, 2, 3_2, 3_1] \\
[1, 2, 3_1, 3_2] \\
[3_2, 3_1, 2, 1] \\
[3_1, 3_2, 2, 1] \\
[3_1, 2, 3_2, 1] \\
[3_1, 2, 1, 3_2] \\
[3_2, 2, 3_1, 1] \\
[2, 3_2, 3_1, 1] \\
[2, 3_1, 3_2, 1] \\
[2, 3_1, 1, 3_2] \\
[3_2, 2, 1, 3_1] \\
[2, 3_2, 1, 3_1] \\
[2, 1, 3_2, 3_1] \\
[2, 1, 3_1, 3_2]
\end{matrix}
$$

由于数组$$ s $$中存在重复的元素，产生的全排列中也存在$$ [1, 2, 3_1, 3_2] $$和$$ [1, 2, 3_2, 3_1] $$这样的重复排列。去除重复的排列，得到唯一全排列为：

$$
\begin{matrix}
[3, 3, 1, 2] \\
[3, 1, 3, 2] \\
[3, 1, 2, 3] \\
[1, 3, 3, 2] \\
[1, 3, 2, 3] \\
[1, 2, 3, 3] \\
[3, 3, 2, 1] \\
[3, 2, 3, 1] \\
[3, 2, 1, 3] \\
[2, 3, 3, 1] \\
[2, 3, 1, 3] \\
[2, 1, 3, 3]
\end{matrix}
$$

求唯一全排列的方法很简单：仍然使用求解Full Permutation的方法，额外定义全局的哈希表存储每个排列的哈希值，每生成一个新的排列，查询其哈希值是否已经存在于该哈希表中。若存在说明排列重复，跳过该排列；若不存在说明排列不重复，将其哈希值加入哈希表中。

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

