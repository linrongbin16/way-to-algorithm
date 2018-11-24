<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Duplicable Combination - 元素可重复的组合

--------

#### 问题

从包含$$ n $$个元素的集合$$ s = [x_0, x_1, x_2, \dots ,x_{n-1} ] $$中任意取$$ m $$个元素（$$ m \leq n $$）组成组合，求所有组合。

#### 解法

<div>
问题：
<p id="i">在有\(n\)个互不相同元素的集合\(A = \{a_0,a_1,a_2, \dots ,a_{n-1} \}\)中，任意取\(m\)个元素（\(m \leq n\)，\(m\)和\(n\)都是自然数，并且同一个元素可以重复使用）的所有组合。例如对于集合\(A = \{1, 2, 3\}\)，从中取出\(3\)个元素可重复的所有组合为：</p>
\[
[1, 1, 1] \\
[1, 1, 2] \\
[1, 2, 1] \\
[2, 1, 1] \\
[1, 2, 2] \\
[2, 1, 2] \\
[2, 2, 1] \\
[2, 2, 2] \\
[2, 2, 3] \\
[2, 3, 2] \\
[3, 2, 2] \\
[2, 3, 3] \\
[3, 2, 3] \\
[3, 3, 2] \\
[3, 3, 3] \\
[1, 1, 3] \\
[1, 3, 1] \\
[3, 1, 1] \\
[1, 3, 3] \\
[3, 1, 3] \\
[3, 3, 1] \\
[1, 2, 3] \\
[1, 3, 2] \\
[3, 2, 1] \\
[3, 1, 2] \\
[2, 1, 3] \\
[2, 3, 1]
\]
解法：
<p id="i"><a href="https://zhaochenyou.github.io/Way-to-Algorithm/Search/Recursion">Recursion</a>可以解决这个问题。所求的组合是长度为\(m\)的数组\(S\)，其中每个元素\(i\)可以选择的值为集合\(A\)中的任意一个元素。因此我们只需要递归的对每个元素i选择一个值，然后递归下去对元素i+1设置一个值，直到将数组中所有元素都选择了一个值，即可得到一个组合。 </p>
<p id="i">所求组合的长度为\(m\)，集合\(A\)的成员有\(n\)个，该算法的时间复杂度\(O(m^n)\)。 </p>
</div>

Online Judge:
* [leetcode-40](https://leetcode.com/problems/combination-sum/)
* [leetcode-40 source.hpp](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/attachment/leetcode-40.hpp)
