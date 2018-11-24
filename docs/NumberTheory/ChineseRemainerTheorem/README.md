<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Chinese Remainer Theorem - 中国剩余定理

--------

#### 问题

对于非负整数$$ x $$，给定$$ n $$组正整数的除数$$ a_{i} $$和余数$$ m_{i} $$（$$ 0 \leq i \lt n $$）满足：

$$
x \bmod a_{i} = m_{i}
$$

其中所有余数$$ m_{i}, m_{j} $$两两互质。设所有余数的乘积为：

$$
M = m_{0} \times m_{1} \times \cdots \times m_{n-1} = \prod_{i=0}^{n-1} m_{i}
$$

因为任意两个余数互质，显然$$ 0 \leq x \lt M $$。

这样的方程组即为数论中的一元线性同余方程组：

$$
(S) =
\begin{cases}
x \equiv a_{0} \pmod{m_{0}}     \\
x \equiv a_{1} \pmod{m_{1}}     \\
\cdots                          \\
x \equiv a_{n-1} \pmod{m_{n-1}}
\end{cases}
$$

求$$ x $$。

#### 数论倒数/模倒数/模逆元

首先介绍数论倒数，三个整数满足：

$$
a \times b \bmod m = 1
$$

即：

$$
a \times b \equiv 1 \pmod{m}
$$

则称$$ b $$是$$ a $$关于$$ m $$的数论倒数，也称模倒数、模逆元。显然$$ gcd(a, m) $$即为$$ a $$关于$$ m $$的模逆元，可以通过Euclid求出。

#### 中国剩余定理

用中国剩余定理求解一元线性同余方程组。设除了$$ m_{i} $$之外所有余数的乘积为：

$$
M_{i} = \frac{M}{m_{i}}
$$

因为所有余数两两互质，因此存在$$ t_{i} $$为$$ M_{i} $$关于$$ m_{i} $$的模逆元，即：

$$
t_{i} \times M_{i} \equiv 1 \pmod{m_{i}}
$$

可得方程组$$ (S) $$的通解形式为：

$$
x = a_{0} \cdot t_{0} \cdot M_{0} + a_{1} \cdot + t_{1} \cdot M_{1} + \cdots + a_{n-1} \cdot t_{n-1} \cdot M_{n-1} + k \times M = k \times M + \sum_{i=0}^{n-1} a_{i} \cdot t_{i} \cdot M_{i}
$$

其中$$ k $$为整数，$$ 0 \leq i \lt n $$。

对于$$ M $$取模，则有唯一解：

$$
x = \sum_{i=0}^{n-1} a_{i} \cdot t_{i} \cdot M_{i}
$$

该算法的时间复杂度为$$ O(n) $$。

--------

#### 源码

[ChineseRemainerTheorem.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ChineseRemainerTheorem.h)

[ChineseRemainerTheorem.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ChineseRemainerTheorem.cpp)

#### 测试

[ChineseRemainerTheoremTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ChineseRemainerTheoremTest.cpp)
