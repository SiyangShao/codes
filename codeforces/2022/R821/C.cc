#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (a[0] % 2 == 0) {
    for (auto &i : a) {
      i++;
    }
  }
  a.emplace_back(1e9 + 3);
  vector<ll> odd;
  for (ll i = 0; i <= n; ++i) {
    if (a[i] % 2 == 1) {
      odd.emplace_back(i);
    }
  }
  assert(odd.size() >= 2);
  vector<pair<ll, ll>> ans;
  for (ll i = odd.size() - 2; i >= 0; --i) {
    if (a[odd[i]] > a[odd[i + 1]]) {
      ans.emplace_back(odd[i], odd[i + 1]);
      a[odd[i]] = a[odd[i + 1]];
    }
  }
  ll cur = 0;
  for (ll i = 1; i < n; ++i) {
    assert(odd[cur] < n);
    if (a[i] % 2 == 1)
      cur++;
    else
      ans.emplace_back(odd[cur], i);
  }
  cout << ans.size() << "\n";
  for (auto &[u, v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
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