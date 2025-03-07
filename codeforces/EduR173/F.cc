#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll two_inv = 499122177;
constexpr int N = 51;
array<array<array<pair<ll, ll>, 2>, 64>, N + 1> dp;
void merge(pair<ll, ll> &a, pair<ll, ll> b) {
  if (a.first > b.first)
    return;
  if (a.first < b.first) {
    a = b;
    return;
  }
  a.second = (a.second + b.second) % MOD;
}
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  array<vector<int>, N> pos;
  for (int i = 0; i < n; i++) {
    pos[a[i]].emplace_back(i);
  }
  auto sol = [&](int l, int r) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < 64; j++) {
        for (int k = 0; k < 2; k++) {
          dp[i][j][k] = {-1, -1};
        }
      }
    }
    l--, r--;
    dp[0][0][0] = {0, 1};
    for (int i = 0; i < N; i++) {
      auto lef = lower_bound(pos[i].begin(), pos[i].end(), l);
      auto rig = upper_bound(pos[i].begin(), pos[i].end(), r);
      // >= lef, < rig
      ll c = (ll)(rig - lef);
      for (int x = 0; x < 64; x++) {
        for (int k = 0; k < 2; k++) {
          if (dp[i][x][k].first == -1)
            continue;
          // 1. remove all
          merge(dp[i + 1][x][k], {dp[i][x][k].first + c, dp[i][x][k].second});
          // 2. keep one
          if (c >= 1) {
            merge(dp[i + 1][x ^ i][1],
                  {dp[i][x][k].first + c - 1, dp[i][x][k].second * c % MOD});
          }
          // 3. keep 2
          if (c >= 2) {
            merge(dp[i + 1][x][1], {dp[i][x][k].first + c - 2,
                                    dp[i][x][k].second * c % MOD * (c - 1) %
                                        MOD * two_inv % MOD});
          }
        }
      }
    }
    return dp[N][0][1];
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    auto [x, y] = sol(l, r);
    if (x == -1) {
      cout << "-1\n";
    } else {
      cout << x << " " << y << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
