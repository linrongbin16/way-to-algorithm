#include <iostream>
#include "../Util.h"
#include "Sweeping.h"

int main() {
    segment ll[4];
    ll[0] = l0, ll[1] = l1, ll[2] = l2, ll[3] = l3;
    for (int i = 0; i < 4; ++i) {
        ll[i].s_lt.n_idx = i;
        ll[i].s_rt.n_idx = i;
        ll[i].s_lt.n_lt = 1;
        ll[i].s_rt.n_lt = 0;
    }
    for (int i = 0; i < 4; ++i) ll[i].s_print();
    if (sweeping(ll, 4))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
