<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Prefix Tree(Trie Tree) - 前缀树

--------

#### 前缀树

前缀树是一种按照前缀快速查找的数据结构，典型的应用场景是在一个英文单词集合中快速查询某个单词。

为了方便，本问题只考虑字典中的$$ a - z $$这$$ 26 $$个小写字母。前缀树的树节点包含$$ 26 $$个孩子节点，跟节点不包含任何字符，从根节点开始向下查找就可以得到完整的单词。一个包含$$ boy $$、$$ dog $$、$$ bible $$、$$ bill $$的前缀树如图：

![PrefixTree1.png](../res/PrefixTree1.png)

每次查找单词，从根节点开始向下匹配即可。在前缀树中查找一个长度为$$ n $$的单词的时间复杂度为$$ O(n) $$。

--------

#### 源码

[PrefixTree.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/PrefixTree.h)

[PrefixTree.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/PrefixTree.cpp)

#### 测试

[PrefixTreeTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/DataStructure/PrefixTreeTest.cpp)
