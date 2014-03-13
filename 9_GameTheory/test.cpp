//test

#include "general_head.h"
extern bool bash_game(int n, int m, int& get);	//1
extern bool wythoff_game(int a, int b, int& get_a, int& get_b);	//2
extern bool nim_game(int *a, int n, int& idx, int& get);	//3
int main()
{
	int get_a, get_b, idx;
	int a[5] = {34, 45, 77, 13, 43};
	cout << "bash game: A and B take [1, 4] things from 34 things in turn" << endl;
	cout << "A first" << endl;
	if(bash_game(a[0], 4, get_a))	//1
		cout << "A win, A take " << get_a << " things" << endl;
	else
		cout << "A lose, no matter how many he takes" << endl;

	cout << endl << "wythoff game: A and B take at least 1 things from 34 and 45 things in turn" << endl;
	cout << "A first" << endl;
	if(wythoff_game(a[0], a[1], get_a, get_b))	//2
		cout << "A win, A take " << get_a << " from 34 things, and take " << get_b << " from 45 things" << endl;
	else
		cout << "A lost, no matter how many he takes" << endl;

	cout << endl << "nim game: A and B take at least 1 things" << endl;
	cout << "from 34, 45, 77, 13, 43, A first" << endl;
	if(nim_game(a, 5, idx, get_a))
		cout << "A win, A take " << get_a << " things from " << a[idx] << endl;
	else
		cout << "A lost, no matter how many he takes" << endl;
	return(0);
}
