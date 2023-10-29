#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
void process(vector<pair<ll, ll>> &p) {
  sort(p.begin(), p.end(), [&](auto x, auto y) {
    if (x.first != y.first)
      return x.first < y.first;
    return x.second > y.second;
  });
  int n = (int)p.size();
  vector<pair<ll, ll>> q;
  for (int i = 0; i < n; ++i) {
    while (!q.empty() and p[i].second > q.back().second) {
      q.pop_back();
    }
    q.emplace_back(p[i]);
  }
  p = q;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> p(n), q(m);
  for (auto &[u, v] : p) {
    cin >> v >> u;
    v = -v;
    u = -u;
  }
  for (auto &[u, v] : q) {
    cin >> u >> v;
  }
  process(p);
  // reverse(p.begin(), p.end());
  for (auto &[u, v] : p) {
    swap(u, v);
    u = -u;
    v = -v;
  }
  process(q);
  // cout << "p:\n";
  // for (auto [u, v] : p) {
  //   cout << u << " " << v << "\n";
  // }
  // cout << "q:\n";
  // for (auto [u, v] : q) {
  //   cout << u << " " << v << "\n";
  // }
  // cout << "\n";

  constexpr ll inf = 2e18;
  ll ans = 0;
  auto sum = [&](ll x, ll y, ll a, ll b) {
    if (x < a || y < b)
      return -inf;
    return (x - a) * (y - b);
  };
  function<void(int, int, int, int)> cal = [&](int l, int r, int L, int R) {
    if (l > r || L > R)
      return;
    int mid = (l + r) / 2;
    ll cnt = -inf;
    int MID = L;
    for (int i = L; i <= R; ++i) {
      auto [x, y] = q[i];
      auto [a, b] = p[mid];
      ll earn = sum(x, y, a, b);
      // ll earn = (x - a) * (y - b);
      assert(earn >= -inf);
      if (earn > cnt) {
        cnt = earn;
        MID = i;
      }
    }
    // cout << l << " " << r << " " << L << " " << R << " "
    //      << " " << mid << " " << MID << " " << cnt << "\n";
    // cout << mid << " " << cnt << " " << MID << "\n";
    ans = max(ans, cnt);
    cal(l, mid - 1, L, MID);
    cal(mid + 1, r, MID, R);
  };
  cal(0, (int)p.size() - 1, 0, (int)q.size() - 1);
  cout << ans << "\n";
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