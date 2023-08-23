#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  priority_queue<ll, vector<ll>, greater<>> q;
  for (auto &i : a) {
    cin >> i;
    q.emplace(i);
  }
  for (auto &i : b) {
    cin >> i;
  }
  for (auto i : b) {
    q.pop();
    q.emplace(i);
  }
  ll ans = 0;
  while (!q.empty()) {
    ans += q.top();
    q.pop();
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
