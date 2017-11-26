# Unique Subset - 唯一的子集

--------

#### 问题

<p id="i">求拥有\(n\)个元素的集合\(A = \{a_0,a_1,a_2, \cdots ,a_{n-1} \}\)中的不重复的所有子集。 </p>

#### 解法

<p id="i">拥有\(n\)个元素的集合\(A\)的所有子集，可以看作从集合\(A\)中取出\(0\)个元素的所有组合、取出\(1\)个元素的所有组合、...取出\(n-1\)个元素的所有组合、取出\(n\)个元素的所有组合，这些所有组合即为所求。 </p>
<p id="i">具体从n个元素的集合中取出m个元素的所有组合，可以通过<Combination>中的算法求出。因此子集问题只需要遍历所有元素个数即可。</p>
<p id="i">该算法的时间复杂度为\(C_m^n = \frac{n!}{m! \cdot (n-m)!} \)。 </p>
</div>

--------

* [Upper Folder - 上一级目录](../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/Subset.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/Subset.cpp)
