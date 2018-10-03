<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Red Black Tree - 红黑树

--------

#### 红黑树

红黑树比AVL树的实际性能更好，AVL树的插入/删除操作需要从根节点遍历到叶子节点，再从叶子节点回到根节点，操作次数约是$$ 2 \times (log_2 n) $$。而红黑树的操作次数约是$$ log_2 n + 4 $$，面对较大的数据集时，红黑树的实际运行速度比AVL树快一倍。尽管它们插入/删除/查找的时间复杂度都是$$ O(log_2 n) $$。


--------

#### Red Black Tree

* http://faculty.cs.niu.edu/~freedman/340/340notes/340redblk.htm
* https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf

--------

#### 源码

[RedBlackTree.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/RedBlackTree.h)

[RedBlackTree.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/RedBlackTree.cpp)

#### 测试

[RedBlackTreeTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/RedBlackTreeTest.cpp)
