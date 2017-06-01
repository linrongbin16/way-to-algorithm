--------
* [Upper Folder - 上一级目录](../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.cpp)

--------

<div>
<h1 align="center">Combination</h1>
<h1 align="center">组合</h1>
<br>
问题： <br>
&emsp;&emsp;求拥有\(n\)个元素的集合\(A = \{a_0,a_1,a_2, \cdots ,a_{n-1} \}\)中任意取\(m\)个元素（\(m \leq n\)，\(m\)和\(n\)都是自然数）的所有组合。 <br>
<br>
解法： <br>
&emsp;&emsp;本文末尾列了很多关于组合算法的文献。本文介绍一种简单易记的算法。 <br>
&emsp;&emsp;设置数组\(s = [s_0,s_1,s_2, \cdots ,s_{n-1}]\)表示对集合\(A\)的选择，第\(i\)个数字\(s_i = 1\)表示选择数字\(a_i\)，\(s_i = 0\)表示不选择数字\(a_i\)。假设初始状态下从集合\(A = \{a_0,a_1,a_2, \cdots ,a_{n-1} \}\)中取出\(0\)个元素组成组合，即\(s = [0_0,0_1,0_2, \cdots ,0_{n-1}]\)，得到\(1\)个组合\(\{\}\)。<br>
&emsp;&emsp;\((1)\)从集合\(A = \{a_0,a_1,a_2, \cdots ,a_{n-1} \}\)中取出\(1\)个元素作为组合。则数组\(s\)中只有一个元素为\(1\)，其他全是\(0\)，唯一的\(1\)在数组\(s\)中可以选择任意位置，得到\(C_1^n = n\)个组合： <br>
\[
\begin{array}{lcr}
[1_0,0_1,0_2, \cdots ,0_{n-1}] && (1-1) \\
[0_0,1_1,0_2, \cdots ,0_{n-1}] && (1-2) \\
[0_0,0_1,1_2, \cdots ,0_{n-1}] && (1-3) \\
& \cdots & \\
[0_0,0_1,0_2, \cdots ,1_{n-1}] && (1-n)
\end{array}
\]
&emsp;&emsp;\((2)\)从集合A中取出2个元素作为组合，可以看作是在第1轮操作数组s后得到的n个组合的基础上增加一个1。 <br>
&emsp;&emsp;对于第\(1\)轮中的数组\((1-1)\quad [1_0,0_1,0_2, \cdots ,0_{n-1}]\)增加一个\(1\)后得到数组\([1_0,1_1,0_2, \cdots ,0_{n-1}]\)。原本的\(1_0\)保持不变，新增的\(1_1\)可以选择后面等于\(0\)的\(n-1\)个位置，生成\(n-1\)个组合： <br>
\[
\begin{array}{lcr}
[1_0,1_1,0_2,0_3, \cdots ,0_{n-1}] && (2-1-1) \\
[1_0,0_1,1_2,0_3, \cdots ,0_{n-1}] && (2-1-2) \\
[1_0,0_1,0_2,1_3, \cdots ,0_{n-1}] && (2-1-3) \\
& \cdots & \\
[1_0,0_1,0_2,0_3, \cdots ,1_{n-1}] && (2-1-(n-1))
\end{array}
\]
&emsp;&emsp;需要注意的是，新增的\(1\)必须在原数组中所有的\(1\)的后面。对于数组\((1-2) \quad [0_0,1_1,0_2, \cdots ,0_{n-1}]\)，新增的\(1\)只能选择后面等于\(0\)的\(n-1\)个位置，生成\(n-2\)个组合： <br>
\[
\begin{array}{lcr}
[0_0,1_1,1_2,0_3, \cdots ,0_{n-1}] && (2-2-1) \\
[0_0,1_1,0_2,1_3, \cdots ,0_{n-1}] && (2-2-2) \\
& \cdots & \\
[0_0,1_1,0_2,0_3, \cdots ,1_{n-1}] && (2-2-(n-2))
\end{array}
\]
&emsp;&emsp;如果不注意，让新增的\(1\)在原数组的任意的\(1\)的前面，则会产生重复的组合，仍然以数组\((1-2) \quad [0_0,1_1,0_2, \cdots ,0_{n-1}]\)为例，如果新增的\(1\)可以选择任意等于\(0\)的位置，会生成\(n-1\)个组合： <br>
\[
\begin{array}{lcr}
[1_0,1_1,0_2,0_3, \cdots ,0_{n-1}] && (2-2-0) \\
[0_0,1_1,1_2,0_3, \cdots ,0_{n-1}] && (2-2-1) \\
[0_0,1_1,0_2,1_3, \cdots ,0_{n-1}] && (2-2-2) \\
& \cdots & \\
[0_0,1_1,0_2,0_3, \cdots ,1_{n-1}] && (2-2-(n-2))
\end{array}
\]
&emsp;&emsp;但其中\((2-2-0) \quad [1_0,1_1,0_2,0_3, \cdots ,0_{n-1}]\)与第\(1\)个数组产生的组合重复了。对第\(1\)轮中所有的数组重复该操作，即可得到选取\(2\)个元素的所有组合，共有\(C_2^n = \frac{n \times (n-1)}{2} \)个。 <br>
&emsp;&emsp;\((3)\)从集合\(A\)中取出\(3\)个元素作为组合，可以看作是在第\((2)\)轮操作的\((n-1)!\)个组合基础上增加一个\(1\)，对于之前的每个组合，保持之前两个\(1\)不变，新的\(1\)可以选择原数组中最后一个\(1\)之后的任意等于\(0\)的位置。注意新增的\(1\)不能比原数组中的任意的\(1\)更靠前，必须在所有的\(1\)之后的位置进行选择。 <br>
&emsp;&emsp;重复上述的操作，直到选取\(m\)个元素，即可得到所有的组合，算法结束。然后根据\(s\)的全排列生成集合\(A\)的所有组合即可。该算法时间复杂度为\(C_m^n = \frac{n!}{m! \cdot (n-m)!} \)。 <br>
</div>
<br>
StackOverflow上关于组合产生算法的问题：

* [http://stackoverflow.com/questions/127704/algorithm-to-return-all-combinations-of-k-elements-from-n](http://stackoverflow.com/questions/127704/algorithm-to-return-all-combinations-of-k-elements-from-n)

二项式系数：

* [https://en.wikipedia.org/wiki/Binomial_coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient)

Chase’s Twiddle - Algorithm 382: Combinations of M out of N Objects:

* [http://dl.acm.org/citation.cfm?id=362502](http://dl.acm.org/citation.cfm?id=362502)
* [http://www.netlib.no/netlib/toms/382](http://www.netlib.no/netlib/toms/382)

Buckles - Algorithm 515: Generation of a Vector from the Lexicographical Index:

* [http://dl.acm.org/citation.cfm?id=355739](http://dl.acm.org/citation.cfm?id=355739)
* [https://www.researchgate.net/profile/Bill_Buckles/publication/220492658_Algorithm_515_Generation_of_a_Vector_from_the_Lexicographical_Index_G6/links/5716d7ad08ae497c1a5706ec.pdf](https://www.researchgate.net/profile/Bill_Buckles/publication/220492658_Algorithm_515_Generation_of_a_Vector_from_the_Lexicographical_Index_G6/links/5716d7ad08ae497c1a5706ec.pdf)

Remark on algorithm 515: Generation of a vector from the lexicographical index combinations:

* [http://dl.acm.org/citation.cfm?id=1236470](http://dl.acm.org/citation.cfm?id=1236470)

--------
--------
