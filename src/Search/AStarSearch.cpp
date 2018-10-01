#include "AStarSearch.h"
#include <cassert>
#include <cstring>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// get closest node
static BfsNode PopMinF(std::list<BfsNode> *open_tab,
                       const std::unordered_map<BfsNode, int> &close_tab,
                       const BfsNode &end) {
  int f = INF;
  BfsNode ret(-1, -1);
  std::list<BfsNode>::iterator min_i = open_tab->end();

  for (std::list<BfsNode>::iterator i = open_tab->begin(); i != open_tab->end();
       i++) {
    assert(close_tab.find(*i) != close_tab.end());
    int g = close_tab.find(*i)->second;
    int h = std::abs(i->col - end.col) + std::abs(i->row - end.row);
    if (f > h + g) {
      f = h + g;
      ret = *i;
      min_i = i;
    }
  }

  assert(ret.row != -1 && ret.col != -1);
  assert(min_i != open_tab->end());
  open_tab->erase(min_i);
  return ret;
}

static std::vector<BfsNode> AStarPath(BfsNode father[MAX][MAX],
                                      const BfsNode &end) {
  std::vector<BfsNode> path;
  BfsNode i;
  for (i = end; i != father[i.row][i.col]; i = father[i.row][i.col]) {
    path.push_back(i);
  }
  path.push_back(i);
  return path;
}

std::vector<BfsNode> AStarSearch(int block[MAX][MAX], int n, int m,
                                 const BfsNode &beg, const BfsNode &end) {
  BfsNode father[MAX][MAX];
  std::list<BfsNode> open_tab;
  std::unordered_map<BfsNode, int> close_tab;

  std::memset(father, 0, sizeof(BfsNode) * MAX * MAX);
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      father[i][j] = BfsNode(i, j);
  open_tab.push_back(beg);
  close_tab.insert(std::make_pair(beg, 0));

  while (!open_tab.empty()) {
    BfsNode e = PopMinF(&open_tab, close_tab, end);
    if (e == end) {
      return AStarPath(father, end);
    }

    // e的上下左右四周节点
    for (int i = 0; i < 4; i++) {
      int nrow = e.row + row_dir[i];
      int ncol = e.col + col_dir[i];

      if (!in_range(nrow, n) || !in_range(ncol, m)) {
        continue;
      }
      if (block[nrow][ncol]) {
        continue;
      }

      BfsNode y(nrow, ncol);

      // close_tab中不存在节点y
      if (close_tab.find(y) == close_tab.end()) {
        close_tab[y] = close_tab[e] + 1;
        open_tab.push_back(y);
        father[y.row][y.col] = e;
      } else {
        // close_tab中已存在节点y
        int old_g = close_tab[y];
        int new_g = close_tab[e] + 1;
        if (new_g < old_g) {
          close_tab.erase(close_tab.find(y));
          close_tab[y] = new_g;
          open_tab.push_back(y);
          father[y.row][y.col] = e;
        }
      }
    } // for
  }   // while
  return {};
}

