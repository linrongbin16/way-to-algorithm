<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Exponentiation - 求幂运算

--------

#### 问题

求整数$$ x^n $$的最低$$ m $$位数字。

#### 解法

循环的进行$$ x \times x \times \cdots \times x $$共$$ n $$次乘法，然后截取最低$$ m $$位数字，该算法的时间复杂度为$$ O(n) $$。显然太慢了。

快速求幂算法如下：

$$
x^n =
\begin{cases}
1                                   &   n = 0
x                                   &   n = 1
x \times (x^2)^{\frac_{n-1}{2}}     &   x is odd
(x^2)^{\frac_{n}{2}}                &   x is even
\end{cases}
$$

因为次方运算会使$$ x $$迅速增大，导致内置变量$$ int32, int64 $$溢出，因此需要每次计算后对$$ m $$取模。

快速求幂算法的时间复杂度为$$ O(log_2 n) $$。

--------

#### Wikipedia Exponentiation by squaring

* 2k-ary算法
* Sliding-Window算法(滑动窗口算法)
* Montgomery's ladder技术(M的阶梯算法)

--------

#### 源码

[Exponentiation.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Calculation/Exponentiation.h)

[Exponentiation.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Calculation/Exponentiation.cpp)

#### 测试

[ExponentiationTest.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Calculation/ExponentiationTest.cpp)
