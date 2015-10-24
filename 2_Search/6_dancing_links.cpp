#include <iostream>
#include <algorithm>
#include "6_dancing_links.h"
using namespace std;

int main()
{
	//集合有7个成员
	int n = 7;
	//有6个子集
	int sub[MAX][MAX];
	//子集i有cnt[i]个成员 分别从sub[i][1]到sub[i][ cnt[i] ]
	sub[1][1] = 3; sub[1][2] = 5; sub[1][3] = 6;
	sub[2][1] = 1; sub[2][2] = 4; sub[2][3] = 7;
	sub[3][1] = 2; sub[3][2] = 3; sub[3][3] = 6;
	sub[4][1] = 1; sub[4][2] = 4;
	sub[5][1] = 2; sub[5][2] = 7;
	sub[6][1] = 4; sub[6][2] = 5; sub[6][3] = 7;
	int cnt[MAX];
	cnt[1] = 3;
	cnt[2] = 3;
	cnt[3] = 3;
	cnt[4] = 2;
	cnt[5] = 2;
	cnt[6] = 3;
	int m = 6;
	int choose[MAX];

	cout << "there're " << n << " members in set S" << endl;
	for (int i = 1; i <= n; ++i)
		cout << i << ' ';
	cout << endl;
	cout << "there're " << m << " sub set" << endl;
	for (int i = 1; i <= m; ++i) {
		cout << "sub set " << i << '\t';
		for (int j = 1; j <= cnt[i]; ++j) {
			cout << sub[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "dancing_links: " << dancing_links(n, sub, m, cnt, choose) << endl;
	cout << "choose: ";
	for (int i = 1; i <= m; ++i)
		cout << choose[i] << ' ';
	cout << endl;


	char a;
	cin >> a;
	return(0);
}

