#include <iostream>
#include <algorithm>
using namespace std;
#include "3_breadth_first_search.h"

int main()
{
	cout << endl << "breadth first search: " << endl;
	breadth_first_search(4, 5, make_pair(1, 2));	//3

	return 0;
}
