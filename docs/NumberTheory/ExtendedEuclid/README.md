<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Extended Euclid - 扩展欧几里得算法

--------

#### 问题

求两个整数$$ x, y $$，满足不定方程：

$$
a \times x + b \times y = gcd(a, b)
$$

其中$$ a, b $$是正整数，$$ gcd(a,b) $$是$$ a, b $$的最大公约数。

#### 解法

欧几里得扩展算法来源于最大公约数的特性，即对于正整数$$ a, b $$的最大公约数$$ gcd(a,b) $$，必然存在整数$$ x, y $$满足本题的等式。

根据上一节Euclid中的迭代式：

$$
\begin{matrix}
a_{0} & = & a                       \\
b_{0} & = & b                       \\
\cdots                              \\
a_{k} & = & b_{k-1}                 \\
b_{k} & = & a_{k-1} \bmod b_{k-1}
\end{matrix}
$$

存在相应的整数$$ x_{k-1}, y_{k-1}, x_{k}, y_{k} $$满足：

$$
a_{k-1} \times x_{k-1} + b_{k-1} \times y_{k-1} = gcd(a_{k-1}, b_{k-1}) = gcd(a_{k}, b_{k}) = a_{k} \times x_{k} + b_{k} \times y_{k}
$$

变换等式得到：

$$
a_{k-1} \times x_{k-1} + b_{k-1} \times y_{k-1} = b_{k-1} \times x_{k} + (a_{k-1} \bmod b_{k-1}) \times y_{k}
$$

注意到：

$$
a_{k-1} \bmod b_{k-1} = a_{k-1} - \lfloor \frac{a_{k-1}}{b_{k-1}} \rfloor \times b_{k-1}
$$

其中$$ \lfloor x \rfloor $$表示向下取整，小于等于$$ x $$的最大整数。

因此：

$$
a_{k-1} \times x_{k-1} + b_{k-1} \times y_{k-1} = b_{k-1} \times x_{k} + (a_{k-1} - \lfloor \frac{a_{k-1}}{b_{k-1}} \rfloor \times b_{k-1}) \times y_{k}
$$

将上面等式按照参数$$ a_{k-1}, b_{k-1} $$等式变换，得到：

$$
a_{k-1} \cdot (x_{k-1}) + b_{k-1} \cdot (y_{k-1}) = a_{k-1} \cdot (y_{k-1}) + b_{k-1} \cdot (x_{k} - \lfloor \frac{a_{k-1}}{b_{k-1}} \rfloor \cdot y_{k})
$$

由于等式两边括号外的参数完全相同，可得：

$$
\begin{matrix}
x_{k-1} & = & y_{k}       \\
y_{k-1} & = & x_{k} - \lfloor \frac{a_{k-1}}{b_{k-1}} \rfloor \cdot y_{k}
\end{matrix}
$$

递归的最后一步$$ n + 1 $$时有$$ a_{n+1} = b_{n}, b_{n+1} = 0 $$。这时有一组解：

$$
\begin{matrix}
a_{n+1} \times x_{n+1} + b_{n+1} \times y_{n+1} = gcd(a_{n+1}, b_{n+1})     &   x_{n+1} = 1, y_{n+1} = 0
\end{matrix}
$$

在辗转相除发计算最大公约数时，每一步中都可以顺带着计算出这一步的$$ x, y $$，最后得到一组解。该算法的时间复杂度约为$$ O(log_2 (max(a, b))) $$。

--------

#### Exgcd

* https://www.zybuluo.com/samzhang/note/541890

--------

#### 源码

[ExtendedEuclid.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ExtendedEuclid.h)

[ExtendedEuclid.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ExtendedEuclid.cpp)

#### 测试

[ExtendedEuclidTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/ExtendedEuclidTest.cpp)
