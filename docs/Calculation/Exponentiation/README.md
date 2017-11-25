# Exponentiation - 求幂运算

--------

#### 问题

求整数$$ x $$的$$ n $$次方的最低8位数字。显然循环计算$$ x * x * ... * x $$共$$ n $$次乘法是错误的算法。

#### 解法

快速求幂算法基于下面的递归公式：

$$
x^n =
\begin{cases}
1                           & n == 0
x                           & n == 1
x * (x ^ 2)^((n - 1) / 2)   & x为奇数
(x ^ 2)^(n / 2)             & x为偶数
\end{cases}
$$

可以写出递归函数来算出$$ x^n $$。因为次方运算会使$$ x $$迅速增大，当我们求最低$$ m $$位数字时，每次计算次方后都可以对$$ m $$取模，防止$$ x $$增大到$$ int32 $$无法表示。

该算法还可以改写为非递归的二进制形式，性能更高。

--------

#### Wikipedia Exponentiation by squaring

* 2k-ary算法
* Sliding-Window算法(滑动窗口算法)
* Montgomery's ladder技术(M的阶梯算法)

--------

#### 源码

[import, lang:"c_cpp"](../../../src/Calculation/LargeNumber.hpp)

#### 测试

[import, lang:"c_cpp"](../../../src/Calculation/LargeNumber.cpp)
