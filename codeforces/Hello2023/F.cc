#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int x_sum = 0;
  for (auto &i : a) {
    cin >> i;
    x_sum ^= i;
  }
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    E[p].emplace_back(i);
    // E[i].emplace_back(p);
  }
  if (x_sum == 0) {
    cout << "1\n1\n";
    return;
  } else if (n % 2 == 0) {
    cout << "2\n1 1\n";
    return;
  }
  // observation: Only even tree would change the XOR sum of the subtree
  vector<int> siz(n);
  function<void(int)> dfs = [&](int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      dfs(v);
      a[u] ^= a[v];
      siz[u] += siz[v];
    }
  };
  dfs(0);
  constexpr int N = 32;
  vector<bitset<N>> dp(n);
  function<void(int)> sol = [&](int u) {
    dp[u][0] = true;
    for (auto v : E[u]) {
      sol(v);
    }
    for (auto v : E[u]) {
      bitset<N> new_dp(0);
      for (int x = 0; x < N; ++x) {
        if (dp[u][x]) {
          for (int y = 0; y < N; ++y) {
            if (dp[v][y]) {
              new_dp[x ^ y] = true;
            }
          }
        }
      }
      dp[u] = new_dp;
    }
    if (siz[u] % 2 == 0) {
      dp[u][a[u]] = true;
    }
  };
  sol(0);
  if (!dp[0][a[0]]) {
    cout << "-1\n";
    return;
  }
  vector<int> ans;
  function<void(int, int)> res = [&](int u, int val) {
    if (val == 0)
      return;
    if (siz[u] % 2 == 0 && val == a[u]) {
      ans.emplace_back(u);
      return;
    }
    int sz = (int)E[u].size();
    vector<vector<int>> pr(sz + 1, vector<int>(N, -1));
    pr[0][0] = 0;
    for (int it = 0; it < sz; ++it) {
      int v = E[u][it];
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          if (pr[it][j] != -1 && dp[v][k]) {
            pr[it + 1][j ^ k] = k;
          }
        }
      }
    }
    assert(pr[sz][val] != -1);
    vector<int> use(sz);
    int cur = val;
    for (int it = sz; it > 0; --it) {
      use[it - 1] = pr[it][cur];
      cur ^= pr[it][cur];
    }
    for (int it = 0; it < sz; ++it) {
      res(E[u][it], use[it]);
    }
  };
  res(0, a[0]);
  ans.emplace_back(0);
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
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
