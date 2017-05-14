<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../../)


--------

<div>
<h1 align="center">Knowledge Point</h1>
<h1 align="center">知识要点</h1>
<br>
子图（Subgraph）： <br>
&emsp;&emsp;一个所有顶点和边都属于图\(G\)的图，称为\(G\)的子图。 <br>
<br>
连通（Connectivity）： <br>
&emsp;&emsp;若图\(G\)中从顶点\(v_i\)到另一顶点\(v_j\)有路径相连，并且从\(v_j\)也可以移动到\(v_i\)，则称\(v_i\)和\(v_j\)是连通的（在无向图中，若\(v_i\)可以到达\(v_j\)，则显然\(v_j\)也可以到达\(v_i\)）。 <br>
<br>
连通图（Connected Graph）： <br>
&emsp;&emsp;若图\(G\)中从任意两个顶点\(v_i\)和\(v_j\)都是连通的，则称图\(G\)是连通图。 <br>
<br>
极大连通子图（Strong Components）： <br>
&emsp;&emsp;若图\(G\)中的子图\(S\)是一个连通图，且不论加入任意其他节点，都会使得子图\(S\)不再连通，则称\(S\)为极大连通子图。连通图的极大连通子图即为它自己，非连通图中存在多个极大连通子图。 <br>
<br>
连通分量（Connected Component）： <br>
&emsp;&emsp;无向图\(G\)的一个极大连通子图，连通分量中的任意节点\(v_i\)可以到达任意节点\(v_j\)，且\(v_j\)也可以到达\(v_i\)。 <br>
<br>
强连通分量（Strongly Connected Component）： <br>
&emsp;&emsp;有向图\(G\)的一个极大连通子图，强连通分量中的任意节点\(v_i\)可以到达任意节点\(v_j\)，且\(v_j\)也可以到达\(v_i\)。求强连通分量的算法有双向遍历后取交集、Tarjan算法、Kosaraju算法、Gabow算法 <br>
</div>


--------
--------
