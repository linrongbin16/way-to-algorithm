# Chapter-4 Dynamic Programming
# 第4章 动态规划

--------

1. LinearDP 线性动态规划
    1. [LongestCommonSubsequence 最长公共子序列](LinearDP/LongestCommonSubsequence/)
    2. [LongestIncreasingSubsequence 最长递增子序列](LinearDP/LongestIncreasingSubsequence/)
    3. [LongestIncreasingSubsequenceExtension 最长递增子序列扩展](LinearDP/LongestIncreasingSubsequenceExtension/)
    4. [BidirectionalSubsequence 双向子序列](LinearDP/BidirectionalSubsequence/)
2. BagDP 背包问题
    1. [ZeroOneBag 01背包](BagDP/ZeroOneBag/)
    2. [ZeroOneBagExtension 01背包扩展](BagDP/ZeroOneBagExtension/)
    3. [CompleteBag 完全背包](BagDP/CompleteBag/)
    4. [TwoDimensionBag 二维背包](BagDP/TwoDimensionBag/)
    5. [GroupBag 分组背包](BagDP/GroupBag/)
3. RegionalDP 区域动态规划
    1. [MinimumMergeCost 最小合并代价](RegionalDP/MinimumMergeCost/)
    2. [MinimumMergeCostExtension 最小合并代价扩展](RegionalDP/MinimumMergeCostExtension/)
    3. [MaximumBinaryTreeMerge 最大二叉树合并](RegionalDP/MaximumBinaryTreeMerge/)
4. TreeDP 树形动态规划
    1. [BinaryTreeDP 二叉树动规](TreeDP/BinaryTreeDP/)
    2. [MultipleTreeDP 多叉树动规](TreeDP/MultipleTreeDP/)
    3. [MultipleTreeDPExtension 多叉树动规问题扩展](TreeDP/MultipleTreeDPExtension/)
    4. [LoopedMultipleTreeDP 带环多叉树动规](TreeDP/LoopedMultipleTreeDP/)
    5. [TraverseBinaryTreeDP 遍历二叉树动规](TreeDP/TraverseBinaryTreeDP/)

--------

#### 动态规划

动态规划（Dynamic Programming）是运筹学（线性规划、网络流也属于运筹学）中的一个问题分支，用于求解最优解。Dynamic Programming将一个复杂的问题拆分为多个阶段的决策，决策函数用$$ f $$表示。基本特性如下：

$$ (1) $$ 每个决策所做的计算都只针对当前阶段；

$$ (2) $$ 当前阶段仅仅依赖于上一阶段，与再前面的阶段无关；

$$ (3) $$ 当前阶段的决策为未来决策做出一个

动态规划一般使用递归公式求解。递归公式也称作状态转移方程。

最优性原则：对以后阶段所做出的未来决策会产生一个最优策略，它与前面各阶段所采用的策略无关。

本书中我们将动态规划问题分为$$ 4 $$个部分：

$$ (1) $$ 线性DP；

$$ (2) $$ 背包问题；

$$ (3) $$ 区域DP；

$$ (4) $$ 树型DP；

--------

#### 运筹学

* https://en.wikipedia.org/wiki/Operations_research
* https://book.douban.com/subject/4747771/
