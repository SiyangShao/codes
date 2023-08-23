#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  // Jump from i to i+1 and i+2
  // Want to from 1 to n
  // If we connecet edge between adj nodes, we should find a minimum-weight
  // vertex cover As there shouldn't be a node that there doesn't exist choosen
  // vertex on it's left and it's right Not Bipartite Graph
  int n, m;
  cin >> n >> m;
  vector<int> c(n), x(m);
  for (auto &i : c) {
    cin >> i;
    i--;
  }
  ll ans = 0;
  for (auto &i : x) {
    cin >> i;
    ans += i;
  }
  function<ll(ll)> pos = [&](ll u) { return 1LL << u; };
  function<ll(ll)> get_p = [&](ll u) {
    if (u == 1)
      return 0LL;
    return get_p(u / 2) + 1LL;
  };
  vector<ll> mp(m);
  vector<ll> shall(m);
  for (int i = 0; i + 1 < n; ++i) {
    if (c[i] == c[i + 1])
      shall[c[i]] = 1;
    mp[c[i]] |= pos(c[i + 1]);
    mp[c[i + 1]] |= pos(c[i]);
  }
  mp[c[0]] |= pos(c[0]);
  mp[c[n - 1]] |= pos(c[n - 1]);
  shall[c[0]] = shall[c[n - 1]] = 1;
  int first_half = m / 2;
  vector<ll> dp(pos(first_half)), vis(pos(first_half));
  function<ll(ll)> dfs = [&](ll msk) {
    if (!msk)
      return 0LL;
    if (msk < pos(first_half) && vis[msk])
      return dp[msk];
    ll p = get_p(msk);
    ll res = dfs(msk ^ pos(p));
    if (!shall[p]) {
      res = max(res, dfs(msk ^ pos(p) ^ (mp[p] & msk)) + x[p]);
    }
    if (msk < pos(first_half)) {
      vis[msk] = 1;
      dp[msk] = res;
    }
    return res;
  };
  cout << ans - dfs(pos(m) - 1) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
