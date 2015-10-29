#include <iostream>
#include "3_longest_increasing_subsequence_extension.h"
using namespace std;

void printArray(int *s, int n, const char *msg)
{
    cout << msg << endl;
    for (int i = 1; i <= n; ++i)
        cout << s[i] << ' ';
    cout << endl;
}

int main()
{
	int s1[12] = {0, 1, 1, 5, 4, 9, 7, 31, -13, 34, 21, 17};
	int s2[12] = {0, 5, 6, 11, 4, 9, 0, 34, 21, -13, 17, 3};
	int s3[9] = {0, 9, 3, 7, 6, 10, 15, 8, 11};

    printArray(s1, 11, "s1:");
    printArray(s2, 11, "s2:");
    printArray(s3, 8, "s3:");

	int m;
	cout << "s1 extended subsequence: "
		 << longest_increasing_subsequence_extension(s1, 11, m) << endl;
	cout << "number of the subsequence: " << m << endl << endl;

	cout << "s2 extended subsequence: "
		 << longest_increasing_subsequence_extension(s2, 11, m) << endl;
	cout << "number of the subsequence: " << m << endl << endl;

	cout << "s3 extended subsequence: "
		 << longest_increasing_subsequence_extension(s3, 8, m) << endl;
	cout << "number of the subsequence: " << m << endl << endl;

	return 0;
}
