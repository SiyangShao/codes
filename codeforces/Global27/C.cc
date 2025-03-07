#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...)                                                               \
  {}
#endif
using namespace std;
using ll = long long;
auto sol(ll n, ll mx) {
  assert(mx + 1 <= n);
  vector<ll> ans;
  for (ll i = 1; i <= n; ++i) {
    if (i != mx && i != mx + 1 && i != mx - 1) {
      ans.emplace_back(i);
    }
  }
  ans.emplace_back(mx + 1);
  ans.emplace_back(mx);
  ans.emplace_back(mx - 1);
  return ans;
}
auto solve() {
  ll n;
  cin >> n;
  if (n == 5) {
    cout << "5\n2 1 3 4 5\n";
    return;
  }
  bool odd = false;
  if (n % 2 == 1) {
    odd = true;
    n--;
  }
  ll mx = 1;
  while (mx * 2 <= n) {
    mx *= 2;
  }
  // mx is the largest power of 2 less than n
  // take mx+1, mx, mx-1 as the last 3
  vector<ll> ans;
  if (mx == n) {
    ans = sol(n - 2, mx / 2);
    ans.emplace_back(mx - 1);
    ans.emplace_back(mx);
  } else {
    ans = sol(n, mx);
  }
  if (odd) {
    n++;
    ans.emplace_back(n);
  }
  ll sum = 0;
  for (ll i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      sum = sum & ans[i - 1];
    } else {
      sum = sum | ans[i - 1];
    }
  }
  cout << sum << "\n";
  for (ll i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
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
