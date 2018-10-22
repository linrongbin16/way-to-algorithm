<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Bellman Ford - Bellman Ford算法

--------

#### 问题

假设图$$ G $$中任意两顶点$$ v_i, v_j $$可以相互到达，求顶点$$ v_0 $$到其他所有顶点的最短距离。

#### 解法

设$$ G(i, j) $$为节点$$ v_i $$到$$ v_j $$的边的距离，二元数组$$ dist(i, j) $$表示从节点$$ v_i $$到$$ v_j $$的最短距离。

初始时设相邻顶点之间的最短距离为边的距离，不相邻顶点之间的最短距离为无穷大：

$$
dist(i, j) = 
\begin{cases}
+ G(i,j)            &   v_i is adjacent to v_j      \\
+ \infty            &   v_i is not adjacent to v_j
\end{cases}
$$

进行两层遍历，对图$$ G $$的点集$$ V $$中的每个顶点$$ v_i $$，遍历其所有临边$$ e_i $$上的另一端点$$ v_j $$，进行松弛操作。

对于临边$$ e_i $$的两个端点$$ v_i, v_j $$

$$ (1) $$ 若$$ dist(v_0, v_j) \gt dist(v_0, v_i) + G(v_i, v_j) $$，则更新距离$$ dist(v_0, v_j) = dist(v_0, v_i) + G(v_i, v_j) $$；

$$ (2) $$ 若$$ dist(v_0, v_i) \gt dist(v_0, v_j) + G(v_j, v_i) $$，则更新距离$$ dist(v_0, v_i) = dist(v_0, v_j) + G(v_j, v_i) $$；

--------

#### 源码

[BellmanFord.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/BellmanFord.h)

[BellmanFord.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/BellmanFord.cpp)

#### 测试

[BellmanFordTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/BellmanFordTest.cpp)


# BellmanFord BellmanFord算法
