#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, q;
  cin >> n >> q;
  if (n % 2 == 1) {
    for (int i = 0; i < q; ++i) {
      cout << "NO\n";
    }
    return;
  }
  string s;
  cin >> s;
  set<int> st;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == (s[i] == '(')) {
      st.emplace(i);
    }
  }
  while (q--) {
    int pos;
    cin >> pos;
    pos--;
    if (st.contains(pos)) {
      st.erase(pos);
    } else {
      st.emplace(pos);
    }
    if (!st.empty() && ((!(*st.begin() % 2)) || *st.rbegin() % 2)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
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