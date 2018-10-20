<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Prime Sieve - 素数筛法

--------

#### 问题

素数（质数）是除了$$ 1 $$和它自身没有其他数能够整除的正整数，最小的素数是$$ 2 $$。而不符合该特性的正整数是合数，常见的素数有$$ 2, 3, 5, 7, 9, 11, 13, 17, 19, 23 \dots $$。素数是数论学科中的基础概念，关于素数的最为著名的问题就是哥德巴赫猜想。

判断$$ [2 \dots n-1] $$中哪些是素数，哪些是合数。

#### 简单筛法

按照素数的定义，判断一个正整数$$ n $$是否为素数，需要满足$$ [1, n] $$范围内的所有正整数除了$$ 1, n $$没有其他能够被$$ n $$整除的整数。

即遍历$$ [2, n-1] $$所有数字$$ i $$，判断其是否能被$$ n $$整除（$$ n /% i = 0 $$）即可。

用该算法判断一个正整数是否为素数的时间复杂度为$$ O(n) $$，判断范围$$ [2, n-1] $$内的整数是否为素数的时间复杂度为$$ O(n ^ 2) $$。

#### 埃拉托斯特尼筛法/埃氏筛法（Sieve of Eratosthenes）

埃式筛法设置数组$$ s = [2 \dots n-1] $$，$$ s[i] $$表示数字$$ i $$是否为素数。

$$ (1) $$ 以$$ 2 $$为筛子，除了$$ 2 $$本身所有$$ 2 $$的倍数都不是素数，即$$ s[2] = true, s[2 \times 2] = false, s[2 \times 3] = false, \dots $$；

$$ (2) $$ 以$$ 3 $$为筛子，除了$$ 3 $$本身所有$$ 3 $$的倍数都不是素数，即$$ s[3] = true, s[3 \times 2] = false, s[3 \times 3] = false, \dots $$；

$$ (3) $$ 以$$ 5 $$为筛子，除了$$ 5 $$本身所有$$ 5 $$的倍数都不是素数，即$$ s[5] = true, s[5 \times 2] = false, s[5 \times 3] = false, \dots $$；

$$
\cdots
$$

称这样作为遍历起点的数字为筛子。

若正整数$$ x $$不是素数，那么存在正整数$$ a \times b = x $$，显然$$ a, b $$不能同时大于$$ \sqrt{x} $$。因此筛子只需要选择$$ [2, \lfloor \sqrt{n-1} \rfloor ] $$，即可判断$$ [2, n-1] $$范围内的所有数字是否为素数。

筛子$$ x $$遍历倍数时$$ [2 \cdot x, 3 \cdot x, \dots, x \cdot x, \dots, n-1] $$，其实$$ [2 \cdot x, 3 \cdot, \dots, (x-1) \cdot x] $$这部分已经被之前的筛子$$ [2 \dots x-1] $$筛选过了。即筛子$$ 2 $$筛选了$$ 2 \cdot x $$，筛子$$ 3 $$筛选了$$ 3 \cdot x $$，$$ \dots $$，筛子$$ x - 1 $$筛选了$$ (x-1) \cdot x $$。可以跳过这部分来节省时间。因此对于筛子$$ x $$，只需要遍历$$ [x^2, x^2 + x, \dots, n-1] $$的部分即可。

由于存在某些素数被重复筛选，埃氏筛法的时间复杂度为$$ O(n \cdot log_2 (log_2 n)) $$（证明略）。

--------

#### 素数筛法

* http://101.96.10.63/research.cs.wisc.edu/techreports/1990/TR909.pdf
* https://www.cs.utexas.edu/users/misra/scannedPdf.dir/linearSieve.pdf

--------

#### 源码

[PrimeSieve.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/PrimeSieve.h)

[PrimeSieve.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/PrimeSieve.cpp)


#### 测试

[PrimeSieveTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/NumberTheory/PrimeSieveTest.cpp)
