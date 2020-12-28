#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
array<vector<vector<pair<int, int>>>, 60> dp = {
nt,int>>};
constexpr ll N = 61;
array<ll, N> num, w;
vector<pair<int, int>> pii;
int n;
ll ans;
void check() {
  auto it = pii.begin();
  priority_queue<ll, vector<ll>, greater<>> Q;
  dbg(num);
  for (int i = 1; i <= n; ++i) {
    while (it != pii.end() && (it->first <= i)) {
      Q.emplace(it->second);
      it++;
    }
    if (num[i] == 0) {
      continue;
    }
    ll x = num[i] * i;
    while (x) {
      if (Q.empty()) {
        return;
      }
      if (Q.top() < i) {
        dbg("*itt < i");
        return;
      }
      x--;
      Q.pop();
    }
  }
  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt = cnt + num[i] * w[i];
  }
  ans = max(ans, cnt);
}
void cal(int u, ll res) {
  if (res == 0) {
    check();
    return;
  }
  if (u == 1) {
    num[u] = res / u;
    check();
    num[u] = 0;
    return;
  }
  for (ll i = 0; i * u <= res; ++i) {
    num[u] = i;
    int tmp = min(u - 1, (int)(res - i * u));
    cal(tmp, res - i * u);
  }
  num[u] = 0;
}

void realCal(int u) {
  if (u <= 8) {
    cal(u, u);
    return;
  }
  auto &d = dp[u - 1];
  for (auto &c : d) {
    fill(num.begin(), num.end(), 0);
    int sum = u;
    for (auto &p : c) {
      num[p.first] = p.second;
      sum -= p.first * p.second;
    }
    cal(8, sum);
  }
}

auto solve() {
  cin >> n;
  pii.resize(n);
  for (auto &[l, r] : pii) {
    cin >> l >> r;
  }
  sort(pii.begin(), pii.end(),
       [&](auto x, auto y) { return x.first < y.first; });
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  constexpr ll inf = 1e16;
  ans = -inf;
  realCal(n);
  if (ans == -inf) {
    cout << "impossible\n";
  } else {
    cout << ans << "\n";
  }
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