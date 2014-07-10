//多源点多汇点最大流
//multi_source_sink_maxflow.cpp

//求拥有多个源点和汇点流网络的最大流

//多源点多汇点最大流问题可以很轻松的转化为已知的单源点汇点最大流问题
//对原流网络R进行如下构造得到新的单源点汇点流网络R'：
//添加超级源点s_beg和超级汇点s_end
//从s_beg向原R中每个源点添加一条容量为极大值INF的管道，原R中源点现成为普通节点
//从原R中每个汇点向s_end添加一条容量为极大值INF的管道，原R中汇点现成为普通节点
//对新R'应用距离标号算法得到的最大流即为原多源点多汇点流网络R的最大流

//int multi_source_sink_maxflow(graph_matrix residue,
//		int *beg, int bn, int *end, int en);
