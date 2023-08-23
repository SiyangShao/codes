
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
constexpr ll N = 1e7;
vector<ll> prime, myprime;
bitset<N> vis;
void init() {
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      prime.emplace_back(i);
      if (i >= (ll)5e5)
        myprime.emplace_back(i);
    }
    for (auto j : prime) {
      if (i * j >= N)
        break;
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
}
ll prime1, prime2;
ll h(ll x) { return x * x * x * prime1 + prime2; }
ll f(ll x) { return h(x & ((1LL << 31) - 1)) + h(x >> 31); }
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  vector<ll> hash(n), siz(n);
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
  };
  dfs(0, 0);
  function<bool(int, int)> check = [&](int u, int fa) {
    set<pair<ll, ll>> st;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (st.contains({hash[v], siz[v]})) {
        st.erase({hash[v], siz[v]});
      } else {
        st.emplace(hash[v], siz[v]);
      }
    }
    if (st.empty())
      return true;
    if (st.size() >= 2)
      return false;
    auto [h, s] = *st.begin();
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (hash[v] == h && siz[v] == s) {
        return check(v, u);
      }
    }
    return false;
  };
  if (check(0, 0)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  random_device rd;
  mt19937 g(rd());
  init();
  std::uniform_int_distribution<mt19937::result_type> dist(0,
                                                           myprime.size() - 1);
  prime1 = myprime[dist(g)];
  prime2 = myprime[dist(g)];
  if (prime2 == prime1) {
    prime2 = myprime[dist(g)];
  }
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
}