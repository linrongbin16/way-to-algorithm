<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Extended Euclid - 扩展欧几里得算法

--------

#### 问题

求任意100对整数$$ x, y $$，满足不定方程：

$$

a \times x + b \times y = gcd(a, b)

$$

其中$$ a, b $$是正整数，$$ gcd(a,b) $$是$$ a, b $$的最大公约数。

#### 解法

欧几里得扩展算法来源于最大公约数的特性，即对于非负整数$$ a, b $$的公约数$$ gcd(a,b) $$，必然存在整数$$ x, y $$满足问题中的等式。

设：

$$
a \times x_1 + b \times y_1 = gcd(a, b)
$$

又因为：

$$
gcd(a, b) = gcd(b, a % b)
$$

设：

$$
b \times x_2 + (a % b) \times y_2 = gcd(b, a % b)
$$

连合两个等式可得：

$$
a \times x_1 + b \times y_1 = b \times x_2 + (a % b) \times y_2
$$

注意到：

$$
a % b = a - \lceil \frac{a}{b} \rceil \times b
$$

其中$$ \lceil x \rceil $$表示向下取整，小于等于$$ x $$的最大整数。

因此：

$$
a \times x_1 + b \times y_1 = b \times x_2 + (a - \lceil \frac{a}{b} \rceil \times b) \times y_2
$$


--------

#### Exgcd

* https://www.zybuluo.com/samzhang/note/541890


--------

#### 源码

[EuclidExtension.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidExtension.h)

[EuclidExtension.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidExtension.cpp)

#### 测试

[EuclidExtensionTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidExtensionTest.cpp)
