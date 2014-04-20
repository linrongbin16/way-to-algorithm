//背包头文件
//pack.h

//支持背包问题一节的自定义数据结构

#define OMAX 10				//物品最大数量
#define WMAX 20				//背包承重(费用)最大值
#define GMAX 10				//分组最大数量

struct object{
	int o_value;			//该种物品的价值
	int o_weigh;			//该种物品的重量1(费用1)
	int o_count;			//该种物品的数量
	int o_weigh2;			//该种物品的重量2(费用2)
	object(int cvalue = 0, int cweigh = 0, int ccount = 0, int cweigh2 = 0)
		: o_value(cvalue), o_weigh(cweigh), o_count(ccount), o_weigh2(cweigh2){
	}
	object(const object& cr)
		: o_value(cr.o_value), o_weigh(cr.o_weigh),
		o_count(cr.o_count), o_weigh2(cr.o_weigh){
	}
};
struct packet_object{
	//专门用于支持分组背包的计算
	
	object g[GMAX][OMAX];	//分组物品
							//第1维数组指代分组，从1到g_grpcnt
							//第2维数组指代当前分组下物品，从1到g_objcnt
	int g_grpcnt;			//g_grpcnt指代分组背包中分组数量
	int g_objcnt;			//g_objcnt指代每组中的物品种类
	int g_totalcnt;			//g_totalcnt指代总共物品种类
	//一般有g_totalobjectcnt = g_packetcnt * g_objectcnt
	//物品总共种类 = 每组物品种类 * 分组数量
	packet_object(int cgrpcnt = 0, int cobjcnt = 0, int ctotalcnt = 0)
		: g_grpcnt(cgrpcnt), g_objcnt(cobjcnt), g_totalcnt(ctotalcnt){
	}
};








