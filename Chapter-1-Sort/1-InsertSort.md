----------
## <p align="center">Insert Sort</p>
## <p align="center">插入排序</p>

----------
#### 问题：
&emsp;&emsp; 将长度为$n$的无序序列$s$进行排序。

----------
#### 解法：
&emsp;&emsp; 本问题对无序序列$s$进行升序排序，排序后$s$是从小到大的。
&emsp;&emsp; 将长度为$n$的序列$s$分为左右两个部分$left$和$right$，$left$是已序的，范围为$s[0,k]$，$right$是未序的，范围为$s[k+1,n-1]$，其中$0≤k<n$。对$right$中最左边的元素$x=s[k+1]$，在$left$部分中找到一个位置$i$，满足$s[i-1]\leqx\leqs[i]$，也就是说$x$可以夹在$s[i-1]$和$s[i]$之间。为了满足$left$的有序性，将$left$中$s[i,k]$部分的元素向右移动一个位置到$s[i+1,k+1]$，将$x$放置在原$s[i]$的位置即可。
&emsp;&emsp; 例如下图中，$left$部分为$s[0,5]$，$right$部分为$s[6,n-1]$，$right$最左边的首部元素$x=s[6]=41$，在$left$部分中合适的插入位置为$i=3$（$s[2]≤x≤s[3]$）。
<p align="center"><img src="https://github.com/zhaochenyou/Way-to-Algorithm/raw/master/Chapter-1/res/1-InsertSort-1.png" /></p>

