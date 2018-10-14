<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Complete Bag - 完全背包

--------

#### 问题

现有$$ n $$种珠宝，每种都有无穷多$$ + \infty $$个，已知第$$ i $$个珠宝的价值是$$ v_{i} $$，重量是$$ w_{i} $$。给你一个背包，你可以自由挑选珠宝装到背包中，但背包可以装载的最大重量为$$ weight $$。求背包能够装载珠宝的最大价值$$ value $$。

#### 解法

设$$ f(i,j) $$为背包中放入前$$ i $$件物品，重量不大于$$ j $$的最大价值，其中$$ i \in [1,n] $$，$$ j \in [0,weight] $$。有如下状态转移方程：

$$
f(i,j) =
\begin{cases}
0                                                       &   (initialize)    &   i \in [0,n], j \in [0,weight]         \\
max(f(i-1,j),f(i-1,j-k \times w_{i}) + k \times v_{i})  &   (loop)          &   i \in [1,n], j \in [1,weight], j \geq k \times w_{i}, k \geq 0
\end{cases}
$$

$$ (1) $$ 初始化，背包中没有放入任何珠宝时$$ f(i,j) = 0 $$；

$$ (2) $$ 对于第$$ i $$种珠宝，若装入背包$$ k $$个，则背包价值增大$$ k \times v_{i} $$，背包的剩余重量减小$$ k \times w_{i} $$（其中$$ k \geq 0, j \geq k \times w_{i} $$），即$$ f(i,j) = f(i-1,j-k \times w_{i}) + k \times v_{i} $$；若不装入背包，则一切维持不变，即$$ f(i,j) = f(i-1,j) $$。选择这两种情形中的最大值；

$$ f(n,weight) $$即为$$ n $$个珠宝中重量不超过$$ weight $$的最大价值。该算法的时间复杂度是$$ O(n \times weight^2) $$，因为状态转移方程中的参数$$ k $$的规模与背包最大重量$$ weight $$线性相关。

--------

#### 源码

[CompleteBag.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/CompleteBag.h)

[CompleteBag.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/CompleteBag.cpp)

#### 测试

[CompleteBagTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/BagDP/CompleteBagTest.cpp)
