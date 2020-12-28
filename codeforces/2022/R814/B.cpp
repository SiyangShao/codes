#include <bits/stdc++.h>
#include <queue>
#include <type_traits>
using namespace std;
using ll = long long;
constexpr ll inf = 1e9 * 100;
vector<ll> Feb;
auto pre() {
  ll ans = 1, cnt = 1;
  while (ans <= inf) {
    Feb.emplace_back(ans);
    ll tmp = ans;
    ans = cnt;
    cnt += tmp;
  }
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> c(n);
  priority_queue<ll> Q;
  ll sum = 0;
  for (auto &i : c) {
    cin >> i;
    Q.emplace(i);
    sum += i;
  }
  ll cur = -1;
  for (auto i : Feb) {
    if (sum == 0) {
      break;
    }
    if (sum < 0) {
      cout << "NO\n";
      return;
    }
    sum -= i;
    cur++;
  }
  ll pre = 0;
  for (ll i = cur; i >= 0; --i) {
    auto u = Q.top();
    Q.pop();
    if (u >= Feb[i]) {
      u -= Feb[i];
    } else {
      cout << "NO\n";
      return;
    }
    Q.emplace(pre);
    pre = u;
  }
  cout << "YES\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  pre();
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
