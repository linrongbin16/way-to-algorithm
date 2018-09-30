<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>

# Sieve - 筛选算法

--------

#### 问题

素数是除了$$ 1 $$和它自身没有其他数能够整除的正整数，最小的素数是$$ 2 $$。而不符合该特性的正整数是合数，常见的素数有$$ 2, 3, 5, 7, 9, 11, 13, 17, 19, 23 \dots $$。素数是数论学科中的基础概念，关于素数的最为著名的问题就是哥德巴赫猜想。

判断$$ [1 \dots n) $$中哪些是素数，哪些是合数。

#### 解法

按照素数的定理，判断一个正整数$$ x $$是否为素数，需要遍历$$ [1 \dots x] $$中所有数字$$ i $$是否能被$$ x $$整除，即$$ x % i = 0 $$。判断一个数字的时间复杂度为$$ O(n) $$，判断$$ n $$个数字的时间复杂度为$$ O(n ^ 2) $$。埃拉托斯特尼筛选法（Eratosthenes Sieve）可以更快的完成所有判断。

设置数组$$ s = [1 \dots n) $$，$$ s[i] $$表示数字$$ i $$是否为素数。初始时显然有$$ s[1] = false $$。

$$ (1) $$ 以$$ 2 $$为筛子，$$ s[2] = true, s[2 \times 2] = false, s[2 \times 3] = false \dots $$，除了$$ 2 $$本身，所有$$ 2 $$的倍数都不是素数；

$$ (2) $$ 以$$ 3 $$为筛子，$$ s[3] = true, s[3 \times 2] = false, s[3 \times 3] = false \dots $$，除了$$ 3 $$本身，所有$$ 3 $$的倍数都不是素数；

$$ (3) $$ 以$$ 5 $$为筛子，$$ s[5] = true, s[5 \times 2] = false, s[5 \times 3] = false \dots $$，除了$$ 5 $$本身，所有$$ 5 $$的倍数都不是素数；

$$

\cdots

$$

因为显然偶数中除了$$ 2 $$都是合数，可以跳过所有偶数只考察奇数。

--------

#### 源码

[Sieve.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Sieve.h)

[Sieve.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/Sieve.cpp)

[import, lang:"c_cpp"](../../../src/NumberTheory/Sieve.h)

[import, lang:"c_cpp"](../../../src/NumberTheory/Sieve.cpp)

#### 测试

[SieveTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/SieveTest.cpp)

[import, lang:"c_cpp"](../../../src/NumberTheory/SieveTest.cpp)
