#include <bits/stdc++.h>
using namespace std;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int, int>> vec(m);
  {
    int cnt = 0;
    for (auto &[w, u, v, id] : vec) {
      cin >> u >> v >> w;
      u--, v--;
      id = ++cnt;
    }
  }
  sort(vec.begin(), vec.end(), greater<>());
}