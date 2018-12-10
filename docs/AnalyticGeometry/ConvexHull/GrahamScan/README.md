<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Graham Scan - Graham扫描算法

--------

#### 问题

用Graham Scan算法求拥有$$ n $$个点的点集$$ Q $$的凸包$$ CH(Q) $$，任意两点的坐标不同。

#### 解法

在二维平面上选取$$ y $$坐标最小，$$ x $$坐标最小的顶点$$ p_0 $$，将其余$$ n-1 $$个顶点$$ [p_1, p_2, \dots, p_{n-1}] $$按照以$$ p_0 $$的顺时针方向排序。如图所示：

<!--![GrahamScan1.png](../res/GrahamScan1.png)-->


--------

#### Introduction to Algorithms

* [VII.Selected Topics - 33.Computational Geometry - 33.3.Finding the convex hull](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[GrahamScan.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/GrahamScan.h)

[GrahamScan.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/GrahamScan.cpp)

#### 测试

[GrahamScanTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/GrahamScanTest.cpp)

