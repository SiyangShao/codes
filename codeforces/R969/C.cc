https://contest.ucup.ac/contests#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto sol2(int n, vector<ll> b) {
  vector<vector<ll>> a(n + 1, vector<ll>(20, 0));
  vector<ll> log2(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    a[i][0] = b[i];
    if (i != 1) {
      log2[i] = log2[i / 2] + 1;
    }
  }
  for (int j = 1; j < 20; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      a[i][j] = gcd(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
    }
  }
  constexpr ll inf = 1LL << 33;
  function<ll(int, int)> ask = [&](int l, int r) {
    auto k = log2[r - l + 1];
    ll result = gcd(a[l][k], a[r - (1 << k) + 1][k]);
    if (result == 0) {
      result = inf;
    }
    return result;
  };
  function<int(int, ll)> check = [&](int i, ll x) {
    if(x == 0) {
      x = inf;
    }
    int l = i, r = n;
    int ans = l;
    while (l <= r) {
      int mid = (l + r) / 2;
      ll result = ask(i, mid);
      if (result < x) {
        r = mid - 1;
      } else {
        l = mid + 1;
        ans = max(ans, mid);
      }
    }
    return ans;
  };
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int j = check(i, a[i][0]);
    if ((a[i][0] & (a[i][0] - 1)) == 0) {
      ans += j - i + 1;
    }
    while (j < n) {
      auto g = ask(i, j + 1);
      int nj = check(i, g);
      if ((g & (g - 1)) == 0) {
        ans += nj - j;
      }
      j = nj;
    }
  }
  return ans;
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<ll> b(n);
  for (int i = 1; i < n; ++i) {
    b[i] = abs(a[i] - a[i - 1]);
  }
  dbg(b);
  auto ans = sol2(n - 1, b);
  cout << ans + n << "\n";
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