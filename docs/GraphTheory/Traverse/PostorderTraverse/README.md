* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/PostorderTraverse.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/GraphTheory/Traverse/PostorderTraverse.cpp)

--------

### Postorder Traverse
### 后序遍历
<div>
问题：
<p id="i">用后序遍历的方式来遍历二叉树。 <br>
解法：
<p id="i">从二叉树根节点\(root\)开始，递归的对二叉树上的每个节点\(i\)，总是优先访问节点\(i\)的左孩子节点，然后访问\(i\)的右孩子节点，最后访问\(i\)节点本身。如图： </p>
<p id="c"><img src="../res/PostorderTraverse1.png" /></p>
<p id="i">后序遍历的时间复杂度是\(O(n)\)。 </p>
</div>
