#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto check(ll x, ll val) {
  ll sum = x * (x - 1) / 2;
  return val >= sum;
}
auto sol(int n) {
  ll sum = (n + 1LL) * n / 2;
  vector<int> str(n);
  sum /= 2;
  sum -= n;
  ll len = 0;
  int x = 0;
  while (sum > 0) {
    ll l = 1, r = n;
    ll ans = 1;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (check(mid, sum)) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    sum -= (ans - 1) * ans / 2;
    for (ll i = len; i < len + ans; ++i) {
      str[i] = x;
    }
    x ^= 1;
    len += ans;
  }
  for (ll i = len; i < n; ++i) {
    str[i] = x;
    x ^= 1;
  }
  // cout<<n<<" "<<len<<"\n";
  assert(n >= len);
  return str;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  if (n % 4 == 0 || n % 4 == 3) {
    cout << "Yes\n";
    auto str = sol(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << str[i] << " \n"[j + 1 == m];
      }
    }
  } else if (m % 4 == 0 || m % 4 == 3) {
    cout << "Yes\n";
    auto str = sol(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << str[j] << " \n"[j + 1 == m];
      }
    }
  } else {
    cout << "No\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // for (int i = 1; i <= 100; ++i) {
  //   if (i % 4 == 3 || i % 4 == 0) {
  //     cout<<i<<" ";
  //     auto str = sol(i);
  //     for(auto j :str ){
  //       cout<<j;
  //     }
  //     cout<<"\n";
  //   }
  // }
  cin >> _;
  while (_--) {
    solve();
  }
}