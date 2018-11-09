<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Maximum Continuous Subsequence Sum - 最大连续子序列和

--------

#### 问题

序列$$ s $$的连续子序列是原序列的子集，元素在原序列中是连续的。例如$$ s = [-1,2,3] $$的连续子序列有$$ [-1,2,3],[-1,2],[2,3],[-1],[2],[3],[] $$，所有子序列的各个元素之和中最大的是$$ 5 = [2,3] $$（显然负数会使子序列之和减小）。

求序列$$ s $$的最大连续子序列的和。

#### 解法

设序列$$ s $$长度为$$ n $$（数组从$$ 1 $$开始，范围$$ [1,n] $$）。设$$ f(i) $$为$$ s = [1,i] $$的最大连续子序列的和，则有状态转移方程：

$$
f(i) =
\begin{cases}
0                           &   (initialize)    &   i \in [0,n] \\
s[i]                        &   (loop)          &   i \in [1,n]     &   f(i-1) \leq 0   \\
f(i-1) + s[i]               &   (loop)          &   i \in [1,n]     &   f(i-1) \gt 0
\end{cases}
$$

$$ (1) $$ 初始化$$ [1,i] $$之间的连续子序列和为$$ f(i) = 0 $$；

$$ (2) $$ 对于元素$$ s[i] $$，若前$$ i-1 $$个元素之和$$ f(i-1) \leq 0 $$，则之前部分的子序列和会使最终的和变小（因为是负值），所以直接抛弃之前的所有序列，把$$ s[i] $$作为子序列的起始，则当前最大子序列和为$$ f(i) = s[i] $$；

$$ (3) $$ 对于元素$$ s[i] $$，若前$$ i-1 $$个元素之和$$ f(i-1) \gt 0 $$，则之前部分的子序列和会使最终的和变大（因为是正值），所以在之前的子序列和基础上继续累加，则当前最大子序列和为$$ f(i) = f(i-1) + s[i] $$；

$$ f(n) $$即为序列$$ s $$的最大连续子序列和。该算法的时间复杂度为$$ O(n) $$。

--------

#### 源码

[MaximumContinuousSubsequenceSum.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/MaximumContinuousSubsequenceSum.h)

[MaximumContinuousSubsequenceSum.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/MaximumContinuousSubsequenceSum.cpp)

#### 测试

[MaximumContinuousSubsequenceSumTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/MaximumContinuousSubsequenceSumTest.cpp)

