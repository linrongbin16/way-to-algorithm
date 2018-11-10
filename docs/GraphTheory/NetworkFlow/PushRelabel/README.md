<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Push Relabel - 压入与重标记算法

--------

#### 问题

用压入与重标记算法求网络$$ G = <V,E> $$的最大流，$$ G $$是单源点、单汇点，边的容量都为正整数的网络。

#### 定义

设网络中每个节点都有一个水位高度$$ level $$，当$$ c_f(i,j) = c(i,j) - f(i,j) \gt 0 $$时边$$ e_{i,j} $$仍然可以容纳更多的流，当$$ c_f(i,j) = 0 $$时称边$$ e_{i,j} $$为饱和边，不能容纳更多的流。

设节点$$ v_i $$（$$ v_i \in V \backslash \{s, t\} $$）的流入和流出之差为：

$$
x(i) = inflow_{i} - outflow_{i} = \sum_{u \in V} f(u, i) - \sum_{v \in V} f(i, v)
$$

若相邻节点$$ v_i, v_j $$满足$$ c_f(i,j) \gt 0 $$，称$$ v_i, v_j $$之间可以容纳额外的流。

#### 压入操作

压入操作条件：

$$ (1) $$ 相邻节点$$ v_i, v_j $$的水位满足$$ level(i) = level(j) + 1 $$（称$$ v_j $$在$$ v_i $$的低位，$$ v_i $$在$$ v_j $$的高位）；

$$ (2) $$ 相邻节点$$ v_i, v_j $$的边的剩余容量满足$$ c_f(i,j) \gt 0 $$；

压入操作：像高处的水流向最低洼的位置，对于满足压入操作条件的相邻节点，由节点$$ v_i $$流向节点$$ v_j $$，边$$ e_{i,j} $$的剩余容量更新为：

$$
\begin{cases}
f(i,j) = f(i,j) + \Delta        \\
f(j,i) = f(j,i) - \Delta        \\
x(i) = x(i) + \Delta          \\
x(j) = x(j) - \Delta
\end{cases}
$$

其中$$ \Delta = min(x(i), c_f(i,j)) $$。任意节点$$ v_i $$能够流出的最大值为$$ x(i) $$（不能凭空制造流，每个节点必须有流入才能流出），而边$$ e_{i,j} $$能够额外容纳的流为$$ c_f(i,j) $$，因此实际可用的流是两者的最小值。

网络中将源点视作入流无穷大的节点，即有

$$
\begin{matrix}
inflow_{s} = + \infty   \\
x(s) = + \infty
\end{matrix}
$$

将汇点视作出流无穷大的节点，即有

$$
outflow_{t} = - \infty  \\
x(t) = - \infty
$$

#### 重标记操作

重标记操作是调整相邻节点之间的水位高度差的辅助操作，目的是尽可能将更多的流压入汇点。

重标记操作条件：

$$ (1) $$ 节点$$ v_i $$的流入和流出之差满足$$ x(i) \gt 0 $$，说明该节点仍然能够制造出流；

$$ (2) $$ 节点$$ v_i $$存在可以容纳额外的流的邻节点$$ v_j $$（即$$ c_f(i,j) \gt 0 $$），且水位高度之差满足$$ level(i) \leq level(j) $$；

重标记操作：

$$
level(i) = min \{ level(j) \} + 1
$$

其中$$ v_j $$是所有满足重标记条件的$$ v_i $$的邻节点，将$$ v_i $$的水位设置为所有节点中最低的水位加$$ 1 $$。

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

对源点$$ s $$进行预压入操作（无视水位）：

$$
x(i) = f(s, i) = c(s, i)
$$

其中$$ v_i $$是所有与源点$$ s $$相邻，且满足剩余容量$$ c_f(s,i) \gt 0 $$的邻节点。

然后设置网络中节点的水位：

$$
level(i) =
\begin{cases}
\mid V \mid     &   v_i = s                         \\
0               &   v_i \in V \backslash \{ s \}
\end{cases}
$$

遍历网络找到满足压入操作、重标记操作的相邻节点和边，并进行对应操作。重复这两种操作直到无法继续，算法结束。网络的最大流即为汇点$$ t $$的邻节点的出流之和：

$$
flow_{max} = \sum_{u \in V} f(u, t)
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
