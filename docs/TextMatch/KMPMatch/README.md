# KMP(Knuth Morris Pratt) Match - KMP匹配

--------

#### 问题

在文本$$ text $$中查找字符串$$ str $$的位置（设$$ text $$长度为n，$$ str $$长度为$$ m $$，该场景满足$$ n \gt m $$）。

#### 解法

KMP算法的性能为$$ O(n) $$，比SimpleMatch高很多。在$$ text = abcxbciabcab $$搜索$$ str = abcab $$的过程中，其实仔细观察一下会发现，没有必要在每次失败的时候，都重新从$$ str $$的起始处开始匹配，我们可以跳过一部分。

对于下面这个匹配：

![KMPMatch1.svg](../res/KMPMatch1.svg)

$$ (1) $$ 从$$ text $$第$$ 0 $$个字符开始匹配，有$$ text[0 \cdots 2] = str[0 \cdots 2]，text[3] \ne str[3] $$；

$$ (2) $$ 这次我们不希望从$$ text $$的第$$ 1 $$个字符开始匹配，因为这样需要重复比较$$ str[0 \cdots 2] $$这$$ 3 $$个字符，导致时间复杂度成为$$ O(n \times m) $$。

这里我们定义两个概念：前缀、后缀。设字符串$$ s $$的前缀$$ prefix $$、后缀$$ suffix $$分别表示该字符串的真子集（即$$ prefix \ne s $$且$$ suffix \ne s $$），并且，前缀是从头开始的连续字符串子集，后缀是从尾开始的连续字符串子集，包括空字符串（空集）。比如字符串$$ s = abcab $$，其前缀为$$ prefix = [ \emptyset, a, ab, abc, abca ] $$，后缀为$$ suffix = [ \emptyset, b, ab, cab, bcab ] $$（注意前缀和后缀中不能有字符串$$ s = abcab $$本身，必须是真子集）。

在前缀、后缀的概念下，对于长度为$$ m $$的字符串$$ str $$的任意一个子字符串$$ str[0 \cdots i] $$，我们都可以求出它的前缀和后缀。例如对于字符串$$ str = abcab $$，可以得到：

$$ (1) $$ 子字符串$$ str[0 \cdots 0] = a $$的前缀为$$ prefix = [ \emptyset ] $$，后缀为$$ suffix = [ \emptyset ] $$；

$$ (2) $$ 子字符串$$ str[0 \cdots 1] = ab $$的前缀为$$ prefix = [ \emptyset, a ] $$，后缀为$$ suffix = [ \emptyset, b ] $$；

$$ (3) $$ 子字符串$$ str[0 \cdots 2] = abc $$的前缀为$$ prefix = [ \emptyset, a, ab ] $$，后缀为$$ suffix = [ \emptyset, c, bc ] $$；

$$ (4) $$ 子字符串$$ str[0 \cdots 3] = abca $$的前缀为$$ prefix = [ \emptyset, a, ab, abc ] $$，后缀为$$ suffix = [ \emptyset, a, ca, bca ] $$；

$$ (5) $$ 子字符串$$ str[0 \cdots 4] = abcab $$的前缀为$$ prefix = [ \emptyset, a, ab, abc, abca ] $$，后缀为$$ suffix = [ \emptyset, b, ab, cab, bcab ] $$；

设字符串$$ str $$的每个字符$$ str[i] $$有个回文长度$$ len[i] $$。对于子字符串$$ str[i] $$的前缀、后缀，找到其中相同的前缀和后缀$$ same $$（如果存在多个，选最长的），则$$ len[i] = length\_{same} $$。

$$ (1) $$ 子字符串$$ str[0 \cdots 0] $$，其相同的最长的前缀和后缀为$$ \emptyset $$，因此$$ len[0] = 0 $$；

$$ (2) $$ 子字符串$$ str[0 \cdots 1] $$，其相同的最长的前缀和后缀为$$ \emptyset $$，因此$$ len[1] = 0 $$；

$$ (3) $$ 子字符串$$ str[0 \cdots 2] $$，其相同的最长的前缀和后缀为$$ \emptyset $$，因此$$ len[2] = 0 $$；

$$ (4) $$ 子字符串$$ str[0 \cdots 3] $$，其相同的最长的前缀和后缀为$$ a $$，因此$$ len[3] = 1 $$；

$$ (5) $$ 子字符串$$ str[0 \cdots 4] $$，其相同的最长的前缀和后缀为$$ ab $$，因此$$ len[4] = 2 $$；

最终得到的回文长度为$$ len = \[ 0, 0, 0, 1, 2 ] $$。回文长度代表的意义是子字符串中从头开始、和从尾开始的两部分字符串的最长相同部分的长度。

回到开始，当匹配$$ text[0 \cdots 4] \ne str[0 \cdots 4] $$时，其中$$ text[0 \cdots 2]_{abc} = str[0 \cdots 2]_{abc} $$，而$$ text[3]_{x} \ne str[3]_{a} $$。这时以最后一个成功匹配的字符$$ str[2] $$为准，我们知道$$ len[2] = 0 $$，即$$ str[2] $$这个字符存在最大长度为2的前缀和后缀，即$$ str[0 \cdots 1]_{ab} $$和$$ str[3 \cdots 4]_{ab} $$。这时可以算出$$ 移动长度 = 已经匹配的字符数量 - 最后一位匹配字符的匹配长度值 $$，即$$ 1 = 3 - 2 $$。

在上面这个例子中，该公式表达了，已经匹配的字符串$$ str[0 \cdots 2] = abc $$，它的前缀$$ str[0 \cdots 1] = ab $$，和它后面没有被匹配的后缀$$ str[3 \cdots 4] = ab $$是相同的。利用这个特点，下一次匹配我们希望可以直接让前缀$$ ab $$和

--------

#### 源码

[import, lang:"c_cpp"](../../../src/TextMatch/KMPMatch.h)

#### 测试

[import, lang:"c_cpp"](../../../src/TextMatch/KMPMatch.cpp)
