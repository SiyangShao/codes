#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 3e5 + 7, inf = 1e16;
bitset<N> vis, cur;
vector<ll> pri;
vector<vector<ll>> E(N * 2);
vector<ll> dis(N * 2, inf);
vector<ll> pre(N * 2, -1);
void init() {
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (auto j : pri) {
      if (i * j >= N)
        break;
      vis[i * j] = true;
      if (i % j == 0) {
        break;
      }
    }
  }
}
long long Pollard_Rho(long long x) {
  long long s = 0, t = 0;
  long long c = (long long)rand() % (x - 1) + 1;
  int step = 0, goal = 1;
  long long val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) { // 倍增优化
    for (step = 1; step <= goal; ++step) {
      t = (t * t + c) % x;
      val = val * abs(t - s) % x;
      if ((step % 127) == 0) {
        long long d = gcd(val, x);
        if (d > 1)
          return d;
      }
    }
    long long d = gcd(val, x);
    if (d > 1)
      return d;
  }
}
void fac(ll x, ll id) {
  if (x < 2) {
    return;
  }
  if (!vis[x]) {
    if (!cur[x]) {
      E[id + N].emplace_back(x);
      E[x].emplace_back(id + N);
      cur[x] = true;
    }
    return;
  }
  ll p = x;
  while (p >= x) {
    p = Pollard_Rho(x);
  }
  while ((x % p) == 0) {
    x /= p;
  }
  fac(x, id), fac(p, id);
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    cur = vis;
    fac(a[i], i);
  }
  ll s, t;
  cin >> s >> t;
  s--, t--;
  s += N, t += N;
  dis[s] = 0;
  set<pair<ll, ll>> st;
  st.emplace(dis[s], s);
  while (!st.empty()) {
    auto [d, u] = *st.begin();
    st.erase(st.begin());
    for (auto v : E[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        st.erase({dis[v], v});
        st.emplace(dis[v], v);
        pre[v] = u;
      }
    }
  }
  vector<ll> ans;
  while (t != -1) {
    if (t >= N) {
      ans.emplace_back(t - N);
    }
    t = pre[t];
  }
  reverse(ans.begin(), ans.end());
  if (ans[0] != s - N) {
    cout << "-1\n";
    return;
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  // cin >> _;
  while (_--) {
    solve();
  }
}
