#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  if (a[0] == b[0]) {
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        cout << "NO\n";
        return;
      }
    }
    vector<pair<int, int>> ans;
    int num = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == '0') {
        ans.emplace_back(i, i);
        num++;
      }
    }
    if (num % 2 == 0) {
      // 1 has 2xor, 1 is 1
      // 0 has 1xor, 0 is 1
      ans.emplace_back(0, 0);
      ans.emplace_back(1, n - 1);
    } else {
      // 1 has 1xor, 1 is 0
      // 0 has 0xor, 0 is 0
      ans.emplace_back(0, n - 1);
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto &[l, r] : ans) {
      cout << l + 1 << " " << r + 1 << "\n";
    }
    return;
  } else {
    for (int i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
        cout << "NO\n";
        return;
      }
    }
    vector<pair<ll, ll>> ans;
    int num = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == '0') {
        ans.emplace_back(i, i);
        num++;
      }
    }
    if (num % 2 == 0) {
      ans.emplace_back(0, n - 1);
    } else {
      ans.emplace_back(0, 0);
      ans.emplace_back(1, n - 1);
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto &[l, r] : ans) {
      cout << l + 1 << " " << r + 1 << "\n";
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