#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> output(n + 1, 0);
  set<ll> st;
  for (ll i = 1; i <= n; ++i) {
    st.emplace(i);
  }
  for (ll i = n - 1; i > 0; --i) {
    ll dif = a[i - 1] - a[i];
    if (dif < 0) {
      continue;
    }
    auto pos = st.lower_bound(dif);
    assert(pos != st.end());
    output[*pos] = i;
    st.erase(pos);
  }
  for (ll i = 1; i <= n; ++i) {
    cout << output[i] + 1 << " ";
  }
  cout << "\n";
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