#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  stack<int> st;
  int top = -1;
  for (auto &i : a) {
    cin >> i;
  }
  for (auto i : a) {
    if (i == top) {
      continue;
    } else {
      if (st.empty()) {
        if (top != -1)
          st.emplace(top);
        top = i;
      } else {
        if (st.top() > top && top > i) {
          top = i;
        } else if (st.top() < top && top < i) {
          top = i;
        } else {
          st.emplace(top);
          top = i;
        }
      }
    }
  }
  st.emplace(top);
  cout << st.size() << "\n";
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