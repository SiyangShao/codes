#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  deque<ll> que;
  for (auto &i : a) {
    cin >> i;
    que.emplace_back(i);
  }
  vector<pair<ll, ll>> op(n - 1);
  for (ll i = 0; i + 1 < n; ++i) {
    auto tp = que.front();
    que.pop_front();
    auto sec = que.front();
    que.pop_front();
    op[i] = {tp, sec};
    if (tp <= sec) {
      swap(tp, sec);
    }
    que.push_front(tp);
    que.push_back(sec);
  }
  for (ll i = 0; i < n; ++i) {
    a[i] = que.front();
    que.pop_front();
  }
  assert(a[0] == *max_element(a.begin(), a.end()));
  while (q--) {
    ll m;
    cin >> m;
    if (m < n) {
      cout << op[m - 1].first << " " << op[m - 1].second << "\n";
    } else {
      m -= n;
      m %= n - 1;
      cout << a[0] << " " << a[m + 1] << "\n";
    }
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