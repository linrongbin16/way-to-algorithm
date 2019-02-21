<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Kosaraju - Kosaraju算法

--------

#### 问题

用Kosaraju算法求有向图$$ DG $$的所有强连通分支。

#### 解法

首先用DFS搜索所有顶点，然后按照DFS逆序对每个顶点进行DFS。根据强连通分支的定义可知。逆序时任意顶点$$ v_i $$按照DFS搜索可以到达的顶点都和它属于同一强连通分支。Kosaraju算法使用并查集将顶点分配给不同的强连通分支。

Kosaraju算法分为$$ 3 $$步：

$$ (1) $$ 初始化空队列$$ queue $$，该队列记录有向图中所有顶点的DFS顺序；

$$ (2) $$ 类似DFS和二叉树的后续遍历，遍历图$$ DG $$所有顶点$$ v_i $$，对每个顶点$$ v_i $$进行搜索操作：$$ 2.1) $$ 若顶点$$ v_i $$已被染红则跳过，否则将$$ v_i $$染红并加入队列$$ queue $$；$$ 2.2) $$ 选取$$ v_i $$的邻节点中未被染红的邻节点$$ v_j $$，递归进行相同的搜索操作，直到无法搜索到更多未被染红的顶点；

$$ (3) $$ 类似DFS和并查集算法，首先令队列$$ queue $$中的任意顶点$$ v_i $$属于根节点为$$ v_i $$（即自己）的强连通分支，即设父指针$$ father(i) = i $$。逆序遍历队列$$ queue $$所有顶点，对每个顶点$$ v_i $$进行聚合：$$ 3.1) $$ 若顶点$$ v_i $$存在$$ father(i) \neq i $$则跳过，表示该顶点已经被分配到某个强连通分支；$$ 3.2) $$ 选取$$ v_i $$的邻节点中满足$$ father(j) = j $$的邻节点$$ v_j $$，将$$ v_j $$分配给以$$ v_i $$为根节点的强连通分支，即$$ father(j) = i $$；

第$$ (3) $$步结束后，每个顶点都被分配给某个强连通分支。查询某两个顶点$$ v_i, v_j $$是否属于同一个强连通分支，判断$$ father(i) = father(j) $$是否成立即可，同一强连通分支中的所有顶点的父节点相同，最终所有顶点都被分配到某个强连通分支。

下图演示有向图的搜索操作和分配操作：

![Kosaraju1.png](../res/Kosaraju1.png)

上图进行DFS搜索后，得到的队列为$$ [0, 4, 3, 1, 2, 7, 6, 5, 8] $$，逆序为$$ [8, 5, 6, 7, 2, 1, 3, 4, 0] $$。第$$ (2) $$步的DFS搜索过程如下图：

![Kosaraju2.png](../res/Kosaraju2.png)

按照逆序DFS遍历所有顶点，得到两个强连通分支$$ [8] $$和$$ [0, 1, 2, 3, 4, 5, 6, 7] $$：

![Kosaraju3.png](../res/Kosaraju3.png)

该算法时间复杂度为$$ O(\| V \|) $$。

--------

#### Strongly-Connectivity Algorithm

* https://pdfs.semanticscholar.org/1912/4d1b464fdbb4e9dffb1c915468ae201b5df0.pdf

#### Introduction To Algorithms

* [VI.Graph Algorithms - 22.Elementary Graph Algorithms - 22.5.Strongly connected components](https://www.google.com/search?q=Introduction+to+Algorithms+3rd+Edition+pdf)

--------

#### 源码

[Kosaraju.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StronglyConnectedComponents/Kosaraju.h)

[Kosaraju.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StronglyConnectedComponents/Kosaraju.cpp)

#### 测试

[KosarajuTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StronglyConnectedComponents/KosarajuTest.cpp)
