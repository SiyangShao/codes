#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll M = LONG_LONG_MAX;
ll getMSB(ll x) {
  if (!x)
    return M;
  return 1LL << (63 - __builtin_clzll(x));
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  if (n == 1) {
    cout << "1\n";
    return;
  }
  l[1] = r[n] = getMSB(a[n]);
  for (int len = n - 1; len >= 1; --len) {
    for (int i = 1, j = i + len - 1; j <= n; i++, j++) {
      ll xor_sum = a[j] ^ a[i - 1];
      ll msk = (xor_sum & l[i]) | (xor_sum & r[j]);
      int f = 0;
      if (msk || l[i] == M || r[j] == M) {
        l[i] |= getMSB(xor_sum);
        r[j] |= getMSB(xor_sum);
        f = 1;
      }
      if (len == 1)
        cout << f;
    }
  }
  cout << "\n";
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