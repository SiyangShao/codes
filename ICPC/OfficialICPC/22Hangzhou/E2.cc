#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;
array dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
template <class Cap> struct Hungarain {
  // O(n^3), only wokrs on *bipartite graph maximum perfect matching*
  // ok if negative
  int n;
  vector<int> match_x, match_y, pre;
  vector<bool> vis_x, vis_y;
  vector<vector<Cap>> g;
  vector<Cap> slack;
  vector<Cap> lx, ly;
  Cap inf, res;
  queue<int> q;
  int org_n, org_m;
  Hungarain(int _n, int _m) {
    org_n = _n, org_m = _m;
    n = max(_n, _m);
    inf = numeric_limits<Cap>::max();
    res = 0;
    // if negative, change here to -inf
    g = vector<vector<Cap>>(n, vector<Cap>(n));
    match_x = match_y = vector<int>(n, -1);
    pre = vector<int>(n);
    vis_x = vis_y = vector<bool>(n);
    lx = vector<Cap>(n, -inf);
    ly = vector<Cap>(n);
    slack = vector<Cap>(n);
  };
  void addEdge(int u, int v, Cap w) { g[u][v] = w; }
  bool check(int v) {
    vis_y[v] = true;
    if (match_y[v] != -1) {
      q.push(match_y[v]);
      vis_x[match_y[v]] = true;
      return false;
    }
    while (v != -1) {
      match_y[v] = pre[v];
      swap(v, match_x[pre[v]]);
    }
    return true;
  }
  void bfs(int i) {
    while (!q.empty()) {
      q.pop();
    }
    q.push(i);
    vis_x[i] = true;
    while (true) {
      while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
          if (!vis_y[v]) {
            auto delta = lx[u] + ly[v] - g[u][v];
            if (slack[v] >= delta) {
              pre[v] = u;
              if (delta) {
                slack[v] = delta;
              } else if (check(v)) {
                return;
              }
            }
          }
        }
      }
      auto a = inf;
      for (int j = 0; j < n; ++j) {
        if (!vis_y[j]) {
          a = min(a, slack[j]);
        }
      }
      for (int j = 0; j < n; ++j) {
        if (vis_x[j]) {
          lx[j] -= a;
        }
        if (vis_y[j]) {
          ly[j] += a;
        } else {
          slack[j] -= a;
        }
      }
      for (int j = 0; j < n; ++j) {
        if (!vis_y[j] && slack[j] == 0 && check(j)) {
          return;
        }
      }
    }
  }
  auto solve() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        lx[i] = max(lx[i], g[i][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      fill(slack.begin(), slack.end(), inf);
      fill(vis_x.begin(), vis_x.end(), false);
      fill(vis_y.begin(), vis_y.end(), false);
      bfs(i);
    }
    // output
    for (int i = 0; i < n; ++i) {
      if (g[i][match_x[i]] > 0) {
        // have edge, if negative change >0 to >-inf
        res += g[i][match_x[i]];
      } else {
        // no match
        match_x[i] = -1;
      }
    }
    return res;
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mp(n * 2 - 1);
  for (auto &i : mp)
    cin >> i;
  vector<vector<int>> val(n, vector<int>(m));
  Hungarain<int> G(n * m, n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      val[i][j] = mp[i * 2][j * 2] - '0';
      if (val[i][j] > 6) {
        val[i][j]++;
      }
      val[i][j] %= 2;
    }
  }
  auto cal = [&](int i, int j) { return i * m + j; };
  auto is_edge = [&](int i, int j) {
    return i == 0 || j == 0 || i == n - 1 || j == m - 1;
  };
  auto is_valid = [&](int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
  };
  int match = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (val[i][j] == 0)
        match++;
      for (int k = 0; k < 4; ++k) {
        int u = i + dx[k], v = j + dy[k];
        if (!is_valid(u, v))
          continue;
        if (is_edge(i, j) != is_edge(u, v))
          continue;
        if (is_edge(i, j)) {
          if (!((i == 0 && u == 0) || (i == n - 1 && u == n - 1) ||
                (j == 0 && v == 0) || (j == m - 1 && v == m - 1))) {
            continue;
          }
        }
        if (val[i][j] == 1 || val[u][v] == 1)
          continue;
        if (i % 2 == j % 2) {
          G.addEdge(cal(i, j), cal(u, v), 1);
          // cout << i << " " << j << " " << u << " " << v << "\n";
        } else {
          assert(u % 2 == v % 2);
          G.addEdge(cal(u, v), cal(i, j), 1);
          // cout << u << " " << v << " " << i << " " << j << "\n";
        }
      }
    }
  }
  int res = G.solve();
  if (res * 2 != match) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  auto between = [&](int x1, int y1, int x2, int y2) {
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    assert((x1 == x2 && abs(y1 - y2) == 2) || (y1 == y2 && abs(x1 - x2) == 2));
    if (x1 == x2) {
      return pair<int, int>{x1, (y1 + y2) / 2};
    } else {
      return pair<int, int>{(x1 + x2) / 2, y1};
    }
  };
  auto get_pos = [&](int y) { return pair<int, int>{y / m, y % m}; };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i % 2 != j % 2) || val[i][j] != 0)
        continue;
      int y = G.match_x[cal(i, j)];
      auto [u, v] = get_pos(y);
      // cout << y << ", ";
      // cout << i << " " << j << " " << u << " " << v << "\n";
      auto [a, b] = between(i * 2, j * 2, u * 2, v * 2);
      mp[a][b] = 'x';
    }
  }
  for (int i = 0; i < n * 2 - 1; ++i) {
    for (int j = 0; j < m * 2 - 1; ++j) {
      if (mp[i][j] == '.') {
        mp[i][j] = '#';
      } else if (mp[i][j] == 'x') {
        mp[i][j] = '.';
      }
    }
    cout << mp[i] << "\n";
  }
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