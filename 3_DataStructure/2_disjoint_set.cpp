#include "2_disjoint_set.h"
#include <iostream>
using namespace std;

int main()
{
    disjoint_set set;
    disjoint_set_init(&set);
    cout << endl << "disjoint set" << endl;
    cout << "union" << endl;
    for(int i = 0; i < 10; ++ i){
        cout << "number " << i << " and " << 3 * i << " is in one set" << endl;
        disjoint_set_union(&set, i, 3 * i);
    }
    cout << "query" << endl;
    if(disjoint_set_query(&set, 1, 27))
        cout << "number 1 and 27 in one set" << endl;
    else
        cout << "number 1 and 27 not in one set" << endl;
    if(disjoint_set_query(&set, 2, 18))
        cout << "number 2 and 18 in one set" << endl;
    else
        cout << "number 2 and 18 not in one set" << endl;
    if(disjoint_set_query(&set, 2, 21))
        cout << "number 2 and 21 in one set" << endl;
    else
        cout << "number 2 and 21 not in one set" << endl;
	
	return 0;
}
