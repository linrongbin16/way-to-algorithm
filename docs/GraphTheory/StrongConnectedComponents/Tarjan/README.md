<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Tarjan - Tarjan算法

--------

#### 问题

用Tarjan算法求有向图$$ DG $$的所有强连通分支。

#### 解法

Tarjan算法通过定义强连通分支的根节点，来求出有向图$$ DG $$的所有强连通分支。有向图$$ DG = <V,E> $$中一个强连通分支中的根节点是该强连通分支中下标最小的顶点，也是该强连通分支中所有顶点通过DFS能够搜索到的下标最小的顶点。

设$$ index $$为顶点下标，$$ lowlink $$为该顶点所属强连通分支的根节点下标，显然属于同一个强连通分支的所有顶点$$ lowlink $$值相等。同一个强连通分支中的所有顶点满足$$ index_i \geq lowlink_i $$，强连通分支的根节点满足$$ index_{root} = lowlink_{root} $$，其他顶点则满足$$ index_i \gt lowlink_i $$。

Tarjan算法按照以下几步操作：

$$ (1) $$ 初始时设任意顶点$$ v_i $$的强连通分支的根节点指向自己，即$$ father(i) = i $$，Tarjan的根节点和Kosaraju中并查集的父节点含义完全相同，因此也用父指针表示；

$$ (2) $$ 用DFS算法搜索有向图$$ DG $$的所有顶点，得到每个顶点的$$ lowlink $$，并按照搜索顺序将顶点推入堆栈$$ Stack $$（先入后出）；

$$ (3) $$ 从堆栈$$ Stack $$中依次取出每个顶点（即逆序遍历DFS搜索到的所有顶点）$$ v_i $$，判断其是否为根节点（$$ index_i = lowlink_i $$）。若出栈顶点$$ v_i $$是根节点，则在$$ v_i $$之前出栈的且未分配到其他强连通分支的顶点（$$ father(j) = j $$的顶点$$ v_j $$即为未分配的顶点），都属于以$$ v_i $$为根节点的强连通分支，设置$$ father(j) = i $$；若出栈顶点$$ v_i $$不是根节点，则等待根节点$$ v_j $$，$$ v_i $$属于以$$ v_j $$为根节点的强连通分支；

该算法时间复杂度为$$ O(\| V \| + \| E \|) $$。

--------

#### Tarjan Algorithm

* https://rjlipton.files.wordpress.com/2009/10/dfs1971.pdf

#### Introduction To Algorithms

* [VI.Graph Algorithms - 22.Elementary Graph Algorithms - 22.5.Strongly connected components](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[Tarjan.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StrongConnectedComponents/Tarjan.h)

[Tarjan.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StrongConnectedComponents/Tarjan.cpp)

#### 测试

[TarjanTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StrongConnectedComponents/TarjanTest.cpp)
