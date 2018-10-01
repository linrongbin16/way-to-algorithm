<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# LargeNumber - 大数字

--------

#### 问题

计算两个整数$$ a $$和$$ b $$的加减乘除，这些数字非常大到无法用内置的$$ int64 $$、$$ float64 $$存储。

#### 解法

将每个数字分为符号、整数区两个部分，模拟加减乘除的运算过程得到结果。设$$ a $$有$$ n_{a} $$位，$$ b $$有$$ n_{b} $$位。

#### 取反

如果$$ a = 0 $$，$$ a $$的负值为它自己，如果$$ a \ne 0 $$，$$ a $$的负值为$$ -a $$。

#### 加法

加法$$ a + b $$有以下情况：

$$ (1) $$相同符号的$$ a, b $$相加可以把整数部分直接相加，符号与$$ a, b $$的符号相同，将$$ 0 $$视作与正数符号相同；

$$ (2) $$不同符号的$$ a, b $$相加可以转化为相同符号的减法，比如$$ 12 + (-4) \rightarrow 12 - 4 $$，$$ (-1) + 8 \rightarrow (-1) - (-8) $$，然后交给减法器处理；

对于相同符号的加法$$ c = a + b $$，从低位（$$ i = 0 \rightarrow max(n_{a} + 1, n_{b} + 1) $$）开始依次计算：

$$

c[i] = ( c[i] + a[i] + b[i] ) % 10 \\
c[i+1] = c[i+1] + ( c[i] + a[i] + b[i] ) \div 10

$$

#### 减法

减法$$ a - b $$有以下情况：

$$ (1) $$ 符号不同的$$ a $$和$$ b $$相减可以转化为符号相同的加法，比如$$ 12 - (-4) \rightarrow 12 + 4 $$，$$ -12 - 4 \rightarrow (-12) + (-4) $$，然后交给加法器处理；

$$ (2) $$ 符号相同的两整数减法，且被减数大于等于减数（$$ a - b, a \ge b $$），可以把整数部分直接相减，符号为正；

$$ (3) $$ 符号相同的两整数减法，且被减数小于减数（$$ a - b, a \lt b $$），可以把两个数字的整数部分交换位置再相减，符号为负；

对于相同符号且满足$$ a \ge b $$的减法$$ c = a - b $$，从高位（$$ i = n_{a} \rightarrow 0 $$）开始依次计算：

$$

c[i] =
\begin{cases}
a[i] - b[i] & a[i] \ge b[i] \\
a[i] + 10 - b[i], c[i+1] = c[i+1] - 1 & a[i] \lt b[i]
\end{cases}

$$

#### 乘法

乘法$$ a \times b $$把整数部分直接相乘。若两数字符号相同其结果的符号为正，若两数字符号不同其结果的符号为负。

对于$$ c = a \times b $$，从低位（$$ i = 0 \rightarrow max(n_{a} + 1, n_{b} + 1) $$）开始依次计算：

$$

c[i] = ( c[i] + a[i] \times b[i] ) % 10 \\
c[i+1] = c[i+1] + ( c[i] + a[i] \times b[i] ) \div 10

$$

#### 除法

数字$$ a \div b $$，除法的模拟有些麻烦，我们会在后面补上。

--------

#### 源码

[LargeNumber.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Calculation/LargeNumber.h)

[LargeNumber.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Calculation/LargeNumber.cpp)

#### 测试

[LargeNumberTest.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Calculation/LargeNumberTest.cpp)
