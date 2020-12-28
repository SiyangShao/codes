#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k % 2 == 1) {
    vector<char> l, r;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        l.push_back(s[i]);
      } else {
        r.push_back(s[i]);
      }
    }
    ranges::sort(l);
    ranges::sort(r);
    auto itl = l.begin(), itr = r.begin();
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        cout << *itl;
        ++itl;
      } else {
        cout << *itr;
        ++itr;
      }
    }
    cout << "\n";
  } else {
    ranges::sort(s);
    cout << s << "\n";
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