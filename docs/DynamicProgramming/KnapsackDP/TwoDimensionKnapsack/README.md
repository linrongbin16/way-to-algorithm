<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DataStructure/TwoDimensionKnapsack.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DataStructure/TwoDimensionKnapsack.cpp)


--------

<div>
<h1 align="center">Two Dimension Knapsack</h1>
<h1 align="center">二维背包</h1>
<br>
问题： <br>
&emsp;&emsp;你面前摆放着\(n\)个珠宝（共\(n\)种，每种\(1\)个），已知珠宝\(s_i\)的价值是\(v_i\)，重量\(1\)是\(w1_i\)，重量\(2\)是\(w2_i\)。给你一个背包，你可以自由挑选珠宝装到背包中，但背包可以装载的最大重量\(1\)为\(t1\)，最大重量\(2\)为\(t2\)。求背包能够装载珠宝的最大价值\(v\)。 <br>
&emsp;&emsp;该问题与01背包的区别就是，重量属性变成了\(2\)维属性，背包中所有珠宝的总重量\(1\)不能超过\(t1\)，总重量\(2\)不能超过\(t2\)。 <br>
<br>
解法： <br>
&emsp;&emsp;设\(f(i,j,k)\)为背包中放入前\(i\)件物品，重量\(1\)不大于\(j\)，重量\(2\)不大于\(k\)的最大价值，其中\(i \in [1,n]\)，\(j \in [0,t1]\)，\(k \in [0,t2]\)。有如下状态转移方程： <br>
\[
f(i,j,k) =
\begin{cases}
0 & (初始化)i = 0 \\
f(i-1,j,k) & i,j,k \gt 0 \\
max{f(i-1,j,k),f(i-1,j-w1_i,k-w2_i)+v_i} & i,j,k \gt 0,j \geq w1_i且k \geq w2_i
\end{cases}
\]
&emsp;&emsp;用数组中的下标\(0\)来存储初始的固定值，背包中没有放入任何珠宝时，\(f(0,j) = 0\)； <br>
&emsp;&emsp;对于第\(i\)件珠宝\(s_i\)，背包的剩余重量\(1\)（还能装载的重量）为\(w1\)，剩余重量\(2\)为\(w2\)，若\(w1 \geq k \times w1_i\)，\(w2 \geq k \times w2_i\)，那么可以装进\(1\)个珠宝\(s_i\)，背包的价值增大\(v_i\)，剩余重量\(1\)减小\(w1_i\)，剩余重量\(2\)减小\(w2_i\)。即\(f(i,j,k) = f(i-1,j-w1_i,k-w2_i)+v_i\)；若不装入背包，则一切维持不变，即\(f(i,j,k) = f(i-1,j,k)\)。选择这两种情形中的最大值； <br>
&emsp;&emsp;\(f(n,t1,t2)\)即为\(n\)个珠宝中重量\(1\)不超\(t1\)，重量\(2\)不超过\(t2\)的最大价值。该算法的时间复杂度是\(O(n \times t1 \times t2)\)。 <br>
</div>


--------
--------
