#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = 0;
  for (auto i : s) {
    if (i == '(')
      l++;
    else
      r++;
  }
  if (l != r) {
    cout << "-1\n";
    return;
  }
  vector<int> id(s.length(), 2);
  l = 0, r = n - 1;
  while (l < r) {
    while (l < n && s[l] == '(') {
      l++;
    }
    while (r >= 0 && s[r] == ')') {
      r--;
    }
    if (l >= r || l >= n || r < 0)
      break;
    id[l] = id[r] = 1;
    l++, r--;
  }
  set<int> st;
  for (auto i : id) {
    st.emplace(i);
  }
  if (st.size() == 1) {
    cout << "1\n";
    for (int i = 0; i < n; ++i) {
      cout << "1 ";
    }
    cout << "\n";
    return;
  }
  cout << "2\n";
  for (auto i : id) {
    cout << i << " ";
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