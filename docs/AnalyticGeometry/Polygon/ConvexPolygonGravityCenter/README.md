<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>
<script> gitbook.events.bind("page.change", function() { MathJax.Hub.Queue(["Typeset",MathJax.Hub]); } </script>

# ConvexPolygonGravityCenter 凸多边形重心

--------

#### 问题

求凸多边形重心的坐标。

#### 解法

$$ (1) $$ 三角形重心

顶点为$$ a $$，$$ b $$，$$ c $$的三角形重心坐标为$$ x = (x_{a} + x_{b} + x_{c}) \div  3 $$，$$ y = (y_{a} + y_{b} + y_{c}) \div 3 $$。

$$ (2) $$ 凸多边形重心

凸多边形的重心不能像三角形一样求所有顶点的$$ x $$和$$ y $$坐标的平均值。

像<ConvexPolygonArea>中的方法，在凸多边形中选取一个顶点$$ p $$，$$ p $$与其他顶点连线可以将凸多边形划分为$$ n $$个三角形，对于每个三角形求其重心和面积。

//设所有的三角形的重心和面积分别为o1，o2，...，on和s1，s2，...，sn
//多边形重心是这些三角形的重心坐标的面积加权平均值
//x = sum(xi * si) / sum(si)，y = sum(yi * si) / sum(si)
//其中1 <= i <= n
//
//具体的实现中选取二维坐标系中的原点作为一个划分点p
//按照逆时针方向依次遍历多边形的每条边，重复以下操作：
//多边形上一条边的两端点分别是s1和s2，其中s2在s1的逆时针方向
//该边的两端点与划分点p组成一个三角形，计算该三角形的重心及面积

向量$$ \vec{v_{1}} $$和$$ \vec{v_{2}} $$的叉积的值恰好等于由$$ \vec{v_{1}} $$、$$ \vec{v_{2}} $$组成的平行四边形的面积，组成的三角形的面积的$$ 2 $$倍。

$$ (2) $$ 多边形面积

二维坐标系上的$$ n $$多边形有$$ n $$个顶点，随意选取一个顶点$$ p $$。$$ p $$与多边形的每条边的两个端点$$ a $$、$$ b $$组成一个三角形，像这样顶点$$ p $$与所有边分别组成的所有三角形的面积之和，即为该多边形的面积。注意到叉积的值可能为负数，最终的面积取绝对值即可。

该算法的时间复杂度为$$ O(n) $$。

--------

#### 源码

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Util.h)

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Polygon/ConvexPolygonArea.h)


#### 测试

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Polygon/ConvexPolygonArea.cpp)


