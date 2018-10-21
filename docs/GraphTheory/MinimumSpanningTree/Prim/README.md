<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Prim - Prim 算法

--------

#### 问题

用Prim算法求无向图$$ UG $$的最小生成树。

#### 解法

Prim算法是一种贪心算法：

$$ (1) $$ 初始时将图$$ G $$的边集$$ E $$按照权值从小到大进行排序，设生成树的边集合为$$ E_{tree} $$，点集合为$$ V_{tree} $$，初始时生成树为空；

$$ (2) $$ 遍历每一条边（权值从小到大），对于边$$ e_i $$，若其与边集合$$ E_{tree} $$中已有的边不会形成环 ，则将$$ e_i $$加入$$ E_{tree} $$，将$$ e_i $$的两端点加入生成树的点集合$$ V_{tree} $$；

$$ (3) $$ 反之若$$ e_i $$与边集合$$ E_{tree} $$中已有的边会形成环，则跳过$$ e_i $$；

判断环的方法有点像并查集Disjoint Set：若边$$ e_i $$的两个端点$$ v_1 $$和$$ v_2 $$都属于生成树的点集合$$ V_{tree} $$，则边$$ e_i $$会使生成树中增加环，跳过该边。

--------

#### 源码

[Prim.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/Prim.h)

[Prim.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/Prim.cpp)

#### 测试

[PrimTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/PrimTest.cpp)

