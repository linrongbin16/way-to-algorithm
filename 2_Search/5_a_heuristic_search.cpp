#include <iostream>
#include <algorithm>
#include "5_a_heuristic_search.h"
using namespace std;

int main()
{
	hs_node beg, end;
	beg.m_status = "4132x6758";
	end.m_status = "12345678x";
	cout << endl << "A* heuristic search:" << endl;
	a_heuristic_search(beg, end);	//5

	return 0;
}
