<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>
<script> gitbook.events.bind("page.change", function() { MathJax.Hub.Queue(["Typeset",MathJax.Hub]); } </script>

# Knuth Morris Pratt - KMP匹配算法

--------

#### 问题

在文本$$ text $$中查找字符串$$ pattern $$出现的所有位置（$$ text $$长度为$$ n $$，$$ pattern $$长度为$$ m $$，$$ n, m $$都是正整数且$$ n \gt m $$）。

#### 解法

没有学习AC自动机前想要理解KMP算法非常困难，KMP算法可以看作只有一个模式的AC自动机的简化版。所以将KnuthMorrisPratt放在AhoCorasickAutomata之后，请读者在学习KMP算法之前先阅读AhoCorasickAutomata。

将AC自动机应用在只有一个模式的匹配时，我们会发现这样的AC自动机中没有输出指针，只有失败指针。为了简化我们不再使用树形结构体，而用数组下标来表示失败指针：

![KnuthMorrisPratt1.svg](../res/KnuthMorrisPratt1.svg)

得到模式$$ pattern $$的每个节点跳转的下标，在KMP算法中，这个跳转的下标数组称为失败函数（Failure Function），或部分匹配表（Partial Match Table）。

当匹配到$$ text[0 \dots 3] = pattern[0 \dots 3] $$但$$ text[4] \ne pattern[4] $$时，已知$$ pattern[0 \dots 3] $$的最长后缀字符串为$$ pt[0 \dots 1] $$，按照AC自动机的算法，当前的匹配位置是$$ pattern[3] $$，沿着失败指针$$ pattern[3] \rightarrow pattern[1] $$跳转，然后继续尝试匹配$$ pattern[2] $$和$$ text[4] $$。指向前缀树根节点的下标都调整为$$ 0 $$（而不是$$ -1 $$这种无意义的值）。

由此可得，当$$ text[i] = pattern[j] $$而在$$ text[i+1] \ne pattern[j+1] $$处匹配失败时，若$$ j = 0 $$则匹配位置不动，文本上的位置向右移动一位$$ i = i + 1 $$；若$$ j \gt 0 $$则匹配位置跳转到$$ j = pmt[j] $$，文本上的位置不动，然后继续尝试匹配$$ text[i+1] $$和$$ pattern[j+1] $$。当$$ text[i] = pattern[j] $$匹配成功（即$$ text[i-m+1 \dots i] = pattern[j-m+1 \dots j] $$），模式的匹配位置仍然沿着失败指针跳转到$$ j = pmt[j] $$，继续匹配。

KMP算法的时间复杂度为$$ O(n + m) $$。

--------

KMP算法

* https://www.zhihu.com/question/21923021/answer/281346746

--------

#### 源码

[import, lang:"c_cpp"](../../../src/TextMatch/KnuthMorrisPratt.h)

#### 测试

[import, lang:"c_cpp"](../../../src/TextMatch/KnuthMorrisPratt.cpp)
