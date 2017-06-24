* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Kosaraju.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Kosaraju.cpp)

--------

### Kosaraju
### Kosaraju算法
<div>
问题：
<p id="i">用Kosaraju算法求有向图\(G\)的强连通分支。 </p>
解法：
<p id="i">Kosaraju算法分为3个步骤：</p>
<p id="i">\((1)\)依次对图\(G\)中每个节点求出其DFS到终点的距离；
<p id="i">\((2)\)求出图\(G\)的逆图\(G'\)；
<p id="i">对逆图\(G'\)中每个节点求出其DFS到终点的距离进行拓扑排序。按照拓扑排序中节点顺序，依次对每个节点进行深度优先搜索。每一次深度优先搜索的过程中，遍历到的所有节点属于同一个强连通分支。 </p>
<p id="i">对于有向图\(G\)来说，其逆图\(G'\)为：</p>
<p id="c"><img src="../res/Kosaraju1.svg" /></p>
<p id="c"><img src="../res/Kosaraju2.svg" /></p>
<p id="i">用矩阵可以表示为：</p>
\[
G =
\begin{bmatrix}
0 & 1 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 & 0 & 0 \\
0 & 0 & 0 & 1 & 1 & 0 \\
1 & 0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 0 & 0 & 0
\end{bmatrix}
G' =
\begin{bmatrix}
0 & 0 & 0 & 1 & 0 & 0 \\
1 & 0 & 0 & 0 & 0 & 0 \\
1 & 0 & 0 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 & 0 & 0 \\
0 & 0 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 & 1 & 0
\end{bmatrix}
\]
<p id="i">然后对逆图\(G'\)进行拓扑排序（参考<Topological Sort>），得到：</p>
\[ [5, 4, 0, 1, 2, 3] \]
<p id="i">按照逆图\(G'\)的拓扑顺序依次对原图\(G\)的每个节点进行深度优先搜索，每一次DFS遍历到的节点极为一个极大强连通分支。</p>

</div>
