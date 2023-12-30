#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 256;

bitset<N> vis;
auto solve() {
  vis.reset();
  vis[0] = true;
  int n;
  cin >> n;
  int pre = 0;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto i : a | ranges::views::reverse) {
    pre ^= i;
    vis[pre] = true;
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < N; ++j) {
      if (vis[j] && vis[i ^ j]) {
        cout << i << "\n";
        return;
      }
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}