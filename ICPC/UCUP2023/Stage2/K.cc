#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
constexpr ll mid_inf = 1e9;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<ll>> c(n, vector<ll>(k));
  for (auto &i : c) {
    for (auto &j : i) {
      cin >> j;
    }
    i.emplace_back(mid_inf);
  }
  vector<int> a(k);
  for (auto &i : a) {
    cin >> i;
  }
  a.emplace_back(0);
  vector<vector<set<pair<ll, int>>>> transfer(
      k + 1, vector<set<pair<ll, int>>>(k + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      transfer[j][k].emplace(c[i][j] - c[i][k], i); // current at k; will go j
    }
  }
  ll ans = mid_inf * n; // suppose at first every point is directly to k
  for (int x = 0; x < n; ++x) {
    vector<ll> dis(k + 1, inf);
    queue<int> Q;
    vector<bool> inQ(k + 1);
    vector<int> pre(k + 1, -1);
    for (int i = 0; i < k; ++i) {
      if (a[i] > 0) {
        Q.emplace(i); // new entry can be i
        inQ[i] = true;
        dis[i] = 0;
      }
    }
    while (!Q.empty()) { // bellman ford
      int u = Q.front();
      Q.pop();
      inQ[u] = false;
      for (int v = 0; v <= k; ++v) {
        if (!transfer[u][v].empty()) {
          ll d = dis[u] + transfer[u][v].begin()->first;
          if (d < dis[v]) {
            dis[v] = d;
            pre[v] = u;
            if (!inQ[v]) {
              Q.emplace(v);
              inQ[v] = true;
            }
          }
        }
      }
    }
    ans += dis[k];
    // cout << dis[k] + mid_inf << "\n";
    for (int v = k; pre[v] != -1; v = pre[v]) {
      int u = pre[v];
      // transfer from v to u
      // delete all v's s, and add them to u
      int s = transfer[u][v].begin()->second;
      for (int i = 0; i <= k; ++i) {
        if (v != i) {
          transfer[i][v].erase({c[s][i] - c[s][v], s});
        }
      }
      for (int i = 0; i <= k; ++i) {
        if (u != i) {
          transfer[i][u].emplace(c[s][i] - c[s][u], s);
        }
      }
      a[u]--, a[v]++;
    }
    // for (int i = 0; i <= k; ++i) {
    //   cout << a[i] << " ";
    // }
    // cout << "\n";
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
