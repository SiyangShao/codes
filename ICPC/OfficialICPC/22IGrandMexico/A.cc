#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 50;
array<ll, N + 1> bs;
ll sum = 0;
void insert(ll x) {
  for (ll i = N; i >= 0; --i) {
    if (sum & (1LL << i))
      continue;
    if (!(x & (1LL << i)))
      continue;
    if (!bs[i]) {
      bs[i] = x;
      break;
    }
    x ^= bs[i];
  }
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
    sum ^= i;
  }
  for (auto &i : a) {
    insert(i);
  }
  ll take = 0;
  for (ll i = N; i >= 0; --i) {
    if (sum & (1LL << i)) {
      // odd one, we don't care
      continue;
    }
    // even one
    if (take & (1LL << i)) {
      // have one. continue
      continue;
    } else {
      // doesn't have 1 in our choosen. choose 1.
      take ^= bs[i];
    }
  }
  cout << take + (sum ^ take) << "\n";
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
