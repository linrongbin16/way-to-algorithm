<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Longest Common Subsequence - 最长公共子序列

--------

#### 问题

序列$$ s = [1,2,3] $$的子序列有$$ [1,2,3],[1,2],[1,3],[2,3],[1],[2],[3],[] $$，但$$ [2,1] $$不是。子序列是原序列的子集，相对顺序不变。

查找两个序列$$ s_{1} $$和$$ s_{2} $$中最长公共子序列$$ s_{common} $$的长度，$$ s_{common} $$既是$$ s_{1} $$的子序列，也是$$ s_{2} $$的子序列，并且是所有子序列中最长的。

#### 解法

设序列$$ s $$长度为$$ n $$（数组从$$ 1 $$开始，范围$$ [1,n] $$），前$$ i $$个元素组成的子序列为$$ [1,i] $$。设$$ f(i,j) $$为$$ s_1 = [1,i] $$和$$ s_2 = [1,j] $$的最长公共子序列的长度，则有状态转移方程：

$$
f(i,j) =
\begin{cases}
0                       &   (initialize)    &   i,j \in [0,n] \\
f(i-1,j-1)+1            &   i,j \in [1,n]   &   s_1 [i] = s_2 [j] \\
max(f(i,j-1),f(i-1,j))  &   i,j \in [1,n]   &   s_1 [i] \neq s_2 [j]
\end{cases}
$$

$$ (1) $$ 用数组中的下标$$ 0 $$来存储初始的固定值，$$ f(i,j) = 0 $$；

$$ (2) $$ 若$$ s_1 [i] = s_2 [j] $$，则显然两个序列的这个部分是公共的，所以$$ f(i,j) $$在$$ f(i-1,j-1) $$的基础上加$$ 1 $$；

$$ (3) $$ 若$$ s_1 [i] \neq s_2 [j] $$，则两个序列的这个部分不是公共的，所以$$ f(i,j) $$仍然保持之前的值，为了获取最大值我们会在$$ f(i,j-1) $$和$$ f(i-1,j) $$中选取最大的那个；

$$ f(n,n) $$即为序列$$ s_1 $$和$$ s_2 $$的最长公共子序列的长度值。遍历该算法的时间复杂度是$$ O(n^2) $$。

--------

#### 源码

[LongestCommonSubsequence.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestCommonSubsequence.h)

[LongestCommonSubsequence.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestCommonSubsequence.cpp)

#### 测试

[LongestCommonSubsequenceTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestCommonSubsequenceTest.cpp)
