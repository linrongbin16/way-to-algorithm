<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Multiple Source Multiple Sink Max flow - 多源点多汇点最大流

--------

#### 问题

求网络流$$ G = <V,E> $$的最大流，$$ G $$是多源点、多汇点，边的容量都为正整数的网络。

#### 解法

将多源点、多汇点的网络改造为单源点、单汇点的，就可以将该问题转化为普通的最大流问题。

设$$ n $$个源点为$$ [s_1, s_2, \dots, s_n] $$，$$ m $$个汇点为$$ [t_1, t_2, \dots, t_m] $$，如下图所示：

<!--![MultipleSourceMultipleSinkMaxFlow1.png](../res/MultipleSourceMultipleSinkMaxFlow1.png)-->

新增源点$$ s $$和汇点$$ t $$，构造新增源点$$ s $$到所有源点$$ s_1, s_2, \dots, s_n $$的边，容量为无穷大，即

$$
c(s, s_i) = + \infty
$$

其中$$ 1 \leq i \leq n $$。

构造所有汇点$$ t_1, t_2, \dots, t_m $$到新增汇点$$ t $$的边，容量为无穷大，即

$$
c(t_i, t) = + \infty
$$

其中$$ 1 \leq i \leq m $$。

把原网络中的源点汇点当作普通节点，即可得到新的单源点、单汇点网络，如下图所示：

<!--![MultipleSourceMultipleSinkMaxFlow2.png](../res/MultipleSourceMultipleSinkMaxFlow2.png)-->

新网络的最大流即为原网络的最大流，该算法的时间复杂度与所采用最大流算法的时间复杂度相同。

--------

#### 源码

[MultipleSourceMultipleSinkMaxFlow.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/MultipleSourceMultipleSinkMaxFlow.h)

[MultipleSourceMultipleSinkMaxFlow.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/MultipleSourceMultipleSinkMaxFlow.cpp)

#### 测试

[MultipleSourceMultipleSinkMaxFlowTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/NetworkFlow/MultipleSourceMultipleSinkMaxFlowTest.cpp)
