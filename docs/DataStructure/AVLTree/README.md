<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# AVL Tree - AVL二叉树

--------

#### AVL二叉平衡树

随机添加、删除操作非常容易造成二叉树的左右孩子子树高度差距较大，导致查找节点的时间复杂度退化为$$ O(n) $$。AVL树是最早发明的一种自平衡二叉查找树，树中的任何节点的左右两个子树的高度最大差别为$$ 1 $$，因此也称为高度平衡树。包含$$ n $$个节点的AVL树其查找、插入、删除操作的平均时间复杂度都是$$ O(log_{2}⁡n) $$。AVL树高度为$$ O(log_{2}⁡n) $$。

AVL树保持金字塔形状的秘诀在于通过调整LL（左左）、RR（右右）、LR（左右）、RL（右左）四种情况：

![AVLTree1.png](../res/AVLTree1.png)

![AVLTree2.png](../res/AVLTree2.png)

![AVLTree3.png](../res/AVLTree3.png)

![AVLTree4.png](../res/AVLTree4.png)

上面四种情况包含了所有从不平衡转化为平衡，分别称为单向右旋平衡处理LL，单向左旋平衡处理RR，双向旋转（先左后右）平衡处理LR，双向旋转（先右后左）平衡处理RL。

这四种操作既能够平衡左右子树的高度，还能够保持树的有序性。即平衡后的树的左子树中所有节点仍然小于（或大于）树的根节点，而右子树中所有节点仍然大于（或小于）树的根节点。

AVL树的每个节点都有一个高度值$$ depth $$，称一个节点的左右孩子节点的高度差为该节点的平衡因子$$ factor = depth_{left} - depth_{right} $$。当一个节点的$$ | factor | \le 1 $$时称以该节点为根节点的子树是平衡的，否则是不平衡的。

将空节点的高度值视作$$ - 1 $$，一个节点的高度值为$$ depth_{node} = max⁡(depth_{left},depth_{right}) + 1 $$。上面LL、RR、LR和RL四种操作，都会将其节点$$ 1 $$的高度值减$$ 2 $$，其余节点的高度值都不变。

对于下面这个AVL树，每个节点中上面的数字是节点下标，下面的数字是该节点的高度值$$ depth $$。将节点$$ 18 $$插入下面的AVL树：

![AVLTree5.png](../res/AVLTree5.png)

$$ (1) $$从根节点开始，将节点$$ 18 $$与节点$$ 10 $$比较，有$$ 18 \lt 10 $$，因此把节点$$ 18 $$插入节点$$ 10 $$的右子树；

$$ (2) $$将节点$$ 18 $$与节点$$ 15 $$比较，有$$ 18 \gt 15 $$，因此把节点$$ 18 $$插入节点$$ 15 $$的右子树；

$$ (3) $$将节点$$ 18 $$与节点$$ 19 $$比较，有$$ 18 \lt 19 $$，因此把节点$$ 18 $$插入节点$$ 19 $$的左子树；

$$ (4) $$将节点$$ 18 $$与节点$$ 16 $$比较，有$$ 18 \gt 16 $$，因此把节点$$ 18 $$插入节点$$ 16 $$的右子树；

$$ (5) $$将节点$$ 18 $$与节点$$ 17 $$比较，有$$ 18 \gt 17 $$，因此把节点$$ 18 $$插入节点$$ 17 $$的右子树，节点$$ 17 $$的右孩子节点为空，因此节点$$ 18 $$成为节点$$ 17 $$的右孩子节点；

然后从节点$$ 18 $$开始，向上依次更新所有节点的高度值，若新的高度值不满足AVL树的平衡性，则进行旋转操作：

$$ (6) $$节点$$ 18 $$为叶子节点，因此高度值为$$ 0 $$；

![AVLTree6.png](../res/AVLTree6.png)

$$ (7) $$节点$$ 17 $$的平衡因子为$$ factor_{17} = |depth_{nil} - depth_{18}| = |- 1 - 0| = 1 $$，不需要旋转，高度值更新为$$ depth_{17} = max⁡(depth_{nil},depth_{nil}) + 1 = max⁡(-1,0) + 1 = 1 $$；

![AVLTree7.png](../res/AVLTree7.png)

$$ (8) $$节点$$ 16 $$的平衡因子为$$ factor_{16} = |depth_{nil} - depth_{17} | = |- 1 - 1| = 2 $$，高度值更新为$$ depth_{16} = max⁡(depth_{nil},depth_{17}) + 1 = max⁡(-1,1) + 1 = 2 $$，由于节点$$ 16 $$的平衡因子超过$$ 1 $$，需要进行RR操作，旋转后节点$$ 16 $$的高度值减$$ 2 $$；

![AVLTree8.png](../res/AVLTree8.png)

![AVLTree9.png](../res/AVLTree9.png)

$$ (9) $$节点$$ 19 $$的平衡因子为$$ factor_{19} = |depth_{17} - depth_{20}| = |1 - 0| = 1 $$，高度值更新为$$ depth_{19} = max⁡(depth_{16},depth_{20}) + 1 = max⁡(1,0) + 1 = 2 $$；

![AVLTree10.png](../res/AVLTree10.png)

$$ (10) $$节点$$ 15 $$的平衡因子为$$ factor_{15} = |depth_{13} - depth_{19}| = |1 - 2| = 1 $$，高度值更新为$$ depth_{15} = max⁡(depth_{13},depth_{19}) + 1 = max⁡(1,2) + 1 = 3 $$；

![AVLTree11.png](../res/AVLTree11.png)

$$ (11) $$节点$$ 10 $$的平衡因子为$$ factor_{10} = |depth_{5} - depth_{15}| = |2 - 3| = 1 $$，高度值更新为$$ depth_{10} = max⁡(depth_{5},depth_{15}) + 1 = max⁡(2,3) + 1 = 4 $$；

![AVLTree12.png](../res/AVLTree12.png)

到此我们完成了一次AVL树插入新节点的操作：首先从根节点向下找到一个合适的插入位置，然后再沿着父节点指针向上遍历所有节点，更新其高度值，若高度不满足AVL平衡树的要求，则进行相应的LL、RR、LR、RL操作。

--------

#### 源码

[AVLTree.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/AVLTree.h)

[AVLTree.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/AVLTree.cpp)

#### 测试

[AVLTreeTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/AVLTreeTest.cpp)
