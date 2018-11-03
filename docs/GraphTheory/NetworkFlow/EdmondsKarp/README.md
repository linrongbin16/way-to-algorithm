<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Edmonds Karp - Edmonds Karp算法（最短路径增广算法）

--------

#### 问题

用Edmond Karp算法求网络流$$ G $$的最大流，$$ G = <V,E> $$是单源点、单汇点，边的容量为正整数。

#### Ford–Fulkerson方法

Ford-Fulkerson方法是用于求解最大流的方法（并不是算法），它通过寻找增广路径（Argumenting Path）来求最大流，但具体寻找的方法有多种算法实现。

网络流中边$$ e_{u,v} $$的剩余容量（Residual Capacity）是：

$$
c_f (u,v) = c(u,v) - f(u,v)
$$

边的剩余容量定义了剩余网络（Residual Network）$$ G_f = <V, E_f>  $$，表示该网络的可用容量。

网络中每新增一个流就会占用一部分剩余容量，新增的流从源点$$ Source $$出发到达汇点$$ Sink $$，中途经过的所有边的剩余容量都被该流占用，称这样的流为增广路径。

Ford-Fulkerson方法的主要过程如下：

$$ (1) $$ 初始时将网络$$ G $$看作一个未被使用的原始剩余网络，该网络的最大流的值初始化为$$ flow = 0 $$；

$$ (2) $$ 尝试从当前剩余网络中找到一条增广路径，该路径经过的所有边的最小的剩余容量$$ c_{min} $$即为这整条流可以使用的容量（就像木桶能够装的水由最短的那块木板决定一样）。使用该路径后最大流的值增大为$$ flow = flow + c_{min} $$，并将该路径经过的边的容量都减去$$ c_{min} $$（更新所有经过的边的剩余容量）；

$$ (3) $$ 

#### Edmonds Karp算法

按照强连通分支的定义，任意两顶点可以相互到达。首先按照DFS顺序遍历所有顶点，然后再按照这个遍历的逆序DFS尝试搜索所有顶点，显然逆序时某顶点按照DFS可以搜索到的所有顶点，都和它处于同一强连通分支。

算法过程分为$$ 3 $$步：

$$ (1) $$ 初始化空队列$$ queue $$；

$$ (2) $$ （类似DFS和二叉树的后续遍历）遍历图$$ DG $$所有顶点$$ v_i $$，对每个顶点$$ v_i $$进行搜索操作：$$ 2.1) $$ 若顶点$$ v_i $$已被访问过则跳过，否则将$$ v_i $$染红并加入队列$$ queue $$；$$ 2.2) $$ 递归的搜索顶点$$ v_i $$的所有邻节点（设为$$ v_j $$），同样做该搜索操作；

$$ (3) $$ （类似DFS和并查集算法）初始时，令队列中所有顶点$$ v_i $$属于根节点为$$ v_i $$即自己的强连通分支。逆序遍历队列$$ queue $$所有顶点，对每个顶点$$ v_i $$进行分配操作：$$ 3.1) $$ 若顶点$$ v_i $$所属的强连通分支的根节点不是自己则跳过；$$ 3.2) $$ 递归的搜索顶点$$ v_i $$的所有邻节点（设为$$ v_j $$），若$$ v_j $$所属的强连通分支的根节点不是$$ v_j $$自己则跳过，否则将$$ v_j $$分配给以$$ v_i $$为根节点的强连通分支；

第$$ (3) $$步结束后，每个顶点都被分配给某个强连通分支，设$$ v_i $$所属的强连通分支的根节点为$$ v_j $$，则只有当$$ v_i = v_j $$时才说明$$ v_i $$为根节点，否则要递归的继续查询。

最终图$$ DG $$的所有顶点都被分配到某个强连通分支。

下图演示有向图的搜索操作和分配操作：

![EdmondKarp1.png](../res/EdmondKarp1.png)

上图进行DFS搜索后，得到的队列为$$ [0, 4, 3, 1, 2, 7, 6, 5, 8] $$，逆序为$$ [8, 5, 6, 7, 2, 1, 3, 4, 0] $$。第$$ (2) $$步的DFS搜索过程如下图：

![EdmondKarp2.png](../res/EdmondKarp2.png)

按照逆序DFS遍历所有顶点，得到两个强连通分支$$ [8] $$和$$ [0, 1, 2, 3, 4, 5, 6, 7] $$：

![EdmondKarp3.png](../res/EdmondKarp3.png)

该算法时间复杂度为$$ O(|V|) $$。

--------

#### Strongly-Connectivity Algorithm

* https://pdfs.semanticscholar.org/1912/4d1b464fdbb4e9dffb1c915468ae201b5df0.pdf

#### Introduction To Algorithms

* [VI.Graph Algorithms - 22.Elementary Graph Algorithms - 22.5.Strongly connected components](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[EdmondKarp.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/EdmondKarp.h)

[EdmondKarp.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/EdmondKarp.cpp)

#### 测试

[EdmondKarpTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/EdmondKarpTest.cpp)
