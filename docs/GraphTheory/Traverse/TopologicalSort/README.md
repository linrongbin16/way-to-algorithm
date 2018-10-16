<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Topological Sort - 拓扑排序

--------

#### 问题

对有向图$$ DG $$进行拓扑排序。

#### 解法

拓扑排序是深度优先搜索的一种典型应用。根据拓扑排序的特性，认为有向图$$ DG $$上的所有节点通过DFS都可以最终到达一个终点（无法再搜索到其他节点），即为该图的拓扑排序的末尾节点。

对有向图$$ DG $$的每个节点$$ i $$都进行一次深度优先搜索，尝试从节点$$ i $$出发搜索到尽量多的节点（直到无法搜索到更多的节点）。从$$ i $$出发DFS所经过的节点数量是节点$$ i $$到终点的距离$$ d_i $$。将所有节点到终点的距离$$ d_i $$从大到小排序，即为有向图的拓扑排序。终点到自己的距离是$$ 1 $$。

下面演示有向图$$ DG $$的拓扑排序：

![TopologicalSort1.svg](../res/TopologicalSort1.svg)

从节点$$ 4 $$开始可以遍历到$$ 6 $$个节点，从节点$$ 3 $$开始可以遍历到$$ 5 $$个节点：

![TopologicalSort2.svg](../res/TopologicalSort2.svg)

对图中的所有节点依次进行DFS，节点$$ [0, \dots, 7] $$到终点的距离依次为$$ [8, 6, 3, 4, 2, 7, 1, 1] $$。按照距离排序得到有向图$$ DG $$的拓扑排序为$$ [0, 5, 1, 3, 2, 4, 6, 7] $$。

每个节点的DFS时间复杂度为$$ O(n) $$，共$$ n $$个节点，因此拓扑先序遍历的时间复杂度是$$ O(n^2) $$。

--------

#### 源码

[import, lang:"c_cpp"](../../../../src/GraphTheory/Traverse/TopologicalSort.hpp)

#### 测试

[import, lang:"c_cpp"](../../../../src/GraphTheory/Traverse/TopologicalSort.cpp)
