# Cross - 叉积

--------

#### 描述

1. 向量

向量$$ \vec{v} = [x, y, z] $$表示三维空间中一个有长度的方向，单位长度为$$ 1 $$。

或者也可以写作：

$$
\vec{v} = x \times \vec{i} + y \times \vec{j} + z \times \vec{k}
$$

其中$$ \vec{i}, \vec{j}, \vec{k} $$是$$ x, y, z $$三个轴上的单位向量，平面中的向量可以视为$$ z $$轴长度为$$ 0 $$的三维空间中一种特殊的向量。

2. 点积

两个向量的点积计算方式如下：

$$
\vec{v_{1}} \cdot \vec{v_{2}} = x_{1} \times x_{2} + y_{1} \times y_{2} + z_{1} \times z_{2}
$$

两个向量的点积结果是一个数字。

3. 叉积

两个向量的叉积计算方式如下：

$$
v_{1} \times v_{2} =

\begin{vmatrix}
i       &   j       &   k       \\
x_{1}   &   y_{1}   &   z_{1}   \\
x_{2}   &   y_{2}   &   z_{2}
\end{vmatrix}
$$

叉积的结果是一个向量，此向量遵循右手法则，将右手四指卷起大拇指伸出。从$$ v_{1} $$沿着四根卷起的手指指向$$ v_{2} $$，叉积结果向量与大拇指方向相同，与$$ v_{1} $$和$$ v_{2} $$所在平面垂直。

4. 行列式计算公式

如下：

$$
\begin{vmatrix}
a   &   b   &   c   \\
d   &   e   &   f   \\
g   &   h   &   i
\end{vmatrix}

=

\begin{vmatrix}
e   &   f   \\
h   &   i
\end{vmatrix}


\begin{vmatrix}
d   &   f   \\
g   &   i
\end{vmatrix}


\begin{vmatrix}
d   &   e   \\
g   &   h
\end{vmatrix}


a_(-1)^(1+1)_| e f | + b_(-1)^(1+2)_| d f | + c_(-1)^(1+3)_| d e |
             | h i |                | g i |                | g h |

$$

可得三维空间中v1 cross v2 = (y1_z2 - y2_z1)i-(x1_z2 - x2_z1)j+(x1_y2 - x2_y1)k
二维平面中v1 cross v2 = (x1_y2 - x2_y1)k

5.  向量夹角

在平面中v1 cross v2 = x1_y2 - x2_y1
若为正数则v1在v2的顺时针方向 按照右手螺旋法则从v2到v1旋转时 大拇指与z轴反方向一致(向下)
若为负数则v1在v2的逆时针方向 按照右手螺旋法则从v2到v1旋转时 大拇指与z轴正方向一致(向上)
若为0则v1和v2共线 此为边界情况
在两连续线段p0_p1 p1_p2中 考察角&lt;p0p1p2是左转还是右转
即计算向量p0->p2在p0->p1的顺时针方向还是逆时针方向 可以通过计算p0->p2 cross p0->p1
在向量a->b中 a是向量起点 b是向量终点
若为正则p0->p2在p0->p1的顺时针方向 角右转
若为负则p0->p2在p0->p1的逆时针方向 角左转
若为0则p0 p1 p2三点共享
这里需要注意叉积的正负值与向量间顺时针逆时针的关系 实际运算时很容易搞混

本节引用了"数学复习全书(2013年李永乐李正元考研数学 数学一)" 作者"李永乐""李正元"

--------

#### 源码

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Polygon/Cross.h)


#### 测试

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Polygon/Cross.cpp)
