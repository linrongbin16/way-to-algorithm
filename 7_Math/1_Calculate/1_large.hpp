//大数计算
//large_calculate.hpp

//对任意两十进制大数进行加减乘除计算

//将大数存储在一个数组中，模拟大数字计算过程中每一位的变化
//为了方便本文只处理整数

#include "general_head.h"

struct large{
	int l_num[MAX];			//通过数组存储一个大整数
							//从低位到高位反向存储数字
							//下标0存储最低位，下标l_len-1存储最高位
							//输出打印时只需反向输出即可
	int l_len;
	large(int cl = 0)
		: l_len(cl){
			for(int i = 0; i < MAX; ++ i)
				l_num[i] = 0;
	}
	large(const large& cr)
		: l_len(cr.l_len){
			for(int i = 0; i < MAX; ++ i)
				l_num[i] = cr.l_num[i];
	}
	large operator+(large cr){
		int n(max(l_len, cr.l_len));
		large p(*this);
		for(int i = 0; i < n; ++ i){
			int tmp = p.l_num[i] + cr.l_num[i];
			if(tmp >= 10){
				++ p.l_num[i + 1];
				tmp -= 10;
			}
			p.l_num[i] = tmp;
		}
		while(p.l_num[p.l_len])
			++ p.l_len;
		return(p);
	}
	large operator-(large cr){
		//默认被减数较大，减数较小，且两个数字都是正数，结果也是正数
		int n(l_len);
		large p(*this);
		for(int i = 0; i < n; ++ i){
			int tmp = p.l_num[i] - cr.l_num[i];
			if(tmp < 0){
				-- p.l_num[i + 1];
				tmp += 10;
			}
			p.l_num[i] = tmp;
		}
		while(!p.l_num[p.l_len - 1])
			-- p.l_len;
		return(p);
	}
	large operator*(large cr){
		large p(l_len + cr.l_len - 1);
		for(int i = 0; i < cr.l_len; ++ i)
			for(int j = 0; j < l_len; ++ j){
				int tmp = l_num[j] * cr.l_num[i];
				if(tmp >= 10){
					p.l_num[i + j + 1] += tmp / 10;
					tmp %= 10;
				}
				p.l_num[i + j] += tmp;
				if(p.l_num[i + j] >= 10){
					p.l_num[i + j + 1] += p.l_num[i + j] / 10;
					p.l_num[i + j] %= 10;
				}
			}
		while(p.l_num[p.l_len])
			++ p.l_len;
		return(p);
	}
	void l_print(){
		for(int i = l_len - 1; i >= 0; -- i)
			cout << l_num[i];
	}
};
