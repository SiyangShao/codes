#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
namespace internal {
template <class T> struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T &t) { payload.push_back(t); }
  T &front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};
} // namespace internal
template <class Cap> struct mf_graph {
public:
  mf_graph() : _n(0) {}
  explicit mf_graph(int n) : _n(n), g(n) {}
  int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to)
      to_id++;
    g[from].push_back(_edge{to, to_id, cap});
    g[to].push_back(_edge{from, from_id, 0});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result;
    for (int i = 0; i < m; i++) {
      result.push_back(get_edge(i));
    }
    return result;
  }
  void change_edge(int i, Cap new_cap, Cap new_flow) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    assert(0 <= new_flow && new_flow <= new_cap);
    auto &_e = g[pos[i].first][pos[i].second];
    auto &_re = g[_e.to][_e.rev];
    _e.cap = new_cap - new_flow;
    _re.cap = new_flow;
  }

  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    std::vector<int> level(_n), iter(_n);
    internal::simple_queue<int> que;

    auto bfs = [&]() {
      std::fill(level.begin(), level.end(), -1);
      level[s] = 0;
      que.clear();
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : g[v]) {
          if (e.cap == 0 || level[e.to] >= 0)
            continue;
          level[e.to] = level[v] + 1;
          if (e.to == t)
            return;
          que.push(e.to);
        }
      }
    };
    auto dfs = [&](auto self, int v, Cap up) {
      if (v == s)
        return up;
      Cap res = 0;
      int level_v = level[v];
      for (int &i = iter[v]; i < int(g[v].size()); i++) {
        _edge &e = g[v][i];
        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0)
          continue;
        Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
        if (d <= 0)
          continue;
        g[v][i].cap += d;
        g[e.to][e.rev].cap -= d;
        res += d;
        if (res == up)
          return res;
      }
      level[v] = _n;
      return res;
    };

    Cap flow = 0;
    while (flow < flow_limit) {
      bfs();
      if (level[t] == -1)
        break;
      std::fill(iter.begin(), iter.end(), 0);
      Cap f = dfs(dfs, t, flow_limit - flow);
      if (!f)
        break;
      flow += f;
    }
    return flow;
  }

  std::vector<bool> min_cut(int s) {
    std::vector<bool> visited(_n);
    internal::simple_queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      visited[p] = true;
      for (auto e : g[p]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }

private:
  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
  };
  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

auto solve() {
  int t, n;
  cin >> t >> n;
  vector<int> cnt(26, 0);
  vector<int> ans(n, -1);
  vector<vector<int>> cannot(26, vector<int>(n, 0));
  vector<int> enough(26, 0);
  for (int _ = 1; _ < t; ++_) {
    string s, response;
    cin >> s >> response;
    vector<int> curCount(26, 0);
    for (int i = 0; i < n; ++i) {
      int cur = s[i] - 'a';
      if (response[i] == 'G') {
        assert(ans[i] == -1 || ans[i] == cur);
        ans[i] = cur;
        curCount[cur]++;
      } else if (response[i] == 'Y') {
        curCount[cur]++;
        cannot[cur][i] = 1;
      } else {
        enough[cur] = 1;
        cannot[cur][i] = 1;
      }
    }
    for (int i = 0; i < 26; ++i) {
      cnt[i] = max(cnt[i], curCount[i]);
    }
  }
  mf_graph<ll> G(n + 26 + 3);
  int S = n + 26, T = n + 26 + 1, SS = n + 26 + 2;
  ll lowerbound = 0;
  for (int i = 0; i < 26; ++i) {
    lowerbound += cnt[i];
    G.add_edge(S, i + n, cnt[i]);
  }
  G.add_edge(S, SS, n - lowerbound);
  for (int i = 0; i < 26; ++i) {
    if (!enough[i])
      G.add_edge(SS, i + n, n);
  }

  for (int i = 0; i < n; ++i) {
    G.add_edge(i, T, 1);
    if (ans[i] != -1) {
      dbg(ans[i], i);
      G.add_edge(ans[i] + n, i, 1);
    } else {
      for (int c = 0; c < 26; ++c) {
        if (!cannot[c][i])
          G.add_edge(c + n, i, 1);
      }
    }
  }
  ll sum = G.flow(S, T);
  dbg(sum);
  assert(sum == n);
  for (auto [u, v, c, f] : G.edges()) {
    if (u == S || u == SS || v == T)
      continue;
    if (c == f) {
      // cout << "From " << u << " to " << v << " is " << c << " " << f << endl;
      ans[v] = u - n;
    }
  }
  dbg(ans);
  for (int i = 0; i < n; ++i) {
    cout << char(ans[i] + 'a');
  }
  cout << "\n";
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