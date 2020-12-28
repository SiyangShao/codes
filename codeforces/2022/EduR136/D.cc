#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> E(n);
  for (ll i = 1; i < n; ++i) {
    ll p;
    cin >> p;
    p--;
    E[p].emplace_back(i);
    E[i].emplace_back(p);
  }
  vector<ll> h(n);
  function<bool(ll)> judge = [&](ll len) {
    ll stp = 0;
    function<void(ll, ll)> dfs = [&](ll u, ll fa) {
      h[u] = 0;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        h[u] = max(h[u], h[v] + 1);
      }
      if (h[u] == len - 1 && fa != 0) {
        stp++;
        h[u] = -1;
      }
    };
    dfs(0, 0);
    return stp <= k;
  };
  ll L = 1, R = n - 1;
  ll ans = R;
  while (L <= R) {
    ll mid = (L + R) / 2;
    if (judge(mid)) {
      R = mid - 1;
      ans = min(ans, mid);
    } else {
      L = mid + 1;
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