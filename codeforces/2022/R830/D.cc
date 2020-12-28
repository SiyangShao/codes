#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll q;
  cin >> q;
  set<ll> st;
  set<ll> erase;
  st.emplace(0);
  map<ll, ll> mex;
  vector<pair<char, ll>> query(q);
  map<ll, vector<ll>> factor; // all the factors which may be used
  for (auto &[op, x] : query) {
    cin >> op >> x;
    if (op == '+') {
      st.emplace(x);
    } else if (op == '?') {
      while (st.contains(mex[x] * x)) {
        factor[mex[x] * x].emplace_back(x); // save all factors
        mex[x]++;
      }
    }
  }
  map<ll, set<ll>> del;
  for (auto &[x, me] : mex) {
    for (ll i = 1; i <= me; ++i) {
      del[x].emplace(i); // initiate
    }
  }
  for (auto &[op, x] : query) {
    if (op == '+') {
      for (auto i : factor[x]) {
        del[i].erase(x / i); // we add x/i
      }
    } else if (op == '-') {
      for (auto i : factor[x]) {
        del[i].emplace(x / i); // we del x/i
      }
    } else {
      if (del[x].empty()) { // nothing to del
        cout << mex[x] * x << "\n";
      } else { // have del del.begin which must be minimum (mex)
        cout << (*del[x].begin()) * x << "\n";
      }
    }
  }
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