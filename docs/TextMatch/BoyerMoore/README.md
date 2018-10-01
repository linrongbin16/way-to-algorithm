<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Boyer Moore - Boyer-Moore算法

--------

#### 问题

在文本$$ text $$中查找字符串$$ pattern $$出现的所有位置（$$ text $$长度为$$ n $$，$$ pattern $$长度为$$ m $$，$$ n, m $$都是正整数且$$ n \gt m $$）。

#### 解法

Boyer-Moore算法与KMP算法类似，当匹配失败时跳转到某个位置继续匹配。

--------

#### 源码

[BoyerMoore.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/TextMatch/BoyerMoore.h)

[BoyerMoore.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/TextMatch/BoyerMoore.cpp)

#### 测试

[BoyerMooreTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/TextMatch/BoyerMooreTest.cpp)
