#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2000;
auto solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  bitset<N> a(s), b(t);
  if ((not a.any() and b.any()) or (a.any() and not b.any())) {
    cout << "-1\n";
    return;
  }
  if (a == b) {
    cout << "0\n";
    return;
  }
  vector<int> ans;
  auto clear = [&](auto &x) {
    for (int i = n; i < N; ++i) {
      x[i] = false;
    }
  };
  int lsb = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i]) {
      if (!a[i]) {
        for (int j = 0; j < n; ++j) {
          if (a[j]) {
            ans.emplace_back(i - j);
            if (j > i) {
              a ^= (a >> (j - i));
            } else {
              a ^= (a << (i - j));
            }
            clear(a);
            break;
          }
        }
      }
      int msb = -1;
      for (int j = n - 1; j >= 0; --j) {
        if (a[j]) {
          msb = j;
          break;
        }
      }
      assert(msb >= i);
      for (int j = i - 1; j >= 0; --j) {
        if (a[j]) {
          ans.emplace_back(j - msb);
          a ^= (a >> (msb - j));
          clear(a);
        }
      }
      lsb = i;
      break;
    }
  }
  for (int i = lsb; i < n; ++i) {
    if (a[i] == b[i])
      continue;
    ans.emplace_back(i - lsb);
    a ^= (a << (i - lsb));
    clear(a);
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
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