<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Dijkstra - Dijkstra算法

--------

#### 问题

假设图$$ G = <V, E> $$中顶点$$ v_0 $$可以到达任意其他顶点$$ v_j $$，用Dijkstra算法求顶点$$ v_0 $$到其他所有顶点的最短距离。

#### 解法

设$$ G(i, j) $$为顶点$$ v_i $$到$$ v_j $$的边的距离，数组$$ dist(i) $$表示从顶点$$ v_0 $$到$$ v_i $$的最短距离。

初始时，顶点$$ v_0 $$到自己的距离为0（即$$ dist(0) = 0 $$），$$ v_0 $$到其他顶点的距离为无穷大；

$$
dist(i) =
\begin{cases}
0                   &   i = 0       \\
+ \infty            &   i \neq 0
\end{cases}
$$

类似BFS算法，初始时将$$ v_0 $$加入队列$$ queue $$中并染红。当$$ queue $$不为空时，从$$ queue $$中取出头节点$$ v_i $$，遍历其所有未被染红的邻节点，通过松弛操作更新$$ v_0 $$到$$ v_i $$的所有邻节点（设邻节点为$$ v_j $$）的最短距离，并将访问过的邻节点染红：

$$ (1) $$ 若$$ dist(j) \gt dist(i) + G(i, j) $$，则更新距离$$ dist(j) = dist(i) + G(i, j) $$；

$$ (2) $$ 若$$ dist(i) \gt dist(j) + G(j, i) $$，则更新距离$$ dist(i) = dist(j) + G(j, i) $$；

通过这种BFS算法将图$$ G $$中所有顶点都访问过后，算法结束。顶点$$ v_0 $$到任意其他顶点$$ v_i $$的最短距离为$$ dist(i) $$。该算法时间复杂度为$$ O(\| V \| \times log_2 \| V \|) $$，其中$$ log_2 \| V \| $$表示平均每个顶点的临边数量。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 24.Single-Source Shortest Paths - 24.3.Dijkstra's algorithm](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)


--------

#### 源码

[Dijkstra.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/Dijkstra.h)

[Dijkstra.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/Dijkstra.cpp)

#### 测试

[DijkstraTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/DijkstraTest.cpp)
