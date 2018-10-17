<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Modular Linear Equations - 模线性方程组

--------

#### 问题

求两正整数$$ a $$和$$ b $$的最大公约数（$$ Greatest Common Divisor $$）和最小公倍数（$$ Least Common Multiple $$）。

#### 解法

最大公约数$$ gcd $$的意义是最大的能同时被$$ a, b $$整除的正整数。最小公倍数$$ lcm $$的意义是最小的能同时整除$$ a, b $$的正整数。

比如对于$$ a = 36 $$，能被$$ a $$整除的数字为$$ divisors_{a} = [ 1, 2, 3, 4, 6, 9, 12, 18, 36] $$，能整除$$ a $$的数字为$$ multiples_{a} = [36, 72, 108 \dots] $$。对于$$ b = 66 $$，能被$$ b $$整除的数字为$$ divisors_{b} = [ 1, 2, 3, 6, 11, 22, 33, 66] $$，能整除$$ b $$的数字为$$ multiples_{b} = [66, 132, 198 \dots] $$。那么$$ 36, 66 $$的最大公约数为$$ 6 $$，最小公倍数为$$ 396 $$。

将$$ a = 36, b = 66 $$分解可得$$ 36 = 1 \times 2 \times 2 \times 3 \times 3, 66 = 1 \times 2 \times 3 \times 11 $$，其中每一个数字都称为分解因子。可以把$$ a $$和$$ b $$的分解因子看作两个集合$$ factor_{a} = [1, 2, 2, 3, 3], factor_{b} = [1, 2, 3, 11] $$。

求最大公约数的问题转化为找到一个最大集合满足：

$$

\begin{equation}
factor_{gcd} = [1, g_{1}, g_{2} \dots g_{n}] \\
factor_{gcd} \subseteq factor_{a} \\
factor_{gcd} \subseteq factor_{b}
\end{equation}

$$

则最大公约数为$$ gcd = 1 \times g_{1} \times g_{2} \cdots g_{n} = 1 \times \prod_{i=1}^{n} g_{i} $$。

求最小公倍数的问题转化为找到一个最小集合满足：

$$

\begin{equation}
factor_{lcm} = [1, l_{1}, l_{2} \dots l_{m}] \\
factor_{a} \subseteq factor_{lcm} \\
factor_{b} \subseteq factor_{lcm}
\end{equation}

$$

则最小公倍数为$$ lcm = 1 \times l_{1} \times l_{2} \cdots l_{m} = 1 \times \prod_{i=1}^{m} l_{i} $$。

设$$ r_{k-2} = q_{k} \times r_{k-1} + r_{k} $$，其中$$ 0 \le r_{k} \lt r_{k-1} $$，$$ k \ge 0 $$。初始时令$$ k = 0, r_{-2} = a, r_{-1} = b $$，依次得到：

$$

\begin{matrix}
r_{-2} = q_{0} \times r_{-1} + r_{0}    & k = 0 \\
r_{-1} = q_{1} \times r_{0} + r_{1}     & k = 1 \\
r_{0} = q_{2} \times r_{1} + r_{2}      & k = 2 \\
\cdots
\end{matrix}

$$

或者写作：

$$

\begin{matrix}
r_{0} = r_{-2} \mod r_{-1}  & k = 0 \\
r_{1} = r_{-1} \mod r_{0}   & k = 1 \\
r_{2} = r_{0} \mod r_{1}    & k = 2 \\
\cdots
\end{matrix}

$$

若$$ a \lt b $$，则第一步实际上会交换两个数字的位置，因为必然有$$ a \div b = 0 $$，因此$$ a = b \times 0 + b $$可得$$ r_{0} = b $$。因此对于$$ k \ge 0 $$总有$$ r_{k} \lt r_{k-1} $$。

由于第$$ k $$步得到的余数总有$$ r_{k} \lt r_{k-1} $$越来越小，必然存在某个$$ k = Z $$使得$$ r_{Z} = 0 $$，那么$$ r_{Z-1} $$就是$$ a, b $$得最大公约数。

已知$$ gcd $$为$$ a, b $$的最大公约数，必有$$ a = gcd \times c, b = gcd \times d $$。且$$ c, d, gcd $$三个数字相互无法整除，即互为素数，最大公约数为$$ 1 $$。因此最小公倍数为$$ lcm = gcd \times c \times d $$。

--------

#### 源码

[Euclid.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Euclid.h)

[Euclid.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Euclid.cpp)

#### 测试

[EuclidTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/EuclidTest.cpp)

