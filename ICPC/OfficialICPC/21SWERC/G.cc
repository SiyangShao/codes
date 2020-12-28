// Online Mirror G, Gym K
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1000010;
bitset<N> vis;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int fa;
    cin >> fa;
    fa--;
    E[fa].emplace_back(i);
    E[i].emplace_back(fa);
  }
  vector<int> siz(n);
  vector<ll> dp(n), cnt(n);
  vector<int> vec;
  function<ll()> cal = [&]() {
    auto mx = *max_element(vec.begin(), vec.end());
    if (mx >= n / 2) {
      return (n - 1 - mx + 1LL) * (mx + 1LL);
    }
    vis.reset();
    vis[0] = true;
    fill(cnt.begin(), cnt.end(), 0);
    for (auto &i : vec) {
      cnt[i]++;
    }
    for (int i = 0; i <= min(n - 1, mx); ++i) {
      while (cnt[i] >= 3) {
        cnt[i] -= 2;
        cnt[i * 2]++;
        mx = max(mx, i * 2);
      }
      for (int j = 0; j < cnt[i]; ++j) {
        vis = vis | (vis << i);
      }
    }
    for (int i = n / 2; i >= 0; --i) {
      if (vis[i]) {
        return (n - 1 - i + 1LL) * (i + 1LL);
      }
    }
    return 0LL;
  };
  ll ans = 0, sum = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      siz[u] += siz[v];
    }
    vec.clear();
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      vec.emplace_back(siz[v]);
    }
    if (siz[u] != n) {
      vec.emplace_back(n - siz[u]);
    }
    sum += siz[u];
    dp[u] = cal();
  };
  dfs(0, 0);
  // for (int i = 0; i < n; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << "\n";
  function<void(int, int)> reroot = [&](int u, int fa) {
    ans = max(ans, sum - n + dp[u]);
    const ll cur_sum = sum;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      // u: n -> n - siz[v]
      // v: siz[v] -> n
      sum = cur_sum - siz[v] + n - siz[v];
      reroot(v, u);
    }
  };
  reroot(0, 0);
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