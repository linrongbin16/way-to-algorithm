<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Dijkstra - Dijkstra算法

--------

#### 问题

假设图$$ G = <V, E> $$中顶点$$ v_0 $$可以到达任意其他顶点$$ v_j $$，用Dijkstra算法求顶点$$ v_0 $$到其他所有顶点的最短距离。

#### 解法

设$$ G(i, j) $$为节点$$ v_i $$到$$ v_j $$的边的距离，二维数组$$ dist(i, j) $$表示从节点$$ v_i $$到$$ v_j $$的最短距离。

初始时设顶点$$ v_i $$到自己的距离为0，与$$ v_i $$相邻的顶点$$ v_j $$的最短距离为边的距离$$ G(i,j) $$，与其不相邻的顶点的最短距离为无穷大：

$$
dist(i, j) =
\begin{cases}
0                   &   v_i = v_j                   \\
G(i,j)            &   v_i is adjacent to v_j      \\
+ \infty            &   v_i is not adjacent to v_j
\end{cases}
$$

类似BFS算法，初始时将$$ v_0 $$加入队列$$ queue $$中并染红。当$$ queue $$不为空时：

$$ (1) $$ 从$$ queue $$中取出头节点$$ v_i $$，遍历所有邻节点，通过松弛操作更新$$ v_i $$到邻节点（设邻节点为$$ v_j $$）的最短距离：

$$ (1) $$ 若$$ dist(v_0, v_j) \gt dist(v_0, v_i) + G(v_i, v_j) $$，则更新距离$$ dist(v_0, v_j) = dist(v_0, v_i) + G(v_i, v_j) $$；

$$ (2) $$ 若$$ dist(v_0, v_i) \gt dist(v_0, v_j) + G(v_j, v_i) $$，则更新距离$$ dist(v_0, v_i) = dist(v_0, v_j) + G(v_j, v_i) $$；

顶点$$ v_0 $$到任意其他顶点$$ v_i $$的最短距离为$$ dist(v_0, v_i) $$。该算法时间复杂度为$$ O(|V| \times |E|) $$。

--------

#### 源码

[Dijkstra.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/Dijkstra.h)

[Dijkstra.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/Dijkstra.cpp)

#### 测试

[DijkstraTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/DijkstraTest.cpp)
