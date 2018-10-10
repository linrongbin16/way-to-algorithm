<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Unique Path - 唯一路径

--------

#### 问题

在$$ n $$行$$ m $$列的二维矩阵上从左上角移动到右下角$$ [1,1] \rightarrow [n,m] $$，每次移动只能向右/向下移动。求有多少种不同的路径。

#### 解法

设$$ f(i,j) $$为从$$ [1,1] $$到$$ [i,j] $$的不同路径的数量，其中$$ i \in [1,n], j \in [1,m] $$。因此有如下状态转移方程：

$$
f(i,j) =
\begin{cases}
0                                               &   (initialize)    &   i \in [0,n], j \in [0,m]    \\
1                                               &   (initialize)    &   i = j = 1   \\
f(i-1,j) + f(i,j-1)                             &   i \in [1,n], j \in [1,m]
\end{cases}
$$

$$ (1) $$ 初始化$$ f(i,j) = 0 $$；

$$ (2) $$ 初始化，设$$ f(1,1) = 1 $$，认为从$$ [1,1] $$到$$ [1,1] $$的路径有1条；

$$ (3) $$ 对于节点$$ [i,j] $$，既可以从上方$$ [i,j-1] $$过来，也可以从左方$$ [i-1,j] $$过来。因此$$ f(i,j) = f(i-1,j)+f(i,j-1) $$；

$$ f(n,m) $$即为从$$ [1,1] $$到$$ [n,m] $$的不同路径的数量。该算法的时间复杂度是$$ O(n \times m) $$。

--------

#### LeetCode

* https://leetcode.com/problems/unique-paths/description/

[leetcode-62.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/leetcode/leetcode-62.cpp)

--------

#### 源码

[UniquePath.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/RegionalDP/UniquePath.h)

[UniquePath.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/RegionalDP/UniquePath.cpp)

#### 测试

[UniquePathTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/RegionalDP/UniquePathTest.cpp)
