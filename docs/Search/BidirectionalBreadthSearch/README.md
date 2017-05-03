<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/Search/BidirectionalBreadthSearch.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/Search/BidirectionalBreadthSearch.cpp)


--------

<div>
<h1 align="center">Bidirectional Breadth Search</h1>
<h1 align="center">双向广度搜索</h1>
<br>
问题： <br>
&emsp;&emsp;在\(m×n\)的二维方格图\(s\)中用双向广度搜索从\(beg\)点移动到\(end\)点。 <br>
<br>
解法： <br>
&emsp;&emsp;双向广度优先搜索是在广度优先搜索基础上的一个变种，搜索速度更快。该算法从\(beg\)和\(end\)两个点开始，同时进行广度优先搜索，两边的点在某一处相遇，即可得到一条从\(beg\)到\(end\)的路径。 <br>
&emsp;&emsp;初始时将\(beg\)和\(end\)分别加入两个队列\(begqueue\)和\(endqueue\)中。每次从\(begqueue\)或\(endqueue\)队列中取出头节点\(x\)进行访问，访问后将\(x\)染成红色（\(x \epsilon begqueue\)）或绿色（\(x \epsilon endqueue\)）。若\(x\)取出后发现其已被一个队列染色过，而又将染成另一种颜色，则说明两个队列在此处相遇，算法结束。 <br>
&emsp;&emsp;在下面这个\(m = 5\)，\(n = 4\)的二维方格\(s\)中，从\(beg = [1,0]\)移动到\(end = [4,3]\)的过程如下： <br>
<p align="center"><img src="../res/BidirectionalBreadthSearch1.png" /></p>
&emsp;&emsp;对于二维方格\(s\)，广度优先搜索从\(beg\)点遍历到\(end\)点的过程一般是从\(beg\)向四周发散开，一直到达\(end\)点： <br>
<p align="center"><img src="../res/BidirectionalBreadthSearch2.png" /></p>
&emsp;&emsp;而双向广度优先搜索则是从\(beg\)和\(end\)两个点分别发散开，在中间相遇： <br>
<p align="center"><img src="../res/BidirectionalBreadthSearch3.png" /></p>
&emsp;&emsp;双向广度搜索的时间复杂度与广度优先搜索一样，也是\(O(m×n)\)。 <br>
</div>


--------
--------
