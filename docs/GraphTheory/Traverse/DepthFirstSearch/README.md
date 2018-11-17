<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Depth First Search(DFS) - 深度优先搜索

--------

#### 问题

用深度优先搜索从图$$ G = <V,E> $$的顶点$$ v_0 $$开始遍历所有顶点。

#### 解法

深度优先搜索类似二叉树的先序遍历，从顶点$$ v_0 $$开始遍历所有顶点：

$$ (1) $$ 对于任意顶点$$ v_i $$，若该顶点已染红则跳过；若该顶点未染色则先访问$$ v_i $$本身并染红，再从$$ v_i $$所有邻节点中挑选未被染红的邻节点$$ v_j $$作为下一个搜索的顶点（跳过已染红的邻节点），继续递归的进行搜索操作。直到无法找到更多可以访问的顶点，本次搜索结束，继续遍历下一个顶点；

搜索顶点的顺序可以看作顶点的搜索距离，也可看作搜索时间（每搜索一个顶点消耗一个时间单位）。为了避免重复搜索，每访问一个顶点后需要将其染红。

下图演示无向图$$ UG $$从顶点$$ v_0 $$开始深度优先搜索的过程：

![DepthFirstSearch1.png](../res/DepthFirstSearch1.png)

顶点访问的顺序为$$ [0, 4, 3, 1, 2, 5] $$。深度优先搜索时间复杂度为$$ O(\mid V \mid) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 22.Elementary Graph Algorithms - 22.3.Depth-first search](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[DepthFirstSearch.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/DepthFirstSearch.h)

[DepthFirstSearch.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/DepthFirstSearch.cpp)

#### 测试

[DepthFirstSearchTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/DepthFirstSearchTest.cpp)
