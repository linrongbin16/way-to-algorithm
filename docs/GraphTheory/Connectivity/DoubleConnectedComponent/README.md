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
<p id="i">\((1)\)求出图\(G\)的逆图\(G'\)；</p>
<p id="i">\((2)\)求出逆图\(G'\)的拓扑排序\(T\)；</p>
<p id="i">\((3)\)按照逆图\(G'\)拓扑排序\(T\)的顺序，对原图\(G\)中每个节点进行DFS，得到的森林即为所求的强连通分支。注意每个节点只能属于一个强连通分支，因此当一个节点被DFS遍历到后，需要将其染红；</p>
<p id="i">求出有向图\(G\)的逆图\(G'\)：</p>
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
<p id="i">对逆图\(G'\)进行拓扑排序，得到顺序\(T = [5, 4, 0, 1, 2, 3]\)。</p>
<p id="i">按照顺序\(T\)对原图\(G\)进行DFS搜索，得到下面的森林，即为有向图\(G\)的\(3\)个强连通分支。这\(3\)个强连通分支中，任意节点\(V_i\)都存在一条路径可以到达其他任意节点\(V_j\)。</p>
\[
\begin{bmatrix}
tree_1 = [ 5 ] \\
tree_2 = [ 4 ] \\
tree_3 = [ 0, 1, 3, 2 ]
\end{bmatrix}
\]

</div>
