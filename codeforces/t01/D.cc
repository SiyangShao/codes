#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll h(ll x) { return x * x * x * 156007 + 995669; }
ll f(ll x) { return h(x & ((1LL << 31) - 1)) + h(x >> 31); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  vector<vector<int>> E(n);
  vector<int> non_cent(n), father(n, -1);
  vector<ll> hash(n), siz(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  auto dfs = [&](auto self, int u, int fa) -> void {
    siz[u] = 1;
    hash[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      self(self, v, u);
      hash[u] += f(hash[v]);
      siz[u] += siz[v];
    }
  };
  dfs(dfs, 0, 0);
  bool flag = true;
  auto dp = [&](auto self, int u, int fa) -> void {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      hash[u] -= f(hash[v]);
      siz[u] -= siz[v];
      hash[v] += f(hash[u]);
      siz[v] += siz[u];
      self(self, v, u);
      hash[v] -= f(hash[u]);
      siz[v] -= siz[u];
      hash[u] += f(hash[v]);
      siz[u] += siz[v];
    }
    map<pair<ll, ll>, ll> st;
    // cout << "Center: " << u + 1 << endl;
    for (auto v : E[u]) {
      st[{hash[v], siz[v]}]++;
      //   cout << "Node: " << v + 1 << " Hash: " << hash[v] << " Size: " <<
      //   siz[v]
      //        << endl;
    }
    if (st.size() > 2) {
      flag = false;
      return;
    }
    if (st.size() == 1)
      return;
    assert(st.size() == 2);
    pair<ll, ll> k1, k2;
    ll v1, v2;
    tie(k1, v1) = *st.begin();
    tie(k2, v2) = *st.rbegin();
    if (v1 > 1 && v2 > 1) {
      flag = false;
    } else if (v1 == 1 && v2 == 1) {
      non_cent[u] = 1;
    } else {
      assert(v1 == 1 || v2 == 1);
      if (v2 == 1)
        swap(k1, k2), swap(v1, v2);
      // v1 == 1
      assert(v1 == 1);
      for (auto v : E[u]) {
        if (hash[v] == k1.first && siz[v] == k1.second) {
          // v must be u's father
          // cout << u + 1 << " father is " << v + 1 << endl;
          father[u] = v;
          break;
        }
      }
    }
  };
  dp(dp, 0, 0);
  if (!flag) {
    cout << "-1\n";
    return 0;
  }
  vector<int> vis(n, 0);
  auto dfs2 = [&](auto self, int u, int fa) -> void {
    if (vis[u])
      return;
    if (fa != father[u] && father[u] != -1) {
      cout << "-1\n";
      exit(0);
    }
    father[u] = fa;
    vis[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      self(self, v, u);
    }
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i] && father[i] != -1) {
      // cout << i + 1 << " father is " << father[i] + 1 << endl;
      dfs2(dfs2, i, father[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i] && !non_cent[i]) {
      cout << i + 1 << " " << "\n";
      exit(0);
    }
  }
  cout << "-1\n";
}
