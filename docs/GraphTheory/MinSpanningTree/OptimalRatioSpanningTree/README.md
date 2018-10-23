<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Optimal Ratio Spanning Tree - 最优比率生成树

--------

#### 问题

无向图$$ UG $$的每个边$$ e_i $$都有两个值，距离$$ dist_i $$和开销$$ cost_i $$。设该图生成树的点集为$$ V_{tree} $$，边集为$$ E_{tree} $$，生成树的比率为所有边的开销和与距离和之比：

$$
ratio = \frac{ \sum_{i=0}{n-1} cost_{i} }{ \sum_{i=0}{n-1} dist_{i} }
$$

求无向图$$ UG $$的最优/最小比率生成树。

#### 解法

--------

#### 源码

[OptimalRatioSpanningTree.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/OptimalRatioSpanningTree.h)

[OptimalRatioSpanningTree.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/OptimalRatioSpanningTree.cpp)

#### 测试

[OptimalRatioSpanningTreeTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/MinimumSpanningTree/OptimalRatioSpanningTreeTest.cpp)
