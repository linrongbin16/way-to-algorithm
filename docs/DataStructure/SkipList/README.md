<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Skip List - 跳跃表

--------

#### 跳跃表

跳跃表是一种随机化链表数据结构，其添加、删除、查找的时间复杂度与平衡树/二叉查找树的时间复杂度相同$$ O(log_2 n) $$。相比平衡树，跳跃表的实现方式更简单，实际应用中对并发的支持更好（内部多条链表可以分别由不同线程操作），但占更多内存。

下图是一个典型的跳跃表：

![SkipList1.png](../res/SkipList1.png)

#### 查找

在跳跃表中查找元素$$ x $$时，从最高层链表向下到最低层链表，更高一层链表充当了下一层链表的快速跑到。

从第一个节点的最高层链表$$ high $$开始，向右移动找到第一个节点$$ e $$满足$$ e \geq x $$或$$ e = NIL $$。若$$ e = x $$则查找结束；若$$ e \gt x $$或$$ e = NIL $$则退回上一个查找位置，然后移动到下一层链表，再递归的继续向右移动找到第一个满足$$ e' \geq x $$或$$ e' = NIL $$的节点。若直到最低层链表仍无法找到元素$$ x $$则说明该跳跃表中不存在该元素。

以上图中的跳跃表为例，查询元素$$ 6 $$的过程如下图所示：

![SkipList2.png](../res/SkipList2.png)

查询过程中，在$$ h_{1} $$链表中经历了节点$$ [1] $$，在$$ h_{2} $$链表中经历了节点$$ [1, 4] $$，在$$ h_{3} $$链表中经历了节点$$ [4] $$，在$$ h_{4} $$链表中经历了节点$$ [4, 6] $$最终找到元素$$ 6 $$。

查询元素$$ 9 $$的过程如下图所示：

![SkipList3.png](../res/SkipList3.png)

查询过程中，在$$ h_{1} $$链表中经历了节点$$ [1] $$，在$$ h_{2} $$链表中经历了节点$$ [1, 4, 7] $$，在$$ h_{3} $$链表中经历了节点$$ [7] $$，在$$ h_{4} $$链表中经历了节点$$ [7, 8] $$最终无法找到元素$$ 9 $$。

--------

#### Skip Lists

* https://www.cl.cam.ac.uk/teaching/0506/Algorithms/skiplists.pdf

--------

#### 源码

[SkipList.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/SkipList.h)

[SkipList.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/SkipList.cpp)

#### 测试

[SkipListTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/SkipListTest.cpp)

