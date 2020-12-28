#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 10;
vector<ll> b;
template <int len = 1> ll cal(ll sum) {
  if (sum >= len) {
    return cal<min(len * 2, N)>(sum);
  }
  bitset<len> cur;
  cur[0] = true;
  for (auto v : b) {
    cur = cur | (cur << v);
  }
  ll ans = 0;
  for (ll i = 0; i <= sum; ++i) {
    if (cur[i])
      ans = max(ans, i * (sum - i));
  }
  return ans;
}
ll ans;
vector<vector<int>> E;
vector<ll> siz;
void dfs(int u) {
  siz[u] = 1;
  if (E[u].empty())
    return;
  for (auto v : E[u]) {
    dfs(v);
    siz[u] += siz[v];
  }
  if (E[u].empty())
    return;
  vector<ll> a(E[u].size());
  for (int i = 0; i < (int)E[u].size(); ++i) {
    a[i] = siz[E[u][i]];
  }
  ll sum = siz[u] - 1;
  ranges::sort(a, greater<>());
  if (a[0] * 2 >= sum) {
    ans += a[0] * (sum - a[0]);
    return;
  }
  a.emplace_back(0);
  b.clear();
  ll pi = 0;
  for (int i = 1; i < (int)a.size(); ++i) {
    if (a[i] != a[i - 1]) {
      ll cnt = i - pi;
      ll x = a[i - 1];
      ll j = 1;
      while (j < cnt) {
        b.emplace_back(x * j);
        cnt -= j;
        j *= 2;
      }
      b.emplace_back(x * cnt);
      pi = i;
    }
  }
  ans += cal(sum);
}
auto solve() {
  int n;
  cin >> n;
  ans = 0;
  E = vector<vector<int>>(n);
  siz = vector<ll>(n, 1);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    E[p].emplace_back(i);
  }
  dfs(0);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}