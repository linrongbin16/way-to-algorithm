<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Longest Increasing Subsequence - 最长递增子序列

--------

#### 问题

序列$$ s $$的递增子序列是原序列的子集，元素相对原序列的顺序不变，且依次递增。例如序列$$ s = [3,0,2,1,4] $$的递增子序列有$$ [], [3], [0], [2], [1], [4], [3,4], [0,2], [0,4], [2,4], [1,4], [0,2,4], [0,1,4] $$。

求序列$$ s $$的最长递增子序列的长度。

#### 解法

设序列$$ s $$的长度为$$ n $$，范围为$$ [1,n] $$，前$$ i $$个元素组成的子序列为$$ [1,i] $$。设$$ f(i) $$是以$$ s[i] $$为最后一个元素的最长递增子序列的长度，则有状态转移方程：

$$
f(i) =
\begin{cases}
0                   &   (initialize)    &   i = 0 \\
max \{ f(k)+1 \}    &   i \in [1,n], k \in [1,i-1], s[i] \gt s[k]
\end{cases}
$$

$$ (1) $$ 前$$ 0 $$个字符$$ s[0] $$的最长递增子序列显然是空的，因此$$ f(0) = 0 $$；

$$ (3) $$ 对于序列$$ s $$中第$$ i $$个数字$$ s[i] $$，至少$$ s[i] $$一个字符可以作为一个递增子序列，因此至少有$$ f(i) \geq 1 $$。若$$ s[i] \gt s[k] $$（其中$$ k \in [1,i-1] $$）则$$ s[i] $$与$$ s[1,k] $$的最长递增子序列可以组成一个更长的递增子序列，因此$$ f(i) = f(k)+1 $$，遍历所有可能的$$ k $$，找出下一个最长的递增子序列；

该算法的时间复杂度是$$ O(n^2) $$。

--------

#### 源码

[LongestIncreasingSubsequence.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestIncreasingSubsequence.h)

[LongestIncreasingSubsequence.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestIncreasingSubsequence.cpp)

#### 测试

[LongestIncreasingSubsequenceTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestIncreasingSubsequenceTest.cpp)
