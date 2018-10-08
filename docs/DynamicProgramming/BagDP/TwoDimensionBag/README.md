<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Two Dimension Bag - 二维背包

--------

#### 问题

现有$$ n $$个珠宝（共$$ n $$种，每种$$ 1 $$个），已知第$$ i $$个珠宝的价值是$$ v_{i} $$，重量$$ 1 $$是$$ w1_{i} $$，重量$$ 2 $$是$$ w2_{i} $$。给你一个背包，你可以自由挑选珠宝装到背包中，但背包可以装载的最大重量$$ 1 $$为$$ weight1 $$，最大重量$$ 2 $$为$$ weight2 $$。求背包能够装载珠宝的最大价值$$ value $$。

该问题与01背包的区别就是，重量属性变成了$$ 2 $$维属性，背包中所有珠宝的总重量$$ 1 $$不能超过$$ weight1 $$，总重量$$ 2 $$不能超过$$ weight2 $$。

#### 解法

设$$ f(i,j,k) $$为背包中放入前$$ i $$件物品，重量$$ 1 $$不大于$$ j $$，重量$$ 2 $$不大于$$ k $$的最大价值，其中$$ i \in [1,n] $$，$$ j \in [0,weight1] $$，$$ k \in [0,weight2] $$。有如下状态转移方程：

$$
f(i,j,k) =
\begin{cases}
0                                                   &   (intialize)     &   i \in [0,n], j \in [0,weight1], k \in [0,weight2] \\
max{f(i-1,j,k),f(i-1,j-w1_{i},k-w2_{i})+v_{i}}      &   i \in [1,n], j \in[0,weight1], k \in [0,weight2], j \geq w1_{i}, k \geq w2_{i}
\end{cases}
$$

$$ (1) $$ 初始化，背包中没有放入任何珠宝时$$ f(i,j) = 0 $$；

$$ (2) $$ 对于第$$ i $$个珠宝时，若装进背包，则背包的价值增大$$ v_{i} $$，剩余重量$$ 1 $$减小$$ w1_{i} $$，剩余重量$$ 2 $$减小$$ w2_{i} $$，即$$ f(i,j,k) = f(i-1,j-w1_{i},k-w2_{i})+v_{i} $$（其中$$ j \geq w1_{i}, k \geq w2_{i} $$）；若不装入背包，则一切维持不变，即$$ f(i,j,k) = f(i-1,j,k) $$。选择这两种情形中的最大值；

$$ f(n,weight1,weight2) $$即为$$ n $$个珠宝中重量$$ 1 $$不超$$ weight1 $$，重量$$ 2 $$不超过$$ weight2 $$的最大价值。该算法的时间复杂度是$$ O(n \times weight1 \times weight2) $$。

--------

#### 源码

[TwoDimensionBag.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/TwoDimensionBag.h)

[TwoDimensionBag.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/TwoDimensionBag.cpp)

#### 测试

[TwoDimensionBagTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/TwoDimensionBagTest.cpp)
