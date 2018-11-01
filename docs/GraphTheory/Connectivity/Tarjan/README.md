<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Tarjan - Tarjan算法

--------

#### 问题

用Tarjan算法求有向图$$ DG $$的所有强连通分支。

#### 解法

Tarjan算法定义了强连通分支的根节点的概念，来求出有向图$$ DG $$的所有强连通分支。设有向图$$ DG = <V,E> $$的顶点下标范围为$$ [0, 1, 2, \dots, |V|-1] $$，每个顶点拥有唯一下标。一个强连通分支中的根节点是该强连通分支中下标最小的顶点，同事也是强连通分支中任意顶点能够DFS搜索到的下标最小的顶点。

设每个顶点的$$ index $$表示其下标，$$ lowlink $$表示其所属强连通分支的根节点的下标。显然属于同一个强连通分支的所有顶点$$ lowlink $$值相等。同一个强连通分支中的任意顶点一定满足$$ index_i \geq lowlink_i $$，强连通分支的根节点一定满足$$ index_i = lowlink_i $$，其他顶点则满足$$ index_i \gt lowlink_i $$。

算法过程分为以下几步：

$$ (1) $$ 用DFS算法搜索有向图$$ DG $$的所有顶点，标记出每个顶点的$$ lowlink $$值，并按照搜索顺序将顶点推入堆栈$$ Stack $$（先入后出）；

$$ (2) $$ 从堆栈$$ Stack $$中依次取出每个顶点（其实是逆序的遍历之前DFS搜索到的所有顶点），判断其是否为根节点（$$ index = lowlink $$）。若出栈顶点$$ v_i $$是根节点，则在$$ v_i $$之前出栈的且不属于其他强连通分支的顶点，都属于以$$ v_i $$为根节点的强连通分支；若出栈顶点$$ v_i $$不是根节点，则等待后面出栈的根节点$$ v_j $$，属于以$$ v_j $$为根节点的强连通分支；

该算法时间复杂度为$$ O(|V| + |E|) $$。

--------

#### Tarjan Algorithm

* https://rjlipton.files.wordpress.com/2009/10/dfs1971.pdf

#### Introduction To Algorithms

* [VI.Graph Algorithms - 22.Elementary Graph Algorithms - 22.5.Strongly connected components](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[Tarjan.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Tarjan.h)

[Tarjan.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Tarjan.cpp)

#### 测试

[TarjanTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/TarjanTest.cpp)
