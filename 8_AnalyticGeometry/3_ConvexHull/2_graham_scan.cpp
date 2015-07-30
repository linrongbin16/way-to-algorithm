//Graham扫描算法
//graham scan

//在平板上钉很多钉子 用一紧绷的橡皮筋将所有钉子围起来
//求所有令皮筋改变方向的钉子 不包括那些位于同一条直线上的钉子
//一组点中外围的连续三个不共线的点的集合称为一个点集的凸包

//1)凸包
//欧式空间中
//凸集是任意两点的连线都在这个集合内的集合
//凸包是包含点集s的所有凸集的交集
//凸包可以是三维或更多维度的空间中的集合
//平板上撑起橡皮筋的最外层的钉子的集合是一个典型的凸包
//
//一个点集中相距最远的两点一定是凸包上的两点 可以在求出凸包后枚举凸包上的所有顶点
//即可得到点集中相距最远的两点的距离
//
//2)包裹算法 也称Jarvis步进法
//初始时选择一个必定属于凸包的顶点 一般选择点集中最左下角的顶点p0
//重复以下步骤: 
//从当前顶点 初始时是p0 再选择一个顶点p1使得剩余所有点都位于p0->p1的右边
//然后以点p1为当前顶点 继续选择下一个使剩余所有点都在右边的点
//当最后回到初始点p0时 被选择的所有点即为凸包
//该算法在每次选择一个新的顶点时 都需要遍历剩余的所有点 选择当前点最逆时针方向的点
//
//2)Graham扫描算法
//Graham扫描相比与包裹算法
//主要在于预先将所有顶点按照相对于初始点p0按照逆时针方向排序
//然后按照逆时针方向绕着点集的外围旋转一圈 最终回到起点p0
//在逆时针旋转的过程中
//该算法每次都选择位于它最右前方的顶点作为下一个顶点
//保证点集中的剩余点都在当前点和下一顶点组成的边的左边
//从而使得在每次选择一个新的顶点时不必遍历所有的剩余顶点
//
//将点集中最左下方点作为起点p0
//将剩余的所有点按照相对于p0的角度逆时针排序
//若角度相同则取距离p0较大的点 删去较小的点
//维护一个堆栈存储凸包顶点
//初始时存储p0和已排序的顶点序列中的前两点p1和p2
//依次对已序序列中剩下的每个顶点i重复以下步骤: 
//可知栈中当前的顶部点top和顶部下的第二个点next
//若向量next->i相对于向量next->top的角度方向不是逆时针 即顺时针方向或共线
//则将栈中的顶部点top出栈 从凸包中删去该点
//否则将新的点i入栈 加入凸包
//对点集中所有顶点重复以上步骤之后 堆栈从底部到顶部按逆时针方向存储着点集的凸包
//
//3)旋转卡壳与包裹算法 Graham扫描算法
//很多中文文档中都会提到可以用旋转卡壳方法来求一个点集的凸包
//但实际上在没有给出一个凸多边形的所有边的情况下
//每旋转一次需要枚举所有点集中的点 通过叉积的计算找出旋转角度最小的下一个顶点
//实际上这和包裹算法 Graham扫面中沿着点集外围旋转的思路是相同的
//所以我认为旋转卡壳并不适合求点集的凸包
//旋转卡壳方法应用的典型场景是通过围绕凸多边形的外围旋转来求凸多边形的一些性质


#include "general_head.h"
#include "geometry.h"
//cross.cpp
extern double cross(vec v1, vec v2);
//nearest_neighbour.cpp
extern double node_distance(node a, node b);
node next_top(stack<node> stk);

class compare{
	//由于需要比较两个顶点到起点p0的距离 构造了仿函数compare
private:
	node p0;
public:
	compare(const node& cp)
		: p0(cp){
	}
	bool operator()(node a, node b){
		//计算向量p0->a和p0->b的叉积
		double c = cross(vec(p0, a), vec(p0, b));
		if(c > 0)
			//若叉积为正值 则p0->a在P0->b的顺时针方向 按照逆时针旋转的方向排序
			return(true);
		if(c == 0)
			//若叉积为0 则两向量共线 即p0 a b三点共线
			//按照到p0点距离从小到大排序
			//算法导论中原本的描述是删去到p0距离较近的点 此处并未实现删除操作
			//但在后面栈的操作中仍然可以保证: 
			//若凸包上存在多个点共线 只选取共线的边的两端点作为凸包顶点
			//而不选取中间的点
			return(node_distance(p0, a) < node_distance(p0, b));
		return(false);
	}
};
void graham_scan(vector<node> s, stack<node>& stk) 
{//点集s用vector实作
 //返回点集s的凸包 从底部到顶部按逆时针方向存储于栈中
	//stk初始化为空
	while(!stk.empty())
		stk.pop();
	node p0(INF, INF);
	vector<node>::iterator p0_pos;
	for(vector<node>::iterator it = s.begin(); it != s.end(); ++ it){
		//找出点集s中最左下角的点p0
		if(p0.n_y > it->n_y){
			p0 = *it;
			p0_pos = it;
		}
		else if(p0.n_y == it->n_y && p0.n_x > it->n_x){
			p0 = *it;
			p0_pos = it;
		}
	}
	//从点集s中删除p0点
	s.erase(p0_pos);
	//将s中所有顶点按照相对于p0点逆时针方向排序
	sort(s.begin(), s.end(), compare(p0));

	stk.push(p0); 
	stk.push(s[0]); 
	stk.push(s[1]);
	vector<node>::iterator pos = s.begin() + 2;
	while(pos != s.end()){
		while(cross(vec(next_top(stk), *pos), vec(next_top(stk), stk.top())) >= 0)
			//计算向量next->pos相对于next->top的转向
			//是顺时针或向量共线 而不是逆时针时 删除栈的顶部点top
			stk.pop();
		stk.push(*pos);
		++ pos;
	}
}
node next_top(stack<node> stk) 
{
	node tmp = stk.top(); stk.pop();
	node nexttmp = stk.top(); stk.push(tmp);
	return(nexttmp);
}
