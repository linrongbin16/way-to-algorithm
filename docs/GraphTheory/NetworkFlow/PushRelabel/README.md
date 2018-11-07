<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Push Relabel - 压入与重标记算法

--------

#### 问题

用压入与重标记算法求网络流$$ G = <V,E> $$的最大流，$$ G $$是单源点、单汇点的，边的容量为正整数。

#### 压入操作

设网络中每个节点都有一个水位高度$$ height $$，设节点$$ v_i $$的邻节点为$$ [v_{1}, v_{2}, \dots, v_{n}] $$，与这些邻节点的边为$$ e_{i,j} $$（其中$$ 1 \leq j \leq n $$），剩余容量为$$ c(i,j) $$。节点$$ v_i, v_j $$已经存在的流为$$ f(i,j) $$，满足反对称性$$ f(i,j) = -f(j,i) $$，当$$ f(i,j) \lt c(i,j) $$时边$$ e_{i,j} $$仍然可以容纳更多的流，当$$ f(i,j) = c(i,j) $$时边$$ e_{i,j} $$为饱和边，不能容纳更多的流。

若相邻节点$$ v_i, v_j $$的边的剩余容量满足$$ c(i,j) \gt 0 $$，称$$ v_i, v_j $$之间存在额外的流，可以由$$ v_i $$流出到$$ v_j $$的流是该边的剩余容量，否则认为$$ v_i $$无法流向$$ v_j $$。

压入操作必须满足条件：邻节点$$ v_i, v_j $$的水位满足$$ height_{i} = height_{j} + 1 $$（称$$ v_j $$在$$ v_i $$的低位，$$ v_i $$在$$ v_j $$的高位）且剩余容量满足$$ c(i,j) \gt 0 $$。

在$$ v_i $$的所有邻节点中选择最大的额外流$$ flow_{i,j} $$，从节点$$ v_i $$流向节点$$ v_j $$，就像高处的水流向最低洼的位置一样。

边$$ e_{i,j} $$的剩余容量和流更新为：

$$
\begin{cases}
c(i,j) = c(i,j) - flow_{i,j}        \\
f(i,j) = f(i,j) + flow_{i,j}        \\
f(j,i) = f(j,i) - flow_{i,j}
\end{cases}
$$

其中$$ flow = c(i,j) $$。

#### 重标记操作

初始时设网络的源点$$ Source $$的水位为$$ height_{source} = + \infty $$，汇点$$ Sink $$的水位为$$ height_{sink} = 0 $$，其他节点的水位初始化为$$ height_{i} = 0 $$。进行预压入操作（无视水位）：

$$
\begin{cases}
f(source, i) = c(source, i)     \\
f(i, source) = -c(source, i)     \\
c(source, i) = 0
\end{cases}
$$

再重复的遍历剩余网络中的所有边，对于存在边$$ e_{i,j} $$且剩余容量$$ c(i,j) \gt 0 $$的相邻节点$$ v_i, v_j $$进行如下操作：

$$ (1) $$ 若节点$$ v_i, v_j $$满足压入操作的条件，则对$$ v_i, v_j $$进行压入操作，并更新网络的最大流$$ flow = flow + flow_{i,j} $$；

$$ (2) $$ 若节点$$ v_i $$没有邻节点$$ v_j $$满足$$height_{i} = height_{j} + 1 $$，但存在邻节点满足$$ c(i,j) \gt 0 $$。为了让$$ v_i $$流向$$ v_j $$，找出$$ v_i $$所有邻节点中水位最低的节点$$ v_{min} $$（$$ height_{min} = min \{ v_j \} $$），将节点$$ v_i $$的水位设置为$$ height_{i} = height_{min} + 1 $$。然后再尝试继续遍历所有边，进行第$$ (1) $$步操作；

重复上述操作，直到剩余网络无法进行压入操作，算法结束。该算法的时间复杂度为$$ O(\mid V \mid ^2 \cdot \mid E \mid ) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 26.Maximum Flow - 26.2.The-Ford-Fulkerson method](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[PushRelabel.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabel.h)

[PushRelabel.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabel.cpp)

#### 测试

[PushRelabelTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabelTest.cpp)
