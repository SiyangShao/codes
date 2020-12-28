#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll N = 1e7 + 7;
vector<ll> prime, myprime;
bitset<N> vis;
void init() {
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      prime.emplace_back(i);
      if (i >= (ll)5e5)
        myprime.emplace_back(i);
    }
    for (auto j : prime) {
      if (i * j >= N)
        break;
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
}
ll prime1, prime2;
struct TreeHashing {
  ll MOD;
  set<int> solve(int n, auto &&E, auto &a) {
    random_device rd;
    mt19937 g(rd());
    std::uniform_int_distribution<mt19937::result_type> dist(n + 1, MOD);
    ll base = (ll)dist(g);
    // ll base = 2;
    vector<ll> qpow(n + 1);
    qpow[0] = 1;
    for (int i = 1; i <= n; ++i) {
      qpow[i] = qpow[i - 1] * base % MOD;
    }
    ll H = 0;
    for (auto i : a) {
      H = (H + qpow[i]) % MOD;
    }
    set<ll> st;
    for (int i = 0; i <= n - 1; ++i) {
      st.emplace((H + qpow[i]) % MOD);
    }
    vector<ll> dp(n, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {
      dp[u] = qpow[0];
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        dp[u] = (dp[u] + dp[v] * base % MOD) % MOD;
      }
    };
    dfs(0, 0);
    set<int> ans;
    function<void(int, int)> change_root = [&](int u, int fa) {
      // dbg(u + 1, dp[u]);
      // dbg(dp);
      if (st.contains(dp[u])) {
        ans.emplace(u);
      }
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        const ll x = dp[u], y = dp[v];
        dp[u] = (((x - y * base % MOD) % MOD + MOD) % MOD * base) % MOD;
        dp[v] = (y + dp[u]) % MOD;
        change_root(v, u);
        dp[u] = x, dp[v] = y;
      }
    };
    change_root(0, 0);
    return ans;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n - 1ul);
  for (auto &i : a)
    cin >> i;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  TreeHashing x, y, p, q;
  x.MOD = prime1, y.MOD = prime2;
  p.MOD = 1e9 + 7, q.MOD = 1e9 + 9;
  auto l = x.solve(n, E, a);
  auto r = y.solve(n, E, a);
  auto P = p.solve(n, E, a);
  auto Q = q.solve(n, E, a);
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (l.contains(i) && r.contains(i) && P.contains(i) && Q.contains(i)) {
      ans.emplace_back(i);
    }
  }
  cout << ans.size() << "\n";
  if (!ans.empty()) {
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  random_device rd;
  mt19937 g(rd());
  init();
  std::uniform_int_distribution<mt19937::result_type> dist(0,
                                                           myprime.size() - 1);
  prime1 = myprime[dist(g)];
  prime2 = myprime[dist(g)];
  if (prime2 == prime1) {
    prime2 = myprime[dist(g)];
  }
  // cin >> _;
  while (_--) {
    solve();
  }
}