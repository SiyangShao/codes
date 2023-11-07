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
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> num(n + 1, 0);
  for (auto &i : a) {
    cin >> i;
    num[i]++;
  }
  ll ans = 0;
  vector<ll> p(32);
  function<void(ll)> add = [&](ll x) {
    for (int i = 31; i >= 0; --i) {
      if (!(x >> i))
        continue;
      if (!p[i]) {
        p[i] = x;
        break;
      }
      x ^= p[i];
    }
  };
  function<int()> jiji = [&]() {
    int ji = 0;
    for (auto i : p) {
      if (i != 0) {
        ji++;
      }
    }
    return ji;
  };
  function<ll(ll)> cal = [&](int x) {
    if (x == 1) {
      return qpow(2, num[x] - 1);
    }
    fill(p.begin(), p.end(), 0);
    ll sum = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0 && num[i] != 0) {
        add(i);
        sum += num[i];
      }
      if (x % i == 0 && x / i != i && i != 1 && num[x / i] != 0) {
        add(x / i);
        sum += num[x / i];
      }
    }
    int ji = jiji();
    ll tmp = qpow(2, sum - ji);
    tmp = (tmp % MOD + MOD) % MOD;
    tmp = tmp * qpow(2, num[x] - 1) % MOD;
    return tmp;
  };
  for (ll i = 1; i <= n; ++i) {
    if (num[i] == 0)
      continue;
    ll cnt = cal(i);
    cnt = (cnt % MOD + MOD) % MOD;
    // cout << i << " " << cnt << "\n";
    ans = (ans + cnt) % MOD;
  }
  // cout << ans << ", ";
  fill(p.begin(), p.end(), 0);
  for (auto i : a) {
    add(i);
  }
  int ji = jiji();
  ans += qpow(2, n - ji) - 1;
  ans = (ans % MOD + MOD) % MOD;
  cout << ans << "\n";
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