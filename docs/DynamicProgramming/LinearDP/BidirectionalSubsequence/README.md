<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Bidirectional Subsequence - 双向子序列

--------

#### 问题

递减子序列和递增子序列的概念相同，但渐变方向相反，递减子序列的元素之间依次递减。

在长度为$$ n $$的序列$$ s = [1,n] $$中寻找元素$$ s[i] $$，使得$$ s[1,i] $$的最长递增子序列和$$ s[i,n] $$的最长递减子序列，求两段子序列的长度的最大之和。

#### 解法

设$$ f(i) $$是以$$ s[i] $$作为最右边元素的最长递增子序列的长度，$$ g(i) $$是以$$ s[i] $$作为最左边元素的最长递减子序列的长度。$$ f(i), g(i) $$的状态转移方程见$$ LongestIncreasingSubsequence $$。

最后返回$$ max\{ f(i)+g(i)-1 \} $$（$$ i \in [1,n] $$），即所有$$ f(i)+g(i)-1 $$中的最大值，之所以减去$$ 1 $$是因为$$ s[1,i] $$最右边的元素和$$ s[i,n] $$最左边的元素是同一个元素，重复了因此长度减$$ 1 $$。该算法的时间复杂度为$$ O(n^2) $$。

--------

#### 源码

[BidirectionalSubsequence.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/BidirectionalSubsequence.h)

[BidirectionalSubsequence.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/BidirectionalSubsequence.cpp)

#### 测试

[BidirectionalSubsequenceTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/BidirectionalSubsequenceTest.cpp)
