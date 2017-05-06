<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/InorderTraverse.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/InorderTraverse.cpp)


--------

<div>
<h1 align="center">Depth First Search</h1>
<h1 align="center">深度优先搜索</h1>
<br>
问题： <br>
&emsp;&emsp;深度优先搜索是指对于图\(G\)的任意节点\(i\)，总是优先搜索它的其中一个邻节点。 <br>
<br>
解法： <br>
&emsp;&emsp;从二叉树根节点\(root\)开始，递归的对二叉树上的每个节点\(i\)，总是优先访问节点\(i\)本身，然后访问\(i\)的左孩子节点，最后访问\(i\)的右孩子节点。如图： <br>
<p align="center"><img src="../res/DepthFirstSearch1.png" /></p>
&emsp;&emsp;先序遍历的时间复杂度是O(n)。 <br>
</div>
<br>
深度优先搜索：
* [https://en.wikipedia.org/wiki/Depth-first_search](https://en.wikipedia.org/wiki/Depth-first_search)


--------
--------
