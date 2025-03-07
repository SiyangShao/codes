#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto check(ll n, ll k) {
  ll cnt = 1, ans = 0;
  while (n >= k) {
    if (n & 1)
      ans += cnt;
    n /= 2;
    cnt *= 2;
  }
  return ans;
}
auto cal(ll n, ll k) {
  if (n < k) {
    return 0LL;
  }
  ll newLen = n / 2;
  ll m = (n + 1) / 2;
  ll layer = check(n / 2, k);
  auto res = cal(newLen, k) * 2LL;
  ll ans = res + layer * m;
  if (n & 1)
    ans += m;

  // cout << "DEBUG: " << n << " " << k << " " << m << " " << newLen << " "
       // << layer << " " << res << " " << ans << endl;
  return ans;
}
auto solve() {
  ll n, k;
  cin >> n >> k;
  cout << cal(n, k) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
