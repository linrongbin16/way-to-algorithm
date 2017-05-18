<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/EulerCycle.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/EulerCycle.cpp)


--------

<div>
<h1 align="center">Euler Cycle</h1>
<h1 align="center">欧拉回路</h1>
<br>
问题： <br>
&emsp;&emsp;求无向图\(UG\)和有向图\(DG\)的欧拉回路。 <br>
<br>
解法： <br>
无向图\(UG\)的欧拉回路解法： <br>
&emsp;&emsp;本文介绍求无向图欧拉回路的Fleury算法。我们假定本问题给定的无向图\(UG\)中必然存在欧拉回路（因为欧拉回路存在的判定非常简单）。设矩阵\(g\)表示无向图\(UG\)，其中\(g[i,j] = 1\)表示顶点\(v_i\)到\(v_j\)之间存在单向边\(e_{i,j}\)，\(g[i,j] = 0\)表示顶点\(v_i\)到\(v_j\)之间不存在单向边\(e_{i,j}\)。 <br>
<p align="center"><img src="../res/EulerCycle1.png" /></p>
&emsp;&emsp;上面的无向图可以表示为 <br>
\[
g =
\begin{bmatrix}
\end{bmatrix}
\]
&emsp;&emsp;选取顶点\(v_0\)作为起始顶点，对整个图进行一种类似DFS搜索的操作。对于当前顶点\(v_i\)，任意选取它的邻节点\(v_j\)作为下一个遍历的节点。但需要保证：必须存在一条与边\(e_{i,j}\)相反的边\(e_{j,i}\)，来保证可以从\(v_i\)到达\(v_j\)，又可以从\(v_j\)到达\(v_i\)。 <br>
&emsp;&emsp;设矩阵\(g\)表示无向图\(UG\)，其中\(g[i,j] = 1\)表示顶点\(v_i\)到\(v_j\)之间存在单向边\(e_{i,j}\)，\(g[i,j] = 0\)表示顶点\(v_i\)到\(v_j\)之间不存在单向边\(e_{i,j}\)。在进行上面的遍历操作过程中，从节点\(v_i\)移动到邻节点\(v_j\)时，将边\(e_{i,j}\)删去（令\(g[i,j] = 0\)）。重复这样的遍历操作，直到再次回到起始节点\(v_0\)，算法结束。整个过程中删除的边的顺序即为一条欧拉回路，可以用一个链表依次记录所有被删除的边。 <br>
&emsp;&emsp;在上面删除边的操作中，假设节点\(v_i\)和\(v_j\)之间存在一条双向边\(e\)，则有\(g[i,j] = 1\)和\(g[j,i] = 1\)，当从\(v_i\)移动到\(v_j\)时，令\(g[i,j] = 0\)（即删除边\(e_{i,j}\)）。之后还会出现从\(v_j\)移动到\(v_i\)的情况，这时边\(e_{j,i}\)不存在与它相反的边\(e_{i,j}\)（之前被删除了）。若这时节点\(v_j\)相邻的节点中没有满足上述的相反的边，则可以打破该原则，选择没有相反的边的\(e_{j,i}\)，从\(v_j\)移动到\(v_i\)。这个原则是为了保证总是优先遍历那些有两个相反方向的边的节点，当这些双向的边的一半被删除，图中不存在双向的边时，这个原则就可以打破，不再考虑了。 <br>
&emsp;&emsp;Fleury算法的时间复杂度是\(O(|E|)\)（\(|E|\)为无向图\(UG\)的边的数量）。 <br>
有向图\(DG\)的欧拉回路解法： <br>
&emsp;&emsp;有向图也可以用Fleury算法来进行求解，唯一的不同就是不能随意选择任意节点作为起始点，因为有向图中的欧拉回路与无向图不一样。有向图的欧拉回路起点满足\(degree_{out} = degree_{in} + 1\)，终点满足\(degree_{in} = degree_{out} + 1\)。因此需要遍历有向图\(DG\)找出欧拉回路的起点，再应用Fleury算法。 <br>
</div>


--------
--------
