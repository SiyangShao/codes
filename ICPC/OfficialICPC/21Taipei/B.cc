#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  vector<ll> a(n * 2), b(n * 2);
  ll bs = 0, l = 0, r = 0;
  for (ll i = 0; i < n; ++i) {
    a[i * 2] = s1[i] - 'a';
    a[i * 2 + 1] = -1;
    b[i * 2] = s2[i] - 'a';
    b[i * 2 + 1] = -1;
    if (a[i * 2] == b[i * 2]) {
      bs++;
    }
  }
  ll ans = bs;
  for (ll i = 0; i < n * 2 - 1; ++i) {
    ll cnt = bs;
    for (ll len = 1; i - len >= 0 && i + len < n * 2 - 1; ++len) {
      ll L = i - len, R = i + len;
      if (a[L] == -1) {
        continue;
      }
      if (a[L] == b[L]) {
        cnt--;
      }
      if (a[R] == b[R]) {
        cnt--;
      }
      if (a[L] == b[R]) {
        cnt++;
      }
      if (a[R] == b[L]) {
        cnt++;
      }
      if (cnt > ans) {
        // cout<<l<<" "<<r<<"\n";
        ans = cnt;
        l = L, r = R;
      }else if(cnt == ans){
        ll len1 = (r/2+1) - (l/2+1) + 1;
        ll len2 = (R/2+1) - (L/2+1) + 1;
        if(len1 > len2){
          l = L, r = R;
        }
      }
    }
  }
  cout << bs << " " << ans << " " << l / 2 + 1 << " " << r / 2 + 1 << "\n";
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