//test

#include "general_head.h"
extern int longest_common_subsequence(int *s1, int *s2, int n);
extern int longest_increasing_subsequence1(int *s, int n);
extern int longest_increasing_subsequence2(int *s, int n);
extern int extended_longest_increasing_subsequence(int *s, int n, int& m);
extern int bidirection_subsequence(int *s, int n, int& idx);
extern void range_max_query(int *s, int n, map<pair<int, int>, int>& query);
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
		 << extended_longest_increasing_subsequence(s3, 8, m) << endl;
	cout << "number of the subsequence: " << m << endl << endl;
	cout << "bidirection subsequence: "
		 << bidirection_subsequence(s3, 8, m) << endl
		 << "the elem is: " << m << endl;

	cout << endl << "range max query" << endl;
	cout << "sequence: ";
	int q[15] ={0, 3, 4, 12, 34, -5, 3, 45, 12, 22, 9, 7, 56, 27, 11};
	for(int i = 1; i < 15; ++ i)
		cout << q[i] << ' ';
	cout << endl;
	map<pair<int, int>, int> query;
	query.insert(make_pair(make_pair(1, 14), 0));
	query.insert(make_pair(make_pair(1, 1), 0));
	query.insert(make_pair(make_pair(11, 14), 0));
	range_max_query(q, 14, query);
	for(map<pair<int, int>, int>::iterator it = query.begin(); 
			it != query.end(); ++ it)
		cout << "query:(" << it->first.first << "," << it->first.second << "),max: " << it->second << endl;
	return(0);
}






