# LargeNumber - 大数字

--------

#### 问题

计算两个数字$$ a $$和$$ b $$的加减乘除，这些数字非常大，无法用编程语言中内置的$$ int64 $$、$$ float64 $$等类型来存储。

#### 解法

对每个数字设置符号、整数区、小数区三个部分，模拟小学数学中的加减乘除运算过程，得到结果。

#### 取反

如果$$ a \eq 0 $$，$$ a $$的负值为它自己，如果$$ a \ne 0 $$，$$ a $$的负值为$$ -a $$。

#### 加法

数字$$ a + b $$，有两种情况：

$$ (1) $$相同符号：可以把数字部分直接进行相加；

$$ (2) $$不同符号：比如$$ 12 + (-4) $$，可以转化为减法$$ 12 - 4 $$来计算，因此只需要考虑符号相同的两个数字相加；

对于$$ -125.39 + (-91.70935) = -217.09935 $$，从小数区最低位开始相加，注意进位：

$$ (1) $$

![LargeNumber1.svg](../res/LargeNumber1.svg)

$$ (2) $$

![LargeNumber2.svg](../res/LargeNumber2.svg)

$$ (3) $$

![LargeNumber3.svg](../res/LargeNumber3.svg)

$$ (4) $$

![LargeNumber4.svg](../res/LargeNumber4.svg)

$$ (5) $$

![LargeNumber5.svg](../res/LargeNumber5.svg)

#### 减法

数字$$ a - b $$，有两种情况：

$$ (1) $$不同符号：比如$$ 12 - (-4) $$和$$ -12 - 4$$，可以转化为加法$$ 12 + 4 $$和$$ -12 + (-4) $$来计算；

$$ (2) $$相同符号$$ a \lt b $$：比如$$ 1 - 14 $$可以转化为$$ -(14 - 1) $$；

$$ (3) $$相同符号$$ a \ge b $$：直接计算$$ a - b $$；

对于$$ 125.39 - 91.70935 = 33.68065 $$，从整数区最高位开始，注意借位：

$$ (1) $$

![LargeNumber1.svg](../res/LargeNumber1.svg)

$$ (2) $$

![LargeNumber2.svg](../res/LargeNumber2.svg)

$$ (3) $$

![LargeNumber3.svg](../res/LargeNumber3.svg)

$$ (4) $$

![LargeNumber4.svg](../res/LargeNumber4.svg)

$$ (5) $$

![LargeNumber5.svg](../res/LargeNumber5.svg)

#### 乘法

对于$$ -125.39 * 91.70935 = -11499.4353965 $$，从小数区最低位开始，注意进位：

$$ (1) $$

![LargeNumber1.svg](../res/LargeNumber1.svg)

$$ (2) $$

![LargeNumber2.svg](../res/LargeNumber2.svg)

$$ (3) $$

![LargeNumber3.svg](../res/LargeNumber3.svg)

$$ (4) $$

![LargeNumber4.svg](../res/LargeNumber4.svg)

$$ (5) $$

![LargeNumber5.svg](../res/LargeNumber5.svg)

--------

#### 源码

[import, lang:"c_cpp"](../../../../src/Calculation/LargeNumber.hpp)

#### 测试

[import, lang:"c_cpp"](../../../../src/Calculation/LargeNumber.cpp)
