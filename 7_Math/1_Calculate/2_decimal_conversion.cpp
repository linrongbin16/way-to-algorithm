//十进制转换
//decimal_conversion.cpp

//将给十进制数字转换为另一小于十进制的数字

//通过除法和求模运算转换禁制

#include "general_head.h"
string int2str(int p);

string decimal_conversion(int num, int b)
{//将十数字num，转换为小于十的b进制数字返回
	string s("");
	while(num){
		int t = num % b;
		num /= b;
		//新的数字位加在左边
		s = int2str(t) + s;
	}
	return(s);
}
string int2str(int p)
{
	stringstream s; 
	string t;
	s.clear(); 
	s << p; 
	s >> t;
	return(t);
}
