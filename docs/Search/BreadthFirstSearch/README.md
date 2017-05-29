<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/Search/BreadthFirstSearch.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/Search/BreadthFirstSearch.cpp)


--------

<div>
<h1 align="center">Breadth First Search</h1>
<h1 align="center">广度优先搜索</h1>
<br>
问题： <br>
&emsp;&emsp;在\(m \times n\)的二维方格图\(s\)中从\(beg\)点移动到\(end\)点。 <br>
<br>
解法： <br>
&emsp;&emsp;广度优先搜索是优先搜索二维方格图\(s\)中每个节点的相邻节点，与之相对的深度优先搜索则会沿着节点的一个相邻节点试图走到最远。 <br>
&emsp;&emsp;例如在下面这个\(4 \times 5\)二维方格\(s\)中从\(beg = [0,1]\)（本书中所有的矩阵索引\([i,j]\)，\(i\)表示横行数字，\(j\)表示竖行数字）移动到\(end = [3,4]\)。初始时将起点\(beg\)加入等待搜索的队列\(queue\)中，之后每次从\(queue\)中取出头节点\(e\)，访问\(e\)四周从未被访问的邻节点，并将邻节点加入\(queue\)中。访问过一个节点之后就将其染为红色，避免以后重复访问。 <br>
<p align="center"><img src="../res/BreadthFirstSearch1.png" /></p>
&emsp;&emsp;图中的队列左边为头部，右边为尾部，新访问的节点插入队列尾部，每次从队列中取出头节点\(e\)，若有\(e = beg\)则搜索成功，算法结束。如果需要额外的获取从\(beg\)点到\(end\)点的路径，则需要在遍历时标记每个节点的上一个点，即“父节点”，最终可以从\(end\)通过父节点指针逆向的找到一条回到\(beg\)点的路径。 <br>
&emsp;&emsp;该算法下时间复杂度为\(O(m \times n)\)。 <br>
</div>


--------
--------
