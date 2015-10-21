#include "4_quick_sort.h"
#include <iostream>

using namespace std;


void printArray(int s[], int n, const char *msg)
{
	cout << msg << endl;
	for (int i = 0; i < n; ++i) {
		cout << s[i] << ' ';
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl << endl;
}

void printQuick1(int s[], int n, const char *strname)
{
	cout << strname << ":" << endl;
	cout << "before quick sort 1: " << endl;
	printArray(s, n, strname);

	quick_sort1(s, 0, n-1);

	cout << "after quick sort 1: " << endl;
	printArray(s, n, strname);
	cout << endl;
}

void printQuick2(int s[], int n, const char *strname)
{
	cout << strname << ":" << endl;
	cout << "before quick sort 2: " << endl;
	printArray(s, n, strname);

	quick_sort2(s, 0, n-1);

	cout << "after quick sort 2: " << endl;
	printArray(s, n, strname);
	cout << endl;
}

int main()
{
	int s1[MAX] = {
		234, 10, -41, 0, 34, 15, 64, 653, -745, 74,
		65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
		134, 10, -41, 801, 32, 25, 63, 653, -715, 18,
		65, 36, 987, -875, -21, -4861, 24, 16, 64, 46,
		234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
		13, 33, 387, -875, -90, -8871, 77, 66, 66, 34,
	};

	int s2[20] = {
		234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
		65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
	};

	int s3[2] = { 154, 46 };

	int s4[50] = {
		234, 10, -41, 0, 34, 15, 64, 653, -745, 74,
		65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
		134, 10, -41, 801, 32, 25, 63, 653, -715, 18,
		65, 36, 987, -875, -21, -4861, 24, 16, 64, 46,
		234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
	};

	int s5[MAX] = {
		234, 10, -41, 0, 34, 15, 64, 653, -745, 74,
		65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
		134, 10, -41, 801, 32, 25, 63, 653, -715, 18,
		65, 36, 987, -875, -21, -4861, 24, 16, 64, 46,
		234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
		13, 33, 387, -875, -90, -8871, 77, 66, 66, 34,
	};

	int s6[20] = {
		234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
		65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
	};

	int s7[2] = { 154, 46 };

	int s8[50] = {
		234, 10, -41, 0, 34, 15, 64, 653, -745, 74,
		65, 26, 987, -875, -25, -2861, 45, 16, 64, 46,
		134, 10, -41, 801, 32, 25, 63, 653, -715, 18,
		65, 36, 987, -875, -21, -4861, 24, 16, 64, 46,
		234, 10, -41, 20, 38, 19, 40, 653, -785, 23,
	};
	printQuick1(s1, MAX, "s1");
	printQuick1(s2, 20, "s2");
	printQuick1(s3, 2, "s3");
	printQuick1(s4, 50, "s4");

	printQuick2(s5, MAX, "s5");
	printQuick2(s6, 20, "s6");
	printQuick2(s7, 2, "s7");
	printQuick2(s8, 50, "s8");

	return 0;
}

