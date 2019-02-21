<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Quick Hull - 快速凸包算法

--------

#### 问题

用Quick Hull算法求拥有$$ n $$个点的点集$$ Q $$的凸包$$ CH(Q) $$，任意两点的坐标不同。

#### 解法

该算法的时间复杂度为$$ O(n \cdot log_2 n) $$。

--------

#### Introduction to Algorithms

* [VII.Selected Topics - 33.Computational Geometry - 33.3.Finding the convex hull](https://www.google.com/search?q=Introduction+to+Algorithms+3rd+Edition+pdf)

--------

#### 源码

[QuickHull.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/QuickHull.h)

[QuickHull.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/QuickHull.cpp)

#### 测试

[QuickHullTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/QuickHullTest.cpp)
