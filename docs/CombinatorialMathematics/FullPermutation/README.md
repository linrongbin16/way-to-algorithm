<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>

# Full Permutation - 全排列

--------

#### 问题

<p id="i">求拥有\(n\)个不同元素的数组\(A = [a_0,a_1,a_2,…,a_{n-1}]\)的所有全排列。 </p>
解法：
<p id="i">本文介绍Steinhaus-Johnson-Trotter算法。 </p>
<p id="i">初始时假设数组\(A = []\)，其全排列只有\(1\)个，即\([]\)本身。 </p>
<p id="i">在初始状态的基础上增加新的元素，新的元素可以插入在原数组中的任意位置。例如对于数组\(B = [1, 2, 3]\)，新元素\(x\)可以在\(3\)个元素中选择\(4\)个任意位置插入，得到\(4\)种情况：</p>
\[
[x, 1, 2, 3] \\
[1, x, 2, 3] \\
[1, 2, x, 3] \\
[1, 2, 3, x]
\]
<p id="i">\((1)\)在初始状态\(A = []\)的基础上增加新的元素\(a_0\)，新元素的位置是唯一的，得到\(A = [a_0]\)。得到\(1\)个排列： </p>
\[
[a_0] \\
\]
<p id="i">\((2)\)在第\((1)\)轮的基础上增加新的元素\(a_1\)，新元素可以插入的位置有\(2\)个，得到的排列有\(2\)个： </p>
\[
[a_0,a_1] \\
[a_1,a_0]
\]
<p id="i">\((3)\)在第\((2)\)轮的基础上增加新的元素\(a_2\)，对于第\((2)\)轮中的每个排列，新元素可以插入的位置都有\(3\)个，得到的排列共有\(2 \times 3 = 6\)个： </p>
\[
[a_0,a_1,a_2] \\
[a_0,a_2,a_1] \\
[a_2,a_1,a_0] \\
[a_1,a_0,a_2] \\
[a_2,a_0,a_1] \\
[a_1,a_2,a_0]
\]
<p id="i">重复上述操作，即可得到长度为\(n\)的数组\(A = [a_0,a_1,a_2, \dots ,a_{n-1}]\)的全排列。该算法的时间复杂度为\(O(n!)\)。 </p>
</div>

--------

#### StackOverflow上关于全排列的问题

* [http://stackoverflow.com/questions/9878846/listing-all-permutations-of-a-given-set-of-values](http://stackoverflow.com/questions/9878846/listing-all-permutations-of-a-given-set-of-values)

#### Steinhaus-Johnson-Trotter算法

* [https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm](https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm)

#### LeetCode

* [leetcode-46](https://leetcode.com/problems/permutations/#/description)
* [leetcode-46 source.hpp](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/attachment/leetcode46.hpp)

--------

* [Upper Folder - 上一级目录](../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.cpp)
