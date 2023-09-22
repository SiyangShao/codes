#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); };
  int find(int u) {
    if (u == fa[u])
      return u;
    return fa[u] = find(fa[u]);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &i : s)
    cin >> i;
  vector dis(n, vector<ll>(n, inf));
  vector<pair<int, int>> edg;
  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    dis[i][i] = 0;
    for (int j = i + 1; j < n; ++j) {
      if (s[i][j] == '1') {
        edg.emplace_back(i + 1, j + 1);
        dis[i][j] = dis[j][i] = 1;
        dsu.merge(i, j);
      }
    }
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dis[i][j] % 2 != (s[i][j] - '0')) {
        cout << "NO\n";
        return;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) == i)
      cnt++;
  }
  if (cnt > 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << edg.size() << "\n";
  for (auto &[u, v] : edg) {
    cout << u << " " << v << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}