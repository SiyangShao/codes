#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 10;
constexpr ll MOD = 998'244'353;
int n;
array<ll, N> a, b;
array<ll, N> frac, inv;
array<array<array<array<ll, 12>, 12>, 12>, 12> dp;
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
void init() {
  frac[0] = 1;
  for (int i = 1; i < N; i++) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  inv[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (int i = N - 1; i > 0; i--) {
    inv[i - 1] = inv[i] * i % MOD;
  }
  dp[0][0][0][0] = 1;
  for (int i = 0; i <= 11; i++) {
    for (int j = 0; j <= 11; j++) {
      if (i < j)
        continue;
      dp[i][j][i][j] = 1;
      for (int s = i; s < 11; s++) {
        for (int t = j; t < 11; t++) {
          if (s < t)
            continue;
          // i win or j win is ok
          dp[i][j][max(s, t + 1)][min(s, t + 1)] += dp[i][j][s][t];
        }
      }
    }
  }
}
ll C(ll x, ll y) {
  // choose y from x
  if (x < y) {
    return 0;
  }
  return frac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll gap(int l, int r) {
  // from l to r
  if (a[r] + b[r] != r) {
    return 0;
  }
  if (a[l] + b[l] != l) {
    return 0;
  }
  if (a[l] >= 11 && a[l] - b[l] >= 2) {
    return 0;
  }
  if (a[r] >= 11 && a[r] - b[r] > 2) {
    return 0;
  }
  if (a[l] > a[r] || b[l] > b[r]) {
    return 0;
  }
  if (a[r] < 11) {
    // any is ok
    // case 1: a[l] -> a[r], b[l] -> b[r]
    ll b_win = b[r] - b[l];
    return C(r - l, b_win);
  }
  if (a[l] >= 11) {
    // dif cannot larger than 1
    // assert: b[l] == a[l] - 1
    // so must be ...
    // and last must be win
    ll round = r - l;
    if (a[l] == b[l] + 1) {
      // must be loser win
      round--;
    }
    return qpow(2, (round + 1) / 2);
  }
  // a[l] < 11, a[r] >= 11
}
void solve() {
  cin >> n;
  int lst = 0;
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] < b[i])
      swap(a[i], b[i]);
    if (a[i] != -1) {
      ans = ans * gap(lst, i) % MOD;
      lst = i;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
