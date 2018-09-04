<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"/></script>
<script> gitbook.events.bind("page.change", function() { MathJax.Hub.Queue(["Typeset",MathJax.Hub]); } </script>

# ConvexPolygonArea 凸多边形面积

//多边形面积
//polygon_area.cpp

//求多边形面积

//1)三角形面积
//向量v1和v2的叉积的值恰好
//等于由v1，v2组成的平行四边形的面积大小
//等于由v1，v2组成的三角形面积的二倍
//若三角形中三个顶点a，b，c按照逆时针排列，其坐标分别是(x1, y1)，(x2, y2)，(x3, y3)
//设v1是a->b，v2是a->c，则v1 cross v2的值是该三角形的面积
//2)多边形面积
//设多边形有n个顶点，在二维坐标系上随意选取一点p
//则p与多边形的每一条边的两端点a、b组成一个三角形pab
//所有三角形的面积之和即为多边形面积
//而且p点在任意位置均适用
//不需要考虑各个三角形之间的覆盖，不需要考虑多边形的凹凸性
//p与多边形的边的两端点a，b组合的顺序
//若按照逆时针排列则可得正值的面积
//若按照顺时针排列则可得负值的面积
//但当p与多边形各边的组合不按照一定的顺序组合时无法得到正确的面积

