#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 10000 + 5;
array<ll, N> w, c;
array<vector<ll>, N> E;
array<bitset<N>, N> vis;
auto solve() {
  int n;
  ll TH;
  cin >> n >> TH;
  for (int i = 1; i <= n; ++i) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    E[X].emplace_back(Y);
    E[X].emplace_back(Z);
    cin >> w[X];
  }
  for (int i = n + 1; i > 1; --i) {
    vis[i][i] = true;
    for (int j = i; j <= n + 1; ++j) {
      if (vis[i][j]) {
        c[i] += w[j];
      }
    }
    for (auto v : E[i]) {
      vis[v] = vis[v] | vis[i];
    }
  }
  int cnt = 0;
  for (int i = 2; i <= n + 1; ++i) {
    if (c[i] >= TH) {
      cout << i << " " << c[i] << "\n";
      cnt++;
    }
  }
  cout << cnt << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}