<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Modular Exponentiation - 模幂运算

--------

#### 问题

给定正整数$$ b, e, m $$，求：

$$
c = b^{e} \pmod{m}
$$

#### 解法

初始化$$ c = 1 $$，重复$$ e - 1 $$次$$ c = (c \times b) \bmod m $$即可，时间复杂度为$$ O(e) $$。

--------

#### 源码

[ModularExponentiation.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ModularExponentiation.h)

[ModularExponentiation.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ModularExponentiation.cpp)

#### 测试

[ModularExponentiationTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ModularExponentiationTest.cpp)
