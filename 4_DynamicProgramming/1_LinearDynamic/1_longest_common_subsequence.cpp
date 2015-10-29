#include <iostream>
#include "1_longest_common_subsequence.h"
using namespace std;

int main()
{
	int s1[12] = {0, 1, 1, 5, 4, 9, 7, 31, -13, 34, 21, 17};
	int s2[12] = {0, 5, 6, 11, 4, 9, 0, 34, 21, -13, 17, 3};

    cout << "s1:" << endl;
    for (int i = 1; i <= 11; ++i) {
        cout << s1[i] << ' ';
    }
    cout << endl;
    cout << "s2:" << endl;
    for (int i = 1; i <= 11; ++i) {
        cout << s2[i] << ' ';
    }
    cout << endl;
	cout << "longest common subsequence: ";
    cout << longest_common_subsequence(s1, s2, 11) << endl;

    int s3[20] = {
        0, 
        12, 142, -5, 14, 15, 45, 42, 61, 41, 0,
        42, 42, -5, 14, 215, 45, -42, 1, 31
    };
    int s4[20] = {
        0, 
        42, 42, -5, 14, 215, 45, -42, 1, 31, 0,
        12, 142, -5, 14, 15, 45, 42, 61, 41
    };
    cout << endl;
    cout << "s3:" << endl;
    for (int i = 1; i <= 19; ++i) {
        cout << s3[i] << ' ';
    }
    cout << endl;
    cout << "s4:" << endl;
    for (int i = 1; i <= 19; ++i) {
        cout << s4[i] << ' ';
    }
    cout << endl;
	cout << "longest common subsequence: " 
		 << longest_common_subsequence(s3, s4, 19) << endl;

	return 0;
}
