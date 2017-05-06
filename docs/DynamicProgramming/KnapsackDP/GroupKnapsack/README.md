<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/GroupKnapsack.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/GroupKnapsack.cpp)


--------

<div>
<h1 align="center">Group Knapsack</h1>
<h1 align="center">分组背包</h1>
<br>
问题： <br>
&emsp;&emsp;你面前摆放着\(n\)个珠宝（共\(n\)种，每种\(1\)个），这些珠宝被分成\(m\)个组（显然\(n \geq m\)）。已知珠宝\(s_i\)的价值是\(v_i\)，重量是\(w_i\)。给你一个背包，你可以挑选珠宝装到背包中，但背包可以装载的最大重量为\(t\)，并且同一个组的珠宝至多只能选择\(1\)个。求背包能够装载珠宝的最大价值\(v\)。 <br>
&emsp;&emsp;该问题与01背包的区别就是，对珠宝进行了分组，并且一个组内的珠宝互斥。 <br>
<br>
解法： <br>
&emsp;&emsp;设\(f(i,j)\)为背包中放入前\(i\)组物品，重量不大于\(j\)的最大价值，其中\(i \in [1,m]\)，\(j \in [0,t]\)。第\(i\)组中有\(group_{i}\)个珠宝，其中某珠宝\(k\)的价值是\(v_k\)，重量是\(w_k\)。则有如下状态转移方程： <br>
\[
f(i,j) = 
\begin{cases}
0 & (初始化)i = 0 \\
f(i-1,j) & i,j \gt 0 \\
max(f(i-1,j),f(i-1,j - w_k ) + v_k) & i,j \gt 0且k \in [1,group_i],j \geq w_k
\end{cases}
\]
&emsp;&emsp;\((1)\)用数组中的下标\(0\)来存储初始的固定值，背包中没有放入任何珠宝时，\(f(0,j) = 0\)； <br>
&emsp;&emsp;\((2)\)对于第\(i\)组珠宝，背包的剩余重量（还能装载的重量）为\(w\)，在第\(i\)组珠宝中选择某个珠宝\(k\)，若\(w \geq w_k\)，那么可以装进珠宝\(k\)，背包的价值增大\(v_k\)，剩余重量减小\(w_k\)，即\(f(i,j) = f(i-1,j - w_k) + v_k\)；若不装入背包，则一切维持不变，即\(f(i,j) = f(i-1,j)\)。选择这两种情形中的最大值； <br>
&emsp;&emsp;\(f(m,t)\)即为\(m\)组珠宝中重量不超过\(t\)的最大价值。该算法的时间复杂度是\(O(n \times t)\)。 <br>
</div>


--------
--------
