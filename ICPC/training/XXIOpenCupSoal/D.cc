#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1000000 + 1;
vector<vector<ll>> X(N), Y(N);
vector<ll> x(N), y(N);
vector<pair<ll, ll>> id;
vector<ll> val;
multiset<ll> stL, stR;
auto cal(ll i) {
  ll sum = x[i];
  for (auto v : X[i]) {
    stR.erase(stR.lower_bound(y[id[v].second]));
    y[id[v].second] -= val[v];
    stR.emplace(y[id[v].second]);
  }
  auto cur = stR.rbegin();
  for (ll i = 0; i < 2; ++i) {
    sum += *cur;
    cur++;
  }
  for (auto v : X[i]) {
    stR.erase(stR.lower_bound(y[id[v].second]));
    y[id[v].second] += val[v];
    stR.emplace(y[id[v].second]);
  }
  return sum;
}
auto solve() {
  ll n;
  cin >> n;
  id.resize(n), val.resize(n);
  for (ll i = 0; i < n; ++i) {
    cin >> id[i].first >> id[i].second >> val[i];
    x[id[i].first] += val[i];
    X[id[i].first].emplace_back(i);
    y[id[i].second] += val[i];
    Y[id[i].second].emplace_back(i);
  }
  for (ll i = 0; i < N; ++i) {
    if (x[i] != 0) {
      stL.emplace(x[i]);
    }
    if (y[i] != 0) {
      stR.emplace(y[i]);
    }
  }
  stL.emplace(0);
  stL.emplace(0);
  stR.emplace(0);
  stR.emplace(0);
  ll ans = 0;
  auto cur = stL.rbegin();
  for (ll i = 0; i < 3; ++i) {
    ans += *cur;
    cur++;
  }
  ll ttt = 0;
  cur = stR.rbegin();
  for (ll i = 0; i < 3; ++i) {
    ttt += *cur;
    cur++;
  }
  ans = max(ans, ttt);
  // cout << ans << " ";
  for (ll i = 0; i < N; ++i) {
    if (x[i] != 0) {
      ans = max(ans, cal(i));
    }
  }
  // cout << ans << " ";
  swap(x, y);
  swap(X, Y);

  for (ll i = 0; i < n; ++i) {
    swap(id[i].first, id[i].second);
  }
  swap(stL, stR);
  for (ll i = 0; i < N; ++i) {
    if (x[i] != 0) {
      ans = max(ans, cal(i));
    }
  }
  cout << ans << "\n";
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