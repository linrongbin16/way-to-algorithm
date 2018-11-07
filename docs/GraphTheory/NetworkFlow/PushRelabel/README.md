<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Push Relabel - 压入与重标记算法

--------

#### 问题

用压入与重标记算法求网络流$$ G = <V,E> $$的最大流，$$ G $$是单源点、单汇点的，边的容量为正整数。

#### 压入操作

设网络中每个节点都有一个水位高度$$ height $$，设节点$$ v_i $$的邻节点为$$ [v_{1}, v_{2}, \dots, v_{n}] $$，与这些邻节点的边为$$ e_{i,j} $$（其中$$ 1 \leq j \leq n $$），剩余容量为$$ c(i,j) $$。

压入操作必须满足条件：邻节点$$ v_i, v_j $$的水位满足$$ height_{i} \gt height_{j} $$且剩余容量满足$$ c(i,j) \gt 0 $$。否则认为$$ v_i $$无法流向$$ v_j $$，即节点$$ v_i $$对邻节点$$ v_j $$没有溢出流。满足条件的两相邻节点，可以由$$ v_i $$流出到$$ v_j $$的流是两节点的水位差与边的剩余容量的最小值：

$$
flow = min(height_{i} - height_{j}, c(i,j))
$$

在$$ v_i $$的所有邻节点中选择最大的可压出流$$ flow_{i,j} $$，从节点$$ v_i $$流向节点$$ v_j $$，就像高处的水流向最低洼的位置一样。

节点$$ v_i, v_j $$和边$$ e_{i,j} $$的水位高度和剩余容量更新为：

$$
\begin{cases}
height_{i} = height_{i} - flow_{i,j}        \\
height_{j} = height_{j} + flow_{i,j}        \\
c(i,j) = c(i,j) - flow_{i,j}
\end{cases}
$$

其中$$ flow = min(height_i - height_j, c(i,j)) $$。

将源点$$ Source $$的水位看作无穷大$$ + \infty $$，汇点$$ Sink $$的水位看作$$ 0 $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 26.Maximum Flow - 26.2.The-Ford-Fulkerson method](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[PushRelabel.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabel.h)

[PushRelabel.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabel.cpp)

#### 测试

[PushRelabelTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabelTest.cpp)
