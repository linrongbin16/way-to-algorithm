<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Convex Polygon Area - 凸多边形面积

--------

#### 问题

求凸多边形面积。

#### 解法

$$ (1) $$ 三角形面积

向量$$ \vec{v_{1}} $$和$$ \vec{v_{2}} $$的叉积的值恰好等于由$$ \vec{v_{1}} $$、$$ \vec{v_{2}} $$组成的平行四边形的面积，组成的三角形的面积的$$ 2 $$倍。

![ConvexPolygonArea1.svg](../res/ConvexPolygonArea1.svg)

$$ (2) $$ 多边形面积

二维坐标系上的$$ n $$多边形有$$ n $$个顶点，随意选取一个顶点$$ p $$。$$ p $$与多边形上其他每条边的两个端点组成一个三角形（共$$ n - 2 $$个三角形），像这样顶点$$ p $$与所有边分别组成的所有三角形的面积之和，即为该多边形的面积。注意到叉积的值可能为负数，最终的面积取绝对值即可。如图所示：

![ConvexPolygonArea2.svg](../res/ConvexPolygonArea2.svg)

该算法的时间复杂度为$$ O(n) $$。

--------

#### 源码

[ConvexPolygonArea.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/Polygon/ConvexPolygonArea.h)

[ConvexPolygonArea.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/Polygon/ConvexPolygonArea.cpp)

#### 测试

[ConvexPolygonAreaTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/Polygon/ConvexPolygonAreaTest.cpp)
