#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s, t;
  cin >> s >> t;
  map<char, ll> fs, ft;
  for (auto e : s)
    fs[e]++;
  for (auto e : t)
    ft[e]++;

  for (auto [u, v] : ft) {
    if (fs[u] < v) {
      cout << 0 << '\n';
      return;
    } else
      fs[u] -= v;
  }

  // find max group cnt,
  map<char, ll> mp = ft;
  for (ll i = 1; i < t.length(); ++i) {
    ll m = (ll)t.length();
    ll len = i;
    ll num = m / len;
    ll sum_len = 0;
    map<char, ll> fullGRP;
    vector<pair<char, ll>> can_do;
    bool flag = false;
    for (auto [u, v] : ft) {
      ll each = v / num;
      ll res = v - each * num;
      fullGRP[u] = each;
      if (each < res) {
        flag = true;
        break;
      }
      sum_len += each;
      can_do.emplace_back(u, (each - res) / (num + 1));
    }
    if (flag)
      continue;
    if (sum_len < len)
      continue;
    ll dif = sum_len - len;
    sort(can_do.begin(), can_do.end(), [&](pair<char, ll> l, pair<char, ll> r) {
      return fs[l.first] < fs[r.first];
    });
    for (auto [u, l] : can_do) {
      if (dif == 0) {
        break;
      }
      ll change = min(dif, l);
      dif -= change;
      fullGRP[u] -= change;
    }
    if (dif != 0)
      continue;
    mp = fullGRP;
    break;
  }
  assert(!mp.empty());
  ll ans = 1e16;
  for (auto [u, v] : mp) {
    if (v == 0)
      continue;
    assert(v > 0);
    ll can = fs[u] / v;
    ans = min(ans, can);
  }
  cout << ans + 1 << endl;
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
