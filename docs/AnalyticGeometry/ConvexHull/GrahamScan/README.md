<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Graham Scan - Graham扫描算法

--------

#### 问题

用Graham Scan算法求拥有$$ n $$个点的点集$$ Q $$的凸包$$ CH(Q) $$，任意两点的坐标不同。

#### 解法

在二维平面上选取$$ y $$坐标最小，$$ x $$坐标最小的顶点$$ p_0 $$，将其余$$ n-1 $$个顶点$$ [p_1, p_2, \dots, p_{n-1}] $$按照以$$ p_0 $$的顺时针方向排序。如图所示：

![GrahamScan1.png](../res/GrahamScan1.png)

上图中以$$ p_0 $$点为基准，对其余点排序的结果为$$ [p_1, p_2, p_3, p_4, p_5, p_6, p_7, p_8] $$。

根据Cross中向量叉积的知识，可知对于三个顶点$$ p_0, p_1, p_2 $$组成的向量$$ \vec{p_0 p_1}, \vec{p_0 p_2} $$，设$$ C = \vec{p_0 p_1} \times \vec{p_0 p_2} $$有以下情况：

$$ (1) $$ 若$$ C \gt 0 $$则$$ \vec{p_0 p_1} $$在$$ \vec{p_0 p_2} $$顺时针方向。如图：

![GrahamScan2.png](../res/GrahamScan2.png)

$$ (2) $$ 若$$ C \lt 0 $$则$$ \vec{p_0 p_1} $$在$$ \vec{p_0 p_2} $$逆时针方向。如图：

![GrahamScan3.png](../res/GrahamScan3.png)

$$ (3) $$ 若$$ C = 0 $$则$$ \vec{p_0 p_1} $$与$$ \vec{p_0 p_2} $$方向相同。对于向量完全相同的两顶点$$ p_1, p_2 $$，按照到$$ p_0 $$距离从近到远排序。如图：

![GrahamScan4.png](../res/GrahamScan4.png)


--------

#### Introduction to Algorithms

* [VII.Selected Topics - 33.Computational Geometry - 33.3.Finding the convex hull](https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf)

--------

#### 源码

[GrahamScan.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/GrahamScan.h)

[GrahamScan.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/GrahamScan.cpp)

#### 测试

[GrahamScanTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/ConvexHull/GrahamScanTest.cpp)

