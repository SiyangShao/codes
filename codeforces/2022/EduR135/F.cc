#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b;
  // ASSUME: for each x, it can be range from x to n*x. And our
  // goal is to select distinct n values. If we can select n distinct values, it
  // must be suitable for the answer. (Also easy to prove) As there are totally
  // n numbers, for each, the maximum number which can be choose is n*x.
  for (auto &i : a) {
    cin >> i;
    for (ll j = 1; j <= n; ++j) {
      b.emplace_back(j * i);
    }
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  ll m = b.size();
  vector<ll> vis(n), link(n, -1);
  vector<vector<ll>> E(m);
  function<bool(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        return true;
      }
    }
    return false;
  };
  for (ll i = 0; i < n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      ll nxt = a[i] * j;
      ll pos = lower_bound(b.begin(), b.end(), nxt) - b.begin();
      assert(b[pos] == nxt);
      E[pos].emplace_back(i);
    }
  }
  // roughly thinking: biparte graph maximum matching (and we assume it can have
  // perfect matching) with smallest weight

  // Hungrain? can't. Hungrain is max(n,m)^3, and here our m is n^2.

  // Network flow? still too slow. O(nmf), which is n^4. (here m is n^2, f is n)

  // Just try simple maximum matching! But why it works? Because here, the
  // weight of edge is same as the weight of right point! As we sort the right
  // point and do simple maximum matching from the smallest vertice to the
  // largest, the answer is easy to prove to be the minimum.
  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    if (dfs(i)) {
      ans += b[i];
      fill(vis.begin(), vis.end(), 0);
      // if you haven't found an augmenting path, don't reset the values
      // representing which vertices were visited by the algorithm

      // O(M(E+V))

      // M is the size of maximum matching, E is number of edges, V is number of
      // verticles

      // When we find the argument path, each time we will add 1 and traverse
      // the graph, which is E + V
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