#include <iostream>
#include <algorithm>
#include "1_brute_force.h"
using namespace std;

int main()
{
	int u[4] = {0, 0, 0, 0};
	cout  << endl << "brute force: " << endl;
	brute_force(u, 4, 3);	//1
	return(0);
}
