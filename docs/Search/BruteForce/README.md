<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>

# Brute Force - 暴力枚举

--------

#### 问题

序列$$ s $$有$$ n $$个成员$$ [s_1,s_2, \dots ,s_n] $$，每个成员可以选取$$ [1,2, \dots ,m] $$这$$ m $$种值。

例如当$$ n = 5 $$，$$ m = 3 $$时，序列$$ s $$有如下排列组合：

$$
[1,1,1,1,1], [1,1,1,1,2], [1,1,1,1,3], [1,1,1,2,1] \dots
$$

遍历序列$$ s $$的可能排列组合的所有情况。

#### 原理

加法原理：完成一件事情有$$ n $$类方法，每类方法有若干子方法，完成这件事需要且只需要$$ n $$类方法中的一类方法中的一个子方法。第$$ 1 $$类方法有$$ m_1 $$种子方法，第$$ 2 $$类方法有$$ m_2 $$种子方法，$$ \dots $$，第$$ n $$类方法有$$ m_n $$种子方法。则完成这件事共有$$ m_1 + m_2 + \cdots + m_n $$种方法。

乘法原理：完成一件事情需要$$ n $$个步骤，每个步骤有若干子方法，完成这件事情需要$$ n $$个步骤都完成，每个步骤需要且只需要选择一种方法。第$$ 1 $$步有$$ m_1 $$种子方法，第$$ 2 $$步有$$ m_2 $$种子方法，$$ \dots $$，第$$ n $$步有$$ m_n $$种子方法。则完成这件事共有$$ m_1 \times m_2 \times \cdots \times m_n $$种方法。

#### 解法

通过$$ for $$循环枚举出序列$$ s $$中的所有可能。

例如对于序列$$ [s_1,s_2,s_3,s_4] $$，其中每个元素的取值范围是$$ [0,m] $$。如果把该序列看作一个正整数，从$$ 0000 $$依次数到$$ 9999 $$即为全部的排列组合。

对于成员数量为$$ n $$，每个成员有$$ m $$种值的序列$$ s $$，遍历所有排列组合的时间复杂度$$ O(n^m) $$。

--------

#### 源码

[BruteForce.h](../../../src/Search/BruteForce.h)

[import, lang:"c_cpp"](../../../src/Search/BruteForce.h)

[BruteForce.cpp](../../../src/Search/BruteForce.cpp)

[import, lang:"c_cpp"](../../../src/Search/BruteForce.cpp)

#### 测试

[BruteForceTest.cpp](../../../src/Search/BruteForceTest.cpp)

[import, lang:"c_cpp"](../../../src/Search/BruteForceTest.cpp)
