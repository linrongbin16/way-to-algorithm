<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Topological Sort - 拓扑排序

--------

#### 问题

对有向图$$ DG $$进行拓扑排序。

#### 解法

拓扑排序是深度优先搜索的典型应用。

对有向图$$ DG $$的所有顶点做深度优先搜索。从任意顶点$$ v_i $$出发进行DFS（包括$$ v_i $$顶点自己），直到无法搜索到更多的节点停止，经过的顶点数量即为顶点$$ v_i $$的DFS距离$$ d_i $$。将所有顶点的DFS距离从大到小排序，即为有向图的拓扑排序。DFS距离最小为$$ 1 $$。

对下图中的有向图$$ DG $$进行拓扑排序：

![TopologicalSort1.png](../res/TopologicalSort1.png)

$$ (1) $$ 顶点$$ 0 $$的DFS距离为$$ d_0 = 8 $$，遍历到顶点的顺序为$$ [0, 1, 2, 4, 6, 7, 3, 5] $$，如下图；

![TopologicalSort2.png](../res/TopologicalSort2.png)

$$ (2) $$ 顶点$$ 1 $$的DFS距离为$$ d_1 = 6 $$，遍历到顶点的顺序为$$ [1, 2, 4, 6, 7, 3] $$，如下图；

![TopologicalSort3.png](../res/TopologicalSort3.png)

$$ (3) $$ 顶点$$ 2 $$的DFS距离为$$ d_2 = 4 $$，遍历到顶点的顺序为$$ [2, 4, 6, 7] $$，如下图；

![TopologicalSort4.png](../res/TopologicalSort4.png)

$$ (4) $$ 顶点$$ 3 $$的DFS距离为$$ d_3 = 5 $$，遍历到顶点的顺序为$$ [3, 2, 4, 6, 7] $$；

$$ (5) $$ 顶点$$ 4 $$的DFS距离为$$ d_4 = 3 $$，遍历到顶点的顺序为$$ [4, 6, 7] $$；

$$ (6) $$ 顶点$$ 5 $$的DFS距离为$$ d_5 = 7 $$，遍历到顶点的顺序为$$ [5, 1, 2, 4, 6, 7, 3] $$；

$$ (7) $$ 顶点$$ 6 $$的DFS距离为$$ d_6 = 1 $$，遍历到顶点的顺序为$$ [6] $$；

$$ (8) $$ 顶点$$ 7 $$的DFS距离为$$ d_7 = 1 $$，遍历到顶点的顺序为$$ [7] $$；

按照DFS距离排序得到有向图$$ DG $$的拓扑排序为$$ [0, 5, 1, 3, 2, 4, 6, 7] $$。

每个顶点进行DFS搜索的时间复杂度为$$ O(|V|) $$，因此拓扑先序遍历的时间复杂度是$$ O(|V|^{2}) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 22.Elementary Graph Algorithms - 22.4.Topological sort](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[TopologicalSort.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/TopologicalSort.h)

[TopologicalSort.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/TopologicalSort.cpp)

#### 测试

[TopologicalSortTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/TopologicalSortTest.cpp)
