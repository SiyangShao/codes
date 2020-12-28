#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> ans;
  vector<int> p0, p1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      p0.push_back(i + 1);
    } else {
      p1.push_back(i + 1);
    }
  }
  reverse(p1.begin(), p1.end());
  int l = p1.back(), r = p0.back();
  for (auto x : p0) {
    if (x != r) {
      ans.emplace_back(x, r);
    }
  }
  for (auto x : p1) {
    if (x != l) {
      ans.emplace_back(x, l);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (i != l && i != r && j != l && j != r) {
        ans.emplace_back(i, j);
      }
    }
  }
  int b = (int)p0.size();
  for (int i = b; i > l; --i) {
    ans.emplace_back(l, i);
  }
  for (int i = 1; i < l; ++i) {
    ans.emplace_back(l, i);
  }
  for (int i = b + 1; i < r; ++i) {
    ans.emplace_back(i, r);
  }
  for (int i = n; i > r; --i) {
    ans.emplace_back(i, r);
  }
  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    if (x > y) {
      swap(x, y);
    }
    cout << x << " " << y << "\n";
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