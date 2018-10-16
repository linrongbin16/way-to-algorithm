<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Depth First Search(DFS) - 深度优先搜索

--------

#### 问题

用深度优先搜索遍历图$$ G $$的所有节点。

#### 解法

图$$ G $$中，假设节点$$ i $$的邻节点组成的集合为$$ V_i $$，（类似二叉树的先序遍历）访问节点$$ i $$并将其染红，然后从其邻节点集合$$ V_i $$中挑选节点$$ j $$作为下一个要访问的节点，若节点$$ j $$为红色则跳过不访问。递归的重复该访问操作，直到没有更多为被染红的节点可以访问，这时再考虑从递归上一层的集合$$ V_i $$中选取下一个节点，尝试访问。

遍历过程中遇到的节点的顺序，即为Dfs的搜索顺序。遍历中两个节点之间的搜索次数，为两个节点的距离，也可以看作搜索需要的时间（每次搜索消耗一个单位时间）。为了避免重复访问同一个节点，访问节点之后将其染红。下图演示无向图$$ UG $$从节点$$ 0 $$开始深度优先搜索的过程：

![DepthFirstSearch1.svg](../res/DepthFirstSearch1.svg)

节点访问的顺序为$$ [0, 4, 3, 1, 2, 5] $$。

节点数量为$$ n $$的图上深度优先搜索时间复杂度为$$ O(n) $$。

--------

#### 深度优先搜索

* https://en.wikipedia.org/wiki/Depth-first_search

--------

#### 源码

[DepthFirstSearch.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/DepthFirstSearch.h)

[DepthFirstSearch.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/DepthFirstSearch.cpp)

#### 测试

[DepthFirstSearchTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/DepthFirstSearchTest.cpp)
