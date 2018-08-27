#include "GrahamScan.h"

int main() {
    Node s[26];
    s[0].x = 10;
    s[0].y = 1;
    s[1].x = 12;
    s[1].y = 1;
    s[2].x = 17;
    s[2].y = 2;
    s[3].x = 19;
    s[3].y = 4;
    s[4].x = 22;
    s[4].y = 10;
    s[5].x = 22;
    s[5].y = 11;
    s[6].x = 20;
    s[6].y = 13;
    s[7].x = 15;
    s[7].y = 15;
    s[8].x = 7;
    s[8].y = 15;
    s[9].x = 2;
    s[9].y = 9;
    s[10].x = 2;
    s[10].y = 7;
    s[11].x = 3;
    s[11].y = 4;
    s[12].x = 18;
    s[12].y = 3;
    s[13].x = 20;
    s[13].y = 6;
    s[14].x = 21;
    s[14].y = 8;
    s[15].x = 12;
    s[15].y = 15;
    s[16].x = 11;
    s[16].y = 15;
    s[17].x = 10;
    s[17].y = 15;
    s[18].x = 9;
    s[18].y = 15;
    s[19].x = 8;
    s[19].y = 15;
    s[20].x = 7;
    s[20].y = 13;
    s[21].x = 8;
    s[21].y = 11;
    s[22].x = 7;
    s[22].y = 6;
    s[23].x = 10;
    s[23].y = 6;
    s[24].x = 15;
    s[24].y = 2;
    s[25].x = 20;
    s[25].y = 11;

    vector<Node> s1;
    stack<Node> stk;
    for (int i = 0; i < 26; ++i) s1.push_back(s[i]);
    graham_scan(s1, stk);  // 2
    cout << "graham scan:" << endl;
    cout << "the convex hull has " << (int)stk.size() << " nodes" << endl;
    while (!stk.empty()) {
        Node p = stk.top();
        p.print();
        cout << endl;
        stk.pop();
    }
    return 0;
}
