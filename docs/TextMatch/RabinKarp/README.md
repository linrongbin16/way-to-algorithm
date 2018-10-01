<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Rabin Karp - Rabin-Karp算法

--------

#### 问题

在文本$$ text $$中查找字符串$$ pattern $$出现的所有位置（$$ text $$长度为$$ n $$，$$ pattern $$长度为$$ m $$，$$ n, m $$都是正整数且$$ n \gt m $$）。

#### 解法

从位置$$ i, j $$开始的匹配，每次成功的匹配都需要时间复杂度为$$ O(m) $$的遍历，才能确定$$ text[i \dots i+m-1] = pattern[0 \dots m-1] = pattern $$是否成立。如果用$$ hash(i, i+m-1) $$来表示字符串$$ text[i \dots i+m-1] $$的哈希值，$$ hash(pattern) $$表示字符串$$ pattern $$的哈希值，则比较$$ hash(i, i+m-1) = hash(pattern) $$是否成功的时间复杂度为$$ O(1) $$。显然当$$ hash(i, i+m-1) \ne hash(pattern) $$时必然有$$ text[i \dots i+m-1] \ne pattern $$。反之若哈希值相同，再用简单匹配来确定字符串$$ text[i \dots i+m-1] = pattern $$确实为真，这样即可找出所有成功匹配。

我们通过Rabin Fingerprint算法计算字符串的哈希值，ASCII码中每个字符对应的数字值范围在$$ [0 - 127] $$之间，设每读入新的字符时旧的哈希值的扩大倍数为$$ base = 128 $$（这个$$ base $$是字符表大小的范围）。则有：

$$

hash(0, i+1) = hash(0, i) \cdot base + text[i+1]

$$

实际我们想计算的是$$ hash(text[i \dots i+m-1]) $$，当$$ i $$右移一位时，不仅要考虑右边界新加入的字符，还需要考虑左边界离开的字符。一个字符从最右边界一直移动到最左边界，其值乘以$$ base $$共$$ m-1 $$次。因此哈希值要减去$$ base^{m-1} \cdot text[i] $$。特别注意$$ pattern $$长度为$$ 1 $$时$$ base^{m-1} = 1 $$：

$$

hash(i+1, i+m) = hash(i, i+m-1) \cdot base - base^{m-1} \cdot text[i] + text[i+1]

$$

由于数字太大时计算会溢出，用一个较大的素数来对结果取模$$ prime = 16777619 $$，最终得到哈希函数：

$$

hash(i+1, i+m]) = (hash(i, i+m-1) \cdot base - base^{m-1} \cdot text[i] + text[i+1]) % prime

$$


Rabin Fingerprint算法可以连续的处理字符串，在时间复杂度为$$ O(n) $$内求出所有字符串$$ text[i \dots i+m-1] $$的哈希值（其中$$ 0 \ge i \ge n-m+1 $$）。Rabin-Karp算法的时间复杂度为$$ O(n + z \cdot m) $$，其中$$ z $$是模式$$ pattern $$在文本中出现的次数。

--------

Rabin-Karp

* http://www.cs.cmu.edu/afs/cs/academic/class/15451-f14/www/lectures/lec6/karp-rabin-09-15-14.pdf
* https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

Rabin Fingerprint

* http://www.xmailserver.org/rabin.pdf
* https://pdos.csail.mit.edu/papers/lbfs:sosp01/lbfs.pdf

--------

#### 源码

[RabinKarp.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/TextMatch/RabinKarp.h)

[RabinKarp.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/TextMatch/RabinKarp.cpp)

#### 测试

[RabinKarpTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/TextMatch/RabinKarpTest.cpp)
