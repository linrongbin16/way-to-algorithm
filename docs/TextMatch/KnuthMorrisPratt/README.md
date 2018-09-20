# Knuth Morris Pratt - KMP匹配算法

--------

#### 问题

在文本$$ text $$中查找字符串$$ pattern $$出现的所有位置（$$ text $$长度为n，$$ pattern $$长度为$$ m $$，$$ n, m $$都是正整数且$$ n \gt m $$）。

#### 解法

KMP算法的性能为$$ O(n) $$，比SimpleMatch高很多。在$$ text $$中匹配$$ pattern $$的过程中，仔细观察可以发现，不必在失败时从$$ pattern $$的起始重新匹配，我们可以对这块进行优化。

对于下面这个匹配：

![KnuthMorrisPratt1.svg](../res/KnuthMorrisPratt1.svg)

$$ (1) $$ 从$$ text[i = 0], pattern[j = 0] $$开始，可以得到$$ text[0 \dots 3] = pattern[0 \dots 3] $$但$$ text[4] \ne pattern[4] $$；

$$ (2) $$ 但这次我们不希望从$$ text[i = 1], pattern[j = 0] $$重新开始。通过观察发现，显然$$ text[1] \ne pattern[0] $$，而真正适合作为下一轮匹配的起始点是$$ text[i = 2], pattern[j = 0] $$，因为$$ text[0 \dots 1] = text[2 \dots 3] $$，而上一轮匹配失败时$$ text[0 \dots 3] = pattern[0 \dots 3] $$。我们称$$ i = 4 $$这样令匹配失败的位置为“失败位置”；

在介绍KMP算法之前，我们先介绍失败函数（Failure Function）或者称部分匹配表（Partial Match Table）。如图：

![KnuthMorrisPratt2.svg](../res/KnuthMorrisPratt2.svg)

上图中字符串$$ text = "abababca" $$的前缀包括$$ prefix = ["a", "ab", "aba", "abab", "ababa", "ababab", "abababc"] $$（字符串的前缀不能是它本身，也不能是空字符串），后缀包括$$ suffix = ["bababca", "ababca", "babca", "abca", "bca", "ca", "a"] $$。其中$$ prefix $$称为前缀集合，$$ suffix $$是后缀集合。$$ pmt $$的值即为一个字符串的前缀集合和后缀集合的交集中最长字符串的长度。下面是几个示例：

$$ (1) $$ 字符串$$ text = "abababca" $$的$$ prefix $$和$$ suffix $$的交集是$$ ["a"] $$，其中最长字符串的长度为$$ 1 $$。

$$ (2) $$ 字符串$$ text = "ababa" $$的$$ prefix = ["a", "ab", "aba", "abab"] $$和$$ suffix = ["baba", "aba", "ba", "a"] $$的交集是$$ ["a", "aba"] $$，其中最长字符串的长度为$$ 3 $$。

$$ (3) $$ 字符串$$ text = "ab" $$的$$ prefix = ["a"] $$和$$ suffix = ["b"] $$的交集是$$ \emptyset $$，其中最长字符串的长度为$$ 0 $$。

有了部分匹配表，我们回到图2中的例子，可以算出$$ text $$的$$ pmt $$：

![KnuthMorrisPratt3.svg](../res/KnuthMorrisPratt3.svg)

当$$ text[0 \dots 3] = pattern[0 \dots 3] $$但$$ text[4] = pattern[4] $$，我们可以发现$$ text[0 \dots 1] = text[2 \dots 3] $$，即字符串$$ text[0 \dots 3] = "abab" $$的前缀集合$$ prefix = ["a", "ab", "aba"] $$和后缀集合$$ suffix = ["bab", "ab", "b"] $$的交集为$$ ["ab"] $$，其中最长的交集字符串$$ "ab" $$的长度为$$ 2 $$。

那么这里我们可以跳过$$ 2 $$个字符，下一次开始匹配的位置为$$ i = 2, j = 0 $$。

![KnuthMorrisPratt4.svg](../res/KnuthMorrisPratt4.svg)

到此，我们通过部分匹配表完成了一次匹配失败时的跳跃。当我们匹配$$ text[i \dots i+j] $$和$$ pattern[0 \dots j] $$时，遇到前$$ k $$个字符成功匹配$$ text[i \dots i+k] = pattern[0 \dots k] $$，而第$$ k + 1 $$处不匹配$$ text[i+k+1] = pattern[k+1] $$时，查看字符串$$ text[0 \dots i+k] $$处部分匹配表$$ pmt[i+k] $$的值，就可以确定出下次重新开始匹配时，需要跳过的字符数量。

因为$$ i+k+1 $$即为失败位置$$ fail $$，可知这时需要查找的部分匹配表$$ pmt[fail-1] $$处的值，为了方便我们将整个$$ pmt $$右移一位，得到$$ next $$数组。这样当$$ text $$上某个位置$$ i = fail $$匹配失败时，可以直接查找$$ next[fail] $$知道下次开始匹配的位置为$$ fail + next[fail] $$

![KnuthMorrisPratt5.svg](../res/KnuthMorrisPratt5.svg)

上一段中的$$ k $$为正整数且满足$$ 0 \gt k \gt fail, 0 \gt fail - k \gt fail  $$。这个函数

$$

k = f(fail)

$$

称作失败函数（Failure Function）、部分匹配表（Partial Match Table）。在字符串$$ pattern[0 \dots m-1] $$上由任意位置$$ j $$组成的前缀字符串$$ pattern[0 \dots j] $$，求出一个最大的$$ k $$使其满足$$ pattern[0 \dots k] = pattern[j-k \dots j] $$。

那么当$$ pattern $$在$$ text[i] $$上匹配失败时，设$$ text[i \dots i+fail-1] = pattern[0 \dots fail-1] $$但$$ text[i+fail] \ne pattern[fail] $$，求出一个$$ k $$可以直接让$$ i = i + k + 1 $$，找到下一次匹配的起始位置。

KMP算法需要对$$ pattern $$进行预处理，来算出每个位置$$ j $$对应的$$ k $$值，实际匹配时可以直接查找。一种简单的构造方法是在长度为$$ m $$的$$ pattern $$上遍历，若$$ pattern[k] = pattern[fail - k] $$（$$ 0 \gt k \gt fail $$）则$$ k $$向右移动，否则即为所求，但该方法的时间复杂度为$$ O(m ^ 2) $$。

介绍一种时间复杂度为$$ O(m) $$的构造$$ pattern $$每个位置上的$$ k $$值的办法。如图所示：

显然由于$$ 0 \gt k \gt fail $$，当$$ f(0), f(1) $$并不存在，一般令$$ f(0) = -1, f(1) = 0 $$。对于$$ fail = 2 $$，若

KMP算法是一种精巧设计的算法，但实际上字符串匹配问题是文法识别问题，可以用确定性有限状态自动机（Deterministic Finite State Automaton，简称DFA）来解决。

--------

KMP算法

* https://www.zhihu.com/question/21923021/answer/281346746

--------

#### 源码

[import, lang:"c_cpp"](../../../src/TextMatch/KnuthMorrisPratt.h)

#### 测试

[import, lang:"c_cpp"](../../../src/TextMatch/KnuthMorrisPratt.cpp)
