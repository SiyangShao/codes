#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
constexpr ll N = 2e5;
using bit = bitset<N>;
auto solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> pos;
  pos.emplace_back(0);
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      pos.emplace_back(i);
    }
  }
  // for (auto i : pos) {
  //   cout << i << " ";
  // }
  // cout << "\n";
  set<pair<int, int>> st;
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    auto L = prev(upper_bound(pos.begin(), pos.end(), l));
    auto R = prev(upper_bound(pos.begin(), pos.end(), r));
    assert(s[*L] == s[l] && s[*R] == s[r]);
    // cout << *L + 1 << " " << *R + 1 << "\n";
    if (*L == *R) {
      st.emplace(-1, -1);
    } else if (*L == *prev(R) && s[*L] == '0') {
      st.emplace(-1, -1);
    } else {
      if (s[l] == '0') {
        l = *L;
      } else {
        if (l == *L) {
          if (L != pos.begin())
            l = *prev(L);
        }
      }
      if (s[r] == '1') {
        r = (R + 1 == pos.end() ? n - 1 : *next(R) - 1);
      } else {
        int end = (R + 1 == pos.end() ? n - 1 : *next(R) - 1);
        if (r == end) {
          R = next(R);
          if (R == pos.end()) {
            r = n - 1;
          } else if (R + 1 == pos.end()) {
            r = n - 1;
          } else {
            R = next(R);
            r = *R - 1;
          }
        }
      }
      st.emplace(l, r);
    }
  }
  // cout << "!\n";
  // for (auto [l, r] : st) {
  //   cout << l << " " << r << "\n";
  // }
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