<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Bellman Ford - Bellman Ford算法

--------

#### 问题

假设图$$ G = <V, E> $$中顶点$$ v_0 $$可以到达任意其他顶点$$ v_j $$，用Bellman Ford算法求顶点$$ v_0 $$到其他所有顶点的最短距离。

#### 解法

设$$ G(i, j) $$为两端点为顶点$$ v_i, v_j $$的边的距离，数组$$ dist(i) $$表示从顶点$$ v_0 $$到$$ v_i $$的最短距离。

初始时，顶点$$ v_0 $$到自己的距离为0（即$$ dist(0) = 0 $$），$$ v_0 $$到其他顶点的距离为无穷大；

$$
dist(i) =
\begin{cases}
0                   &   i = 0                       \\
+ \infty            &   i \neq 0
\end{cases}
$$

进行两层遍历，外层重复次数为点集的数量$$ |V| $$（外层重复$$ |V| $$次必然可以求出$$ v_0 $$到所有其他顶点的最短距离），内层遍历边集$$ E $$中的所有边$$ e_{i,j} $$，设$$ e_{i,j} $$的两端点为$$ v_i, v_j $$。对顶点$$ v_0, v_i, v_j $$进行松弛操作：

$$ (1) $$ 若$$ dist(j) \gt dist(i) + G(i, j) $$，则更新距离$$ dist(j) = dist(i) + G(i, j) $$；

$$ (2) $$ 若$$ dist(i) \gt dist(j) + G(j, i) $$，则更新距离$$ dist(i) = dist(j) + G(j, i) $$；

顶点$$ v_0 $$到任意其他顶点$$ v_i $$的最短距离为$$ dist(i) $$。若某个顶点的最短距离$$ dist(i) \lt 0 $$，则说明该图不存在最短路径。

该算法时间复杂度为$$ O(\mid V \mid \cdot \mid E \mid) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 24.Single-Source Shortest Paths - 24.1.The Bellman-Ford algorithm](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[BellmanFord.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/BellmanFord.h)

[BellmanFord.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/BellmanFord.cpp)

#### 测试

[BellmanFordTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/ShortestPath/BellmanFordTest.cpp)
