<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Triangle Path - 三角形路径

--------

#### 问题

在高度为$$ n $$的三角形上从最上面移动到最下面，三角形上节点$$ i $$的值为$$ v_{i} $$，每次移动只能向下移动左右两个邻节点。如图所示：

![TrianglePath1.svg](../res/TrianglePath1.svg)

从上面移动到下面的代价为所有经过节点的值之和，求从上到下的最小移动代价。

#### 解法

高度为$$ n $$的三角形拥有$$ \frac{(n+1) \times n}{2} $$个节点。设节点下标从$$ 1 $$开始，则第$$ n $$行的节点为$$ [\frac{n \times (n-1)}{2} + 1, \dots, \frac{(n+1) \times n}{2}] $$。左边节点为$$ \frac{n \times (n-1)}{2} + 1 $$，右边节点为$$ \frac{(n+1) \times n}{2} $$。

![TrianglePath2.svg](../res/TrianglePath2.svg)

从上图可知，第$$ 1 $$行的左边节点为$$ \frac{1 \times (1-1)}{2} +1 = 1 $$，右边节点为$$ \frac{(1+1) \times 1}{2} = 1 $$；第$$ 2 $$行的左边节点为$$ \frac{2 \times (2-1)}{2} + 1 = 2 $$，右边节点为$$ \frac{(2+1) \times 2}{2} = 3 $$；第$$ 3 $$行的左边节点为$$ \frac{3 \times (3-1)}{2} + 1 = 4 $$，右边节点为$$ \frac{(3+1) \times 3}{2} = 6 $$；等等。

三角形的第$$ n $$行有$$ n $$个节点，因此节点$$ i $$的左下节点（类似于左孩子节点）为$$ i + n $$，右下节点为$$ i + n + 1 $$。

设$$ f(i) $$为从$$ [1,1] $$到$$ [i,j] $$的不同路径的数量，其中$$ i \in [1,n], j \in [1,m] $$。因此有如下状态转移方程：

$$
f(i,j) =
\begin{cases}
0                                               &   (initialize)    &   i \in [0,n], j \in [0,m]    \\
1                                               &   (initialize)    &   i = j = 1   \\
f(i-1,j) + f(i,j-1)                             &   i \in [1,n], j \in [1,m]
\end{cases}
$$

$$ (1) $$ 初始化，设$$ f(1,1) = 1 $$，认为从$$ [1,1] $$到$$ [1,1] $$的路径有1条，实际编码是设$$ f(0,1)=f(1,0)=f(1,1)=1 $$；

$$ (2) $$ 对于节点$$ [i,j] $$，既可以从上方$$ [i,j-1] $$过来，也可以从左方$$ [i-1,j] $$过来。因此$$ f(i,j) = f(i-1,j)+f(i,j-1) $$；

$$ f(n,m) $$即为从$$ [1,1] $$到$$ [n,m] $$的不同路径的数量。该算法的时间复杂度是$$ O(n \times m) $$。

--------

#### LeetCode

* https://leetcode.com/problems/triangle/description/

[leetcode-120.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/leetcode/leetcode-120.cpp)

--------

#### 源码

[TrianglePath.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/RegionalDP/TrianglePath.h)

[TrianglePath.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/RegionalDP/TrianglePath.cpp)

#### 测试

[TrianglePathTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/RegionalDP/TrianglePathTest.cpp)

