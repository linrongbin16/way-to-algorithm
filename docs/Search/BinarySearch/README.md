<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Binary Search - 二分查找法（折半查找法）

--------

#### 问题

在长度为$$ n $$的升序（从小到大）序列$$ s $$中查找元素$$ x $$的位置。

#### 解法

令$$ low = 0, high = n-1, mid = \lfloor \frac{low+high}{2} \rfloor $$，元素$$ x $$与$$ mid $$的关系有三种情况：

(1) 若$$ x = s[mid] $$，显然已经查询到元素$$ x $$的位置，算法结束；

(2) 若$$ x \lt s[mid] $$，则$$ x $$处于$$ s[mid] $$左边；

(3) 若$$ x \gt s[mid] $$，则$$ x $$处于$$ s[mid] $$右边；

该操作用伪代码表示为：

```
function Search(s, low, high, x):
    let mid = (low + high) / 2
    if x = s[mid]
        return true, mid
    else if x < s[mid]
        return false, low, mid-1
    else if x > s[mid]
        return false, mid+1, high
```

(1) Search函数第2行：计算搜索范围的中间位置$$ mid $$，以$$ s[mid] $$为基准与$$ x $$进行比较；

(2) Search函数第3-8行：比较$$ s[mid] $$和$$ x $$，若$$ x = s[mid] $$则找到结果，若$$ x \lt s[mid] $$则在$$ s[low, mid-1] $$继续寻找，若$$ x \gt s[mid] $$则在$$ s[mid+1, high] $$继续寻找；

上述操作，可以用下图中的示例：

若$$ x = 17 = s[mid] $$，可以直接找到$$ x = s[4] $$：

![BinarySearch1.png](../res/BinarySearch1.png)

若$$ x = 5 \lt s[mid] = 17 $$，则令$$ high = 3 $$之后继续搜索：

![BinarySearch2.png](../res/BinarySearch2.png)

若$$ x = 30 \gt s[mid] = 17 $$，则令$$ low = 5 $$之后继续搜索：

![BinarySearch3.png](../res/BinarySearch3.png)

外围只需循环调用Search函数即可：

```
function BinarySearch(s, n, x):
    let low = 0, high = n-1
    while low <= high
        let found, low, high = Search(s, low, high, x)
        if found
            return low
    return -1
```

#### 复杂度

Search函数的输入规模为$$ T(4) $$，该函数中最多有1次加法、1次除法、3次比较操作，因此时间复杂度为

$$
T(4) = O(5) = O(1)
$$

BinarySearch函数的输入规模为$$ T(n) $$，每次调用Search函数后$$ high - low $$的值都会减小一半，即

$$
\begin{matrix}
T(n)    & = &   T(\frac{n}{2}) + O(1)               \\
        & = &   T(\frac{n}{2^2}) + 2 \cdot O(1)     \\
        & = &   T(\frac{n}{2^3}) + 3 \cdot O(1)     \\
        & = &   \cdots
\end{matrix}
$$

假设递归层数为$$ L $$，可得：

$$
T(\frac{n}{2^L}) = 1
$$

即：

$$
L = T(log_2 n) = O(log_2 n)
$$

将$$ L $$代入原始递推公式，可得：

$$
\begin{matrix}
T(n)    & = &   T(\frac{n}{2^L}) + L \cdot O(1) \\
        & = &   O(1) + O(log_2 n) \cdot O(1)    \\
        & = &   O(log_2 n)
\end{matrix}
$$

该算法时间复杂度为$$ O(log_2 n) $$，空间复杂度为$$ O(1) $$。

#### 源码

[BinarySearch.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BinarySearch.h)

[BinarySearch.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BinarySearch.cpp)

#### 测试

[BinarySearchTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/Search/BinarySearchTest.cpp)
