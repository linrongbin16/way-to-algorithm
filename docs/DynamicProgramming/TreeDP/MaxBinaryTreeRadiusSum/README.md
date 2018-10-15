<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Max Binary Tree Radius Sum - 最大二叉树半径和

--------

#### 问题

在一个二叉树上，从节点$$ i $$到达另一节点$$ j $$的路线是唯一的。设节点$$ i $$权值为$$ v_{i} $$，设所有到节点$$ i $$的距离小于等于$$ radius $$的节点组成的集合为$$ s_{i} = [x_{1}, x_{2}, \dots, x_{n_{i}}] $$，共$$ n_{i} $$个节点，该范围中所有节点的权值之和为$$ \sum_{p=1}^{n_{i}} v_{p} $$ 。称该权值之和为节点$$ i $$在半径$$ radius $$上的半径和。下图演示了节点$$ 4 $$覆盖到的半径为$$ 2 $$的区域：

![MaxBinaryTreeRadiusSum1.svg](../res/MaxBinaryTreeRadiusSum1.svg)

求二叉树的最大半径和。

#### 解法

问题中的示例是一种最简单的情况，即游荡距离为$$ 1 $$，这时节点$$ i $$的最大权值即为该节点与所有相邻节点的权值之和。当游荡距离增大，节点$$ i $$的最大权值为所有到该节点的距离不超过$$ Dist $$的节点的权值之和，即$$ \sum_{1}^{n} v_k $$ （其中$$ n $$为所有节点的数量，$$ k $$节点的权值为$$ v_k $$）。

节点$$ i $$可以到达二叉树的向上和向下$$ Dist $$层的所有节点，如图：

![MaxBinaryTreeRadiusSum2.svg](../res/MaxBinaryTreeRadiusSum2.svg)

![MaxBinaryTreeRadiusSum3.svg](../res/MaxBinaryTreeRadiusSum3.svg)

对于节点$$ 4 $$的奶牛，当其$$ Dist = 2 $$，则向上可以到达节点$$ 2 $$、$$ 1 $$；向下可以到达$$ 7 $$、$$ 8 $$、$$ 20 $$、$$ 21 $$、$$ 22 $$、$$ 23 $$。

$$ (1) $$向上可达的所有节点的权值和：

设$$ up(i,j) $$为游荡距离为$$ j $$的节点$$ i $$，向上可以到达的所有节点的权值之和，则有$$ up(i,j) = up(father_i,j-1)+v_{father-i} $$，即游荡距离为$$ j $$的节点$$ i $$，其向上可达的权值和，等于游荡距离为$$ j-1 $$的父节点$$ father_i $$的向上可达的权值和与父节点自己的权值之和。在上图中可以看出，游荡距离为$$ 2 $$的节点$$ 4 $$，其向上权值和$$ up(4,2) $$，恰好等于游荡距离为$$ 1 $$的节点$$ 2 $$的向上权值和与节点$$ 2 $$的权值之和，即$$ up(4,2) = up(2,1)+v_2 $$。

对于游荡距离为$$ 0 $$的节点$$ i $$，其向上权值和为$$ up(i,0) = 0 $$。

$$ (2) $$向下可达的所有节点的权值和：

设$$ down(i,j) $$为游荡距离为$$ j $$的节点$$ i $$，向下可以到达的所有节点的权值之和，则有$$ down(i,j) = down(leftChild_i,j-1)+down(rightChild_i,j-1)+v_{leftChild-i}+v_{rightChild-i} $$，即游荡距离为$$ j $$的节点$$ i $$，其向下可达的权值和，等于游荡距离为$$ j-1 $$的左右孩子节点$$ leftChild_i $$和$$ rightChild_i $$的向下可达权值和，与左右孩子节点自己的权值的总和。在上图中可以看出，游荡距离为$$ 2 $$的节点$$ 4 $$，其向下权值和$$ down(4,2) $$，恰好等于游荡距离为$$ 1 $$的节点$$ 7 $$、$$ 8 $$的向下权值和，与节点$$ 7 $$、$$ 8 $$的权值的总和，即$$ down(4,2) = down(7,1)+down(8,1)+v_7+v_8 $$。

对于游荡距离为$$ 0 $$的节点$$ i $$，其向下权值和为$$ down(i,0) = 0 $$。

根据$$ (1) $$和$$ (2) $$两个部分，可以得出游荡距离为$$ j $$的节点$$ i $$的最大权值$$ f(i,j) = up(i,j)+down(i,j)+v_i $$。

最终在所有$$ f(i,j) $$中选择最大值作为返回结果（其中$$ i,j \in [0,n) $$）。该算法的时间复杂度是$$ O(n^2) $$。

--------

#### Cow Travelling

* http://train.usaco.org/TESTDATA/MAR08.ctravel.htm

--------

#### 源码

[MaxBinaryTreeRadiusSum.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MaxBinaryTreeRadiusSum.h)

[MaxBinaryTreeRadiusSum.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MaxBinaryTreeRadiusSum.cpp)

#### 测试

[MaxBinaryTreeRadiusSumTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MaxBinaryTreeRadiusSumTest.cpp)
