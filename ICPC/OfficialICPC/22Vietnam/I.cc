#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ask(ll x, ll y) {
  cout << "? " << x << " " << y << endl;
  ll res;
  cin >> res;
  return res;
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = ask(1, i);
  }
  vector<ll> base(n + 1, 0), less(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    if (dp[i] > dp[1]) {
      // a[i] > a[1]
      base[i] = base[i - 1] + 1;
      ll dif = (dp[i] - dp[1]) / 2 + 1;        // >=a[1] and < a[i]
      ll less_one = (i - 1) - base[i - 1] - 1; // <a[i]
      less[i] = dif + less_one;
    } else {
      base[i] = base[i - 1];
      ll dif = (dp[1] - dp[i]) / 2 + 1; // >a[i] and <= a[1]
      ll more_one = base[i];
      less[i] = i - 1 - (dif + more_one);
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << less[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 1; i <= n; ++i) {
  //   cout << base[i] << " ";
  // }
  // cout << "\n";
  vector<ll> ans(n + 1, 0), vis(n + 1, 0);
  for (ll i = n; i >= 1; --i) {
    ll j = 1;
    while (less[i] >= 0) {
      while (vis[j])
        j++;
      if (less[i] == 0)
        break;
      less[i]--;
      j++;
    }
    ans[i] = j;
    vis[j] = 1;
  }
  cout << "!";
  for (int i = 1; i <= n; ++i) {
    cout << " " << ans[i];
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}