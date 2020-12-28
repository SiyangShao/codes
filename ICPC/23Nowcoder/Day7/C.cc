#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
auto solve() {
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << k - 1 << "\n";
    return 0;
  }
  vector<int> b(n);
  for (int i = 1; i < n; ++i) {
    cin >> b[i];
    b[i] ^= b[i - 1];
  }
  auto getSegs = [](ll t1, ll t2) -> array<ll, 32> {
    array<ll, 32> ret;
    for (ll tb = 31; tb >= 0; --tb)
      ret[tb] = -1;
    for (ll tb = 31; tb >= 0; --tb) {
      bool u = (t1 & (1ll << tb));
      bool v = (t2 & (1ll << tb));
      if (u == v)
        continue;
      else if (u < v) {
        ret[tb] = 0;
        break;
      } else {
        ret[tb] = 1;
        break;
      }
    }
    return ret;
  };
  auto base = getSegs(b[0], b[1]);
  // for (auto i : base) {
  // cout << i << " ";
  // }
  // cout << "\n";
  // return 0;
  for (int i = 1; i + 1 < n; ++i) {
    auto ano = getSegs(b[i], b[i + 1]);
    for (int j = 0; j < 32; ++j) {
      if (base[j] == -1) {
        base[j] = ano[j];
      } else if (ano[j] == -1) {
        continue;
      } else {
        if (base[j] != ano[j]) {
          cout << "-1\n";
          return 0;
        }
      }
    }
  }
  k--;
  for (int i = 0; i < 32; ++i) {
    if (base[i] == -1) {
      base[i] = k & 1;
      k >>= 1;
    }
  }

  int ans = 0, bs = 1;
  for (int i = 0; i < 32; ++i) {
    ans += base[i] * bs;
    bs <<= 1;
  }
  if (k != 0 || ans >= (1LL << 30)) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cout << (ans ^ b[i]) << " ";
  }
  cout << "\n";
  return 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    solve();
  }
}