//test

#include "general_head.h"
#include "1_large.hpp"	//struct large
void test_op(large a, large b, string info, int operat);
string decimal_conversion(int num, int b);
int main()
{
	large a(5), b(4), c(6);
	a.l_num[0] = 7; a.l_num[1] = 9; a.l_num[2] = 9; a.l_num[3] = 9; a.l_num[4] = 9;
	b.l_num[0] = 7; b.l_num[1] = 0; b.l_num[2] = 9; b.l_num[3] = 9;
	c.l_num[0] = 2; c.l_num[1] = 3; c.l_num[2] = 0; c.l_num[3] = 0; c.l_num[4] = 0; c.l_num[5] = 1;
	test_op(a, b,"a + b: ", 1);

	test_op(c, a, "c - a: ", 2);
	test_op(c, b, "c - b: ", 2);
	test_op(a, b, "a - b: ", 2);

	test_op(a, c, "a * c: ", 3);
	test_op(c, b, "c * b: ", 3);

	for(int b = 2; b <= 10; ++ b)
		cout << endl << "turn 10 base number "<< 123456789 << " to " << b << " base number:" << decimal_conversion(123456789, b) << endl;

	return(0);
}
void test_op(large a, large b, string info, int operat)
{
	cout << "the number before calculate, " << info;
	a.l_print();
	cout << " ";
	b.l_print();
	cout << endl;
	cout << info;

	switch(operat){
		case 1:{
				   large tmp = a + b;
				   tmp.l_print();
				   break;
			   }
		case 2:{
				   large tmp = a - b;
				   tmp.l_print();
				   break;
			   }
		case 3:{
				   large tmp = a * b;
				   tmp.l_print();
				   break;
			   }
	}	
	cout << endl;
	cout << "the number after calculate, " << info;
	a.l_print(); cout << ' ';
	b.l_print();
	cout << endl << endl;;
}


