* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearch.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/BreadthFirstSearch.cpp)

--------

### Breadth First Search
### 广度优先搜索
<div>
问题：
<p id="i">用广度优先搜索从图\(G\)的节点\(beg\)开始，遍历图\(G\)中的所有节点。 </p>
解法：
<p id="i">在图\(G\)中，假设节点\(i\)的邻节点集合为\(V_i\)，类似于二叉树的先序遍历，对于图中的任意节点\(i\)，总是优先访问节点\(i\)本身，然后访问该节点的邻节点集合\(V_i\)中的所有节点，访问结束之后，再继续递归的对所有邻节点重复该遍历操作，直到没有更多的节点可以搜索，算法结束。 </p>
<p id="i">在整个遍历过程中，为了避免重复的访问一个节点，在访问了某个节点\(i\)之后，我们将它染成红色（实际编码中，可以设置一个数组\(visited\)，通过\(visited_i = true \mid false\)来标记某个节点\(i\)时候被访问过）。下面演示从无向图\(G\)中的节点\(0\)开始进行广度优先搜索过程： </p>
<p id="c"><img src="../res/BreadthFirstSearch1.png" /></p>
<p id="i">\((1)\)访问节点\(0\)本身，将它染成红色，继续遍历其邻节点\( \{1, 5\} \)； </p>
<p id="i">\((2)\)访问节点\(1\)本身，将它染成红色，继续遍历其邻节点\( \{0, 2, 3\} \)（由于节点\(0\)已经为红色，因此不再考虑该节点）； </p>
<p id="c"><img src="../res/BreadthFirstSearch2.png" /></p>
<p id="i">\((3)\)访问节点\(2\)本身，将它染成红色，继续遍历其邻节点\( \{1, 3, 5\} \)（由于节点\(1\)已经为红色，因此不再考虑该节点）； </p>
<p id="c"><img src="../res/BreadthFirstSearch3.png" /></p>
<p id="i">\((4)\)访问节点\(3\)本身，将它染成红色，继续遍历其邻节点\( \{2, 4\} \)（由于节点\(2\)已经为红色，因此不再考虑该节点）； </p>
<p id="c"><img src="../res/BreadthFirstSearch4.png" /></p>
<p id="i">\((5)\)之后的所有节点都已经被访问过，只要返回递归即可，算法结束； </p>
<p id="i">广度优先搜索的时间复杂度是\(O(n)\)。 </p>
</div>

<br>
广度优先搜索：
* https://en.wikipedia.org/wiki/Breadth-first_search
