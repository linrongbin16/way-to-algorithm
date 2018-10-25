<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Convex Polygon Gravity Center - 凸多边形重心

--------

#### 问题

求凸多边形重心的坐标。

#### 解法

$$ (1) $$ 三角形重心

顶点为$$ a, b, c $$的三角形重心坐标为$$ x_{gravity} = \frac{x_{a} + x_{b} + x_{c}}{3} $$，$$ y_{gravity} = \frac{y_{a} + y_{b} + y_{c}}{3} $$。

$$ (2) $$ 凸多边形重心

凸多边形的重心不能像三角形一样求所有顶点的$$ x_{i} $$和$$ y_{i} $$坐标的平均值。

对于$$ n $$个订单的凸多边形，类似ConvexPolygonGravityCenter中的方法，在凸多边形中选取一个顶点$$ p $$，$$ p $$与其他顶点连线可以将凸多边形划分为$$ n - 2 $$个三角形，对于每个三角形求其重心和面积。可以得到所有三角形的重心为$$ center_{1}, center_{2}, \cdots center_{n} $$，面积为$$ area_{1}, area_{2}, \cdots area_{n} $$。

凸多边形的重心是所有三角形的重心坐标的面积加权平均值：

$$
\begin{cases}
x_{gravity} = \frac{\sum_{i=1}^{n} x_{center_{i}} * area_{i}}{\sum_{i=1}^{n} area_{i}}  \\
y_{gravity} = \frac{\sum_{i=1}^{n} y_{center_{i}} * area_{i}}{\sum_{i=1}^{n}area_{i}}
\end{cases}

1 \le i \le n
$$

该算法的时间复杂度为$$ O(n) $$。

--------

#### 源码

[ConvexPolygonGravityCenter.h](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/Polygon/ConvexPolygonGravityCenter.h)

[ConvexPolygonGravityCenter.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/Polygon/ConvexPolygonGravityCenter.cpp)

#### 测试

[ConvexPolygonGravityCenterTest.cpp](https://github.com/linrongbin16/Way-to-Algorithm/blob/master/src/AnalyticGeometry/Polygon/ConvexPolygonGravityCenterTest.cpp)
