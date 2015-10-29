#include "4_bidirection_subsequence.h"
#include <iostream>
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

	int m;
    printArray(s1, 11, "s1:");
    printArray(s2, 11, "s2:");
    printArray(s3, 8, "s3:");

	cout << "s1 bidirection subsequence: "
		 << bidirection_subsequence(s1, 11, m) << endl
		 << "the elem is: " << m << endl;
	cout << "s2 bidirection subsequence: "
		 << bidirection_subsequence(s2, 11, m) << endl
		 << "the elem is: " << m << endl;
	cout << "s3 bidirection subsequence: "
		 << bidirection_subsequence(s3, 8, m) << endl
		 << "the elem is: " << m << endl;
	return(0);
}
