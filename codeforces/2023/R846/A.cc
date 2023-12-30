#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> odd, even;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      even.emplace_back(i + 1);
    } else {
      odd.emplace_back(i + 1);
    }
  }
  if (odd.empty() || (odd.size() <= 2 && even.size() <= 1)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << odd[0] << " ";
    if (odd.size() >= 3) {
      cout << odd[1] << " " << odd[2] << "\n";
    } else {
      assert(even.size() >= 2);
      cout << even[0] << " " << even[1] << "\n";
    }
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