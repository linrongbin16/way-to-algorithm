#include "2_multiple_tree.h"
#include <iostream>
using namespace std;

void init_2f(int f[MAX][MAX]) {
  for (int i = 0; i < MAX; ++i)
    for (int j = 0; j < MAX; ++j)
      f[i][j] = 0;
}
void init_3f(int f[MAX][MAX][MAX]) {
  for (int i = 0; i < MAX; ++i)
    for (int j = 0; j < MAX; ++j)
      for (int k = 0; k < MAX; ++k)
        f[i][j][k] = 0;
}
int main() {
  // construct a tree, 46 nodes, 45 branches
  multiple_tree_node t[60];
  for (int i = 0; i < 60; ++i)
    t[i].m_index = i, t[i].m_value = i;
  t[1].m_count = 3;
  t[1].m_child[0] = &t[2];
  t[1].m_child[1] = &t[3];
  t[1].m_child[2] = &t[4];
  t[2].m_count = 3;
  t[2].m_child[0] = &t[5];
  t[2].m_child[1] = &t[6];
  t[2].m_child[2] = &t[7];
  t[3].m_count = 2;
  t[3].m_child[0] = &t[8];
  t[3].m_child[1] = &t[9];
  t[4].m_count = 3;
  t[4].m_child[0] = &t[10];
  t[4].m_child[1] = &t[11];
  t[4].m_child[2] = &t[12];
  t[6].m_count = 3;
  t[6].m_child[0] = &t[13];
  t[6].m_child[1] = &t[14];
  t[6].m_child[2] = &t[15];
  t[9].m_count = 5;
  t[9].m_child[0] = &t[16];
  t[9].m_child[1] = &t[17];
  t[9].m_child[2] = &t[18];
  t[9].m_child[3] = &t[19];
  t[9].m_child[4] = &t[20];
  t[15].m_count = 2;
  t[15].m_child[0] = &t[22];
  t[15].m_child[1] = &t[23];
  t[20].m_count = 4;
  t[20].m_child[0] = &t[24];
  t[20].m_child[1] = &t[25];
  t[20].m_child[2] = &t[26];
  t[20].m_child[3] = &t[27];
  t[22].m_count = 3;
  t[22].m_child[0] = &t[28];
  t[22].m_child[1] = &t[29];
  t[22].m_child[2] = &t[30];
  t[25].m_count = 3;
  t[25].m_child[0] = &t[31];
  t[25].m_child[1] = &t[32];
  t[25].m_child[2] = &t[33];
  t[30].m_count = 2;
  t[30].m_child[0] = &t[34];
  t[30].m_child[1] = &t[35];
  t[31].m_count = 2;
  t[31].m_child[0] = &t[36];
  t[31].m_child[1] = &t[37];
  t[33].m_count = 2;
  t[33].m_child[0] = &t[38];
  t[33].m_child[1] = &t[39];
  t[34].m_count = 3;
  t[34].m_child[0] = &t[40];
  t[34].m_child[1] = &t[41];
  t[34].m_child[2] = &t[42];
  t[37].m_count = 4;
  t[37].m_child[0] = &t[43];
  t[37].m_child[1] = &t[44];
  t[37].m_child[2] = &t[45];
  t[37].m_child[3] = &t[46];
  t[43].m_count = 2;
  t[43].m_child[0] = &t[47];
  t[43].m_child[1] = &t[48];
  t[44].m_count = 2;
  t[44].m_child[0] = &t[49];
  t[44].m_child[1] = &t[50];
  t[47].m_count = 2;
  t[47].m_child[0] = &t[51];
  t[47].m_child[1] = &t[52];
  t[49].m_count = 2;
  t[49].m_child[0] = &t[53];
  t[49].m_child[1] = &t[54];
  t[50].m_count = 2;
  t[50].m_child[0] = &t[55];
  t[50].m_child[1] = &t[56];
  t[53].m_count = 2;
  t[53].m_child[0] = &t[57];
  t[53].m_child[1] = &t[58];

  int f2[MAX][MAX];
  init_2f(f2);
  cout << "multiple tree dynamic:";
  cout << multiple_tree(&t[22], f2, 5) << endl; // 3

  return 0;
}

