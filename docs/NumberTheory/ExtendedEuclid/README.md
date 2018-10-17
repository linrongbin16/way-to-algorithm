<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Extended Euclid - 扩展欧几里得算法

--------

#### 问题

求两个整数$$ x, y $$，满足：

$$

a \times x + b \times y = gcd(a, b)

$$

其中$$ a, b $$是非负整数，$$ gcd(a,b) $$是$$ a, b $$的最大公约数。

#### 解法

欧几里得扩展算法来源于最大公约数的特性，即对于非负整数$$ a, b $$的公约数$$ gcd(a,b) $$，必然存在整数$$ x, y $$满足问题中的等式。

根据上一节Euclid可知通过辗转相除法可以求出$$ a, b $$的最大公约数，每次相除都有：

$$



$$



--------

#### 源码

[EuclidExtension.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidExtension.h)

[EuclidExtension.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidExtension.cpp)

#### 测试

[EuclidExtensionTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidExtensionTest.cpp)
