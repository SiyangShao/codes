#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  constexpr ll inf = 1e16;
  vector<vector<pair<int, ll>>> E((n - 1) * (m - 1) * 2 + 2);
  vector<ll> dis((n - 1) * (m - 1) * 2 + 2, inf),
      vis((n - 1) * (m - 1) * 2 + 2);
  int S = (n - 1) * (m - 1) * 2, T = (n - 1) * (m - 1) * 2 + 1;
  function<int(int, int)> upper = [&](int x, int y) { return x * (m - 1) + y; };
  function<int(int, int)> lower = [&](int x, int y) {
    return (n - 1) * (m - 1) + upper(x, y);
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      ll w;
      cin >> w;
      if (i == 0) {
        E[upper(i, j)].emplace_back(S, w);
        E[S].emplace_back(upper(i, j), w);
      } else if (i + 1 == n) {
        E[lower(i - 1, j)].emplace_back(T, w);
        E[T].emplace_back(lower(i - 1, j), w);
      } else {
        E[upper(i, j)].emplace_back(lower(i - 1, j), w);
        E[lower(i - 1, j)].emplace_back(upper(i, j), w);
      }
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      ll w;
      cin >> w;
      if (j == 0) {
        E[lower(i, j)].emplace_back(T, w);
        E[T].emplace_back(lower(i, j), w);
      } else if (j + 1 == m) {
        E[upper(i, j - 1)].emplace_back(S, w);
        E[S].emplace_back(upper(i, j - 1), w);
      } else {
        E[lower(i, j)].emplace_back(upper(i, j - 1), w);
        E[upper(i, j - 1)].emplace_back(lower(i, j), w);
      }
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      ll w;
      cin >> w;
      E[upper(i, j)].emplace_back(lower(i, j), w);
      E[lower(i, j)].emplace_back(upper(i, j), w);
    }
  }
  dis[S] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
  Q.emplace(dis[S], S);
  while (!Q.empty()) {
    auto [_, u] = Q.top();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, w] : E[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        Q.emplace(dis[v], v);
      }
    }
  }
  cout << dis[T] << "\n";
}