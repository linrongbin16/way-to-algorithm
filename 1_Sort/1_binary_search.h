#ifndef SORT_BINARY_SEARCH_H
#define SORT_BINARY_SEARCH_H 1
//二分查找法 折半查找法
//binary search

//在从小到大排序的序列s中查找元素x是否存在

//序列s已经是升序的
//直接查看序列s最左最右和中间三个位置处的元素值
//比较元素x是否和中间元素相等 若相等则该中间元素的位置即为所求
//否则若x比中间元素小 则x必然在最左元素和中间元素之间 设置新的查找范围
//若x比中间元素大 则x必然在中间元素和最右元素之间 设置新的查找范围
//按同样思路继续比较元素x和新的查找范围内的中间元素的值
//直到找到相等值的元素或者没有新的范围为止 即可得到结果

#ifndef MAX
#define MAX 60
#endif

int binary_search(int s[MAX], int beg, int end, int x, int &idx)
{
	//[beg, end)是左闭右开区间 s为已序序列 下标从beg到end-1 查找元素值x
	//idx返回查找的下标 返回int标志查找成功与否
	//若查找不成功返回最接近x且比x小的元素下标
    int low = beg;
    int high = end - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid] == x) {
            idx = mid;
            return(1);
        }
        else if(s[mid] > x)
            high = mid - 1;
        else if(s[mid] < x)
            low = mid + 1;
    }
    return(0);
}


#endif
