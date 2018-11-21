<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# 2-SAT - 2-SAT问题

--------

#### 问题

有$$ n $$个成员的集合$$ s = [x_{0}, x_{1}, \dots, x_{n-1}] $$，其中每个成员的值为$$ 0 $$或$$ 1 $$。任意两个成员$$ x_i, x_j $$之间有以下几种约束关系：

$$ x_i \bigvee x_j = 1 $$表示$$ x_i, x_j $$中至少有一个为$$ 1 $$（或关系，有1则1）；

$$ x_i \bigwedge x_j = 0 $$表示$$ x_i, x_j $$中至少有一个为$$ 0 $$（与关系，有0则0）；

$$ x_i \bigoplus x_j = 1 $$表示$$ x_i, x_j $$中一个为$$ 0 $$，另一个为$$ 1 $$（异或关系，相同为0，相异为1）；

给定包含$$ n $$个成员的集合$$ s $$以及一组约束关系，求一个满足集合$$ s $$的中所有成员的都满足该约束关系。该类问题称为2-SAT问题。

#### 解法

将2-SAT问题转化为有向图的强连通分支问题。

首先构造拥有$$ 2 \times n $$个顶点的有向图$$ G = <V,E> $$，每对顶点$$ v_{i}, v_{i+1} $$对应集合$$ s $$中的成员$$ x_{i} $$的值$$ 0 $$和$$ 1 $$。

对于约束$$ x_i \bigvee x_j = 1 $$，构建边$$ e_{i,j+1}, e_{j,i+1} $$，表示：若选择顶点$$ v_{i} $$则必选择顶点$$ v_{j+1} $$（成员$$ x_{i} = 0 $$则必然有$$ x_{j} = 1 $$），若选择顶点$$ v_{j} $$则必选择顶点$$ v_{i+1} $$（成员$$ x_{j} = 0 $$则必然有$$ x_{i} = 1 $$）。

对于约束$$ x_i \bigwedge x_j = 0 $$，构建边$$ e_{i+1,j}, e_{j+1,i} $$，表示：若选择顶点$$ v_{i+1} $$则必选择顶点$$ v_{j} $$（成员$$ x_{i} = 1 $$则必然有$$ x_{j} = 0 $$），若选择顶点$$ v_{j+1} $$则必选择顶点$$ v_{i} $$（成员$$ x_{j} = 1 $$则必然有$$ x_{i} = 0 $$）。

对于约束$$ x_i \bigoplus x_j = 1 $$，构建边$$ e_{i,j+1}, e_{i+1,j}, e_{j,i+1}, e_{j+1,i} $$，表示：若选择顶点$$ v_{i} $$则必选择顶点$$ v_{j+1} $$（成员$$ x_{i} = 0 $$则必然有$$ x_{j} = 1 $$），若选择顶点$$ v_{i+1} $$则必选择顶点$$ v_{j} $$（成员$$ x_{i} = 1 $$则必然有$$ x_{j} = 0 $$），若选择顶点$$ v_{j} $$则必选择顶点$$ v_{i+1} $$（成员$$ x_{j} = 0 $$则必然有$$ x_{i} = 1 $$），若选择顶点$$ v_{j+1} $$则必选择顶点$$ v_{i} $$（成员$$ x_{j} = 1 $$则必然有$$ x_{i} = 0 $$）。

显然特定的约束条件可以构造出特定的有向图$$ G = <V,E> $$，图中让选取某个顶点$$ v $$时，为了满足约束条件必然要选择其他对应的顶点。2-SAT构造的有向图中的所有强连通分支即为2-SAT问题的所有解，该问题转化为有向图的强连通分支求解，应用Kosaraju算法或Tarjan算法即可。

解决2-SAT问题的时间复杂度与所使用强连通分支算法的时间复杂度相同。



--------

#### 源码

[TwoSatisfiability.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StrongConnectedComponents/TwoSatisfiability.h)

[TwoSatisfiability.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StrongConnectedComponents/TwoSatisfiability.cpp)

#### 测试

[TwoSatisfiabilityTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/GraphTheory/StrongConnectedComponents/TwoSatisfiabilityTest.cpp)
