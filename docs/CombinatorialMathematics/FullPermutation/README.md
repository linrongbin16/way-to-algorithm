<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.cpp)


--------

<div>
<h1 align="center">Full Permutation</h1>
<h1 align="center">全排列</h1>
<br>
问题： <br>
&emsp;&emsp;求拥有\(n\)个不同元素的数组\(A = [a_0,a_1,a_2,…,a_{n-1}]\)的所有全排列。 <br>
<br>
解法： <br>
&emsp;&emsp;本文介绍Steinhaus-Johnson-Trotter算法。 <br>
&emsp;&emsp;初始时假设数组\(A = []\)，其全排列只有\(1\)个，即\([]\)。 <br>
&emsp;&emsp;在初始状态的基础上增加新的元素，新的元素可以插入在原数组中的任意位置。例如对于数组\(B = [1, 2, 3]\)，新元素\(x\)可以在\(3\)个元素中选择\(4\)个任意位置插入，得到\(4\)种情况：<br>
\[
[x, 1, 2, 3] \\
[1, x, 2, 3] \\
[1, 2, x, 3] \\
[1, 2, 3, x]
\]
&emsp;&emsp;\((1)\)在初始状态\(A = []\)的基础上增加新的元素\(a_0\)，新元素的位置是唯一的，得到\(A = [a_0]\)。得到\(1\)个排列： <br>
\[
[a_0] \\
\]
&emsp;&emsp;\((2)\)在第\((1)\)轮的基础上增加新的元素\(a_1\)，新元素可以插入的位置有\(2\)个，得到的排列有\(2\)个： <br>
\[
[a_0,a_1] \\
[a_1,a_0]
\]
&emsp;&emsp;\((3)\)在第\((2)\)轮的基础上增加新的元素\(a_2\)，对于第\((2)\)轮中的每个排列，新元素可以插入的位置都有\(3\)个，得到的排列共有\(2 \times 3 = 6\)个： <br>
\[
[a_0,a_1,a_2] \\
[a_0,a_2,a_1] \\
[a_2,a_1,a_0] \\
[a_1,a_0,a_2] \\
[a_2,a_0,a_1] \\
[a_1,a_2,a_0]
\]
&emsp;&emsp;重复上述操作，即可得到长度为\(n\)的数组\(A = [a_0,a_1,a_2, \cdots ,a_{n-1}]\)的全排列。该算法的时间复杂度为\(O(n!)\)。 <br>
</div>
<br>
StackOverflow上关于全排列的问题：
* [http://stackoverflow.com/questions/9878846/listing-all-permutations-of-a-given-set-of-values](http://stackoverflow.com/questions/9878846/listing-all-permutations-of-a-given-set-of-values)
Steinhaus-Johnson-Trotter算法：
* [https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm](https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm)

--------
--------
