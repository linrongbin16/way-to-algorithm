#include "AStarSearch.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int a_star_dir[4] = {-3, 3, -1, 1};

// string operation
#define invalid ("---------")
#define hash(a) (std::hash<std::string>{}(std::string(a, MAX)))
#define streq(a, b) (std::strncmp((a), (b), (MAX)) == 0)

static int StringDiff(const char *a, const char *b) {
  int diff = 0;
  for (int i = 0; i < MAX; ++i)
    if (a[i] != b[i])
      diff++;
  return diff;
}

static const char *Neighbor(const char *a, int dir) {
  int xpos;
  for (xpos = 0; xpos < MAX; xpos++)
    if (a[xpos] == 'x')
      break;
  int npos = xpos + a_star_dir[dir];
  if (npos < 0 || npos >= 9) {
    return invalid;
  }

  char *ret = new char[MAX];
  std::memcpy(ret, a, MAX);
  std::swap(ret[xpos], ret[npos]);
  return ret;
}

// get closest node
static const char *PopOpenTable(std::vector<const char *> *open_tab,
                                const char *end,
                                const std::unordered_map<int, int> &g) {
  const char *ret = invalid;
  int f = INF;
  std::vector<const char *>::iterator i = open_tab->begin();
  for (; i != open_tab->end(); i++) {
    const char *tmp = *i;
    int tmp_hash = hash(tmp);
    int h = StringDiff(tmp, end);
    assert(g.find(tmp_hash) != g.end());
    if (f > h + g.find(tmp_hash)->second) {
      f = h + g.find(tmp_hash)->second;
      ret = tmp;
    }
  }
  open_tab->erase(i);
  return ret;
}

static std::vector<const char *>
AStarPath(const std::unordered_map<const char *, const char *> &close_tab,
          const char *e) {
  std::vector<const char *> path;
  path.push_back(e);

  while (true) {
    std::unordered_map<const char *, const char *>::const_iterator from =
        close_tab.find(e);
    if (from == close_tab.end() || streq(from->second, invalid))
      break;
    path.push_back(from->second);
    e = from->second;
  }
  return path;
}

std::vector<const char *> AStarSearch(const char *beg, const char *end) {
  std::unordered_map<int, int> g;
  std::vector<const char *> open_tab;
  std::unordered_map<const char *, const char *> close_tab;

  // g.insert(std::make_pair(hash(beg)));
  open_tab.push_back(beg);
  close_tab.insert(std::make_pair(beg, invalid));

  while (!open_tab.empty()) {
    const char *node = PopOpenTable(&open_tab, end, g);
    int node_hash = hash(node);
    if (streq(node, end)) {
      return AStarPath(close_tab, end);
    }

    /* node中'x'与上下左右4个方向的数字交换位置 */
    for (int i = 0; i < 4; i++) {
      const char *neighbor = Neighbor(node, i);
      int neighbor_hash = hash(neighbor);
      if (streq(neighbor, invalid)) {
        continue;
      }
      // 邻节点的g(x)加1
      g[neighbor_hash] = g[node_hash] + 1;

      // 若close_tab中已经存在neighbor_node则跳过该点
      if (close_tab.find(neighbor) != close_tab.end())
        continue;
      open_tab.push_back(neighbor);
      close_tab.insert(std::make_pair(neighbor, node));
    }
  }
  return {};
}

