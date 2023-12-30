#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll k, a, b;
  cin >> k >> a >> b;
  a--, b--;
  array<array<ll, 3>, 3> A, B;
  for (auto &i : A) {
    for (auto &j : i) {
      cin >> j;
      j--;
    }
  }
  for (auto &i : B) {
    for (auto &j : i) {
      cin >> j;
      j--;
    }
  }
  ll valA = 0, valB = 0;
  map<pair<ll, ll>, tuple<ll, ll, ll>> mp;
  bool do_loop = false;
  for (ll i = 1; i <= k; ++i) {
    if (a != b) {
      if (a == b + 1 || (a == 0 && b == 2)) {
        valA++;
      } else {
        valB++;
      }
    }
    if (!do_loop) {
      if (mp.contains({a, b})) {
        auto [preA, preB, t] = mp[{a, b}];
        ll loop = i - t;
        ll loop_cycle = (k - i) / loop;
        valA += loop_cycle * (valA - preA);
        valB += loop_cycle * (valB - preB);
        i += loop_cycle * loop;
        do_loop = true;
      } else {
        mp[{a, b}] = {valA, valB, i};
      }
    }
    ll nxtA = A[a][b], nxtB = B[a][b];
    a = nxtA, b = nxtB;
  }
  cout << valA << " " << valB << "\n";
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
