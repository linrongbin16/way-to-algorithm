<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Topological Sort - 拓扑排序

--------

#### 问题

对有向图$$ DG $$进行拓扑排序。

#### 解法

拓扑排序是深度优先搜索的典型应用。

对有向图$$ DG $$的顶点$$ v_i $$进行深度优先搜索，尝试从节点$$ v_i $$出发，直到无法搜索到更多的节点停止。经过的顶点数量即为顶点$$ v_i $$的DFS距离$$ d_i $$。将所有顶点的DFS距离从大到小排序，即为有向图的拓扑排序。DFS距离最小为$$ 1 $$。

下图演示有向图$$ DG $$的拓扑排序：

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
