<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Push Relabel - 压入与重标记算法

--------

#### 问题

用压入与重标记算法求网络流$$ G = <V,E> $$的最大流，$$ G $$是单源点、单汇点的，边的容量为正整数。

#### 定义

设网络中每个节点都有一个水位高度$$ level $$，设节点$$ v_i $$的邻节点为$$ [v_{1}, v_{2}, \dots, v_{n}] $$，与这些邻节点的边为$$ e_{i,j} $$（其中$$ 1 \leq j \leq n $$），容量为$$ c(i,j) $$。节点$$ v_i, v_j $$已经存在的流为$$ f(i,j) $$，满足反对称性$$ f(i,j) = -f(j,i) $$，当$$ c_f(i,j) = c(i,j) - f(i,j) \gt 0 $$时边$$ e_{i,j} $$仍然可以容纳更多的流，当$$ c_f(i,j) = 0 $$时边$$ e_{i,j} $$为饱和边，不能容纳更多的流。

设节点$$ u $$（$$ u \in V \backslash {s, t} $$）的流入和流出之差为：

$$
x(u) = inflow_{u} - outflow_{u} = \sum_{p \in V} f(p, u) - \sum_{q \in V} f(u, q)
$$

若相邻节点$$ v_i, v_j $$满足$$ c_f \gt 0 $$，称$$ v_i, v_j $$之间可以容纳额外/更多的流，否则认为$$ v_i $$无法流向$$ v_j $$。

#### 压入操作

压入操作条件：

$$ (1) $$ 相邻节点$$ v_i, v_j $$的水位满足$$ level_{i} = level_{j} + 1 $$（称$$ v_j $$在$$ v_i $$的低位，$$ v_i $$在$$ v_j $$的高位）；

$$ (2) $$ 相邻节点$$ v_i, v_j $$的边的容量满足$$ c_f(i,j) \gt 0 $$；

压入操作：像高处的水流向最低洼的位置，对于满足压入操作条件的相邻节点，由节点$$ v_i $$流向节点$$ v_j $$，边$$ e_{i,j} $$的流更新为：

$$
\begin{cases}
f(i,j) += \Delta        \\
f(j,i) -= \Delta        \\
x(i) += \Delta          \\
x(j) -= \Delta
\end{cases}
$$

其中$$ \Delta = min(x(i), c_f(i,j)) $$。任意节点$$ v_i $$能够流出的最大值为$$ x(i) $$（只有流入才能流出，而不能凭空制造出流），而边$$ e_{i,j} $$能够额外容纳的流为$$ c_f(i,j) $$，因此实际能够压入的流最大为两者的最小值。

网络中将源点视作入流无穷大的节点，即

$$
inflow_{s} = + \infty
$$

从而有

$$
x(s) = + \infty
$$

将汇点视作出流无穷大的节点，即

$$
outflow_{t} = - \infty
$$

从而有

$$
x(t) = - \infty
$$

#### 重标记操作

重标记操作是调整相邻节点之间的水位高度差的辅助操作，目的是尽可能将更多的流压入汇点。

重标记操作条件：

$$ (1) $$ 节点$$ v_i $$的流入和流出之差满足$$ x(i) \gt 0 $$；

$$ (2) $$ 节点$$ v_i $$存在邻节点$$ v_j $$可以容纳额外的流（即$$ c_f(i,j) \gt 0 $$），且水位高度之差满足$$ level_{i} \leq level_{j} $$；

重标记操作：

$$
level_{i} = min \{ level_{j} \} + 1
$$

其中$$ v_j $$是所有满足重标记条件的$$ v_i $$的邻节点，选取其中水位最低的节点。

#### 解法

初始时设网络中任意两点间的流为$$ 0 $$，即$$ f(i,j) = f(j,i) = 0 $$（其中$$ v_i ,v_j $$为相邻节点），可知任意节点$$ v_i $$的流入流出差为：

$$
x(i) = 
\begin{cases}
+ \infty    &   v_i = s         \\
- \infty    &   v_i  = t        \\
0           &   v_i \in V \backslash \{s, t\}
\end{cases}
$$

对源点$$ s $$进行预压入操作（无视水位），可以得到其所有邻节点的流和流入流出差为：

$$
x(i) = f(s, i) = c(s, i)
$$

其中$$ v_i $$是所有与源点$$ s $$相邻，且边$$ e_{s,i} $$满足容量$$ c(s,i) \gt 0 $$的邻节点。

然后设置网络中节点的水位：

$$
level_{i} =
\begin{cases}
\mid V \mid     &   v_i = s                         \\
0               &   v_i \in V \backslash \{ s \}
\end{cases}
$$

遍历网络找到满足压入操作、重标记操作的相邻节点和边，并进行对应操作。重复这两种操作直到无法继续，算法结束。网络的最大流即为汇点$$ t $$的邻节点的出流之和：

$$
flow = \sum_{u \in V} f(u, t)
$$

该算法的时间复杂度为$$ O(\mid V \mid ^2 \cdot \mid E \mid ) $$。

--------

#### Introduction To Algorithms

* [VI.Graph Algorithms - 26.Maximum Flow - 26.4.Push-relabel algorithms](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[PushRelabel.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabel.h)

[PushRelabel.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabel.cpp)

#### 测试

[PushRelabelTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/PushRelabelTest.cpp)
