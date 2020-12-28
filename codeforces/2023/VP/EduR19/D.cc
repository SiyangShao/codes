#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  vector<ll> pa(n, -1), val(n);
  for (int i = 0; i < n; ++i) {
    cin >> val[i];
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (l >= 0) {
      pa[l] = i;
      E[i].emplace_back(l);
    } else {
      E[i].emplace_back(-1);
    }
    if (r >= 0) {
      pa[r] = i;
      E[i].emplace_back(r);
    } else {
      E[i].emplace_back(-1);
    }
  }
  set<ll> st;
  function<void(int, ll, ll)> dfs = [&](int u, ll l, ll r) {
    if (u == -1)
      return;
    if (l > r)
      return;
    // cout << u << " " << l << " " << r << "\n";
    if (val[u] >= l && val[u] <= r) {
      st.emplace(val[u]);
    }
    dfs(E[u][0], l, min(r, val[u] - 1));
    dfs(E[u][1], max(l, val[u] + 1), r);
  };
  for (int i = 0; i < n; ++i) {
    if (pa[i] == -1) {
      dfs(i, 0, 1e16);
      break;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!st.contains(val[i])) {
      ans++;
      // cout << i + 1 << " ";
    }
  }
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