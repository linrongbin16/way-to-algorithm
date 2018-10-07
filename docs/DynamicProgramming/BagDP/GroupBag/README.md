<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Group Bag - 分组背包

--------

#### 问题

现有$$ m $$组珠宝，每组中有$$ n_{i} $$种珠宝，每种$$ 1 $$个，第$$ i $$组第$$ j $$个珠宝的价值为$$ v_{i, j} $$，重量为$$ w_{i, j} $$。给你一个背包，你可以挑选珠宝装到背包中，但背包可以装载的最大重量为$$ weight $$，并且同一个组的珠宝至多只能选择$$ 1 $$个。求背包能够装载珠宝的最大价值$$ value $$。

该问题与Zero One Bag的区别就是，对珠宝进行了分组，并且一个组内的珠宝互斥。

#### 解法

设$$ f(i,j) $$为背包中放入前$$ i $$组物品，重量不大于$$ j $$的最大价值，其中$$ i \in [1,m] $$，$$ j \in [0,weight] $$。第$$ i $$组中有$$ group_{i} $$个珠宝，其中某珠宝$$ k $$的价值是$$ v_{k} $$，重量是$$ w_{k} $$。则有如下状态转移方程：

$$
f(i,j) =
\begin{cases}
0                                           &   (initialize)    &   i \in [0,n], j \in [0, weight] \\
f(i-1,j)                                    &   i,j \gt 0   \\
max(f(i-1,j),f(i-1,j - w_{k} ) + v_{k})     &   i,j \gt 0       &   k \in [1,group_{i}]  &    j \geq w_{k}
\end{cases}
$$

$$ (1) $$ 用数组中的下标$$ 0 $$来存储初始的固定值，背包中没有放入任何珠宝时，$$ f(0,j) = 0 $$；

$$ (2) $$ 对于第$$ i $$组珠宝，背包的剩余重量（还能装载的重量）为$$ w $$，在第$$ i $$组珠宝中选择某个珠宝$$ k $$，若$$ w \geq w_{k} $$，那么可以装进珠宝$$ k $$，背包的价值增大$$ v_{k} $$，剩余重量减小$$ w_{k} $$，即$$ f(i,j) = f(i-1,j - w_{k}) + v_{k} $$；若不装入背包，则一切维持不变，即$$ f(i,j) = f(i-1,j) $$。选择这两种情形中的最大值；

$$ f(m,weight) $$即为$$ m $$组珠宝中重量不超过$$ weight $$的最大价值。该算法的时间复杂度是$$ O(n \times weight) $$。

--------

#### 源码

[GroupBag.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/GroupBag.h)

[GroupBag.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/GroupBag.cpp)

#### 测试

[GroupBagTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/GroupBagTest.cpp)
