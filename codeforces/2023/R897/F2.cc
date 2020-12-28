#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;

std::map<std::vector<int>, int> tree_hash;
std::vector<int> siz;
std::vector<std::vector<int>> vec;

int f(std::vector<int> &a) {
  if (tree_hash.count(a)) {
    return tree_hash[a];
  }
  int v = tree_hash.size();
  int sz = 1, d = 0;
  for (int i : a) {
    sz += siz[i];
    d++;
  }
  siz.push_back(sz);
  vec.push_back(a);
  return tree_hash[a] = v;
}

void run(int tCase) {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (n == 2) {
    std::cout << "1 2\n";
    return;
  }

  std::vector<int> h(n);
  std::set<int> s;

  auto init = [&](auto &dfs, int u, int fa) -> void {
    std::vector<int> a;
    for (int v : adj[u]) {
      if (v == fa)
        continue;
      dfs(dfs, v, u);
      a.push_back(h[v]);
    }
    std::sort(a.begin(), a.end());
    h[u] = f(a);
    s.insert(h[u]);
  };
  init(init, 0, -1);
  std::vector<int> trees;
  for (int cnt = 1;; ++cnt) {
    std::vector<int> tmp, new_trees;
    int ok = -1;
    auto dfs = [&](auto &dfs, int sum, int idx) -> void {
      if (sum == 0) {
        int v = f(tmp);
        new_trees.push_back(v);
        if (!s.count(v)) {
          ok = v;
        }
        return;
      }
      for (int i = idx; i < trees.size(); i++) {
        int t = trees[i];
        if (sum < siz[t])
          continue;
        tmp.push_back(t);
        dfs(dfs, sum - siz[t], i);
        tmp.pop_back();
        if (~ok)
          return;
      }
    };
    dfs(dfs, cnt - 1, 0);
    if (~ok) {
      dbg(cnt);
      int now = 1;
      for (int i = 0; i < n - cnt; ++i) {
        std::cout << now << ' ' << now + 1 << '\n';
        now++;
      }
      auto print = [&](auto &dfs, int u, int tree) -> void {
        for (auto sub : vec[tree]) {
          int v = ++now;
          std::cout << u << ' ' << v << '\n';
          dfs(dfs, v, sub);
        }
      };
      print(print, now, ok);
      return;
    }
    for (auto t : new_trees) {
      trees.push_back(t);
    }
    std::sort(trees.begin(), trees.end());
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T = 1;
  //    std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    run(t);
  }
  return 0;
}