#include <iostream>
#include <algorithm>
#include "2_depth_first_search.h"
using namespace std;

int main()
{
	int v[3] = {0, 0, 0};
	cout << endl << "depth first search: " << endl;
	depth_first_search(v, 3, 5, 0);	//2

	return(0);
}
