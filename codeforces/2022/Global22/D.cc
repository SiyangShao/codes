#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> b(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  ll k = 0;
  for (ll i = 1; i <= n; ++i) {
    if (i < b[i]) {
      k = i;
    }
  }
  cout << k << "\n";
  vector<vector<ll>> mp(n + 1);
  vector<ll> beg;
  vector<ll> ans;
  for (ll i = 1; i <= n; ++i) {
    if (b[i] == 0 || b[i] == n + 1) {
      beg.emplace_back(i);
    } else {
      mp[b[i]].emplace_back(i);
    }
  }
  while (true) {
    ll nxt = -1;
    for (ll i = 0; i < beg.size(); ++i) {
      if (!mp[beg[i]].empty()) {
        nxt = i;
        break;
      }
    }
    for (ll i = 0; i < beg.size(); ++i) {
      if (i == nxt)
        continue;
      ans.emplace_back(beg[i]);
    }
    if (nxt == -1) {
      break;
    }
    ans.emplace_back(beg[nxt]);
    nxt = beg[nxt];
    beg = move(mp[nxt]);
  }
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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