<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Push Relabel - 压入与重标记算法

--------

#### 问题

用压入与重标记算法求网络流$$ G $$的最大流，$$ G = <V,E> $$是单源点、单汇点，边的容量为正整数。

#### 压入操作/Push

设网络中每个节点都有一个水位高度$$ height $$，若相邻两节点的边$$ e_{i,j} $$的剩余容量为$$ c(i,j) \gt 0 $$，且两节点的水位高度满足$$ height_{i} \gt height_{j} $$，水位高度差为$$ height_{i} - height_{j} \geq c(i,j) $$。（水从高处流向低处）节点$$ v_i $$流出的流为$$ c(i,j) $$，流到节点$$ v_j $$中。

实际中节点$$ v_i, v_j $$和边$$ e_{i,j} $$的水位高度和剩余容量的更新情况为：

$$
\begin{cases}
height_i = height_i - flow        \\
height_j = height_j + flow        \\
c(i,j) = c(i,j) - flow
\end{cases}
$$

其中$$ height_i \gt height_j $$且$$ flow = min(height_i - height_j, c(i,j)) $$，取水位差与剩余容量的最小值。

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
