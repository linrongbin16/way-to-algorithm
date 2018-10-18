<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Prime Sieve - 素数筛法

--------

#### 问题

素数是除了$$ 1 $$和它自身没有其他数能够整除的正整数，最小的素数是$$ 2 $$。而不符合该特性的正整数是合数，常见的素数有$$ 2, 3, 5, 7, 9, 11, 13, 17, 19, 23 \dots $$。素数是数论学科中的基础概念，关于素数的最为著名的问题就是哥德巴赫猜想。

判断$$ [1 \dots n) $$中哪些是素数，哪些是合数。

#### 素数定义

按照素数的定义，判断一个正整数$$ n $$是否为素数，需要满足$$ [1, n] $$范围内的所有正整数除了$$ 1, n $$没有其他能够被$$ n $$整除的整数。

即遍历$$ [2, n-1] $$所有数字$$ i $$，判断其是否能被$$ n $$整除（$$ n /% i = 0 $$）即可。

用该算法判断一个正整数是否为素数的时间复杂度为$$ O(n) $$，判断范围$$ [1, n] $$内的整数是否为素数的时间复杂度为$$ O(n ^ 2) $$。

#### 埃拉托斯特尼筛法/埃氏筛法（Sieve of Eratosthenes）

埃氏筛法进行了几点优化：

$$ (1) $$ 对于正整数$$ n $$，只需要判断$$ [2, \lfloor \sqrt{n-1} \rfloor ] $$范围内的正整数是否能被整除即可。

可以更快的完成所有判断。

设置数组$$ s = [1 \dots n) $$，$$ s[i] $$表示数字$$ i $$是否为素数。初始时显然有$$ s[1] = false $$。

$$ (1) $$ 以$$ 2 $$为筛子，$$ s[2] = true, s[2 \times 2] = false, s[2 \times 3] = false \dots $$，除了$$ 2 $$本身，所有$$ 2 $$的倍数都不是素数；

$$ (2) $$ 以$$ 3 $$为筛子，$$ s[3] = true, s[3 \times 2] = false, s[3 \times 3] = false \dots $$，除了$$ 3 $$本身，所有$$ 3 $$的倍数都不是素数；

$$ (3) $$ 以$$ 5 $$为筛子，$$ s[5] = true, s[5 \times 2] = false, s[5 \times 3] = false \dots $$，除了$$ 5 $$本身，所有$$ 5 $$的倍数都不是素数；

$$

\cdots

$$

因为显然偶数中除了$$ 2 $$都是合数，可以跳过所有偶数只考察奇数。

埃氏筛法的时间复杂度为$$ O() $$。

#### 欧拉筛法（Euler's Sieve）

--------

#### 源码

[PrimeSieve.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/PrimeSieve.h)

[PrimeSieve.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/PrimeSieve.cpp)


#### 测试

[PrimeSieveTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/PrimeSieveTest.cpp)
