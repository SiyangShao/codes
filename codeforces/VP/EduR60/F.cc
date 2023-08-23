#include <bits/stdc++.h>
using namespace std;
constexpr int P = 17;
constexpr int N = 1 << P;
bitset<N> dp, state, cur;
auto solve() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  vector<int> cnt(p);
  vector<vector<int>> pos(p);
  vector pre(p, vector<int>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'a']++;
    pos[s[i] - 'a'].emplace_back(i);
    for (int j = 0; j < p; ++j) {
      pre[j][i + 1] = pre[j][i] + (s[i] == 'a' + j ? 1 : 0);
    }
  }
  vector neighbour(p, vector<int>(p, 0));
  for (auto &i : neighbour) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  state.reset(), state.flip();
  const int bitmask = (1 << p) - 1;
  for (int x = 0; x < p; ++x) {
    for (int y = x; y < p; ++y) {
      // enumerate the two neighbour remain in the final string
      if (neighbour[x][y])
        continue;
      cur.reset(), cur.flip();
      int i = 0, j = 0;
      while (i < (int)pos[x].size() && j < (int)pos[y].size()) {
        if (pos[x][i] == pos[y][j]) {
          j++;
          continue;
        }
        int msk = 0;
        int l = min(pos[x][i], pos[y][j]) + 1;
        int r = max(pos[x][i], pos[y][j]);
        // all other elements appeared are deleted
        for (int z = 0; z < p; ++z) {
          if (pre[z][r] - pre[z][l] > 0) {
            msk |= (1 << z);
          }
        }
        if (pos[x][i] < pos[y][j]) {
          i++;
        } else {
          j++;
        }
        // there should be no else x or y between them
        if (((msk >> x) & 1) || ((msk >> y) & 1))
          continue;
        cur[msk ^ bitmask] = false;
      }
      for (int msk = bitmask; msk >= 0; --msk) {
        if (cur[msk])
          continue;
        for (int e = 0; e < p; ++e) {
          if (e != x && e != y && ((msk >> e) & 1)) {
            // other elements without relation can ignore
            cur[msk ^ (1 << e)] = false;
          }
        }
      }
      state &= cur;
    }
  }
  int ans = n;
  dp.reset();
  dp[bitmask] = true;
  for (int i = bitmask; i >= 0; --i) {
    // cout << i << " " << state[i] << "\n";
    if (dp[i]) {
      int tmp = 0;
      for (int j = 0; j < p; ++j) {
        if ((i >> j) & 1) {
          tmp += cnt[j];
          if (state[i ^ (1 << j)]) {
            dp[i ^ (1 << j)] = true;
          }
        }
      }
      ans = min(ans, tmp);
    }
  }
  cout << ans << "\n";
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