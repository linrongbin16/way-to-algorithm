<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Prim - Prim 算法

--------

#### 问题

用Prim算法求无向图$$ UG $$的最小生成树。

#### 解法

Prim算法是贪心算法的应用：

$$ (1) $$ 初始时设生成树的边集合为$$ E_{tree} $$，点集合为$$ V_{tree} $$（初始时生成树为空）。将一个顶点作为初始顶点加入生成树的点集$$ V_{tree} $$中；

$$ (2) $$ 类似BFS算法，在$$ V_{tree} $$的所有临边（一个端点属于$$ V_{tree} $$，另一个端点不属于的边）中找到权值最小的临边$$ e_{i,j} $$。设$$ e_{i,j} $$的一个端点$$ v_i $$属于$$ V_{tree} $$，另一个端点$$ v_j $$不属于$$ V_{tree} $$，把$$ v_j $$加入生成树点集$$ V_{tree} $$，把$$ e_{i,j} $$加入生成树边集$$ E_{tree} $$；

重复上述操作，直到$$ V_{tree} = V $$为止，这时$$ E_{tree} $$即为无向图$$ UG $$的最小生成树。该算法的时间复杂度为$$ O(|E|) $$。

--------

#### Introduction To Algorithms - VI.Graph Algorithms - 23.Minimum Spanning Trees - 23.2.The algorithms of Kruskal and Prim

* https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf

--------

#### 源码

[Prim.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/Prim.h)

[Prim.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/Prim.cpp)

#### 测试

[PrimTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/PrimTest.cpp)

