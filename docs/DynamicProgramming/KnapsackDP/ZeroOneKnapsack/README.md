<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>

--------
* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/ZeroOneKnapsack.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/ZeroOneKnapsack.cpp)

--------

<div>
<h1 align="center">Zero One Knapsack</h1>
<h1 align="center">01背包</h1>
<br>
问题： <br>
&emsp;&emsp;你面前摆放着\(n\)个珠宝（共\(n\)种，每种\(1\)个），已知珠宝\(s_i\)的价值是\(v_i\)，重量是\(w_i\)。给你一个背包，你可以自由挑选珠宝装到背包中，但背包可以装载的最大重量为\(t\)。求背包能够装载珠宝的最大价值\(v\)。 <br>
<br>
解法： <br>
&emsp;&emsp;设\(f(i,j)\)为背包中放入前\(i\)件物品，重量不大于\(j\)的最大价值，其中\(i \in [1,n]\)，\(j \in [0,t]\)。有如下状态转移方程： <br>
\[
f(i,j) =
\begin{cases}
0 & (初始化)i = 0 \\
f(i-1,j) & i,j \gt 0,j \lt w_i \\
max(f(i-1,j),f(i-1,j-w_i)+v_i) & i,j \gt 0,j \geq w_i
\end{cases}
\]
&emsp;&emsp;\((1)\)用数组中的下标\(0\)来存储初始的固定值，背包中没有放入任何珠宝时，\(f(0,j) = 0\)； <br>
&emsp;&emsp;\((2)\)对于第\(i\)件珠宝\(s_i\)，若背包中还能够装载的重量大于\(w_i\)，那么装入背包，则价值增大\(v_i\)，剩余重量（还能装载的重量）减小\(w_i\)，即\(f(i,j) = f(i-1,j-w_i)+v_i\)；若不装入背包，则一切维持不变，即\(f(i,j) = f(i-1,j)\)。选择这两种情形中的最大值； <br>
&emsp;&emsp;\(f(n,t)\)即为\(n\)个珠宝中重量不超过\(t\)的最大价值。该算法的时间复杂度是\(O(n \times t)\)。 <br>
</div>

--------
--------
