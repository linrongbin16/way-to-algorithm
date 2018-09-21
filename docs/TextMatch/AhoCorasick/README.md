<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>
<script> gitbook.events.bind("page.change", function() { MathJax.Hub.Queue(["Typeset",MathJax.Hub]); } </script>

# Aho Corasick - AC自动机

--------

#### 问题

在文本$$ text $$中查找$$ k $$个模式$$ pattern $$出现的所有位置（其中$$ text $$长度为$$ n $$，$$ pattern_{i} $$的长度为$$ m_{i} $$，其中最长的模式长度为$$ m_{max} $$且$$ n \gt m_{max} $$）。

#### 解法

假设所有模式的长度之和为$$ \sum_{i=1}^{k} m_{i} $$，将简单字符串匹配SimpleMatch应用在本问题上，搜索$$ pattern_{i} $$的时间复杂度为$$ O(n \cdot m_{i}) $$，搜索所有模式的时间复杂度为$$ O(n \cdot \sum_{i=1}^{k} m_{i}) $$。

我们能否在一次匹配$$ text $$的过程中就同时找出所有模式呢？即并行算法（算法上的并行，非多线程多进程的并行）。

首先用所有模式构造一个前缀树$$ Trie Tree $$，如图所示：


--------

#### Aho Corasick Automata

* https://web.stanford.edu/class/cs166/lectures/02/Small02.pdf

--------

#### 源码

[import, lang:"c_cpp"](../../../src/TextMatch/AhoCorasick.h)

#### 测试

[import, lang:"c_cpp"](../../../src/TextMatch/AhoCorasick.cpp)
