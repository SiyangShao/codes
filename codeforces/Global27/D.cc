#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...)                                                               \
  {}
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto check(ll x) {
  ll cnt = 0;
  while (x % 2 == 0) {
    x >>= 1;
    cnt++;
  }
  return cnt;
}
auto qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto cmp(ll x, ll y, ll pw){
  if(pw <= 30){
    return x <= y * (1LL << pw);
  } else {
    return true;
  }
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> bs(n), pw(n), record(n);
  for (auto &i : a)
    cin >> i;
  for (int i = 0; i < n; ++i) {
    pw[i] = check(a[i]);
    bs[i] = a[i] >> pw[i];
  }
  dbg(bs, pw);
  ll ans = 0;
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    ll pw_accu = pw[i];
    while (!st.empty() && cmp(bs[st.top()], bs[i], pw_accu)) {
      auto j = st.top();
      pw_accu += record[j];
      ans = (ans - qpow(2, record[j]) * bs[j] % MOD + MOD) % MOD;
      ans = (ans + bs[j]) % MOD;
      record[j] = 0;
      st.pop();
    }
    record[i] = pw_accu;
    ans = (ans + bs[i] * qpow(2, pw_accu) % MOD) % MOD;
    st.emplace(i);
    cout << ans << " \n"[i + 1 == n];
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
