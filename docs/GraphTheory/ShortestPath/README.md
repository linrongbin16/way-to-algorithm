# Section-3 Shortest Path
# 第3节 最短路径

--------

#### 最短路径（Shortest Path）/松弛操作（Relaxation）

图$$ G $$中所有边都拥有一个正整数距离$$ dist $$，若从顶点$$ v_i $$可以到达$$ v_j $$，必然存在一条距离最短的路径，即最短路径。最短路径中不存在环。

存在边的距离为0，或负值的图不存在最短路径。距离为0的边可以无限重复使用而不会增加两顶点之间的距离，距离为负值的边可以减小整个路径的距离，这些情况都会让最短路径中出现环。

用$$ dist(i,j) $$表示顶点$$ v_i $$到达$$ v_j $$的最短距离（$$ dist(i,j) = + \infty $$表示$$ v_i $$到$$ v_j $$的距离为无限远，即不可达）。当存在顶点$$ k $$满足：

$$
dist(i,j) > dist(i,k) + dist(k,j)
$$

说明$$ v_i $$经由$$ v_k $$到达$$ v_j $$的距离比当前已知的最短路径距离更近，这时更新$$ v_i, v_j $$之间的距离：

$$
dist(i,j) = dist(i,k) + dist(k,j)
$$

下图演示了一个最简单的松弛操作：

![KnowledgePoint1.png](res/KnowledgePoint1.png)

该更新过程即为松弛操作，松弛操作是最短路径算法的主要手段。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

#### 图论术语

* https://en.wikipedia.org/wiki/Glossary_of_graph_theory_terms

