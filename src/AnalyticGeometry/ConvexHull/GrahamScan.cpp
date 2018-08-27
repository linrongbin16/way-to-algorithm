#include "GrahamScan.h"
#include "../Polygon/Cross.h"

static Node NextTop(stack<Node> stk) {
    Node tmp = stk.top();
    stk.pop();
    Node nextTmp = stk.top();
    stk.push(tmp);
    return nextTmp;
}

//由于需要比较两个顶点到起点p0的距离 构造了仿函数Compare
class Compare {
    Node p0;

public:
    Compare(const Node& cp) : p0(cp) {}
    bool operator()(Node a, Node b) {
        //计算向量p0->a和p0->b的叉积
        double c = cross(vec(p0, a), vec(p0, b));
        if (c > 0)
            //若叉积为正值 则p0->a在P0->b的顺时针方向 按照逆时针旋转的方向排序
            return (true);
        if (c == 0)
            //若叉积为0 则两向量共线 即p0 a b三点共线
            //按照到p0点距离从小到大排序
            //算法导论中原本的描述是删去到p0距离较近的点 此处并未实现删除操作
            //但在后面栈的操作中仍然可以保证:
            //若凸包上存在多个点共线 只选取共线的边的两端点作为凸包顶点
            //而不选取中间的点
            return (Node_distance(p0, a) < Node_distance(p0, b));
        return (false);
    }
};

void GrahamScan(
    vector<Node> s,
    stack<Node>& stk) {  //点集s用vector实作
                         //返回点集s的凸包 从底部到顶部按逆时针方向存储于栈中
    // stk初始化为空
    while (!stk.empty()) stk.pop();
    Node p0(INF, INF);
    vector<Node>::iterator p0_pos;
    for (vector<Node>::iterator it = s.begin(); it != s.end(); ++it) {
        //找出点集s中最左下角的点p0
        if (p0.n_y > it->n_y) {
            p0 = *it;
            p0_pos = it;
        } else if (p0.n_y == it->n_y and p0.n_x > it->n_x) {
            p0 = *it;
            p0_pos = it;
        }
    }
    //从点集s中删除p0点
    s.erase(p0_pos);
    //将s中所有顶点按照相对于p0点逆时针方向排序
    sort(s.begin(), s.end(), Compare(p0));

    stk.push(p0);
    stk.push(s[0]);
    stk.push(s[1]);
    vector<Node>::iterator pos = s.begin() + 2;
    while (pos != s.end()) {
        while (cross(vec(next_top(stk), *pos), vec(next_top(stk), stk.top())) >=
               0)
            //计算向量next->pos相对于next->top的转向
            //是顺时针或向量共线 而不是逆时针时 删除栈的顶部点top
            stk.pop();
        stk.push(*pos);
        ++pos;
    }
}
