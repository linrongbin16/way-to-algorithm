# Chapter-4 Dynamic Programming
# 第4章 动态规划

--------

1. LinearDP 线性动态规划
    1. [LongestCommonSubsequence 最长公共子序列](LinearDP/LongestCommonSubsequence/)
    2. [LongestIncreasingSubsequence 最长递增子序列](LinearDP/LongestIncreasingSubsequence/)
    3. [BidirectionalSubsequence 双向子序列](LinearDP/BidirectionalSubsequence/)
    4. [MaximumContinuousSubsequenceSum 最大连续子序列和](LinearDP/MaximumContinuousSubsequenceSum/)
    5. [LongestPalindromicSubsequence 最长回文子序列](LinearDP/LongestPalindromicSubsequence/)
2. BagDP 背包问题
    1. [01-Bag 01背包](BagDP/01-Bag/)
    2. [CompleteBag 完全背包](BagDP/CompleteBag/)
    3. [TwoDimensionBag 二维背包](BagDP/TwoDimensionBag/)
3. RegionalDP 区域动态规划
    1. [MinimumMergeCost 最小合并代价](RegionalDP/MinimumMergeCost/)
    2. [UniquePath 唯一路径](RegionalDP/UniquePath/)
    3. [TrianglePath 三角形路径](RegionalDP/TrianglePath/)
4. TreeDP 树形动态规划
    1. [MaximumBinaryTree 最大二叉树](TreeDP/MaximumBinaryTree/)
    2. [MaximumMultipleTree 最大多叉树](TreeDP/MaximumMultipleTree/)
    5. [MaximumBinaryTreeRadiusSum 最大二叉树和](TreeDP/MaximumBinaryTreeRadiusSum/)

--------

#### 动态规划

动态规划（Dynamic Programming）是运筹学（线性规划、网络流也属于运筹学）中的一个问题分支，在查找有很多重叠子问题的情况的最优解时有效。它将问题重新组合成子问题。为了避免多次解决这些子问题（带来巨大的时间复杂度开销），它们的结果都逐渐被计算并被保存，从简单的问题直到整个问题都被解决。因此，动态规划保存递归时的结果，不会在解决同样的问题时花费时间。

动态规划只能应用于有最优子结构的问题。最优子结构的意思是局部最优解能决定全局最优解（对有些问题这个要求并不能完全满足，故有时需要引入一定的近似）。简单地说，问题能够分解成子问题来解决。

动态规划一般使用递归公式求解。递归公式也称作状态转移方程。编码中用多维数组来实现递归公式中每一步计算的结果。常见的动态规划可以划分为线性、区域、树形等。

--------

#### 运筹学

* https://en.wikipedia.org/wiki/Operations_research
* https://book.douban.com/subject/4747771/
