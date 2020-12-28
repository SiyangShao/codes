#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<vector<ll>> E;
  set<ll> st;
  vector<ll> res;
  for (ll i = 1; i <= n; ++i) {
    st.emplace(i);
  }
  while (!st.empty()) {
    auto u = *st.begin();
    st.erase(st.begin());
    if (u == x) {
      auto ans = {u};
      E.emplace_back(ans);
    } else if (st.contains(u ^ x)) {
      auto ans = {u, u ^ x};
      E.emplace_back(ans);
      st.erase(u ^ x);
    } else {
      res.emplace_back(u);
    }
  }
  ll resXOR = 0;
  for (auto &i : res) {
    resXOR ^= i;
  }
  if (resXOR || ((ll)E.size() < k) || ((ll)E.size() % 2 != k % 2)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<vector<ll>> ans(k);
  for (int i = 0; i < k; ++i) {
    ans[i] = E[i];
  }
  for (ll i = k; i < (ll)E.size(); ++i) {
    for (auto j : E[i])
      ans[k - 1].emplace_back(j);
  }
  for (auto j : res) {
    ans[k - 1].emplace_back(j);
  }
  for (auto &i : ans) {
    cout << i.size();
    for (auto j : i) {
      cout << " " << j;
    }
    cout << "\n";
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