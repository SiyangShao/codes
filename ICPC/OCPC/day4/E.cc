#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ceil_pow2(ll n) {
  ll x = 0;
  while ((1LL << x) < (ll)(n))
    x++;
  x--;
  return x;
}
auto solve() {
  int n;
  cin >> n;
  // cout << ceil_pow2(4) << " " << ceil_pow2(5) << " " << ceil_pow2(3) << "\n";
  vector<pair<ll, ll>> a(n);
  set<pair<ll, ll>> st;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
    st.emplace(a[i]);
  }
  vector<pair<ll, ll>> ans;
  ll sum = 0;
  while (true) {
    auto fi = st.begin();
    auto se = st.rbegin();
    if (fi->first == se->first) {
      break;
    }
    ll x = ceil_pow2(se->first + sum);
    // cout << x << "\n";
    for (ll i = 0; i < n; ++i) {
      st.erase(a[i]);
      a[i].first += sum;
      while (a[i].first <= (1LL << x)) {
        a[i].first = a[i].first * 2;
        ans.emplace_back(1, i + 1);
      }
      a[i].first -= sum;
      // cout<<a[i].first<<" ";
      st.emplace(a[i]);
    }
    sum -= (1LL << x);
    ans.emplace_back(2, 1LL << x);
    // cout << (1LL << x) << "\n";
  }
  cout << ans.size() << "\n";
  for (auto &[l, r] : ans) {
    cout << l << " " << r << "\n";
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