#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int cur = n;
  for (int i = 0; i < n; i += 2) {
    a[i] = cur;
    cur--;
  }
  cur = 1;
  for (int i = 1; i < n; i += 2) {
    a[i] = cur;
    cur++;
  }
  for (auto &i : a) {
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
