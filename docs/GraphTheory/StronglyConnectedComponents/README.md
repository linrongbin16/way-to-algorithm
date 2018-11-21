# Section-4 Strong Connected Components
# 第4节 强连通分支

--------

1. [Kosaraju - Kosaraju算法](Kosaraju/)
2. [Tarjan - Tarjan算法](Tarjan/)
3. [2-SAT - 2-SAT问题](2-SAT/)

--------

#### 平凡图（Trivial Graph）/非平凡图（Nontrivial Graph）

平凡图（Trivial Graph）是只有一个节点，没有边的图。非平凡图（Trivial Graph）是有至少两个节点，一条边的图。

#### 连通（Connected）/连通图（Connected Graph）/连通分支（Connected Components）

图$$ G $$中顶点$$ v_i $$和$$ v_j $$连通（Connected）表示存在从顶点$$ v_i $$到达顶点$$ v_j $$，且从顶点$$ v_j $$也可以到达顶点$$ v_i $$的路径。无向图中$$ v_i $$到达$$ v_j $$，和$$ v_j $$到达$$ v_i $$，互为充分必要条件。

连通图（Connected Graph）是任意两顶点都连通的图。

连通分量/连通分支（Connected Components）是图$$ G $$的子图，又是连通图，且加入图$$ G $$的任意其他节点都会不再连通。连通分支的概念常用于无向图。连通分支也称为极大连通子图（Maximal Strongly Connected Subgraph）。连通图的连通分支即为它自己，非连通图中存在多个连通分支。

强连通分量/强连通分支（Strongly Connected Components）是有向图$$ G $$的子图，又是连通图，且加入图$$ G $$的任意其他节点都会不再连通。强连通分支的概念常用于有向图。

双连通分量/双连通分支（Biconnected Components）。

三连通分量/三连通分支（Triconnected Components）。

图$$ G = <V, E> $$的逆图是将原图的所有边都反向得到的图$$ G' = <V', E'> $$。逆图的点集与原图相同$$ V' = V $$，边集$$ E' $$中任意边$$ e' = (v, u) $$都在原图边集$$ E $$中存在对应的边$$ e = (u, v) $$。逆图也称为图的转置。无向图的逆图永远都是它自己。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

#### 图论术语

* https://en.wikipedia.org/wiki/Glossary_of_graph_theory_terms
