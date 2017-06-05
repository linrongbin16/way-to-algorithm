* [Upper Folder - 上一级目录](../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/CombinatorialMathematics/FullPermutation.cpp)

--------

### Permutation
### 排列
<div>
问题：
<p id="i">求\(n\)个不同元素\(A = [a_0,a_1,a_2, \cdots ,a_{n-1}]\)中任意取\(m\)个元素（\(m \leq n\)，\(m\)和\(n\)都是自然数）的所有排列。 </p>
解法：
<p id="i">在&lt;Full Permutation&gt;和&lt;Combination&gt;的基础上可知，从拥有\(n\)个元素的\(A\)中任意选取\(m\)个元素，得到的所有组合的集合为\(P\)，\(P\)中的每个元素都是\(A\)的一种组合，且任意两个元素不相同。对\(P\)中的每个元素进行全排列，得到的排列即为所求。 </p>
<p id="i">比如对于\(A = [1,2,3,4,5]\)，从中取出\(3\)个元素。其所有组合为：\([1,2,3]\)、\([1,2,4]\)、\([1,2,5]\)、\([1,3,4]\)、\([1,3,5]\)、\([1,4,5]\)、\([2,3,4]\)、\([2,3,5]\)、\([3,4,5]\)。 </p>
<p id="i">对其中的每个组合都进行全排列。其中\([1,2,3]\)的全排列为：\([1,2,3]\)、\([2,1,3]\)、\([2,3,1]\)、\([3,2,1]\)、\([3,1,2]\)、\([1,3,2]\)。类似的对其他组合也进行全排列，得到的所有排列即为从\(A = [1,2,3,4,5]\)中取出\(3\)个元素得到的所有排列。 </p>
<p id="i">该算法的时间复杂度为\(P_m^n = \frac{n!}{(n-m)!}\)。 </p>
</div>
