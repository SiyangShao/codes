#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll ans = 0, sum = 0;
  map<ll, ll> mp;
  vector<vector<int>> E;
  vector<int> tmp;
  bool flag = false;
  for (auto &i : a) {
    if (!flag) {
      if (i == 0) {
        flag = true;
        tmp.emplace_back(0);
      } else {
        sum += i;
        if (sum == 0) {
          ans++;
        }
      }
      continue;
    }
    if (i == 0) {
      E.emplace_back(tmp);
      tmp.clear();
      tmp.emplace_back(0);
    } else {
      tmp.emplace_back(i);
    }
  }
  if (!tmp.empty())
    E.emplace_back(tmp);
  if (E.empty()) {
    cout << ans << "\n";
    return;
  }
  reverse(E.begin(), E.end());
  for (auto &i : E) {
    assert(i[0] == 0);
    sum = 0;
    mp.clear();
    for (auto &j : i) {
      sum += j;
      mp[sum]++;
    }
    ll cnt = 0;
    for (auto &[_, j] : mp) {
      cnt = max(cnt, j);
    }
    ans += cnt;
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