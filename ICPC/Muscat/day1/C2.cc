#include <bits/stdc++.h>
using namespace std;
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
    inf = 1e16;
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
  void solve() {
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
    fill(vis_y.begin(), vis_y.end(), false);
    for (int i = 0; i < n; ++i) {
      if (g[i][match_x[i]] > 0) {
        // have edge, if negative change >0 to >-inf
        res += g[i][match_x[i]];
        vis_y[match_x[i]] = true;
      } else {
        // // no match
        // while (vis_y[cur])
        //   cur++;
        match_x[i] = -1;
      }
    }
    int cur = 0;
    for(int i = 0; i < n; ++i){
      if(match_x[i] == -1){
        while(cur < n && vis_y[cur]) cur++;
        match_x[i] = cur++;
      }
    }
    // cout << res << "\n";
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  vector<int> cnt(k, -1), org;
  int cur = 0;
  for (auto &i : a)
    cin >> i, i--;
  for (auto i : a) {
    if (cnt[i] == -1) {
      cnt[i] = cur++;
      org.emplace_back(i);
    }
  }
  for (int i = 0; i < k; ++i) {
    if (cnt[i] == -1) {
      org.emplace_back(i);
    }
  }
  for (auto &i : b)
    cin >> i, i--;
  vector num(k, vector<int>(k, 0));
  for (int i = 0; i < n; ++i) {
    num[a[i]][b[i]]++;
  }
  Hungarain<long long> G(k, k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      G.addEdge(i, j, num[org[i]][j]);
      // cout << org[i] << " " << j << " " << num[org[i]][j] << "\n";
    }
  }
  G.solve();
  auto &mp = G.match_x;
  for (auto i : a) {
    cout << mp[cnt[i]] + 1 << " ";
  }
  cout << "\n";
}