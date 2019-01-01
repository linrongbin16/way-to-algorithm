<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Skip List - 跳跃表

--------

#### 跳跃表

跳跃表是一种随机化链表数据结构，其添加、删除、查找的时间复杂度与平衡树/二叉查找树的时间复杂度相同$$ O(log_2 n) $$。相比平衡树，跳跃表的实现方式更简单，实际应用中对并发的支持更好（内部多条链表可以分别由不同线程操作），但占更多内存。

下图是一个典型的跳跃表：

![SkipList1.png](../res/SkipList1.png)

--------

#### Skip Lists

* https://www.cl.cam.ac.uk/teaching/0506/Algorithms/skiplists.pdf

--------

#### 源码

[SkipList.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/SkipList.h)

[SkipList.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/SkipList.cpp)

#### 测试

[SkipListTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/SkipListTest.cpp)

