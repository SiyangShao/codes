#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m, q;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  vector<pair<int, int>> ranges(m);
  for (auto &[l, r] : ranges) {
    cin >> l >> r;
    l--, r--;
  }
  set<int> st;
  for (int i = 0; i < n; ++i) {
    st.emplace(i);
  }
  vector<int> v, pos(n, -1);
  for (auto [l, r] : ranges) {
    auto it = st.lower_bound(l);
    vector<int> erase;
    while (it != st.end() && (*it) <= r) {
      erase.emplace_back(*it);
      v.emplace_back(*it);
      pos[*it] = (int)v.size() - 1;
      it++;
    }
    for (auto i : erase) {
      st.erase(i);
    }
  }
  int cnt = 0, change = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      cnt++;
  }
  for (int i = 0; i < min(cnt, (int)v.size()); ++i) {
    if (s[v[i]] == '0') {
      change++;
    }
  }
  while (q--) {
    int p;
    cin >> p;
    p--;
    if (pos[p] != -1 && pos[p] < cnt) {
      if (s[p] == '0') {
        change--;
      } else {
        change++;
      }
    }
    if (s[p] == '0') {
      s[p] = '1';
      cnt++;
      if (cnt <= (int)v.size() && s[v[cnt - 1]] == '0')
        change++;
    } else {
      s[p] = '0';
      if (cnt > 0 && cnt <= (int)v.size() && s[v[cnt - 1]] == '0')
        change--;
      cnt--;
    }
    cout << change  << "\n";
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
