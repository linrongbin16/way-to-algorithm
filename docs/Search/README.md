# Chapter-2 Search
# 第2章 搜索

![Search.png](res/Search.png)

--------

1. [KnowledgePoint 知识要点](KnowledgePoint/README.md)
2. [BinarySearch 二分查找法（折半查找法）](BinarySearch/README.md)
3. [BruteForce 暴力枚举](BruteForce/README.md)
4. [Recursion 递归](Recursion/README.md)
5. [BreadthFirstSearch 广度优先搜索](BreadthFirstSearch/README.md)
6. [BidirectionalBreadthSearch 双向广度搜索](BidirectionalBreadthSearch/README.md)
7. [AStarSearch A\*搜索](AStarSearch/README.md)
8. [DancingLink 舞蹈链](DancingLink/README.md)

--------

#### 平面搜索中的矩阵

下图是一个矩阵$$ matrix $$：

![KnowledgePoint1.png](res/KnowledgePoint1.png)

我们称之为$$ 3 $$行$$ 5 $$列的矩阵，在计算机程序中一般用二位数组$$ m = 5 \times 3 $$表示，$$ matrix[col, row] $$表示第$$ col $$行、第$$ row $$列的元素（也可以颠倒过来表示成$$ matrix[row, col] $$，只需要保证统一即可）。比如：

![KnowledgePoint2.png](res/KnowledgePoint2.png)

![KnowledgePoint3.png](res/KnowledgePoint3.png)

本节中我们将第$$ 1 $$维作为列$$ col $$，将第$$ 2 $$维作为行$$ row $$。

