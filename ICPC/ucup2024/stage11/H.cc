#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
ll qpow(ll x, ll y) {
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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> vec(n);
  for (auto &[t, a, b] : vec) {
    cin >> t >> a >> b;
  }
  sort(vec.begin(), vec.end(), [&](auto &i, auto &j) {
    auto [t1, a1, b1] = i;
    auto [t2, a2, b2] = j;
    return t1 * b1 * b2 + t2 * b2 * a1 < t1 * b1 * a2 + t2 * b2 * b1;
  });
  ll sum = 1, ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    sum *= qpow(get<1>(vec[i]), MOD - 2) * get<2>(vec[i]) % MOD;
    sum %= MOD;
    ans += get<0>(vec[i]) * sum % MOD;
    ans %= MOD;
  }
  cout << ans;
}
