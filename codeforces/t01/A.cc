#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto transfer(string &s) {
  ll res = 0;
  for (auto x : s) {
    res = res * 2 + x - '0';
  }
  return res;
}
auto transfer(ll x, int m) {
  string res;
  for (int i = 0; i < m; i++) {
    res.push_back('0' + (x & 1));
    x >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &x : a) {
    string s;
    cin >> s;
    x = transfer(s);
  }
  sort(a.begin(), a.end());
  ll k = (1LL << m) - n;
  k = (k - 1) / 2;
  ll ans = k;
  while (true) {
    ll less = upper_bound(a.begin(), a.end(), ans) - a.begin();
    // less: number of elements <= ans
    if (ans - less == k) {
      break;
    } else {
      assert(ans - less < k);
      ans++;
    }
  }
  cout << transfer(ans, m) << "\n";
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
