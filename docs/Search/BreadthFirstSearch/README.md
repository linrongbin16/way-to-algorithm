<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Breadth First Search - 广度优先搜索

--------

#### 问题

在$$ n $$行$$ m $$列的的二维方格图$$ s = n \times m $$中从$$ beg $$点移动到$$ end $$点。

#### 解法

广度优先搜索是优先搜索二维方格图$$ s $$中每个节点的相邻节点，与之相对的深度优先搜索则会沿着节点的一个相邻节点试图走到最远。

例如在下面这个$$ 5 \times 4 $$二维方格$$ s $$中从$$ beg = [1,0] $$移动到$$ end = [4,3] $$。初始时将起点$$ beg $$加入待搜索节点的队列$$ queue $$中，之后每次从$$ queue $$中取出头节点$$ e $$，访问$$ e $$四周从未被访问的邻节点，并将邻节点加入$$ queue $$中。将每个节点加入$$ queue $$之前将其染为红色，避免重复访问。

![BreadthFirstSearch1.svg](../res/BreadthFirstSearch1.svg)

$$ (1) $$初始时将$$ beg = [1,0] $$染红并加入$$ queue $$；

$$ (2) $$从$$ queue $$中取出头节点$$ [1,0] $$，因$$ [1,0] \ne end $$，将其四周未被染红的节点$$ [0,0], [1,1], [2,0] $$染红并加入$$ queue $$，图中$$ queue $$的左边为头部，右边为尾部，新访问的节点插入队列尾部，每次从队列中取出头节点$$ e $$：

![BreadthFirstSearch2.svg](../res/BreadthFirstSearch2.svg)

$$ (3) $$从$$ queue $$中取出头节点$$ [0,0] $$，因$$ [0,0] \ne end $$，将其四周未被染红的节点$$ [0,1] $$染红并加入$$ queue $$；

![BreadthFirstSearch3.svg](../res/BreadthFirstSearch3.svg)

![BreadthFirstSearch4.svg](../res/BreadthFirstSearch4.svg)

$$

\cdots

$$

![BreadthFirstSearch11.svg](../res/BreadthFirstSearch11.svg)

$$ (4) $$从$$ queue $$中取出头节点$$ [1,3] $$，因$$ [1,3] \ne end $$，其四周的节点都已经被染红，因此不加入任何新节点；

![BreadthFirstSearch12.svg](../res/BreadthFirstSearch12.svg)

$$

\cdots

$$

![BreadthFirstSearch20.svg](../res/BreadthFirstSearch20.svg)

![BreadthFirstSearch21.svg](../res/BreadthFirstSearch21.svg)

$$ (5) $$从$$ queue $$中取出头节点$$ [4,3] $$，因$$ [4,3] = end $$，算法结束；

本章的图搜索中，一个节点通常只需要搜索一次，常用染色来标记一个节点是否被搜索过，染红后就不会再放入待搜索队列$$ queue $$中。用类似“父节点”指针来记录搜索时遇到节点的上一个节点，搜索完成时通过“父节点”逆向的找到一条从$$ end $$回到$$ beg $$的路径。

该算法的时间复杂度为$$ O(n \times m) $$。

--------

#### 源码

[BreadthFirstSearch.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BreadthFirstSearch.h)

[BreadthFirstSearch.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BreadthFirstSearch.cpp)

#### 测试

[BreadthFirstSearchTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BreadthFirstSearchTest.cpp)
