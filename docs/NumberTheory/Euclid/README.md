<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Euclid - 欧几里得算法（辗转相除法）

--------

#### 问题

求两正整数$$ a $$和$$ b $$的最大公约数（$$ Greatest Common Divisor $$）和最小公倍数（$$ Least Common Multiple $$），最大公约数、最小公倍数满足以下特性：

$$

\begin{matrix}
gcd \times x = a \\
gcd \times y = b \\
a \times p = lcm \\
b \times q = lcm
\end{matrix}

$$

上面四个方程中的$$ a, b, x, y, p, q, gcd, lcm $$均为非负整数。$$ 0 $$和另一个正整数的最大公约数为另一个整数，因为$$ 0 $$除以任何正整数都可以整除。

#### 解法

最大公约数$$ gcd $$的意义是最大的能同时被$$ a, b $$整除的正整数。最小公倍数$$ lcm $$的意义是最小的能同时整除$$ a, b $$的正整数。

比如对于$$ a = 36 $$，能被$$ a $$整除的数字为$$ divisors_{a} = [ 1, 2, 3, 4, 6, 9, 12, 18, 36] $$，能整除$$ a $$的数字为$$ multiples_{a} = [36, 72, 108 \dots] $$。对于$$ b = 66 $$，能被$$ b $$整除的数字为$$ divisors_{b} = [ 1, 2, 3, 6, 11, 22, 33, 66] $$，能整除$$ b $$的数字为$$ multiples_{b} = [66, 132, 198 \dots] $$。那么$$ 36, 66 $$的最大公约数为$$ 6 $$，最小公倍数为$$ 396 $$。

将$$ a = 36, b = 66 $$分解可得$$ 36 = 2 \times 2 \times 3 \times 3, 66 = 2 \times 3 \times 11 $$，其中每一个数字都称为分解因子。可以把$$ a $$和$$ b $$的分解因子看作两个集合$$ factor_{a} = [2, 2, 3, 3], factor_{b} = [2, 3, 11] $$。分解因子是一个NP完全问题。

设$$ gcd(a, b) $$表示非负整数$$ a, b $$的最大公约数，根据欧几里得定理，任意正整数$$ a $$和$$ b $$满足：

$$

gcd(a, b) =
\begin{cases}
b                   &   a % b = 0   \\
gcd(b, a % b)       &   a % b \neq 0
\end{cases}

$$

也可以写作：

$$

gcd(a, b) =
\begin{cases}
a                   &   b = 0   \\
gcd(b, a % b)       &   b \neq 0
\end{cases}

$$

若$$ a \lt b $$，则第一步实际上会交换两个数字的位置，因为必然有$$ a \div b = 0 $$。每一步得到的余数$$ a % b $$都会越来越小，必然存在一个数字$$ r $$使得$$ gcd(r, 0) = gcd(a, b) $$，$$ r $$即为$$ a, b $$的最大公约数。

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
gcd(a, b) \times lcm(a, b)  & = 4 \times 120 = & 24 \times 20 = 480                      \\
gcd(a, lcm(b, c)) = gcd(24, 60) & = 12 = & lcm(gcd(a, b), gcd(a, c)) = lcm(4, 6)        \\
lcm(a, gcd(b, c)) = lcm(24, 10) & = 120 = & gcd(lcm(a, b), lcm(a, c)) = gcd(120, 120)
\end{matrix}

$$

因此最小公倍数为$$ lcm = a \times b \div gcd $$。

欧几里得算法的时间复杂度约为$$ O(log_2 n) $$。

--------

#### 源码

[Euclid.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Euclid.h)

[Euclid.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Euclid.cpp)

#### 测试

[EuclidTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidTest.cpp)
