<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Zero One Bag - 01背包

--------

#### 问题

现有$$ n $$个珠宝，已知第$$ i $$个珠宝的价值是$$ v_{i} $$，重量是$$ w_{i} $$。给你一个背包，你可以自由挑选珠宝装到背包中，但背包可以装载的最大重量为$$ weight $$。求背包能够装载珠宝的最大价值$$ value $$。

#### 解法

设$$ f(i,j) $$为背包中放入前$$ i $$件物品，重量不大于$$ j $$的最大价值，其中$$ i \in [1,n] $$，$$ j \in [0,weight] $$。有如下状态转移方程：

$$
f(i,j) =

\begin{cases}
0                                               &   (initialize)    &   i \in [0,n], j \in [0, weight]  \\
max( f(i-1,j), f(i - 1, j - w_{i}) + v_{i})     &   i \in [1,n], j \in [0,weight], j \geq w_{i}
\end{cases}
$$

$$ (1) $$ 初始化，背包中没有放入任何珠宝时$$ f(i,j) = 0 $$；

$$ (2) $$ 对于第$$ i $$个珠宝$$ s_{i} $$，若装入背包，则背包价值增大$$ v_{i} $$，背包的剩余重量（还能装载的重量）减小$$ w_{i} $$，即$$ f(i,j) = f(i-1,j-w_{i})+v_{i} $$（其中$$ j \geq w_{i} $$）；若不装入背包，则一切维持不变，即$$ f(i,j) = f(i-1,j) $$。选择这两种情形中的最大值；

$$ f(n,weight) $$即为$$ n $$个珠宝中重量不超过$$ weight $$的最大价值。该算法的时间复杂度是$$ O(n \times weight) $$。

--------

#### 源码

[ZeroOneBag.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/ZeroOneBag.h)

[ZeroOneBag.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/ZeroOneBag.cpp)

#### 测试

[ZeroOneBagTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/ZeroOneBagTest.cpp)
