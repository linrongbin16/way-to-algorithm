# Knuth Morris Pratt - KMP匹配算法

--------

#### 问题

在文本$$ text $$中查找字符串$$ pattern $$出现的所有位置（$$ text $$长度为n，$$ pattern $$长度为$$ m $$，$$ n, m $$都是正整数且$$ n \gt m $$）。

#### 解法

KMP算法的性能为$$ O(n) $$，比SimpleMatch高很多。在$$ text $$中匹配$$ pattern $$的过程中，仔细观察可以发现，不必在失败时从$$ pattern $$的起始重新匹配，我们可以对这块进行优化。

对于下面这个匹配：

![KnuthMorrisPratt1.svg](../res/KnuthMorrisPratt1.svg)

$$ (1) $$ 从$$ text[i = 0], pattern[j = 0] $$开始，可以得到$$ text[0 \dots 3] = pattern[0 \dots 3] $$但$$ text[4] \ne pattern[4] $$；

$$ (2) $$ 但这次我们不希望从$$ text[i = 1], pattern[j = 0] $$重新开始。通过观察发现，显然$$ text[1] \ne pattern[0] $$，而真正适合作为下一轮匹配的起始点是$$ text[i = 2], pattern[j = 0] $$，因为$$ pattern[0 \dots 1] = pattern[2 \dots 3] $$，而上一轮匹配失败时$$ pattern[0 \dots j-1] $$都与$$ text[i \dots i+j-1] $$相同（$$ i = 0, j = 4 $$）。我们称$$ j = 4 $$这样令匹配失败的位置为“失败位置”；

我们再举一个更明显的例子：

![KnuthMorrisPratt2.svg](../res/KnuthMorrisPratt2.svg)

$$ (1) $$ 从$$ text[i = 0], pattern[j = 0] $$开始，可以得到$$ text[0 \dots 5] = pattern[0 \dots 5] $$但$$ text[6] \ne pattern[6] $$，这是失败位置为$$ fail = 6 $$；

$$ (2) $$ 读者这里请注意，我们不能因为$$ text[6] \ne pattern[6] $$就武断的认为下一次匹配的起始位置为$$ i = 6 $$或者$$ i = 6 + 1 $$。反直觉的，因为$$ pattern[0 \dots 2] = pattern[4 \dots 6] $$，真正适合作为下一轮匹配的起始点是$$ text[i = 3], pattern[j = 0] $$；

如果再找几个稍微长一点的例子，可以发现当$$ text[i \dots i+fail-1] = pattern[0 \dots fail-1] $$但$$ text[i+fail] \ne pattern[fail] $$，若这时在$$ pattern[1 \dots fail-1] $$上存在一个$$ k $$，使得$$ pattern[0 \dots k] = pattern[fail-k \dots fail] $$（尽可能将$$ k $$最大化），那么下一次匹配，我们可以轻松的跳过$$ k $$个字符，直接从$$ i = i + k + 1, j = 0 $$开始继续匹配，而不用像SimpleMatch中一样从$$ i = i + 1, j = 0 $$开始，显然$$ text[i+1] \dots text[i+k] $$这部分字符作为起始点的匹配都是必然失败的。

上一段中的$$ k $$为正整数且满足$$ 0 \gt k \gt fail, 0 \gt fail - k \gt fail  $$。这个函数

$$

k = f(fail)

$$

称作失败函数（Failure Function）、部分匹配表（Partial Match Table）。在字符串$$ pattern[0 \dots m-1] $$上由任意位置$$ j $$组成的前缀字符串$$ pattern[0 \dots j] $$，求出一个最大的$$ k $$使其满足$$ pattern[0 \dots k] = pattern[j-k \dots j] $$。

那么当$$ pattern $$在$$ text[i] $$上匹配失败时，设$$ text[i \dots i+fail-1] = pattern[0 \dots fail-1] $$但$$ text[i+fail] \ne pattern[fail] $$，求出一个$$ k $$可以直接让$$ i = i + k + 1 $$，找到下一次匹配的起始位置。

KMP算法需要对$$ pattern $$进行预处理，来算出每个位置$$ j $$对应的$$ k $$值，实际匹配时可以直接查找。

--------

#### 源码

[import, lang:"c_cpp"](../../../src/TextMatch/KnuthMorrisPratt.h)

#### 测试

[import, lang:"c_cpp"](../../../src/TextMatch/KnuthMorrisPratt.cpp)
