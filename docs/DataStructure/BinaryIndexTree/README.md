<script type="text/javascript" async src="//cdn.bootcss.com/mathjax/2.7.0/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-MML-AM_CHTML"></script>


--------
[Upper Folder - 上一级目录](../)

[Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DataStructure/BinaryIndexTree.hpp)

[Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DataStructure/BinaryIndexTree.cpp)


--------

<div>
<h1 align="center">Binary Index Tree(Fenwick Tree)</h1>
<h1 align="center">树状数组</h1>
<br>
描述： <br>
&emsp;&emsp;对于包含\(n\)个数字的数组\(s\)，修改其中若干成员\(s[i]\)（其中\(1 \le i \le n\)）后，求数组\(s\)在区间\([p,q]\)（其中\(1 \le p \le q \le n\)）上的所有成员之和。一般是在修改了成员之后，求和时遍历区间\([p,q]\)相加求该区间的和。修改成员\(s[i]\)（其中\(1 \le i \le n\)）的时间复杂度为\(O(1)\)，求\(s[p,q]\)区间的和的时间复杂度为\(O(n)\)。 <br>
&emsp;&emsp;而树状数组可以更快的进行区间求和，将该问题转化为前缀和，即\(s[p,q] = s[1,q] - s[1,q]\)。类似所有整数都可以表示成\(2\)的幂和，也可以把一串序列表示成一系列子序列的和。其中，子序列的个数是其二进制表示中\(1\)的个数，并且子序列代表的\(s[i]\)的个数也是\(2\)的幂。 <br>
\((1)\)LowBit函数 <br>
&emsp;&emsp;函数LowBit用于计算一个数字的二进制形式下最低位的\(1\)代表的十进制的值。比如\(34_{10} = 10,0010_2\)最低位的\(1\)代表的十进制值为\(2_{10}\)，\(12_{10} = 1100_{2}\)最低位的\(1\)代表的十进制值为\(4_{10}\)，\(8_{10} = 1000_2\)最低位的\(1\)代表的十进制值为\(8_{10}\)，则有\(LowBit(34) = 2\)，\(LowBit(12) = 4\)，\(LowBit(8) = 8\)。 <br>
&emsp;&emsp;在C/C++中由于补码的原因，LowBit函数实现如下： <br>
<code style="display: block; white-space: pre-wrap;">
int LowBit(int x) { return x & (x ^ (x-1)); } <br>
</code>
&emsp;&emsp;或者利用计算机补码的特性，写成： <br>
<code style="display: block; white-space: pre-wrap;">
int LowBit(int x) { return x & (-x); } <br>
</code>
&emsp;&emsp;内存中的数字按照补码存储（正整数的补码与原码相同，负整数的补码是原码取反加一，并且最高位\(bit\)设置为\(1\)）。比如： <br>
&emsp;&emsp;\(34_{10} = 0010,0010_{2}\)，则\(- 34_{10} = 1101,1110_{2}\)； <br>
&emsp;&emsp;\(12_{10} = 0000,1100_{2}\)，则\(- 12_{10} = 1111,0100_{2}\)； <br>
&emsp;&emsp;\(8_{10} = 0000,1000_{2}\)，则\(- 8_{10} = 1111,1000_{2}\)； <br>
&emsp;&emsp;对于非负整数\(x\)，\(x\)与\(- x\)进行位与操作，即可得到\(x\)中最低位的\(1\)所代表的十进制的值。比如： <br>
&emsp;&emsp;\(34_{10} \& (- 34_{10} ) = 0010,0010_{2} & 1101,1110_{2} = 10_{2} = 2_{10}\)； <br>
&emsp;&emsp;\(12_{10} \& (- 12_{10} ) = 0000,1100_{2} & 1111,0100_{2} = 100_{2} = 4_{10}\)； <br>
&emsp;&emsp;\[8_{10} & (- 8_{10} ) = 0000,1000_{2} & 1111,1000_{2} = 1000_2 = 8_{10}\]； <br>
&emsp;&emsp;额外需要注意的是，CPU架构中大端模式（Big-Endian）和小端模式（Little-Endian）的区别并不会影响该计算。因为大端和小端影响的是数据在内存中存放的顺序，当数据被CPU加载到寄存器中时，所有的位操作都是在寄存器上进行的，不会影响位操作，因此位操作可以从纯数学计算的角度来看。 <br>
\((2)\)维护\(s\)前缀和的数组\(bit\) <br>
&emsp;&emsp;对于长度为\(n\)的数组\(s\)（该算法需要数组下标从\(1\)开始，因此数组\(s\)的范围为\([1,n]\)），数组\(bit\)中的元素\(bit[i] = \sum_{j = i-LowBit(i)+1}^{i}s[j]\)。比如： <br>
&emsp;&emsp;\(bit[1] = \sum_{j = 1-1+1}^{1}s[j] = s[1]\)； <br>
&emsp;&emsp;\(bit[2] = \sum_{j = 2-2+1}^{2}s[j] = s[1]+s[2]\)； <br>
&emsp;&emsp;\(bit[3] = \sum_{j = 3-1+1}^{3}s[j] = s[3]\)； <br>
&emsp;&emsp;\(bit[4] = \sum_{j = 4-4+1}^{4}s[j] = s[1]+s[2]+s[3]+s[4]\)； <br>
&emsp;&emsp;\(bit[5] = \sum_{j = 5-1+1}^{5}s[j] = s[5]\)； <br>
&emsp;&emsp;\(bit[6] = \sum_{j = 6-2+1}^{6}s[j] = s[5]+s[6]\)； <br>
&emsp;&emsp;\(bit[7] = \sum_{j = 7-1+1}^{7}s[j] = s[7]\)； <br>
&emsp;&emsp;\(bit[8] = \sum_{j = 8-8+1}^{8}s[j] = s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]\)； <br>
&emsp;&emsp;\(bit[9] = \sum_{j = 9-9+1}^{9}s[j] = s[9]\)； <br>
&emsp;&emsp;在数组\(bit\)的基础上，求数组\(s\)中\([0,p]\)的和，只需累加所有\(bit[i]\)，其中初始时\(i = p\)，每累加一次\(bit[i]\)，\(i\)值减去\(LowBit(i)\)，直到\(i \le 0\)。（这里我暂时也没找到更好的讲解方法，解释的不是很清晰） <br>
&emsp;&emsp;对于长度为\(n\)的数组\(s\)，构造树状数组的时间复杂度为\(O(n \cdot log_2⁡n)\)，查询区域和的时间复杂度为\(O(log_2 n)\)，修改数组\(s\)中一个值的时间复杂度为\(O(log_2⁡n)\)，空间复杂度为\(O(n)\)。 <br>
</div>

<br>
树状数组（Fenwick tree）：
* [https://en.wikipedia.org/wiki/Fenwick_tree](https://en.wikipedia.org/wiki/Fenwick_tree)
* [http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.14.8917](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.14.8917)


--------
--------
