#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 500000;
array<ll, N + 5> cnt;
auto solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
    cnt[i]++;
  }
  ll y = 0;
  for (ll i = 1; i <= N; ++i) {
    if (cnt[i] != 0) {
      y = i;
    }
    if (cnt[i] % (i + 1) == 0) {
      cnt[i + 1] += cnt[i] / (i + 1);
    } else {
      break;
    }
  }
  if (y >= x) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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