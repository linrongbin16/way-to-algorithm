//test

#include "general_head.h"
#include "geometry.h"
extern double cross(vec v1, vec v2);
extern int segments_intersection(segment l1, segment l2);
extern bool sweeping(segment *l, int n);
void test_segment(segment l1, segment l2);
int main()
{
	vec v1(1, 1), v2(0, 2);
	cout << "vec1(1,1) cross vec2(0,2): " << cross(v1, v2) << endl << endl;
	node p0(0, 0), p1(0, 1), p2(1, 2), p3(2, 1), p4(2, 0), p5(1, 0), p6(1, 1);
	node s[7];
	s[0] = p4, s[1] = p3, s[2] = p2, s[3] = p1, s[4] = p0, s[5] = p5, s[6] = p6;	
	segment l0(p0, p3), l1(p5, p6), l2(p6, p4), l3(p1, p2);
	test_segment(l0, l1);
	test_segment(l1, l2);
	test_segment(l0, l3);

	segment ll[4];
	ll[0] = l0, ll[1] = l1, ll[2] = l2, ll[3] = l3;
	for(int i = 0; i < 4; ++ i){
		ll[i].s_lt.n_idx = i;
		ll[i].s_rt.n_idx = i;
		ll[i].s_lt.n_lt = 1;
		ll[i].s_rt.n_lt = 0;
	}
	cout << "sweeping:" << endl;
	for(int i = 0; i < 4; ++ i)
		ll[i].s_print();
	if(sweeping(ll, 4))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return(0);
}
void test_segment(segment l1, segment l2)
{
	cout << "segments intersection" << endl;
	l1.s_print();
	l2.s_print();
	int ans = segments_intersection(l1, l2);
	if(ans == 0)
		cout << "no intersection" << endl;
	else if(ans == 2)
		cout << "one segment is 'on' another" << endl;
	else if(ans == 1)
		cout << "two segments intersection" << endl;
	cout << endl;
}
