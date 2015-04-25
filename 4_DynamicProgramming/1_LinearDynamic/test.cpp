//test

#include <iostream>
#include "1_longest_common_subsequence.h"
#include "2_longest_increasing_subsequence.h"
#include "3_longest_increasing_subsequence_extension.h"
#include "4_bidirection_subsequence.h"
using std::cout;
using std::endl;

int main()
{
	int s1[7] = {0, 1, 1, 5, 4, 9, 7};
	int s2[7] = {0, 5, 6, 11, 4, 9, 0};
	cout << "common subsequence: " 
		 << longest_common_subsequence(s1, s2, 6) << endl << endl;
	cout << "increasing subsequence:" << endl
		 << longest_increasing_subsequence1(s1, 6) << endl
		 << longest_increasing_subsequence2(s1, 6) << endl << endl;
	int s3[9] = {0, 9, 3, 7, 6, 10, 15, 8, 11};
	int m;
	cout << "extended subsequence: "
		 << longest_increasing_subsequence_extension(s3, 8, m) << endl;
	cout << "number of the subsequence: " << m << endl << endl;
	cout << "bidirection subsequence: "
		 << bidirection_subsequence(s3, 8, m) << endl
		 << "the elem is: " << m << endl;
	return(0);
}
