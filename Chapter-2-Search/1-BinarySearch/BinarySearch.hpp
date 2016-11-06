#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP 1

#ifndef MAX
#define MAX 1024
#endif


/**
 * 在升序序列s中找出x的位置（下标）
 * @params s            升序序列
 * @params beg          序列s的起始下标
 * @params end          序列s的末尾下标加1，即左闭右开区间[beg, end)
 * @params index        返回找到的x下标
 * @return              找到x返回true 否则返回false
 */
bool BinarySearch(int s[MAX], int beg, int end, int x, int &index)
{
    int low = beg;
    int high = end - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid] == x) {
            index = mid;
            return true;
        } else if (s[mid] > x) {
            high = mid - 1;
        } else if (s[mid] < x) {
            low = mid + 1;
        }
    }
    return false;
}


#endif
