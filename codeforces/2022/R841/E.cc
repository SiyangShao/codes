#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e6 + 7;
vector<ll> pri;
array<ll, N> phi;
bitset<N> vis;
auto init() {
  vis[1] = true;
  phi[1] = 1;
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
      phi[i] = i - 1;
    }
    for (auto j : pri) {
      if (i * j >= N)
        break;
      vis[i * j] = true;
      if (i % j) {
        phi[i * j] = phi[i] * phi[j];
      } else {
        phi[i * j] = phi[i] * j;
        break;
      }
    }
  }
}
auto solve() {
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  for (ll k = n - 1; k >= 1; --k) {
    ll t = phi[n / (k + 1)] / k;
    t = min(t, m / k);
    m -= t * k;
    ans += t * (k + 1);
  }
  if (m) {
    cout << "-1\n";
    return;
  } else {
    cout << ans << "\n";
    return;
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  phi[1]--;
  for (int i = 1; i < N; ++i) {
    phi[i] += phi[i - 1];
  }
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
