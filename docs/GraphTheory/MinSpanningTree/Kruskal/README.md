<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Kruskal - Kruskal算法

--------

#### 问题

用Kruskal算法求无向图$$ UG $$的最小生成树。

#### 解法

Kruskal算法是一种贪心算法，按照以下步骤操作：

$$ (1) $$ 初始时将无向图$$ UG = <V, E> $$的边集$$ E $$按照权值从小到大进行排序，设生成树的边集合为$$ E_{tree} = \varnothing $$，点集合为$$ V_{tree} = \varnothing $$，初始时生成树为空；

$$ (2) $$ 按照边的权值从小到大遍历所有边，对于边$$ e_{i,j} $$，若将其加入边集合$$ E_{tree} $$后不会与已有的边形成环 ，则将该边加入生成树中（将$$ e_{i,j} $$加入边集$$ E_{tree} $$，将$$ v_i, v_j $$加入点集合$$ V_{tree} $$）；若将其加入边集合$$ E_{tree} $$后与已有的边会形成环，则跳过边$$ e_{i,j} $$；

遍历边集$$ E $$的所有边，算法结束。最终$$ E_{tree} $$即为无向图$$ UG $$的最小生成树，而生成树的点集满足$$ V_{tree} = V $$。

判断添加边$$ e_{i,j} $$是否会使生成树形成环的方法是：若边$$ e_{i,j} $$的两个端点$$ v_i $$和$$ v_j $$都属于生成树的点集合$$ V_{tree} $$，则边$$ e_{i,j} $$会使生成树中增加环，跳过该边；否则边$$ e_{i,j} $$不会使生成树形成环。

下图演示无向图用Kruskal算法求解最小生成树的过程，边上的数字即为权值大小：

![Kruskal1.png](../res/Kruskal1.png)

得到生成树为$$ E_{tree} = [ e_{1,2}, e_{3,4}, e_{1,5}, e_{1,3}, e_{0,5} ] $$。

Kruskal算法的时间复杂度为$$ O(| E |) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 23.Minimum Spanning Trees - 23.2.The algorithms of Kruskal and Prim](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[Kruskal.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinSpanningTree/Kruskal.h)

[Kruskal.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinSpanningTree/Kruskal.cpp)

#### 测试

[KruskalTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinSpanningTree/KruskalTest.cpp)

