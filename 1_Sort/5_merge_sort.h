#ifndef SORT_MERGE_H
#define SORT_MERGE_H 1

//TODO: 该算法有错误
//归并排序
//归并排序是建立在归并操作上的一种有效的排序算法
//该算法是采用分治法(Divide and Conquer)的一个非常典型的应用
//将已有序的子序列合并 得到完全有序的序列 即先使每个子序列有序
//再使子序列段间有序 若将两个有序表合并成一个有序表 称为二路归并 
//归并过程为: 比较a[i]和a[j]的大小 若a[i]<=a[j] 则将第一个有序表中的元素a[i]复制到r[k]中 并令i和k分别加上1
//否则将第二个有序表中的元素a[j]复制到r[k]中 并令j和k分别加上1 如此循环下去 直到其中一个有序表取完 
//然后再将另一个有序表中剩余的元素复制到r中从下标k到下标t的单元
//归并排序的算法我们通常用递归实现
//先把待排序区间[s,t]以中点二分 接着把左边子区间排序 再把右边子区间排序
//最后把左区间和右区间用一次归并操作合并成有序的区间[s,t]
//参考博客: http://blog.csdn.net/u011889952/article/details/44775331

#ifndef MAX
#define MAX 60
#endif

void merge(int A[], int p, int q, int r)
{
    int A1[MAX];
    int A2[MAX];
    int i,j,k;
    for ( i=0; i<q-p+1; i++)
        A1[i] = A[p+i];
    for ( i=0; i<r-q; i++)
        A2[i] = A[q+1+i];
    for ( i=0, j=0, k=p; i<(q-p+1) && j<(r-q); ++k) {
        if (A1[i]<=A2[j]) {
            A[k] = A1[i];
            i++;
        }
        else {
            A[k] = A2[j];
            j++;
        }
    }
    for (i; i<q-p+1; i++,k++)
        A[k] = A1[i];

    for (j; j<r-q; j++,k++)
        A[k] = A2[j];
}
void merge_sort(int A[],int l,int r)
{
    if(l==r)
        return;
    merge_sort(A,l,(l+r)/2);
    merge_sort(A,(l+r)/2+1,r);
    merge(A,l,(l+r)/2,r);
    return ;
}

#endif

