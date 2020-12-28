#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 5> base = {1, 10, 100, 1000, 10000};
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  vector cnt(n, vector<ll>(5, 0));
  ll sum = 0;
  vector<ll> v(n);
  auto pre_pos = cnt;
  auto pre_neg = cnt;
  for (int i = n - 1; i >= 0; --i) {
    if (i + 1 < n)
      cnt[i] = cnt[i + 1];
    int ch = s[i] - 'A';
    if (cnt[i][ch] == 0) {
      v[i] = base[ch];
      pre_pos[i][ch]++;
    } else {
      v[i] = -base[ch];
    }
    sum += v[i];
    if (cnt[i][ch] == 1)
      pre_neg[i][ch]++;
    for (int j = 0; j < ch; ++j)
      cnt[i][j]++;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      pre_pos[i][j] += pre_pos[i - 1][j];
      pre_neg[i][j] += pre_neg[i - 1][j];
    }
  }
  ll ans = sum;
  for (int i = 0; i < n; ++i) {
    int ch = s[i] - 'A';
    for (int j = 0; j < 5; ++j) {
      ll tmp = sum - v[i];
      ll f = (i + 1 == n) ? 0 : cnt[i + 1][j];
      tmp += (f ? -1 : 1) * base[j];
      if (i != 0) {
        for (int k = ch; k < j; ++k) {
          tmp -= 2 * pre_pos[i - 1][k] * base[k];
        }
        for (int k = j; k < ch; ++k) {
          tmp += 2 * pre_neg[i - 1][k] * base[k];
        }
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << '\n';
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