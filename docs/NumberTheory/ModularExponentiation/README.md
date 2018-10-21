<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Modular Exponentiation - 模幂运算

--------

#### 问题

给定正整数$$ b, e, m $$，求：

$$
c = b^{e} \pmod{m}
$$

#### 简单算法

按照次方运算的原理，初始化$$ c = 1 $$，重复$$ e $$次：

$$
c = (c \times b) \bmod m
$$

即为所求，该算法的时间复杂度为$$ O(e) $$。

#### 二进制算法

根据二进制可知，任何正整数$$ e $$都可以用$$ n $$个$$ 2 $$的次方和来表示：

$$
e = \sum_{i=0}{n-1} a_{i} \cdot 2^{i}
$$

其中$$ n $$是正整数$$ e $$中1的数量，$$ a_{i} $$要么为$$ 0 $$要么为$$ 1 $$，且$$ a_{n-1} = 1 $$。因此$$ b^{e} $$可以转换为：

$$
b^{e} = b^{(\sum_{i=0}{n-1} a_{i} \cdot 2^{i})} = \prod_{i=0}{n-1} (b^{2^{i}})^{a_{i}}
$$

因此模幂运算转换为：

$$
c \equiv \prod_{i=0}{n-1} (b^{2^{i}})^{a_{i}} \pmod{m}
$$

计算每个元素$$ (b^{2^{i}})^{a_{i}} $$，若$$ a_{i} = 0 $$则结果必然为$$ 1 $$，不必计算，若$$ a_{i} = 1 $$则需要$$ 2^{i} $$次乘法，即时间复杂度为$$ O(2^{i}) $$（其中$$ 0 \leq i \leq n-1 $$）。

该算法的时间复杂度为$$ O(\sum_{i=0}{n-1} 2^{i} \cdot a_{i}) $$。

求正整数$$ e $$中所有为1的bit位的方法，与本书第三章DataStructure中FenwickTree一节使用的方法一样，不再赘述。

#### 快速求幂算法

快速求幂算法基于以下公式：

$$
b^e =
\begin{cases}
1                                               &   e = 0
b                                               &   e = 1
(b \times (b^2)^{\frac{e-1}{2}}) \bmod m        &   b is odd
((b^2)^{\frac{e}{2}}) \bmod m                   &   b is even
\end{cases}
$$

该算法的时间复杂度为$$ O(log_2 e) $$。



--------

#### 源码

[ModularExponentiation.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ModularExponentiation.h)

[ModularExponentiation.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ModularExponentiation.cpp)

#### 测试

[ModularExponentiationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ModularExponentiationTest.cpp)
