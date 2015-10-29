#include "2_longest_increasing_subsequence.h"
#include <iostream>
using namespace std;

int main()
{
	int s1[12] = {0, 1, 1, 5, 4, 9, 7, 31, -13, 34, 21, 17};
	int s2[20] = {
        0, 
        5, 6, 11, 4, 9, 0, 34, 21, -13, 17, 
        3, -123, -23, 235, 8124, 83, 14, 352, 12
    };

    cout << "s1:" << endl;
    for (int i = 1; i <= 11; ++i)
        cout << s1[i] << ' ';
    cout << endl;

    cout << "s2:" << endl;
    for (int i = 1; i <= 19; ++i)
        cout << s2[i] << ' ';
    cout << endl << endl;

	cout << "s1 increasing subsequence 1:" << endl
		 << longest_increasing_subsequence1(s1, 11) << endl;
    cout << "s2 increasing subsequence 1:" << endl;
    cout << longest_increasing_subsequence1(s2, 19) << endl;

	cout << "s1 increasing subsequence 2:" << endl
		 << longest_increasing_subsequence2(s1, 11) << endl;
	cout << "s2 increasing subsequence 2:" << endl;
    cout << longest_increasing_subsequence2(s2, 19) << endl;

	return 0;
}
