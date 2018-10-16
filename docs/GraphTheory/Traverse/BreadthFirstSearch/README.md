<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Breadth First Search(BFS) - 广度优先搜索

--------

#### 问题

用广度优先搜索遍历图$$ G $$的所有节点。

#### 解法

图$$ G $$中，假设节点$$ i $$的邻节点组成的集合为$$ V_i $$，访问节点$$ i $$并将其染红，然后优先访问$$ i $$的所有邻节点，若某个邻节点$$ j $$为红色则跳过不访问。再递归的从邻节点出发访问其他节点，直到没有更多为被染红的节点可以访问。

广度优先搜索需要一个队列$$ queue $$来存储那些等待访问而尚未被访问的节点。为了避免重复访问，当把节点$$ i $$加入待访问队列$$ queue $$时将其染红。下图演示无向图$$ UG $$广度优先搜索的过程：

![BreadthFirstSearch1.svg](../res/BreadthFirstSearch1.svg)

广度优先搜索时间复杂度为$$ O(n) $$。

--------

#### 广度优先搜索

* https://en.wikipedia.org/wiki/Breadth-first_search

--------

#### 源码

[BreadthFirstSearch.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearch.h)

[BreadthFirstSearch.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearch.cpp)

#### 测试

[BreadthFirstSearchTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearchTest.cpp)
