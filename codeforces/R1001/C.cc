#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  ll ans = accumulate(a.begin(), a.end(), 0LL);
  while (n > 1) {
    vector<ll> b(n - 1);
    ll sum = 0;
    for (int i = 0; i + 1 < n; i++) {
      b[i] = a[i] - a[i + 1];
      sum += b[i];
    }
    ans = max(ans, abs(sum));
    swap(a, b);
    n--;
  }
  cout << ans << "\n";
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
