#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class Cap> struct dinic {
  struct edge {
    int from, to;
    Cap w;
    edge(int _f, int _t, Cap _w) : from(_f), to(_t), w(_w){};
  };
  vector<vector<int>> E;
  vector<edge> edg;
  vector<int> d;
  int n;
  dinic(int _n) : n(_n), E(_n), d(_n) {}
  auto addEdge(int u, int v, Cap w) {
    int id = edg.size();
    edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
    E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
    return id;
  }
  auto dfs(int u, int t, Cap flow) {
    if (u == t)
      return flow;
    Cap sum = 0;
    for (auto id : E[u]) {
      if (edg[id].w != 0 && d[edg[id].to] == d[u] + 1) {
        auto tmp = dfs(edg[id].to, t, min(flow, edg[id].w));
        edg[id].w -= tmp, edg[id ^ 1].w += tmp, sum += tmp, flow -= tmp;
        if (sum == flow)
          return sum;
      }
    }
    if (sum == 0)
      d[u] = 0;
    return sum;
  }
  bool level(int s, int t) {
    fill(d.begin(), d.end(), 0);
    queue<int> Q;
    Q.emplace(s);
    d[s] = 1;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (u == t)
        return true;
      for (auto id : E[u]) {
        auto v = edg[id].to;
        if (d[v] == 0 && edg[id].w != 0)
          Q.emplace(v), d[v] = d[u] + 1;
      }
    }
    return false;
  }
  auto solve(int s, int t) {
    Cap ans = 0;
    while (level(s, t))
      ans += dfs(s, t, numeric_limits<Cap>::max());
    return ans;
  }
};
auto solve() {
  ll n;
  cin >> n;
  vector<ll> __d1(n), __d2(n);
  map<ll, ll> mp, link;
  for (auto &i : __d1) {
    cin >> i;
    mp[i]++;
  }
  ll cnt = 0;
  for (auto &[l, r] : mp) {
    link[l] = cnt++;
  }
  for (auto &i : __d2) {
    cin >> i;
  }
  function<bool(ll)> cal = [&](ll l) {
    // l is the distance between p1 and p2
    ll p1 = 0, p2 = l;
    // distance between d2[i] to p1 is d2[i] - l or d2[i] + l
    dinic<ll> G(cnt + 1 + n + 1);
    ll S = cnt + n, T = cnt + n + 1;
    for (auto &[l, r] : mp) {
      G.addEdge(S, link[l], r);
    }
    vector<pair<ll, ll>> edg_id(n, {-1, -1});
    for (ll i = 0; i < n; ++i) {
      bool flag = false;
      if (mp[abs(__d2[i] - l)] != 0) {
        flag = true;
        edg_id[i].first = G.addEdge(link[abs(__d2[i] - l)], cnt + i, 1);
      }
      if (mp[__d2[i] + l] != 0) {
        flag = true;
        edg_id[i].second = G.addEdge(link[abs(__d2[i] + l)], cnt + i, 1);
      }
      if (!flag) {
        return false;
      }
      G.addEdge(i + cnt, T, 1);
    }
    ll ans = G.solve(S, T);
    if (ans != n) {
      return false;
    }
    cout << "YES\n";
    vector<ll> output(n);
    for (ll i = 0; i < n; ++i) {
      auto [l, r] = edg_id[i];
      if (l != -1 && G.edg[l].w == 0) {
        output[i] = p2 - __d2[i];
      }
      if (r != -1 && G.edg[r].w == 0) {
        output[i] = p2 + __d2[i];
      }
    }
    ll mx = *min_element(output.begin(), output.end());
    if (mx < 0) {
      mx = abs(mx);
      p1 += mx, p2 += mx;
      for (auto &i : output) {
        i += mx;
      }
    }
    for (auto &i : output) {
      cout << i << " ";
    }
    cout << "\n";
    cout << p1 << " " << p2 << "\n";
    return true;
  };
  for (ll i = 0; i < n; ++i) {
    if (cal(__d1[0] + __d2[i])) {
      return;
    }
    if (cal(abs(__d1[0] - __d2[i]))) {
      return;
    }
  }
  cout << "NO\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}