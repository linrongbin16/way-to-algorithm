<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Depth First Search(DFS) - 深度优先搜索

--------

#### 问题

用深度优先搜索从图$$ G = <V,E> $$的顶点$$ v_0 $$开始遍历所有顶点。

#### 解法

深度优先搜索类似二叉树的先序遍历，访问节点$$ v_0 $$后将其染红，然后从$$ v_0 $$的所有邻节点中挑选未被染红的邻节点$$ v_j $$作为下一个要访问的节点（红色的顶点跳过不访问）。重复该访问操作，直到没有更多为被染红的节点可以访问，再回到上一层在$$ v_0 $$的其他邻节点中寻找下一个未被染红的邻节点$$ v_k $$，继续搜索。

上述访问顶点的顺序即为DFS的搜索顺序。两个顶点先后搜索到的次序，即为两顶点的距离，也可看作搜索需要的时间（每访问一个顶点消耗一个时间单位）。为了避免重复访问，访问一个节点后将其染红。

下图演示无向图$$ UG $$从节点$$ v_0 $$开始深度优先搜索的过程：

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
