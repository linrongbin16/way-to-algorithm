* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearch.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearch.cpp)

--------

### Breadth First Search(BFS)
### 广度优先搜索
<div>
问题：
<p id="i">用广度优先搜索从图\(G\)的节点\(beg\)开始，遍历图\(G\)中的所有节点。 </p>
解法：
<p id="i">在图\(G\)中，假设节点\(i\)的邻节点集合为\(V_i\)，对于图中的任意节点\(i\)，在访问节点\(i\)之后，总是优先访问该节点的邻节点集合\(V_i\)中的所有节点，然后才继续访问其他节点。 </p>
<p id="i">广度优先遍历需要一个队列\(queue\)来存储那些等待访问而尚未被访问的节点，在遍历过程中，为了避免重复的访问一个节点，当某个节点\(i\)加入\(queue\)时我们将其染成红色。下面演示从无向图\(G\)中的节点\(0\)开始进行广度优先搜索过程： </p>
<p id="i">\((1)\)初始时从节点\(0\)开始，将它染红并加入\(queue\)中； </p>
<p id="i">\((2)\)从\(queue\)中取出头节点\(0\)进行访问，然后考虑其未被染色的邻节点\( \{1, 4, 5\} \)，将\( \{ 1, 4, 5 \}\)节点染红并加入\(queue\)中； </p>
<p id="i">\((3)\)从\(queue\)中取出头节点\(1\)进行访问，然后考虑其未被染色的邻节点\( \{2, 3\} \)，将\( \{ 2, 3 \} \)节点染红并加入\(queue\)中； </p>
<p id="i">\((4)\)从\(queue\)中取出头节点\(4\)进行访问，它没有未被染色的邻节点； </p>
<p id="i">\((5)\)从\(queue\)中取出头节点\(5\)进行访问，它没有未被染色的邻节点； </p>
<p id="i">\((6)\)从\(queue\)中取出头节点\(2\)进行访问，它没有未被染色的邻节点； </p>
<p id="i">\((7)\)从\(queue\)中取出头节点\(3\)进行访问，它没有未被染色的邻节点； </p>
<p id="i">\((8)\)队列\(queue\)为空，算法结束； </p>
<p id="i">广度优先搜索的时间复杂度是\(O(n)\)。 </p>
</div>

<br>
广度优先搜索：
* https://en.wikipedia.org/wiki/Breadth-first_search
