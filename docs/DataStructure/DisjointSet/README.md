<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Disjoint Set - 并查集

--------

#### 描述

现在有一个拥有$$ n $$个成员的集合$$ s = \{ x_0, x_1, x_2, \cdots , x_{n-1} \} $$，依次声明$$ x_i $$和$$ x_j $$属于或不属于同一个家族，最终将所有成员分为两个家庭。每个家族中只有唯一一个祖先，其余的成员必然有一个父亲，递归的向上查找，除了祖先自己，其余每个成员所属的祖先只有$$ 2 $$种可能。并查集是一种适合成员分类的高效树形数据结构，支持快速分类和查询。

设$$ father[x] $$为$$ x $$节点的父节点，当$$ father[x] = x $$时称$$ x $$为祖先节点，它是家族中所有其他成员共同的唯一祖先，设$$ ancestor[x] $$是$$ x $$的祖先节点。

对于拥有$$ 10 $$个成员的集合$$ s = \{ 0,1,2,3,4,5,6,7,8,9 \} $$，将其分成两个家庭$$ A $$和$$ B $$。初始时令每个成员的父亲都是自己，如图所示：

![DisjointSet1.png](../res/DisjointSet1.png)

当声明$$ 2 $$个成员$$ x_i $$和$$ x_j $$（$$ x_i \le x_j $$）属于同一家庭，直接令$$ x_i $$的节点祖先为$$ x_j $$的父亲（也可以反过来），即$$ father[x_j] = ancestor[x_i] $$。这样的操作会使元素$$ x_j $$的最接近祖先节点，从而缩短了递归向上查找的路径长度，因此该操作也称为压缩路径。

下面对上图中的集合$$ s $$进行具体演示：

$$ (1) $$声明$$ 0 $$和$$ 4 $$属于同一家庭，比较$$ 0 $$和$$ 4 $$的祖宗节点，设置$$ father[4] = ancestor[0] = 0 $$，本文中我们取左节点的祖宗节点作为右节点的父节点；

![DisjointSet2.png](../res/DisjointSet2.png)

$$ (2) $$声明$$ 1 $$和$$ 9 $$节点属于同一家庭，设置$$ father[9] = ancestor[1] = 1 $$；

![DisjointSet3.png](../res/DisjointSet3.png)

$$ (3) $$声明$$ 0 $$和$$ 2 $$节点属于同一家庭，设置$$ father[2] = ancestor[0] = 0 $$；

![DisjointSet4.png](../res/DisjointSet4.png)

$$ (4) $$声明$$ 1 $$和$$ 3 $$节点属于同一家庭，设置$$ father[3] = ancestor[1] = 1 $$；

![DisjointSet5.png](../res/DisjointSet5.png)

$$ (5) $$声明$$ 3 $$和$$ 5 $$节点属于同一家庭，设置$$ father[5] = ancestor[3] = 1 $$；

![DisjointSet6.png](../res/DisjointSet6.png)

$$ (6) $$声明$$ 6 $$和$$ 8 $$节点属于同一家庭，设置$$ father[8] = ancestor[6] = 6 $$；

![DisjointSet7.png](../res/DisjointSet7.png)

$$ (7) $$声明$$ 2 $$和$$ 6 $$节点属于同一家庭，设置$$ father[6] = ancestor[2] = 0 $$；

![DisjointSet8.png](../res/DisjointSet8.png)

$$ (8) $$声明$$ 1 $$和$$ 7 $$节点属于同一家庭，设置$$ father[7] = ancestor[1] = 1 $$；

![DisjointSet9.png](../res/DisjointSet9.png)

合并两节点$$ x $$和$$ y $$时，根据固定规则设置$$ father[y] = ancestor[x] $$（或者相反）；查询节点$$ x $$的祖宗节点时，若$$ father[x] \neq ancestor[x] $$则设置$$ father[x] = ancestor[x] $$。并查集的分类、查询操作的时间复杂度接近$$ O(1) $$。

--------

#### 源码

[DisjointSet.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/DisjointSet.h)

[DisjointSet.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/DisjointSet.cpp)

#### 测试

[DisjointSetTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/DisjointSetTest.cpp)
