* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Tarjan.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Tarjan.cpp)

--------

### Tarjan
### Tarjan算法
<div>
问题：
<p id="i">用Tarjan算法求有向图\(G\)的强连通分支。 </p>
解法：
<p id="i">Tarjan算法中定义了概念“强连通分支的根节点”。对有向图\(G\)中的节点\(i\)（范围为\([0, n)\)），设置一个\(low_i\)值，表示从节点\(i\)出发进行DFS可以到达的所有节点中最小的节点标号。若节点\(i\)满足\(low_i = i\)，则该节点为强连通分支的根节点。</p>
<p id="i">Tarjan算法分为3个步骤：</p>
<p id="i">\((1)\)对图\(G\)中的所有节点进行深度优先搜索，计算每个遍历到的节点的\(low\)值，并将其压入栈\(Stack\)中；</p>
<p id="i">\((2)\)依次从栈\(Stack\)中取出每个节点，并放入初始为空的集合\(S\)中。对于刚刚进入集合的节点\(i\)，若该节点为强连通分支的根节点，则当前集合\(S\)中的所有节点属于一个强连通分支。将它们全部取出作为一个强连通分支，将集合\(S\)清空，然后继续从栈\(Stack\)中取出节点，重复该操作。 </p>
<p id="c"><img src="../res/Tarjan1.svg" /></p>
<p id="i">节点的low值分别为\([0_0, 0_1, 0_2, 0_3, 4_4, 5_5]\)，遍历顺序为\([0, 1, 3, 2, 4, 5]\)，依次压入栈后得到\(Stack = [5, 4, 2, 3, 1, 0]\)。 </p>
<p id="i">\((1)\)将节点\(5\)放入集合\(S = [5]\)，节点\(low_5 = 5\)，即节点\(5\)为强连通分支的根节点，因此\([5]\)为一个强连通分支，将集合\(S\)清空；</p>
<p id="i">\((2)\)将节点\(4\)放入集合\(S = [4]\)，节点\(low_4 = 4\)，即节点\(4\)为强连通分支的根节点，因此\([4]\)为一个强连通分支，将集合\(S\)清空；</p>
<p id="i">\((3)\)将节点\(2\)放入集合\(S = [2]\)，节点\(low_2 = 0\)，不做任何操作；</p>
<p id="i">\((4)\)将节点\(3\)放入集合\(S = [2, 3]\)，节点\(low_3 = 0\)，不做任何操作；</p>
<p id="i">\((5)\)将节点\(1\)放入集合\(S = [2, 3, 1]\)，节点\(low_1 = 0\)，不做任何操作；</p>
<p id="i">\((6)\)将节点\(0\)放入集合\(S = [2, 3, 1, 0]\)，节点\(low_0 = 0\)，即节点\(0\)为强连通分支的根节点，因此\([2, 3, 1, 0]\)为一个强连通分支，将集合\(S\)清空；</p>
<p id="i">\((7)\)栈\(Stack\)为空，算法结束；</p>
<p id="i">在有\(N\)个节点的有向图\(G\)上运行Tarjan算法的时间复杂度为\(O(N)\)。 </p>
</div>

Wikipedia:
* [https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm](https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm)
