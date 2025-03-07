#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> val(n);
  vector<int> deg(n);
  vector<ll> op(n);
  for (auto &[l, r] : val)
    cin >> l >> r;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  auto check = [&](ll f) -> bool {
    for (int i = 0; i < n; i++) {
      deg[i] = (int)E[i].size();
      op[i] = 0;
    }
    queue<int> Q;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
      if (deg[i] == 1) {
        Q.push(i);
        vis[i] = 1;
        op[i] = f - val[i].first;
      }
    }
    int rt = -1;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (f < val[u].first) {
        return false;
      }
      cout << u + 1 << " " << op[u] << " " << f << " " << val[u].second << endl;
      if (f > val[u].second + op[u]) {
        if (rt != -1)
          return false;
        rt = u;
        continue;
      }
      op[u] = min(op[u], f - val[u].first);
      int nxt = 0;
      for (auto v : E[u]) {
        if (vis[v])
          continue;
        deg[v]--;
        if (deg[v] == 1) {
          vis[v] = 1;
          op[v] += op[u];
          Q.push(v);
          nxt++;
        }
      }
      assert(nxt <= 1);
    }
    if (rt != -1) {
      ll sum = 0;
      for (auto v : E[rt]) {
        sum += op[v];
      }
      if (sum + val[rt].second < f) {
        return false;
      }
    }
    return true;
  };
  ll l = 0, r = 1e16, ans = r;
  assert(check(3000000000));
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
