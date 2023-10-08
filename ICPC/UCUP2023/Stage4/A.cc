#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 2e4;
using ui = unsigned long long;
template <ui n> struct AdditiveBitset {
  vector<ui> v;
  AdditiveBitset() { v.assign(n / 32, 0); }
  void ls1() {
    bool carry = false;
    for (ui i = 0; i < n / 32; ++i) {
      v[i] = (v[i] << 1) | carry;
      carry = (v[i] & (1ll << 32));
      v[i] %= (1LL << 32);
    }
  }
  bool get(int x) { return v[x / 32] & (1 << (x % 32)); }
  void toggle(int x) { v[x / 32] ^= (1 << (x % 32)); }
  void add(AdditiveBitset &b) {
    bool carry = false;
    for (ui i = 0; i < n / 32; ++i) {
      v[i] = v[i] + b.v[i] + carry;
      carry = (v[i] >> 32) & 1;
      v[i] = v[i] % (1LL << 32);
    }
  }
  ll popcount() {
    ll ans = 0;
    for (ll i = 0; i < n / 32; ++i) {
      for (int j = 0; j < 32; ++j) {
        if (v[i] & (1LL << j))
          ans++;
      }
    }
    return ans;
  }
};
using bst = AdditiveBitset<N>;
auto cal(auto x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x /= 2;
  }
  return cnt;
}

auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  vector<bst> dp(n);
  for (auto &i : a)
    cin >> i;
  if (*max_element(a.begin(), a.end()) == 0) {
    cout << "0\n";
    return;
  }
  vector<vector<int>> E(n);
  vector<int> id, in(n);
  id.reserve(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    in[v]++;
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      Q.emplace(i);
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    id.emplace_back(u);
    Q.pop();
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0) {
        Q.emplace(v);
      }
    }
  }
  int end = id.back();
  dp[end].toggle(0);
  for (auto u : id | ranges::views::reverse) {
    for (auto v : E[u]) {
      auto tmp = dp[v];
      tmp.ls1();
      dp[u].add(tmp);
    }
  }
  ll ans = 0;
  ll bit = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0)
      continue;
    bit += (ll)dp[i].popcount();
  }
  ll round = 0;
  bool flg = false;

  for (int i = 0; i < N; ++i) {
    if (bit == 0) {
      break;
    }
    round++;
    for (int j = 0; j < n; ++j) {
      if (a[j] == 0)
        continue;
      if (dp[j].get(i)) {
        ans += a[j];
        bit--;
      }
    }
    ans /= 2;
  }
  cout << round + cal(ans) << "\n";
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