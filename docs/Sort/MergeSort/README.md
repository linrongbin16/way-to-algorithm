<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Merge Sort - 归并排序

--------

#### 问题

用Merge Sort对长度为$$ n $$的无序序列$$ s $$从小到大（升序）排序。

#### 解法

对于长度为$$ n $$的序列$$ s = [x_0, x_1, \dots, x_{n-1}] $$分为左右两个部分，$$ left = [x_0, \dots, x_k] $$和$$ right = [x_{k+1}, \dots, x_{n-1}] $$，其中$$ 0 \le k \le n-1 $$。想象$$ left $$和$$ right $$都是已排序的。如图：

![MergeSort2.png](../res/MergeSort2.png)

将$$ left $$和$$ right $$两个已排序的序列合并即可得到更大的有序序列：

```
function merge(s, k, n):
    let sc = s[0...n-1]
    let i = 0, j = k+1, k = 0
    while i <= k and j <= n-1
        if s[i] < s[j]
            sc[k++] = s[i++]
        else
            sc[k++] = s[j++]
    while i <= k
        sc[k++] = s[i++]
    while j <= n-1
        sc[k++] = s[j++]
    let s = sc
```

(1) `merge`函数第2行：构造长度与`s`相同的数组`sc`，存储$$ left $$和$$ right $$合并后的结果，该结果最终会复制给`s`。该操作需要的空间规模为$$ T(n) $$；

(2) `merge`函数第3-12行：将$$ left $$和$$ right $$按序合并，得到有序序列`sc`；

(3) `merge`函数第13行：将`sc`复制到`s`上；

上述操作如图：

![MergeSort1.png](../res/MergeSort1.png)

递归的将$$ left[0,k] $$和$$ right[k+1,n-1] $$分别拆分为更小的$$ left $$和$$ right $$两部分，假定子部分也是升序的，重复上述操作即可得到有序的$$ left[0,k] $$和$$ right[k+1,n-1] $$。这样递归下去，当某个部分的长度等于1时，可以看作长度为1的有序部分，递归结束。

对于长度$$ n $$的序列$$ s $$，每一轮放置所需要的时间为$$ O(n) $$，总共需要$$ log_2 n $$轮，该算法的时间复杂度为$$ O(n \cdot log_2 n) $$。

归并排序适用于数据量超过内存的应用场景。试想硬盘上存储着100GB的数字需要排序，而可使用的内存只有1GB，显然无法将所有数字都放在内存中排序（也可以是分布在100台机器的数据无法存储在1台服务器这样的分布式应用场景）。从硬盘中依次读取1GB数字，对其排序后写回硬盘。反复100次即可得到100个已序的数组；再将两个已序数组进行归并排序，排序后写回硬盘，得到更长的已序数组；之后同理。最终可将100GB的数字在硬盘上排序。

--------

#### 源码

[MergeSort.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Sort/MergeSort.h)

[MergeSort.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Sort/MergeSort.cpp)

#### 测试

[MergeSortTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Sort/MergeSortTest.cpp)
