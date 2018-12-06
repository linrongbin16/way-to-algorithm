<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Brute Force - 暴力枚举

--------

#### 问题

排列$$ s $$有$$ n $$个元素$$ [x_0,x_1, \dots ,x_{n-1}] $$，每个元素可以选取$$ [1, 2, \dots, m] $$这$$ m $$个值。

例如$$ n = 3, m = 2 $$的排列$$ s $$有以下情况：

$$
\begin{matrix}
[1,1,1] \\
[2,1,1] \\
[1,2,1] \\
[1,1,2] \\
[2,2,1] \\
[2,1,2] \\
[1,2,2] \\
[2,2,2]
\end{matrix}
$$

给定$$ n, m $$的值，用Brute Force求排列$$ s $$的所有情况。

#### 解法

根据乘法原理可以看出，排列$$ s $$生成每种情况都可以看作一件$$ n $$步才能完成的工作，其中每一步都是每个元素的选择过程。第$$ i $$步的完成有$$ m $$个方法，那么共有$$ n^m $$种方法可以完成该工作。

通过遍历求出所有情况，例如对于排列$$ s = [x_0,x_1,x_2,x_3] $$，每个元素的范围是$$ [1,m] $$。需要对$$ 4 $$个元素枚举所有情况，即可求出排列$$ s $$的所有可能。对$$ n $$个元素，每个有$$ m $$个值的排列$$ s $$，遍历所有情况的时间复杂度$$ O(n^m) $$。

--------

#### 源码

[BruteForce.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BruteForce.h)

[BruteForce.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BruteForce.cpp)

#### 测试

[BruteForceTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BruteForceTest.cpp)
