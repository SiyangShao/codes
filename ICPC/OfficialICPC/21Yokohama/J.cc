#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll solvex(ll n, vector<pair<ll, ll>> &a) {

  sort(a.begin(), a.end());

  // prepare table
  map<pair<ll, ll>, ll> tbl;
  for (ll i = 0; i < n; ++i)
    tbl[a[i]] = i;

  // find two envelopes
  vector<pair<ll, ll>> up;
  for (const auto &[u, v] : a) {
    while (!up.empty() && up.back().second < v) {
      up.pop_back();
    }
    up.emplace_back(u, v);
  }

  vector<pair<ll, ll>> down;
  reverse(a.begin(), a.end());
  for (const auto &[u, v] : a) {
    while (!down.empty() && down.back().second > v) {
      down.pop_back();
    }
    down.emplace_back(u, v);
  }
  reverse(a.begin(), a.end());
  reverse(down.begin(), down.end());

  // process v1
  vector<ll> v1(n), v2(n);
  ll cv = -1e12;
  for (ll i = 0; i < n; ++i) {
    auto [u, v] = a[i];
    if (cv < v)
      cv = v;
    v1[i] = cv;
  }

  // process p2.
  vector<pair<ll, ll>> a_by_y;
  for (auto [u, v] : a)
    a_by_y.emplace_back(v, u);
  sort(a_by_y.begin(), a_by_y.end());
  cv = -1e12;
  for (auto [v, u] : a_by_y) {
    if (cv < u)
      cv = u;
    v2[tbl[{u, v}]] = cv;
  }

  vector<tuple<ll, ll, ll>> up_by_y;
  for (ll i = 0; i < (ll)up.size(); ++i)
    up_by_y.emplace_back(up[i].second, up[i].first, i);
  sort(up_by_y.begin(), up_by_y.end());

  ll ans = 0;
  for (auto [u, v] : down) {
    ll idx = tbl[{u, v}];
    ll minU = v2[idx], minV = v1[idx];
    // first, we find rightmost: upper_bound(up.begin(), up.end())
    auto ub =
        upper_bound(up_by_y.begin(), up_by_y.end(), make_tuple(minV, 0ll, 0ll));
    ll rpos =
        (ub == up_by_y.end() ? -1 : get<2>(*ub)); // TODO. this is inclusive
    ll lpos =
        upper_bound(up.begin(), up.end(), make_pair(minU, 0ll)) - up.begin();
    ans += max(0ll, rpos - lpos + 1);
    cerr << "At up " <<  u << " " << v << ", num ans = " << rpos - lpos + 1
    << endl;
  }
  return ans;
}
auto solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (auto &[u, v] : a)
    cin >> u >> v;
  auto b = a;
  for (auto &[u, v] : a)
    u = -u;
  ll x = solvex(n, a), y = solvex(n, b);
  cout << x + y << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  ll T = 1;
  // cin >> T;
  while (T--)
    solve();
  return 0;
}
