#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<pair<ll, char>> aft;
  for (ll i = 0; i < n; ++i) {
    if (aft.empty()) {
      aft.emplace_back(a[i], s[i]);
    } else {
      if (s[i] != aft.back().second) {
        aft.emplace_back(a[i], s[i]);
      } else {
        auto bck = aft.back();
        aft.pop_back();
        bck.first = max(bck.first, a[i]);
        aft.emplace_back(bck);
      }
    }
  }
  vector<ll> p;
  for (ll i = 1; i + 1 < aft.size(); ++i) {
    p.emplace_back(aft[i].first);
  }
  sort(p.begin(), p.end(), greater<>());
  ll num = (aft.size() - 2 + 1) / 2;
  ll ans = 0;
  for (ll i = 0; i < num; ++i) {
    ans += p[i];
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