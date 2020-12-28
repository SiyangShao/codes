#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  m--;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll ans = 0;
  ll bs = 0;
  priority_queue<ll, vector<ll>, greater<>> Q;
  for (int i = m + 1; i < n; ++i) {
    bs += a[i];
    Q.emplace(a[i]);
    if (bs < 0) {
      assert(!Q.empty());
      ll mx = Q.top();
      Q.pop();
      assert(mx < 0);
      ans++;
      bs -= mx * 2;
    }
  }
  bs = 0;
  priority_queue<ll> q;
  for (int i = m - 1; i >= 0; --i) {
    bs += a[i + 1];
    q.emplace(a[i + 1]);
    if (bs > 0) {
      assert(!q.empty());
      ll mx = q.top();
      q.pop();
      assert(mx > 0);
      ans++;
      bs -= mx * 2;
      mx = 0;
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
