#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  // Jump from i to i+1 and i+2
  // Want to from 1 to n
  // If we connecet edge between adj nodes, we should find a minimum-weight
  // vertex cover As there shouldn't be a node that there doesn't exist choosen
  // vertex on it's left and it's right Not Bipartite Graph
  int n, m;
  cin >> n >> m;
  vector<int> c(n), x(m);
  for (auto &i : c) {
    cin >> i;
    i--;
  }
  for (auto &i : x) {
    cin >> i;
  }
  function<ll(int)> pos = [&](int u) { return 1LL << u; };
  vector<ll> mp(m);
  for (int i = 0; i + 1 < n; ++i) {
    mp[c[i]] |= pos(c[i + 1]);
    mp[c[i + 1]] |= pos(c[i]);
  }
  mp[c[0]] |= pos(c[0]);
  mp[c[n - 1]] |= pos(c[n - 1]);
  // bruteforce the first
  int first_half = m / 2, second_half = m - first_half;
  // cout << first_half << " " << second_half << "\n";
  vector<ll> dp(pos(first_half), inf);
  for (ll msk = 0; msk < pos(second_half); ++msk) {
    ll chk = 0, tot = 0;
    for (int i = 0; i < second_half; ++i) {
      if ((msk >> i) & 1) {
        tot += x[first_half + i];
      } else {
        chk |= mp[first_half + i];
      }
    }
    if (((chk >> first_half) | msk) != msk)
      continue;
    chk &= pos(first_half) - 1; // chk is all nodes should have in first half
    dp[chk] = min(dp[chk], tot);
  }
  // for (ll msk = 0; msk < pos(first_half); ++msk) {
  //   cout << msk << " " << dp[msk] << "\n";
  // }
  for (int i = 0; i < first_half; ++i) {
    for (ll msk = 0; msk < pos(first_half); ++msk) {
      if (!((msk >> i) & 1)) {
        dp[msk | pos(i)] = min(dp[msk | pos(i)], dp[msk]);
        // msk is nodes should have. Of course more points is also can.
      }
    }
  }
  // for (ll msk = 0; msk < pos(first_half); ++msk) {
  //   cout << msk << " " << dp[msk] << "\n";
  // }
  ll ans = inf;
  for (ll msk = 0; msk < pos(first_half); ++msk) {
    ll chk = 0, tot = 0;
    for (int i = 0; i < first_half; ++i) {
      if ((msk >> i) & 1) {
        tot += x[i];
      } else {
        chk |= mp[i];
      }
    }
    chk &= pos(first_half) - 1;
    if ((chk | msk) != msk)
      continue;
    ans = min(ans, dp[msk] + tot);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
