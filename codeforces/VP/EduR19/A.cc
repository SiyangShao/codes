#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> vec;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) {
        vec.emplace_back(i);
        n /= i;
      }
    }
  }
  if (n != 1) {
    vec.emplace_back(n);
  }
  if (vec.size() < k) {
    cout << "-1\n";
  } else {
    for (int i = 0; i + 1 < k; ++i) {
      cout << vec[i] << " ";
    }
    int ans = vec[k - 1];
    for (int i = k; i < vec.size(); ++i) {
      ans *= vec[i];
    }
    cout << ans << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}