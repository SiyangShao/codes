#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  const ll max_size = 2 * n * n + 1;
  unordered_map<ll, ll> mp(max_size), nxt(max_size);
  mp[a[1]] = 1;
  auto output = [&]() {
    ll ans = 0;
    for (auto [j, val] : mp) {
      ans += val;
      ans %= MOD;
    }
    cout << ans << "\n";
  };
  for (int i = 1; i + 1 < n; ++i) {
    nxt.clear();
    for (auto [j, val] : mp) {
      if (val == 0 || j == 0)
        continue;
      nxt[a[i + 1] + j] += val;
      nxt[a[i + 1] + j] %= MOD;
      nxt[a[i + 1] - j] += val;
      nxt[a[i + 1] - j] %= MOD;
    }
    if (mp[0]) {
      nxt[a[i + 1]] += mp[0];
      nxt[a[i + 1]] %= MOD;
    }
    mp = nxt;
  }
  output();
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
