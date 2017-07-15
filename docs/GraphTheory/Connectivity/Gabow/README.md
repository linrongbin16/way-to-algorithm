* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Gabow.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Gabow.cpp)

--------

### Gabow
### Gabow算法
<div>
问题：
<p id="i">用Gabow算法求有向图\(G\)的强连通分支。 </p>
解法：
<p id="i">Gabow算法是Tarjan算法一个变种，区别在于low值（详见<Tarjan>）的处理方式，Gabow算法分为\(2\)个步骤：</p>
<p id="i">\((1)\)对图\(G\)中的所有节点进行深度优先搜索，计算每个遍历到的节点的\(low\)值，并将其压入栈\(Stack\)中；</p>
<p id="i">\((2)\)依次从栈\(Stack\)中取出每个节点，并放入初始为空的集合\(S\)中。对于刚刚进入集合的节点\(i\)，若该节点为强连通分支的根节点，则当前集合\(S\)中的所有节点属于一个强连通分支。将它们全部取出作为一个强连通分支，将集合\(S\)清空，然后继续从栈\(Stack\)中取出节点，重复该操作。 </p>
<p id="i">Tarjan算法在节点数量为\(N\)的有向图上的时间复杂度为\(O(N)\)。</p>

</div>
