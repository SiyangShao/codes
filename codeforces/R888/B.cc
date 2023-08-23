#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> odd, even, pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] & 1)
      odd.push_back(a[i]), pos[i] = 1;
    else
      even.push_back(a[i]);
  }
  ranges::sort(odd);
  ranges::sort(even);
  auto x = odd.begin(), y = even.begin();
  for (int i = 0; i < n; ++i) {
    if (pos[i]) {
      a[i] = *x;
      x++;
    } else {
      a[i] = *y;
      y++;
    }
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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