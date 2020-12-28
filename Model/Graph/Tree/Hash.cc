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
  vector<vector<int>> E(n);
  vector<ll> hash(n), siz(n);
  set<pair<ll, ll>> st;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  function<void(int, int)> dfs = [&](int u, int fa) {
    siz[u] = 1;
    hash[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      hash[u] += f(hash[v]);
    }
    st.emplace(hash[u], siz[u]);
  };
  dfs(0, 0);
  cout << st.size() << "\n";
}