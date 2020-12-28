#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 3e9;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<ll>> son(n);
  set<ll> st;
  for (int i = n - 1; i >= 0; --i) {
    son[i].emplace_back(a[i]);
    st.emplace(a[i]);
    if (i != n - 1) {
      for (auto val : son[i + 1]) {
        ll next_val = lcm(son[i].back(), val);
        if (next_val < inf && next_val != son[i].back()) {
          st.emplace(next_val);
          son[i].emplace_back(next_val);
        }
      }
    }
  }
  ll mex = 1;
  while (st.contains(mex)) {
    ++mex;
  }
  cout << mex << "\n";
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