#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e5 + 7;
constexpr ll BIT = 31;
ll n, q;
array<array<ll, N>, BIT> a;
array<vector<ll>, N> E;
auto init() {
  for (ll i = 0; i < BIT; ++i) {
    for (ll j = 0; j <= n; ++j) {
      a[i][j] = -1;
    }
  }
}
auto output() {
  for (ll i = 1; i <= n; ++i) {
    ll bs = 1, ans = 0;
    for (ll j = 0; j < BIT; ++j) {
      if (a[j][i] == 1) {
        ans += bs;
      }
      bs *= 2;
    }
    cout << ans << " ";
  }
  cout << "\n";
}
auto solve() {
  cin >> n >> q;
  init();
  while (q--) {
    ll i, j, x;
    cin >> i >> j >> x;
    if (i == j) {
      for (ll k = 0; k < BIT; ++k) {
        if (x & 1) {
          a[k][i] = 1;
        } else {
          a[k][i] = 0;
        }
        x /= 2;
      }
      continue;
    }
    E[i].emplace_back(j);
    E[j].emplace_back(i);
    for (ll k = 0; k < BIT; ++k) {
      if (x & 1) {

      } else {
        a[k][i] = 0;
        a[k][j] = 0;
      }
      x /= 2;
    }
  }
  function<void(ll, ll)> greedy = [&](ll u, ll bit) {
    assert(a[bit][u] == -1);
    bool flag = false;
    for (auto v : E[u]) {
      if (a[bit][v] == 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      a[bit][u] = 1;
    } else {
      a[bit][u] = 0;
      for (auto v : E[u]) {
        assert(a[bit][v] != 0);
        a[bit][v] = 1;
      }
    }
  };
  // for(ll bit = 0 ; bit < 3; ++bit){
  //   for(ll i = 1; i<=n; ++i){
  //     cout<<a[bit][i]<<" ";
  //   }
  //   cout<<"\n";
  // }
  // cout<<"\n";
  for (ll bit = 0; bit < BIT; ++bit) {
    for (ll i = 1; i <= n; ++i) {
      if (a[bit][i] == -1) {
        // cout<<bit<<","<<i<<" ";
        greedy(i, bit);
      }
      // cout<<a[bit][i]<<" ";
    }
    // cout<<"\n";
  }
  // for (ll bit = 0; bit < 3; ++bit) {
  //   for(ll i = 1; i<=n; ++i){
  //     cout<<a[bit][i]<<" ";
  //   }
  //   cout<<"\n";
  // }

  output();
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}