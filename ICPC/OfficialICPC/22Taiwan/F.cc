#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2 - 1);
  vector<vector<int>> E(n);
  vector<int> vis(n, 0), fa(n, -1);
  for (auto &i : a) {
    cin >> i;
    i--;
    if (i >= 0)
      vis[i] = 1;
  }
  a[0] = a[n * 2 - 2] = 0;
  vis[0] = 1;

  bool flag = false;
  for (int i = 0; i < n * 2 - 2; ++i) {
    if (a[i] < 0) {
      flag = true;
      break;
    }
  }
  if (!flag) {
    for (auto i : a) {
      cout << i + 1 << " ";
    }
    cout << "\n";
    return;
  }
  flag = false;
  for (int i = 0; i + 1 < n * 2 - 1; ++i) {
    if (a[i] >= 0 && a[i + 1] >= 0) {
      E[a[i]].emplace_back(a[i + 1]);
      E[a[i + 1]].emplace_back(a[i]);
    }
  }
  function<void(int, int)> init = [&](int u, int pa) {
    fa[u] = pa;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      init(v, u);
    }
  };
  init(0, 0);
  set<int> st;
  flag = false;
  int beg = -1, end = -1;
  int len = 0;
  vector<int> cannot_up(n, 0);
  for (int i = 0; i < n * 2 - 1; ++i) {
    if (a[i] != -1) {
      if (flag) {
        if (end == -1)
          end = a[i];
        if (st.find(a[i]) != st.end()) {
          cannot_up[a[i]] = 1;
        }
      } else {
        beg = a[i];
        st.emplace(a[i]);
      }
    } else {
      flag = true;
      len++;
    }
  }
  priority_queue<int, vector<int>, greater<>> Q;
  for (int i = 0; i < n; ++i) {
    if (!vis[i])
      Q.emplace(i);
  }
  function<void(int, int)> build = [&](int u, int pa) {
    if (Q.empty())
      return;
    auto x = Q.top();
    if (cannot_up[u] || x < pa) {
      E[u].emplace_back(x);
      E[x].emplace_back(u);
      fa[x] = u;
      Q.pop();
      build(x, u);
      // build(u, pa);
    } else {
      if (u != pa)
        build(pa, fa[pa]);
    }
  };
  build(beg, fa[beg]);
  for (int i = 0; i < n; ++i) {
    sort(E[i].begin(), E[i].end());
    E[i].erase(unique(E[i].begin(), E[i].end()), E[i].end());
    // cout << i + 1 << ": "; for (auto v : E[i]) { cout << v + 1 << " "; }
    // cout<<"\n";
  }
  // cout<<"\n";
  vector<int> zero;
  vector<int> cur(n, 0), nxt(n, -1);
  // for(int i = 0 ; i < n ;++i){
  //   if(cannot_up[i]){
  //     cout<<i+1<<" ";
  //   }
  // }
  // cout<<"\n";
  while (end != 0) {
    vis[end] = 2;
    end = fa[end];
  }
  function<void(int)> output = [&](int u) {
    vis[u] = 1;
    // cout<<u<<"\n";
    zero.emplace_back(u);
    for (; cur[u] < (int)E[u].size(); ++cur[u]) {
      auto v = E[u][cur[u]];
      if (v == fa[u])
        continue;
      if (vis[v] == 1)
        continue;
      if (vis[v] == 2) {
        nxt[u] = v;
        continue;
      }
      output(v);
      return;
    }
    if (nxt[u] != -1) {
      auto v = nxt[u];
      nxt[u] = -1;
      output(v);
      return;
    }
    if (fa[u] != u)
      output(fa[u]);
  };
  output(beg);
  // for(auto i :zero){
  //   cout<<i+1<<" ";
  // }
  // cout<<"\n";
  flag = false;
  for (int i = 0; i < n * 2 - 1; ++i) {
    if (a[i] == -1) {
      if (flag)
        continue;
      for (int j = 1; j <= len; ++j) {
        cout << zero[j] + 1 << " ";
      }
      flag = true;
    } else {
      cout << a[i] + 1 << " ";
    }
  }
  cout << "\n";
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