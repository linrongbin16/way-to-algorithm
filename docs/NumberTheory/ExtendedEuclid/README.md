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
a % b = a - \lfloor \frac{a}{b} \rfloor \times b
$$

其中$$ \lfloor x \rfloor $$表示向下取整，小于等于$$ x $$的最大整数。

因此：

$$
a \times x_1 + b \times y_1 = b \times x_2 + (a - \lfloor \frac{a}{b} \rfloor \times b) \times y_2
$$

将上面等式按照参数$$ a, b $$进行调整，得到：

$$
a \cdot (x_1) + b \cdot (y_1) = a \cdot (y_1) + b \cdot (x_2 - \lfloor \frac{a}{b} \rfloor \cdot y_2)
$$

由于等式两边括号外的参数完全相同，可得：

$$
\begin{matrix}
x_1 = y_2       \\
y_1 = x_2 - \lfloor \frac{a}{b} \rfloor \cdot y_2
\end{matrix}
$$

根据欧几里得定理，设$$ a_0, b_0 $$为原始的$$ a, b $$，用迭代式表达：

$$
\begin{matrix}
a_{0} = a, b_{0} = b    \\
gcd(a_{0}, b_{0}) = gcd(b_{0}, a_{0} % b_{0}) = gcd(a_{1}, b_{1}) & \rightarrow & a_{1} = b_{0}, b_{1} = a_{0} % b_{0}  \\
gcd(a_{1}, b_{1}) = gcd(b_{1}, a_{1} % b_{1}) = gcd(a_{2}, b_{2}) & \rightarrow & a_{2} = b_{1}, b_{2} = a_{1} % b_{1}  \\
gcd(a_{2}, b_{2}) = gcd(b_{2}, a_{2} % b_{2}) = gcd(a_{3}, b_{3}) & \rightarrow & a_{3} = b_{2}, b_{3} = a_{2} % b_{2}  \\
\cdots
gcd(a_{i}, b_{i}) = gcd(b_{i}, a_{i} % b_{i}) = gcd(a_{i+1}, b_{i+1}) & \rightarrow & a_{i+1} = b_{i}, b_{i+1} = a_{i} % b_{i}  \\
\cdots
gcd(a_{n}, b_{n}) = gcd(b_{n}, a_{n} % b_{n}) = gcd(a_{n+1}, 0) & \rightarrow & a_{n+1} = b_{n}, b_{n+1} = 0  \\
\end{matrix}
$$


--------

#### Exgcd

* https://www.zybuluo.com/samzhang/note/541890

--------

#### 源码

[ExtendedEuclid.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ExtendedEuclid.h)

[ExtendedEuclid.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ExtendedEuclid.cpp)

#### 测试

[ExtendedEuclidTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ExtendedEuclidTest.cpp)
