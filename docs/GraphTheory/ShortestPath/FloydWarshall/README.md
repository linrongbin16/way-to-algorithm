<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Floyd Warshall - Floyd Warshall算法

--------

#### 问题

用Floyd Warshall算法求图$$ G = <V, E> $$中任意两顶点$$ v_i, v_j $$之间的最短距离。

#### 解法

设$$ G(i,j) $$为顶点$$ v_i $$到$$ v_j $$的边的距离，二维数组$$ dist(i,j) $$表示从顶点$$ v_i $$到顶点$$ v_j $$的最短距离。

初始时，任意顶点$$ v_i $$到自己的距离为0（即$$ dist(i,i) = 0 $$），$$ v_i $$到其他顶点的距离为无穷大；

$$
dist(i,j) =
\begin{cases}
0                   &   i = j       \\
+ \infty            &   i \neq j
\end{cases}
$$

对于图$$ G $$中任意两顶点$$ v_i, v_j $$，遍历图中的所有其他顶点，尝试进行松弛操作。若存在顶点$$ v_k $$满足：

$$
dist(i,j) > dist(i,k) + dist(k,j)
$$

则更新$$ v_i, v_j $$之间的最短距离：

$$
dist(i,j) = dist(i,k) + dist(k,j)
$$

遍历任意两顶点，更新最短距离，最终可得图$$ G $$中任意两顶点间的最短距离。该算法时间复杂度为$$ O(\mid V \mid ^3) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 25.All-Pairs Shortest Paths - 25.2.The Floyd-Warshall algorithm](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[FloydWarshall.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/FloydWarshall.h)

[FloydWarshall.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/FloydWarshall.cpp)

#### 测试

[FloydWarshallTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/FloydWarshallTest.cpp)
