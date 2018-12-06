<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Euclid - 欧几里得算法（辗转相除法）

--------

#### 问题

求两正整数$$ a $$和$$ b $$的最大公约数（$$ Greatest Common Divisor $$）和最小公倍数（$$ Least Common Multiple $$）。

#### 解法

设$$ gcd(a, b) $$表示非负整数$$ a, b $$的最大公约数，根据欧几里得定理，任意正整数$$ a $$和$$ b $$满足：

$$

gcd(a, b) =
\begin{cases}
b                       &   a \bmod b = 0   \\
gcd(b, a \bmod b)       &   a \bmod b \neq 0
\end{cases}

$$

也可以写作：

$$

gcd(a, b) =
\begin{cases}
a                       &   b = 0   \\
gcd(b, a \bmod b)       &   b \neq 0
\end{cases}

$$

若$$ a \lt b $$，则第一步实际上会交换两个数字的位置，因为必然有$$ a \div b = 0 $$。每一步得到的余数$$ a \bmod b $$都会越来越小，必然存在一个数字$$ r $$使得$$ gcd(r, 0) = gcd(a, b) $$，$$ r $$即为$$ a, b $$的最大公约数。

设$$ a_0, b_0 $$为原始的$$ a, b $$，用迭代式表达：

$$
\begin{matrix}
a_{0} = a, b_{0} = b    \\
gcd(a_{0}, b_{0}) = gcd(b_{0}, a_{0} \bmod b_{0}) = gcd(a_{1}, b_{1}) & \rightarrow & a_{1} = b_{0}, b_{1} = a_{0} \bmod b_{0}  \\
gcd(a_{1}, b_{1}) = gcd(b_{1}, a_{1} \bmod b_{1}) = gcd(a_{2}, b_{2}) & \rightarrow & a_{2} = b_{1}, b_{2} = a_{1} \bmod b_{1}  \\
gcd(a_{2}, b_{2}) = gcd(b_{2}, a_{2} \bmod b_{2}) = gcd(a_{3}, b_{3}) & \rightarrow & a_{3} = b_{2}, b_{3} = a_{2} \bmod b_{2}  \\
\cdots  \\
gcd(a_{i}, b_{i}) = gcd(b_{i}, a_{i} \bmod b_{i}) = gcd(a_{i+1}, b_{i+1}) & \rightarrow & a_{i+1} = b_{i}, b_{i+1} = a_{i} \bmod b_{i}  \\
\cdots  \\
gcd(a_{n}, b_{n}) = gcd(b_{n}, a_{n} \bmod b_{n}) = gcd(a_{n+1}, 0) & \rightarrow & a_{n+1} = b_{n}, b_{n+1} = 0  \\
\end{matrix}
$$

对于第$$ k $$步递归，有$$ a_{k} = b_{k-1}, b_{k} = a_{k-1} \bmod b_{k-1} $$。迭代到第$$ n + 1 $$步时得到$$ a_{n+1} = b_{n}, b_{n+1} = 0 $$，$$ a_{n+1}, b_{n} $$即为最大公约数。

最大公约数、最小公倍数有以下特性：

$$
\begin{matrix}
gcd(a,b) \times lcm(a,b) & = & a \times b           \\
gcd(a, lcm(b, c)) & = & lcm(gcd(a, b), gcd(a, c))   \\
lcm(a, gcd(b, c)) & = & gcd(lcm(a, b), lcm(a, c))
\end{matrix}
$$

比如$$ a = 24, b = 20, c = 30 $$，满足以下等式：

$$
\begin{matrix}
gcd(a, b) \times lcm(a, b)    & = &   4 \times 120              & = & 24 \times 20  & = & 480                      \\
gcd(a, lcm(b, c))           & = &   gcd(24, 60) & = & 12        & = &   lcm(gcd(a, b), gcd(a, c))   & = & lcm(4, 6)        \\
lcm(a, gcd(b, c))           & = &   lcm(24, 10) & = & 120       & = &   gcd(lcm(a, b), lcm(a, c))   & = & gcd(120, 120)
\end{matrix}
$$

则最小公倍数为$$ lcm = a \times b \div gcd $$。

欧几里得算法的时间复杂度约为$$ O(log_2 (max(a, b))) $$。

--------

#### 源码

[Euclid.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Euclid.h)

[Euclid.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Euclid.cpp)

#### 测试

[EuclidTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidTest.cpp)
