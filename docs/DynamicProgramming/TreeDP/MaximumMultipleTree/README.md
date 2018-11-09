<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Maximum Multiple Tree - 最大多叉树

--------

#### 问题

与Max Binary Tree类似，拥有$$ n $$个节点的多叉树，节点范围为$$ [1,n] $$，节点$$ i $$的权值为正整数$$ v_i $$，整个树的权值为所有节点的权值之和。每个节点$$ i $$有最多$$ k $$个孩子节点。现在要求只保留$$ m $$个节点（$$ 0 \lt m \lt n-1 $$），剪裁掉的节点数量为$$ n-1-m $$，要求剩余部分仍然是一个多叉树，而不能是多个树。

对于拥有$$ n $$个节点的多叉树，求出保留$$ m $$个节点的多叉树的最大权值。

#### 解法

与Max Binary Tree类似，设$$ f(i,j) $$表示以节点$$ i $$为根节点的树上，保留$$ j $$个节点的最大权值。有状态转移方程如下：

$$
f(i,j) =
\begin{cases}
v_i                                             &   (initialize)    &   i \in [1,n], j = 1  \\
max⁡\{ \sum_{p=1}^{k} f(child_p, m_p)+v_i \}    &   (loop)          &   i \in [1,n], \sum_{p=1}^{k} m_p = j-1
\end{cases}
$$

$$ (1) $$ 节点数量为$$ 1 $$的多叉树，至多只能留下1个节点，多叉树的权值即为根节点自己的权值，即$$ f(i,1) = v_i $$；

$$ (2) $$ 对于以$$ i $$为根节点的多叉树，假设它拥有$$ k $$个孩子节点，分别为$$ child_p $$（$$ 1 \leq p \leq k $$）。当子树$$ i $$保留$$ j $$个节点时，它所有孩子节点保留的节点总和为$$ j-1 $$（节点$$ i $$占一个节点），设节点$$ child_p $$拥有节点数量为$$ m_p $$，则有$$ j-1 = \sum_{p=1}^{k} m_p $$。遍历所有可能，选取使得该子树的权值最大即可；

编码时会发现，多叉树的动态规划使用了相互嵌套的递归函数：

$$ (1) $$ $$ f $$函数遍历每个节点$$ i $$，求出该节点的上最多保留$$ j $$个节点时的最大权值，该节点的$$ k $$个孩子节点的保留节点的方案使用$$ g $$函数求出；

$$ (2) $$ $$ g $$函数遍历所有保留节点的方案，给$$ k $$个子树（父结点为$$ i $$的孩子节点）分配共$$ j $$个节点，当孩子节点$$ child_{k} $$的子树分配$$ assign $$个节点时，再使用$$ f $$函数求出$$ child_{k} $$节点的子树上保留$$ assign $$个节点的最大权值；

$$ f(n,m) $$为该多叉树的最大权值。该算法的时间复杂度是$$ O(n \times m) $$。

--------

#### 源码

[MaximumMultipleTree.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MaximumMultipleTree.h)

[MaximumMultipleTree.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MaximumMultipleTree.cpp)

#### 测试

[MaximumMultipleTreeTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DynamicProgramming/TreeDP/MaximumMultipleTreeTest.cpp)
