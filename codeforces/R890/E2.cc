#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e6 + 10;
template <ll len = 1> ll cal(ll sum, vector<ll> &a) {
  if (sum >= len) {
    return cal<min(len * 2, N)>(sum, a);
  }
  bitset<len> cur, revcur;
  cur[0] = true;
  revcur[len - 1] = true;
  for (auto i : a) {
    cur = cur | (cur << i);
    revcur = revcur | (revcur >> i);
  }
  ll mid = sum / 2;
  ll l = cur._Find_next(mid - 1);
  ll r = revcur._Find_next(len - 1 - (mid - 1));
  r = len - 1 - r;
  return max(max(l * (sum - l), r * (sum - r)), 0LL);
}
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    E[p].emplace_back(i);
  }
  vector<int> siz(n, 1);
  ll ans = 0;
  function<void(int)> dfs = [&](int u) {
    if (E[u].empty())
      return;
    ll sum = 0;
    vector<ll> a;
    for (auto v : E[u]) {
      dfs(v);
      siz[u] += siz[v];
      sum += siz[v];
      a.emplace_back(siz[v]);
    }
    a.emplace_back(0);
    ranges::sort(a, greater<>());
    if (a[0] * 2 >= sum) {
      ans += a[0] * (sum - a[0]);
      return;
    }
    vector<ll> b;
    ll pi = 0;
    for (ll i = 1; i < (ll)a.size(); ++i) {
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
    ans += cal(sum, b);
  };
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