#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> h(n);
  priority_queue<int, vector<int>, greater<>> Q;
  for (auto &i : h) {
    cin >> i;
    Q.emplace(i);
  }
  int ans = 0;
  while (!Q.empty()) {
    auto u = Q.top();
    Q.pop();
    if (u == 1) {
      ans++;
      if (Q.empty())
        break;
      auto v = Q.top();
      Q.pop();
      v--;
      if (v)
        Q.emplace(v);
    } else {
      ans += Q.size() + 1;
      break;
    }
  }
  cout << ans << "\n";
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