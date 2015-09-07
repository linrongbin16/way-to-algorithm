#ifndef WAY_TO_ALGORIHTM_DYNAMICPROGRAMMING_TREEDYNAMIC_LOOP_TREE_H
#define WAY_TO_ALGORIHTM_DYNAMICPROGRAMMING_TREEDYNAMIC_LOOP_TREE_H 1

//带环多叉树动规
//loop tree

//之前的多叉树动态规划其实都是依赖问题
//比如对一个父节点r和它的若干孩子节点c 若要选择某个孩子节点 必须选择其父节点
//因为没有办法把树枝截断
//这种情况被称之为: 孩子节点依赖于其父节点
//
//现在设想这样的情况：
//树中存在这样三个节点a b c 其中a依赖b b依赖c c依赖a
//形成了一个环 若要选择其中一个 则必须一起选择它们三个
//这就是多叉树的存在环的变形 求这样的带环多叉树的最大权值

//将树中的所有环转化为一个节点
//比如将a b c三个节点转化为节点d
//d点的权值和费用分别是a b c三者的权值和费用之和
//然后就可以用正常的多叉树动规方法解决了


#endif
