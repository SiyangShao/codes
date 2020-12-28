#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a;
vector<ll> cost;
vector<vector<ll>> dp;
struct DSU {
  int n;
  vector<int> p, size;
  DSU(int _n) : n(_n), p(_n), size(_n,1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  void merge(int x, int y, ll c) {
    x = find(x), y = find(y);
    if (x != y) {
      p[x] = y;
      vector<ll> next(size[x] + size[y] + 1, -1e18);
      for (int i = 0; i <= size[y]; ++i) {
        for (int j = 0; j <= size[x]; ++j) {
          next[i + j] =
              max(next[i + j], dp[y][i] + dp[x][j] + c * (size[y] - i) * j +
                                   c * i * (size[x] - j));
        }
      }
      dp[y] = next;
      // cout << x + 1 << " " << y + 1 << "\n";
      // for (auto i : dp[y]) {
      //   cout << i << " ";
      // }
      // cout << "\n";
      size[y] += size[x];
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  a = vector<int>(n);
  cost = vector<ll>(n);
  dp = vector<vector<ll>>(n, vector<ll>(2, 0));
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : cost) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      dp[i][0] = -cost[i];
      dp[i][1] = 0;
    } else {
      dp[i][0] = 0;
      dp[i][1] = -cost[i];
    }
  }
  vector<tuple<ll, int, int>> vec(n - 1);
  for (auto &[w, u, v] : vec) {
    cin >> u >> v >> w;
    u--, v--;
  }
  sort(vec.begin(), vec.end());
  DSU dsu(n);
  for (auto &[w, u, v] : vec) {
    dsu.merge(u, v, w);
  }
  ll ans = 0;
  ll x = dsu.find(0);
  ans = *max_element(dp[x].begin(), dp[x].end());
  cout << ans << "\n";
}