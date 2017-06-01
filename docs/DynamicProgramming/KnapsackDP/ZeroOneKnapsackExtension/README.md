--------
* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/ZeroOneKnapsackExtension.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/ZeroOneKnapsackExtension.cpp)

--------

<div>
<h1 align="center">Zero One Knapsack Extension</h1>
<h1 align="center">01背包扩展</h1>
<br>
问题： <br>
&emsp;&emsp;在&lt;Zero One Knapsack&gt;的基础上，不仅求出最大价值，还求出具体选择了哪些珠宝，即求出具体的选择方案。 <br>
<br>
解法： <br>
&emsp;&emsp;仍然按照&lt;Zero One Knapsack&gt;中的方法，设\(f(i,j)\)为背包中放入前\(i\)件物品，重量不大于\(j\)的最大价值，其中\(i \in [1,n]\)，\(j \in [0,t]\)。有如下状态转移方程： <br>
\[
f(i,j) =
\begin{cases}
0 & (初始化)i = 0 \\
f(i-1,j) & i,j \gt 0 \\
max(f(i-1,j),f(i-1,j-w_i)+v_i) & i,j \gt 0,j \geq w_i
\end{cases}
\]
&emsp;&emsp;额外的，设\(g(i,j,k)\)表示重量不大于\(j\)，最大价值为\(k\)，第\(i\)件珠宝是否被装入背包，其中\(i \in [1,n]\)，\(j \in [0,t]\)，\(k \in [0,sum\{v_i\}]\)。若\(g(i,j,k) = true\)则该珠宝被选中；若\(g(i,j,k) = false\)则该珠宝未被选中。在遍历所有珠宝的过程中，可以求出所有的\(f(i,j)\)和\(g(i,j,k)\)。 <br>
&emsp;&emsp;已知当前背包的总价值为\(v\)，总重量为\(t\)。逆向的从最后一个珠宝\(n\)开始，对于第\(i\)件珠宝，若\(g(i,t,v) = true\)则说明珠宝\(i\)被装入了背包，那么\(v = v-v_i\)，\(t = t-w_i\)，然后继续考虑下一件珠宝\(i-1\)。 <br>
&emsp;&emsp;该算法的时间复杂度是\(O(n \times t)\)。 <br>
</div>

--------
--------
