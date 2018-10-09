<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Longest Palindromic Subsequence - 最长回文子序列

--------

#### 问题

序列$$ s $$的回文子序列是原序列的子集，元素在原序列中是连续的，回文子序列的前半段和后半段是颠倒的（倒序的前半段与后半段相同）。例如$$ s = [1,2,3,2,1] $$的回文子序列有$$ [1,2,3,2,1],[2,3,2],[3],[] $$。

求序列$$ s $$的最长回文子序列。

#### 解法

设序列$$ s $$长度为$$ n $$（数组从$$ 1 $$开始，范围$$ [1,n] $$）。设$$ f(i,j) $$表示$$ s = [i,j] $$是否为回文子序列，则有状态转移方程：

$$
f(i,j) =
\begin{cases}
true                            &   (initialize)    &   i,j \in [1,n]   &   i=j \\
false                           &   (initialize)    &   i,j \in [1,n]   &   i \neq j \\
f(i+1,j -1) \land s[i] = s[j]   &   1 \leq i \leq n-1, 2 \leq j \leq n  \\
\end{cases}
$$

$$ (1) $$ 初始化，对于单个元素$$ s[i] $$，显然单个元素可以作为一个最短的回文子序列，即$$ f(i,i) = true $$，其他则初始化为$$ f(i,j) = false, i \neq j $$；

$$ (2) $$ 对于子序列$$ s[i+1,j-1] $$，若其为回文子序列且$$ s[i]=s[j] $$则扩展后$$ s[i,j] $$也是回文子序列，若$$ s[i+1][j-1] $$不是回文子序列或$$ s[i] \neq s[j] $$则$$ s[i,j] $$也不是回文子序列；

遍历所有$$ f(i,j), 1 \leq i \leq j \leq n $$找出最大值$$ f_{max} (i_{max}, j_{max}) $$，即为最长回文子序列$$ s[i_{max}, j_{max}] $$。该算法的时间复杂度为$$ O(n^2) $$。

--------

#### LeetCode

* https://leetcode.com/problems/longest-palindromic-substring/description/

[leetcode-5.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/leetcode/leetcode-5.cpp)

--------

#### 源码

[LongestPalindromicSubsequence.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestPalindromicSubsequence.h)

[LongestPalindromicSubsequence.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestPalindromicSubsequence.cpp)

#### 测试

[LongestPalindromicSubsequenceTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/LinearDP/LongestPalindromicSubsequenceTest.cpp)
