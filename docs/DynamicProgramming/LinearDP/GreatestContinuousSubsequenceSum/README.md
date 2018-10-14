<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Greatest Continuous Subsequence Sum - 最大连续子序列和

--------

#### 问题

序列$$ s $$的连续子序列是原序列的子集，元素在原序列中是连续的。例如$$ s = [1,2,3] $$的连续子序列有$$ [1,2,3],[1,2],[2,3],[1],[2],[3],[] $$。

求序列$$ s $$的最大连续子序列的和。

#### 解法

设序列$$ s $$长度为$$ n $$（数组从$$ 1 $$开始，范围$$ [1,n] $$）。设$$ f(i) $$为$$ s = [1,i] $$的最大连续子序列的和，则有状态转移方程：

$$
f(i) =
\begin{cases}
0                           &   (initialize)    &   i \in [0,n] \\
max(f(i-1) + s[i], s[i])    &   (loop)          &   i,j \in [1,n]
\end{cases}
$$

$$ (1) $$ 初始化$$ f(i) = 0 $$；

$$ (2) $$ 对于元素$$ s[i] $$，若$$ s[i] \geq 0 $$则会使该子序列的和变大，若$$ s[i] \lt 0 $$则会使该子序列的和变小。所以有$$ f(i) = max(f(i-1) + s[i], s[i]) $$在$$ f(i-1,j-1) $$的基础上加$$ 1 $$；

$$ f(n,n) $$即为序列$$ s_1 $$和$$ s_2 $$的最长公共子序列的长度值。该算法的时间复杂度为$$ O(n^2) $$。

--------

#### 源码

[GreatestContinuousSubsequenceSum.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/GreatestContinuousSubsequenceSum.h)

[GreatestContinuousSubsequenceSum.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/GreatestContinuousSubsequenceSum.cpp)

#### 测试

[GreatestContinuousSubsequenceSumTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/GreatestContinuousSubsequenceSumTest.cpp)

