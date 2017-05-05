<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../)


--------

<div>
<h1 align="center">Introduction – Combinatorial Mathematics</h1>
<h1 align="center">组合数学介绍</h1>
<br>
集合划分： <br>
&emsp;&emsp;集合\(X\)的划分是\(X\)的非空子集的集合，使得每一个\(X\)的元素都只包含在这些子集的其中一个内。 <br>
&emsp;&emsp;等价的说，集合\(P\)是\(X\)的划分，如果： <br>
&emsp;&emsp;\((1)\)\(P\)的元素都是\(X\)的子集，且不是空集； <br>
&emsp;&emsp;\((2)\)\(P\)的元素的并集等于\(X\)； <br>
&emsp;&emsp;\((3)\)\(P\)的任意两个元素的交集为空集； <br>
&emsp;&emsp;集合\(P\)中的元素也称为\(X\)的一个部分。例如\(X = \{1,2,3,4,5,6\}\)的一个划分是\(P = \{ \{1 \},\{2,6\},\{3,4\},\{5\}\}\)，而\(\{1\}\),\(\{2,6\}\),\(\{3,4\}\),\(\{5\}\)都是\(X\)的一个部分。 <br>
<br>
加法原理： <br>
&emsp;&emsp;集合\(X\)的元素数量等于\(X\)的所有部分的元素数量之和，即\(\mid X \mid = \mid X_1 \mid + \mid X_2 \mid + \cdots + \mid X_n \mid \)。 <br>
<br>
乘法原理： <br>
&emsp;&emsp;若集合\(X\)中的所有元素都是由两个数字组成的序列，即序偶\((a,b)\)。其中第一个元素\(a\)来自拥有\(p\)个元素的集合\(A\)，第二个元素\(b\)来自拥有\(q\)个元素的集合\(B\)。则集合\(X\)的元素数量为\(\mid X \mid = p \times q\)。 <br>
<br>
减法原理： <br>
&emsp;&emsp;设集合\(Y\)包含集合\(X\)，集合\(X\)在\(Y\)中的补集为\(X^'\)，则\( \mid X \mid = \mid Y \mid - \mid X^' \mid \)。 <br>
<br>
除法原理： <br>
&emsp;&emsp;集合\(X\)被划分为\(p\)个部分，每个部分的元素数量都为\(q\)，则\( \mid X \mid = p \times q\)。 <br>
<br>
阶乘： <br>
\[
n \neq
\begin{cases}
1 & n = 0 \\
1 \times 2 \times 3 \times \cdots \times n & \forall n \gt 0
\end{cases}
\]
&emsp;&emsp;也可以写作：
\[
n \neq
\begin{cases}
1 & n = 0 \\
\prod_{k = 1}^n k & \forall n \gt 0
\end{cases}
\]
&emsp;&emsp;阶乘的递归定义为：
\[
n \neq
1 & n = 0 \\
(n-1)! \times n & \forall n \gt 0
\]
<br>
组合： <br>
&emsp;&emsp;在拥有\(n\)个不同元素（没有两两相同的元素）的集合\(A\)中，任意选出\(m\)个元素（\(m \leq n\)，\(m\)和\(n\)都是自然数，即正整数）组成另一个集合\(B\)，称\(B\)为\(A\)的一个子集。集合没有顺序的概念，对于集合\(A\)中的任意元素（\( \forall x \in A\)），都有\(x \in B\)，同时集合\(B\)中的任意元素（\( \forall y \in B\)），都有\(y \in A\)，则集合\(A\)和\(B\)是相同的。比如集合\(s_1 = {1,2,3}\)、\(s_2 = {3,2,1}\)是相同的两个集合。 <br>
&emsp;&emsp;从\(n\)个元素的集合中任意取出\(m\)个元素能够组成的不同集合的数量为： <br>
\[
C_m^n = 
\bigl(
\begin{smallmatrix}
n \\
m
\end{smallmatrix}
\bigr)
= \frac{(P_m^n)}{m!} = \frac{n!}{m! \cdot (n-m)!}
\]
&emsp;&emsp;在二项式定理（https://en.wikipedia.org/wiki/Binomial_coefficient）中，二项式幂\((1+x)^n\)的多项式展开中\(x^k\)（其中\(k \in [0,n]\)）的系数即为\(\bigl( \begin{smallmatrix} n \\ k \end{smallmatrix}\bigr)\)，等同于组合学中从\(n\)个元素中选出\(k\)个元素组成集合的所有组合数量。 <br>
&emsp;&emsp;例如对于\((x+1)^2 = 1x^0 + 2x^1 + x^2\)，从\(2\)个元素中选取\(1\)个的组合数量为\(2\)；选取\(2\)个的组合数量为\(1\)。 <br>
&emsp;&emsp;对于\((x+1)^3 = 1x^0 + 3x^1 + 3x^2 + x^3\)，从\(3\)个元素中选取\(1\)个的组合数量为\(3\)；选取\(2\)个的组合数量为\(3\)；选取\(3\)个的组合数量为\(1\)。 <br>
<br>
排列： <br>
&emsp;&emsp;从\(n\)个不同的元素（没有两两相同的元素）中任意取\(m\)个元素（\(m \leq n\)，\(m\)和\(n\)都是自然数，即正整数）排成一列，得到排列\(s\)。排列\(s_1 = [1,2,3]\)、\(s_2 = [3,2,1]\)、\(s_3 = [2,3]\)两两各不相同，只有当两个排列长度相同，且相同位置的元素也相同时，才称这两个排列相同。 <br>
&emsp;&emsp;从\(n\)个元素中任意取出\(m\)个元素组成的所有排列的数量为： <br>
\[
P_m^n = \frac{n!}{(n-m)!}
\]
&emsp;&emsp;也写作：\(A_m^n = \frac{n!}{(n-m)!} \)，维基百科中特别提到中国大陆教材中写做\(A_n^m\)。特别的当\(m = n\)时，\(P_m^n\)称为全排列，\(P_m^n = 1 \times 2 \times 3 \times \cdots \times n = n!\)。 <br>
</div>
<br>
数学符号表： <br>
* [https://en.wikipedia.org/wiki/List_of_mathematical_symbols](https://en.wikipedia.org/wiki/List_of_mathematical_symbols)


--------
--------
