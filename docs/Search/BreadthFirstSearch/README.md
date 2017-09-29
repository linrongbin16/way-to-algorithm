# Breadth First Search - 广度优先搜索

--------

#### 问题

在$$ m \times n $$的二维方格图$$ s $$中从$$ beg $$点移动到$$ end $$点。

#### 解法

广度优先搜索是优先搜索二维方格图$$ s $$中每个节点的相邻节点，与之相对的深度优先搜索则会沿着节点的一个相邻节点试图走到最远。

例如在下面这个$$ 4 \times 5 $$二维方格$$ s $$中从$$ beg = [0,1] $$移动到$$ end = [3,4] $$。初始时将起点$$ beg $$加入等待搜索的队列$$ queue $$中，之后每次从$$ queue $$中取出头节点$$ e $$，访问$$ e $$四周从未被访问的邻节点，并将邻节点加入$$ queue $$中。将每个节点加入$$ queue $$之前将其染为红色，避免重复访问。

![BreadthFirstSearch1.svg](../res/BreadthFirstSearch1.svg)

$$ (1) $$ 初始时将$$ beg = [0,1] $$染红并加入$$ queue $$；

![BreadthFirstSearch2.svg](../res/BreadthFirstSearch2.svg)

$$ (2) $$ 从$$ queue $$中取出头节点$$ [0,1] $$，因$$ [0,1] \neq end $$，将其四周未被染红的节点$$ [0,0] $$、$$ [1,1] $$、$$ [0,2] $$染红并加入$$ queue $$；

![BreadthFirstSearch3.svg](../res/BreadthFirstSearch3.svg)

$$ (3) $$ 从$$ queue $$中取出头节点$$ [0,0] $$，因$$ [0,0] \neq end $$，将其四周未被染红的节点$$ [1,0] $$染红并加入$$ queue $$；

![BreadthFirstSearch4.svg](../res/BreadthFirstSearch4.svg)

![BreadthFirstSearch5.svg](../res/BreadthFirstSearch5.svg)

![BreadthFirstSearch6.svg](../res/BreadthFirstSearch6.svg)

![BreadthFirstSearch7.svg](../res/BreadthFirstSearch7.svg)

![BreadthFirstSearch8.svg](../res/BreadthFirstSearch8.svg)

![BreadthFirstSearch9.svg](../res/BreadthFirstSearch9.svg)

![BreadthFirstSearch10.svg](../res/BreadthFirstSearch10.svg)

![BreadthFirstSearch11.svg](../res/BreadthFirstSearch11.svg)

![BreadthFirstSearch12.svg](../res/BreadthFirstSearch12.svg)

$$ (4) $$ 从$$ queue $$中取出头节点$$ [3,1] $$，因$$ [3,1] \neq end $$，其四周的节点都已经被染红，因此不做任何操作；

![BreadthFirstSearch13.svg](../res/BreadthFirstSearch13.svg)

![BreadthFirstSearch14.svg](../res/BreadthFirstSearch14.svg)

![BreadthFirstSearch15.svg](../res/BreadthFirstSearch15.svg)

![BreadthFirstSearch16.svg](../res/BreadthFirstSearch16.svg)

![BreadthFirstSearch17.svg](../res/BreadthFirstSearch17.svg)

![BreadthFirstSearch18.svg](../res/BreadthFirstSearch18.svg)

![BreadthFirstSearch19.svg](../res/BreadthFirstSearch19.svg)

![BreadthFirstSearch20.svg](../res/BreadthFirstSearch20.svg)

![BreadthFirstSearch21.svg](../res/BreadthFirstSearch21.svg)

$$ (5) $$ 从$$ queue $$中取出头节点$$ [3,4] $$，因$$ [3,4] = end $$，算法结束；

上列图中的队列$$ queue $$中，左边为头部，右边为尾部，新访问的节点插入队列尾部，每次从队列中取出头节点$$ e $$。如果需要额外的获取从$$ beg $$点到$$ end $$点的完整路径，需要在遍历时标记每个节点的上一个点，即“父节点”，最终可以从$$ end $$通过父节点指针逆向的找到一条回到$$ beg $$点的路径。

该算法下时间复杂度为$$ O(m \times n) $$。

--------

#### 源码

[import, lang:"c_cpp"](../../../src/Search/BreadthFirstSearch.hpp)

#### 测试

[import, lang:"c_cpp"](../../../src/Search/BreadthFirstSearch.cpp)
