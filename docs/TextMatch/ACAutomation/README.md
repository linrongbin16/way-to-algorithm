# AC(Aho Corasick) Automation - AC自动机

--------

#### 问题

在文本$$ text $$中查找$$ k $$个字符串$$ str $$出现的所有位置，其中$$ text $$长度为$$ n $$，$$ str $$长度为$$ m $$。

如果使用SimpleMatch或KMPMatch，我们需要对每一个字符串$$ str[i] $$（其中$$ 0 \le i \lt k $$）都执行一遍匹配算法，对于长度为$$ n $$的文本$$ text $$，一次匹配算法的时间复杂度最小为$$ O(n) $$（KMPMatch），那么整个过程的时间复杂度为$$ O( n \times k ) $$。

AC自动机算法可以在遍历一次文本$$ text $$中找出$$ k $$个字符串的所有位置，时间复杂度接近$$ O(n) $$。

#### 解法

--------

#### 源码

[import, lang:"c_cpp"](../../../src/TextMatch/ACAutomation.h)

#### 测试

[import, lang:"c_cpp"](../../../src/TextMatch/ACAutomation.cpp)
