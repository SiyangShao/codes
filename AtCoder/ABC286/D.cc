#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e4 + 7;
bitset<N> can;
auto solve() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> coin(n);
  can[0] = true;
  for (auto &[a, b] : coin) {
    cin >> a >> b;
    bitset<N> cur;
    for (int i = 0; i <= b; ++i) {
      int num = i * a;
      if (num < N) {
        cur[num] = true;
      }
    }
    for (int i = N - 1; i >= 0; --i) {
      if (can[i]) {
        can |= (cur << i);
      }
    }
  }
  if (can[x]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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