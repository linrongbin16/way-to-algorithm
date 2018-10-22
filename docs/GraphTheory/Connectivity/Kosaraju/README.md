<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Kosaraju - Kosaraju算法

--------

#### 问题

用Kosaraju算法求有向图$$ DG $$的强连通分支。

#### 解法

Kosaraju算法分为$$ 3 $$个步骤：

$$ (1) $$ 求出图$$ DG $$的逆图$$ DG' $$；

$$ (2) $$ 求出逆图$$ DG' $$的拓扑排序$$ T $$；

$$ (3) $$ 按照逆图$$ DG' $$拓扑排序$$ T $$的顺序，对原有向图$$ DG $$中每个节点进行DFS，被访问后将该节点染红，被染红的顶点不能重复访问。得到的森林即为所求的强连通分支；

求出有向图$$ DG $$的逆图$$ DG' $$：

![Kosaraju1.svg](../res/Kosaraju1.svg)

![Kosaraju2.svg](../res/Kosaraju2.svg)

用矩阵可以表示为：

$$
DG =
\begin{bmatrix}
0 & 1 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 & 0 & 0 \\
0 & 0 & 0 & 1 & 1 & 0 \\
1 & 0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 0 & 0 & 0
\end{bmatrix}

DG' =
\begin{bmatrix}
0 & 0 & 0 & 1 & 0 & 0 \\
1 & 0 & 0 & 0 & 0 & 0 \\
1 & 0 & 0 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 & 0 & 0 \\
0 & 0 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 & 1 & 0
\end{bmatrix}
$$

对逆图$$ DG' $$进行拓扑排序得到$$ T = [5, 4, 0, 1, 2, 3] $$。

按照顺序$$ T $$对原有向图$$ DG $$进行DFS搜索，得到下面的森林，即有向图$$ DG $$的$$ 3 $$个强连通分支。这$$ 3 $$个强连通分支中，任意节点$$ v_i $$都存在一条路径可以到达其他任意节点$$ v_j $$。

$$
\begin{bmatrix}
tree_1 = [ 5 ] \\
tree_2 = [ 4 ] \\
tree_3 = [ 0, 1, 3, 2 ]
\end{bmatrix}
$$

在顶点数量为$$ n $$的有向图上，Kosaraju算法的时间复杂度为$$ O(n) $$。
