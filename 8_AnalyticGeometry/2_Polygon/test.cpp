//test

#include "general_head.h"
#include "geometry.h"
extern double polygon_area(node *s, int n);		//1
extern pair<double, double> polygon_gravity_center(node *s, int n);		//2
extern int ray(node *s, int n, node p);		//3
extern double rotating_calipers(node *s, int n);	//4
void print_p(node *s, int n, string info);
void test_ray(node *s, int n, node p, string info);
int main()
{
	node s1[3];
	s1[0].n_x = 1; s1[0].n_y = 0;
	s1[1].n_x = 4; s1[1].n_y = 0;
	s1[2].n_x = 2; s1[2].n_y = 3;
	print_p(s1, 3, "triangle s1:");

	node s2[12];
	s2[0].n_x = 10; s2[0].n_y = 1;
	s2[1].n_x = 12; s2[1].n_y = 1;
	s2[2].n_x = 17; s2[2].n_y = 2;
	s2[3].n_x = 19; s2[3].n_y = 4;
	s2[4].n_x = 22; s2[4].n_y = 10;
	s2[5].n_x = 22; s2[5].n_y = 11;
	s2[6].n_x = 20; s2[6].n_y = 13;
	s2[7].n_x = 15; s2[7].n_y = 15;
	s2[8].n_x = 7; s2[8].n_y = 15;
	s2[9].n_x = 2; s2[9].n_y = 9;
	s2[10].n_x = 2; s2[10].n_y = 7;
	s2[11].n_x = 3; s2[11].n_y = 4;
	print_p(s2, 12, "polygon s2:");

	cout << "triangle s1 area: " << polygon_area(s1, 3) << endl;	//1
	cout << "polygon s2 area: " << polygon_area(s2, 12) << endl;

	pair<double, double> o1 = polygon_gravity_center(s1, 3);	//2
	pair<double, double> o2 = polygon_gravity_center(s2, 12);
	cout << "triange s1 gravity center (x: " << o1.first << ",y: " << o1.second << ")" << endl << endl;
	cout << "polygon s2 gravity center (x: " << o2.first << ",y: " << o2.second << ")" << endl << endl;

	test_ray(s1, 3, node(2, 1), "triange s1");	//3
	test_ray(s2, 12, node(10, 10), "polygon s2");

	print_p(s1, 3, "triangle s1:");
	cout << "triangle s1 diameter: " <<  rotating_calipers(s1, 3) << endl;	//4
	print_p(s2, 12, "polygon s2:");
	cout << "polygon s2 diameter: " << rotating_calipers(s2, 12) << endl;
	return(0);
}
void test_ray(node *s, int n, node p, string info)
{
	p.n_print();
	int as = ray(s, n, p);
	if(as == 0)
		cout << " is in ";
	if(as == 1)
		cout << " is 'on' ";
	if(as == 2)
		cout << " is out ";
	cout << info << endl;
}
void print_p(node *s, int n, string info)
{
	cout << info << endl;
	for(int i = 0; i < n; ++ i){
		cout << i << ' ';
		s[i].n_print();
		cout << endl;
	}
	cout << endl;
}
