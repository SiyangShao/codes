#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  constexpr ll inf = 1e16;
  vector<ll> dp(n, inf);
  dp[0] = 0;
  // Trivial dp
  // for (int i = 1; i < n; ++i) {
  //   ll mi = a[i];
  //   for (int j = i - 1; j >= 0; --j) {
  //     mi = min(mi, a[j]);
  //     dp[i] = min(dp[i], dp[j] + mi * (i - j) * (i - j));
  //   }
  // }
  for (int i = 0; i < n; ++i) {
    // min(a_i ... a_j) * (i-j)^2
    // Obsevation 1:
    // if a_k = min(a_i ... a_j), a_i to a_k, a_k to a_j is better.
    // Jump from i to j iff a[i] == min(a[i] ... a[j]) or a[j] == min(a[i] ...
    // a[j]).
    // Observation 2:
    // If we jump i to i+1, to i+2, ... to j, the cost is no larger than n *
    // (i-j). Only need to consider min(a_i ... a_j) * (i-j) ^2 < n * (i-j). Or,
    // if we jump from i to j, distance of i-j is no larger than n / min(a_i ...
    // a_j), which is n/a_i (from i to k) or n/a_j (from k to j)
    ll dis = n / a[i] + 1;
    for (ll j = i - 1; j >= 0 && i - j <= dis; --j) {
      dp[i] = min(dp[i], dp[j] + a[i] * (i - j) * (i - j));
      if (a[j] <= a[i])
        break;
    }
    for (ll j = i + 1; j < n && j - i <= dis; ++j) {
      dp[j] = min(dp[j], dp[i] + a[i] * (j - i) * (j - i));
      if (a[j] <= a[i])
        break;
    }
  }
  for (auto i : dp) {
    cout << i << " ";
  }
  cout << "\n";
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
