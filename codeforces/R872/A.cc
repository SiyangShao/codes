#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  int l = 0, r = 0;
  vector<int> pos(m);
  for (auto &i : x) {
    cin >> i;
    if (i == -1) {
      l++;
    } else if (i == -2) {
      r++;
    } else {
      i--;
      pos[i]++;
    }
  }
  int L = 0, R = 0, vis = 0;
  for (auto i : pos) {
    if (i)
      vis++;
    else
      R++;
  }
  int ans = max(l, r) + vis;
  for (auto i : pos) {
    if (i) {
      ans = max(ans, min(l, L) + min(r, R) + vis);
    } else {
      L++;
      R--;
    }
  }
  ans = min(ans, m);
  cout << ans << "\n";
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