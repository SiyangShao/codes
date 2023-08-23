#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(k);
  for (auto &i : a) {
    cin >> i;
  }
  priority_queue<ll> Q;
  ll res_max = n * m - 2;
  for (auto &i : a) {
    while (!Q.empty() && Q.top() == k) {
      Q.pop();
      k--;
    }
    Q.emplace(i);
    if ((ll)Q.size() >= res_max) {
      cout << "TIDAK\n";
      return;
    }
  }
  cout << "YA\n";
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