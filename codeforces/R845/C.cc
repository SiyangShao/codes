#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> vis(m + 1, 0);
  for (auto &i : a) {
    cin >> i;
    for (ll j = 1; j * j <= i; ++j) {
      if (i % j == 0 && j <= m) {
        vis[j]++;
        if (i / j != j && i / j <= m) {
          vis[i / j]++;
        }
      }
    }
  }
  for (ll i = 1; i <= m; ++i) {
    if (vis[i] == 0) {
      cout << "-1\n";
      return;
    }
  }
  sort(a.begin(), a.end());
  vector<vector<ll>> fact(n);
  for (int i = 0; i < n; ++i) {
    for (ll j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        if (j <= m) {
          fact[i].emplace_back(j);
        }
        if (a[i] / j <= m && a[i] / j != j) {
          fact[i].emplace_back(a[i] / j);
        }
      }
    }
  }
  ll l = 0, r = 0;
  fill(vis.begin(), vis.end(), 0);
  set<ll> remain;
  for (ll i = 1; i <= m; ++i) {
    remain.emplace(i);
  }
  ll ans = a[n - 1] - a[0];
  vector<ll> can(n);
  while (l <= r && r < n) {
    if (!can[r]) {
      for (auto i : fact[r]) {
        remain.erase(i);
        vis[i]++;
      }
      can[r] = 1;
    }
    if (remain.empty()) {
      ans = min(ans, a[r] - a[l]);
      for (auto i : fact[l]) {
        vis[i]--;
        if (vis[i] == 0) {
          remain.emplace(i);
        }
      }
      l++;
    } else {
      r++;
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