<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Brute Force - 暴力枚举

--------

#### 问题

排列$$ s $$有$$ n $$个元素$$ [x_0,x_1, \dots ,x_{n-1}] $$，每个元素可以选取$$ [0, 1, \dots, m-1] $$这$$ m $$种值。

例如$$ n = 3, m = 2 $$的序列$$ s $$有以下情况：

$$
\begin{matrix}
[0,0,0] \\
[1,0,0] \\
[0,1,0] \\
[0,0,1] \\
[1,1,0] \\
[1,0,1] \\
[0,1,1] \\
[1,1,1]
\end{matrix}
$$

给定$$ n, m $$的值，求序列$$ s $$的所有情况。

#### 原理

加法原理：完成一件事情有$$ n $$类方法，每类方法有若干子方法，完成这件事需要且只需要$$ n $$类方法中的一类方法中的一个子方法。第$$ 1 $$类方法有$$ m_1 $$种子方法，第$$ 2 $$类方法有$$ m_2 $$种子方法，$$ \dots $$，第$$ n $$类方法有$$ m_n $$种子方法。则完成这件事共有$$ m_1 + m_2 + \cdots + m_n $$种方法。

乘法原理：完成一件事情需要$$ n $$个步骤，每个步骤有若干子方法，完成这件事情需要$$ n $$个步骤都完成，每个步骤需要且只需要选择一种方法。第$$ 1 $$步有$$ m_1 $$种子方法，第$$ 2 $$步有$$ m_2 $$种子方法，$$ \dots $$，第$$ n $$步有$$ m_n $$种子方法。则完成这件事共有$$ m_1 \times m_2 \times \cdots \times m_n $$种方法。

#### 解法

通过遍历求出所有情况，例如对于排列$$ s = [x_0,x_1,x_2,x_3] $$，每个元素的范围是$$ [0,m-1] $$。需要对$$ 4 $$个元素枚举所有情况，即可求出排列$$ s $$的所有可能。对$$ n $$个元素，每个有$$ m $$个值的序列$$ s $$，遍历所有情况的时间复杂度$$ O(n^m) $$。

--------

#### 源码

[BruteForce.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BruteForce.h)

[BruteForce.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BruteForce.cpp)

#### 测试

[BruteForceTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BruteForceTest.cpp)
