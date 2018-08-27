#pragma once
#include "../Traverse/DepthFirstSearch.hpp"
#include "../Traverse/TopologicalSort.hpp"

#include "general_head.h"
#include "graph.h"
//topological_sort.cpp

extern void topological_sort1(graph_list g, deque<graph_node>& topo);
void transpose(graph_list g, graph_list& trans);
void dfs_kosaraju(graph_list& g, int p, int* visited, int grp);

void kosaraju(graph_list& g)
{ //图G有g_l.size()个节点，下标从0到g_l.size()-1
    //返回图G的所有极大强连通分量，存储于邻接表头节点的g_value成员中
    //属于同一极大强连通分支的节点其g_value值相等
    //将邻接表所有头结点的g_value初始化为0
    for (int i = 0; i < (int)g.g_l.size(); ++i)
        g.g_l[i][0].g_value = 0;
    graph_list trans;
    //求有向图G的逆图trans
    transpose(g, trans);
    deque<graph_node> trans_topo;
    //求逆图trans的拓扑排序
    //注意本文使用dfs的方法求拓扑顺序，而不能使用删除入度为0节点的方法
    topological_sort1(trans, trans_topo);
    //一次dfs遍历到的所有节点属于同一个极大强连通分支，用grp标记分支号
    //visited数组标记节点是否被访问，并记录该节点所属强联通分支的分支号grp
    int visited[MAX], grp(1);
    memset(visited, 0, MAX * sizeof(int));
    for (int i = 0; i < (int)trans_topo.size(); ++i)
        //trans_topo中按照拓扑顺序存储着有向图逆图的节点拓扑顺序
        //按照该拓扑顺序dfs所有节点
        if (!visited[trans_topo[i].g_idx]) {
            //一次dfs遍历到的节点属于同一个极大强连通分支
            //邻接表中对应的头节点的g_value成员值都为grp
            //这里可以只通过头结点的g_value来判断该节点是否被访问过
            dfs_kosaraju(g, trans_topo[i].g_idx, visited, grp);
            ++grp;
        }
}
void dfs_kosaraju(graph_list& g, int p, int* visited, int grp)
{ //与深度优先搜索中的dfs_kosaraju函数遍历方法一样
    //但不记录遍历的节点数量，而且visited数组用grp的值标记
    //用grp值来标记visited数组，使得不同的极大强连通分支的visited值不一样
    visited[p] = 1;
    g.g_l[p][0].g_value = grp;
    for (int i = 1; i < (int)g.g_l[p].size(); ++i)
        if (!visited[g.g_l[p][i].g_idx])
            dfs_kosaraju(g, g.g_l[p][i].g_idx, visited, grp);
}
void transpose(graph_list g, graph_list& trans)
{
    trans.g_l.clear();
    for (int i = 0; i < (int)g.g_l.size(); ++i) {
        deque<graph_node> tmp;
        //每个队列中插入头结点
        tmp.push_back(graph_node(i));
        //再把该队列插入邻接表中
        trans.g_l.push_back(tmp);
    }
    for (int i = 0; i < (int)g.g_l.size(); ++i)
        for (int j = 1; j < (int)g.g_l[i].size(); ++j)
            trans.g_l[g.g_l[i][j].g_idx].push_back(g.g_l[i][0]);
}

