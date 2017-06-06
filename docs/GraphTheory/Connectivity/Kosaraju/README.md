* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Kosaraju.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Connectivity/Kosaraju.cpp)

--------

### Kosaraju
### Kosaraju算法
<div>
问题：
<p id="i">用Kosaraju算法求有向图\(G\)的强连通分支。 </p>
解法：
<p id="i">首先求出有向图\(G\)的逆图\(G'\)，然后对\(G'\)进行拓扑排序。按照拓扑排序中节点顺序，依次对每个节点进行深度优先搜索。每一次深度优先搜索的过程中，遍历到的所有节点属于同一个强连通分支。 </p>
<p id="i">下面用图\(G\)进行演示：</p>
</div>
