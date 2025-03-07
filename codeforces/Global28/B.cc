#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  if (n == k || k == 1) {
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
    return;
  }
  vector<ll> ans(n);
  ll cur = 1;
  for (ll i = k - 1; i < n; i += k) {
    ans[i] = cur;
    cur++;
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      cout << cur << " ";
      cur++;
    } else {
      cout << ans[i] << " ";
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
