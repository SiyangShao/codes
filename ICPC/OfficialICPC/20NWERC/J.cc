#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll c, t;
  cin >> c >> t;
  vector<vector<ll>> E(c);
  for (ll i = 0; i < t; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<bool> vis(c), in_stack(c);
  ll type1 = 0, type2 = c;
  bool find = false;
  stack<ll> st;
  function<void(ll)> dfs = [&](ll u) {
    in_stack[u] = true;
    vis[u] = true;
    st.emplace(u);
    type2--;
    if (type1 == type2)
      find = true;
    if (find)
      return;
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      dfs(v);
      if (find)
        return;
    }
    in_stack[u] = false;
    type1++;
    st.pop();
    if (type1 == type2)
      find = true;
  };
  dfs(0);
  assert(find && type1 == type2);
  // type1 and type2 kind of nodes will never meet.
  // Why?
  // think of a dfs tree
  // as it is un-directed graph, it's dfs tree won't have cross edge
  // a point is connected only through tree edge & back edge
  // Thus, for a point, it's connected point must be its ancestor. they can't be
  // seperated to 2 different kind of points.
  cout << (c - type1 - type2) << " " << type1 << "\n";
  vector<ll> dig;
  while (!st.empty()) {
    dig.emplace_back(st.top());
    st.pop();
  }
  assert(dig.size() == c - type1 - type2);
  reverse(dig.begin(), dig.end());
  for (auto &i : dig) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  for (ll i = 0; i < c; ++i) {
    if (!vis[i])
      cout << i + 1 << " ";
  }
  cout << "\n";
  for (ll i = 0; i < c; ++i) {
    if (vis[i] && !in_stack[i])
      cout << i + 1 << " ";
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