<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>
<script> gitbook.events.bind("page.change", function() { MathJax.Hub.Queue(["Typeset",MathJax.Hub]); } </script>

# Sweeping - 扫除算法

--------

#### 问题

判断一组线段中是否存在相交的线段。


#### 解法

对于$$ n $$条线段，显然这个问题不能通过遍历每条线段，再遍历它和所有其他线段是否相交，这个算法的时间复杂度为$$ O(n^2) $$。

$$ (1) $$ 扫除算法介绍

在平面中设置垂直扫除线$$ s $$，垂直于$$ x $$轴，平行于$$ y $$轴，从左向右依次经过所有线段。如图所示：

<!--![Sweeping1.svg](../res/Sweeping1.svg)-->

假设扫除线$$ s $$与线段$$ a $$和$$ b $$同时相交，存在以下情况：

$$ (1) $$ 若此时$$ a $$与$$ s $$的交点$$ y $$坐标大于$$ b $$与$$ s $$的交点$$ y $$坐标，则称在$$ x $$处，$$ a \gt b $$，这是一个全序关系。

//若a，b线段相交，则s从左向右经过此交点时
//a与b的全序关系会变化(a > b变为a < b)，即
//s在a和b的交点左边时，a与s的交点y坐标大于b与s的交点y坐标
//s在a和b的交点右边时，a与s的交点y坐标小于b与s的交点y坐标
//2)扫除线的移动
//事件点调度：
//将所有线段的两端点按照其x坐标从小到大排序
//若x坐标相同，则以此端点为线段左端点的优先，再以此端点的y坐标较小的优先
//排序之后的所有端点组成事件点序列
//扫除线状态(T)：
//垂直扫除线s可以从左到右依次经过线段上的每一个端点，维护一个映射T
//垂直扫除线s在移动中遇到左端点时将该端点所在的线段加入T中
//遇到右端点时将该端点所在的线段从T中删除
//扫除线s的状态T维护的信息是当s位于某个x坐标时
//s当前穿过了哪些线段，这些线段与s相交的点的y坐标
//当s经过某个x坐标时有两线段a和b的全序关系发生了变化，则认为a和b线段相交
//T需要实现操作：insert(p)，delete(p)，above(p)，below(p)
//insert(p)：把线段p插入T中
//delete(p)：从T中删除线段p
//above(p)：返回T中紧靠线段p上面的线段
//below(p)：返回T中紧靠线段p下面的线段
//通过红黑树实现T结构，T中的线段按照线段与扫除线交点的y坐标大小排序

--------

#### 源码

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Util.h)

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Polygon/Sweeping.h)


#### 测试

[import, lang:"c_cpp"](../../../../src/AnalyticGeometry/Polygon/Sweeping.cpp)
