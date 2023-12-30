#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  set<int> st;
  for (auto &i : p) {
    cin >> i;
    if (st.contains(i - 1)) {
      st.erase(i - 1);
    }
    st.emplace(i);
  }
  cout << (int)st.size() - 1 << "\n";
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