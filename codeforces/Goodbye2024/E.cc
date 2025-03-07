#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> special(n), leaf(n);
  ll leafnum = 0, specialnum = 0;
  for (int i = 0; i < n; i++) {
    if (E[i].size() == 1) {
      leaf[i] = 1;
      leafnum++;
      for (auto v : E[i]) {
        special[v] = 1;
      }
    }
  }
  // set all leaf to not special
  for (int i = 0; i < n; i++) {
    if (leaf[i]) {
      special[i] = 0;
    }
    if (special[i]) {
      specialnum++;
    }
  }
  ll base = leafnum * (n - leafnum);
  ll normalnum = n - leafnum - specialnum;
  vector<int> normal(n, 0);
  function<void(int, int)> dfs = [&](int u, int fa) {
    if (!leaf[u] && !special[u]) {
      normal[u] = 1;
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      normal[u] += normal[v];
    }
    if (leaf[u])
      return;
    // check what kind of u is
    int losev = -1;
    ll add = normalnum;
    if (!special[u] && !leaf[u])
      add--;
    for (auto v : E[u]) {
      if (!special[v] && !leaf[v]) {
        if (v == fa) {
          add -= normalnum - normal[u];
        } else {
          add -= normal[v];
        }
      }
    }
    base += add;
  };
  dfs(0, 0);
  assert(normal[0] == normalnum);
  cout << base << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
