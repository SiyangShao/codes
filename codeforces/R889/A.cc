#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int max_abs = 0;
  int pos = 0, cnt = 0;
  for (auto &i : a) {
    cin >> i;
    if (abs(i) > abs(max_abs)) {
      max_abs = i;
      pos = cnt;
    }
    cnt++;
  }
  if (n == 1) {
    cout << "0\n";
    return;
  }
  cnt = 0;
  for (auto i : a) {
    if ((i > 0) == (max_abs > 0)) {
      cnt++;
    }
  }
  vector<pair<int, int>> ans;
  if (cnt >= 8 || cnt >= n / 2) {
    for (int i = 0; i < n; ++i) {
      if ((a[i] > 0) != (max_abs > 0)) {
        ans.emplace_back(i, pos);
      }
    }
    if (max_abs > 0) {
      for (int i = 1; i < n; ++i) {
        ans.emplace_back(i, i - 1);
      }
    } else {
      for (int i = n - 2; i >= 0; --i) {
        ans.emplace_back(i, i + 1);
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      if ((a[i] > 0) != (max_abs > 0)) {
        pos = i;
        break;
      }
    }
    for (int i = 0; i < 5; ++i) {
      ans.emplace_back(pos, pos);
    }

    for (int i = 0; i < n; ++i) {
      if ((a[i] > 0) == (max_abs > 0)) {
        ans.emplace_back(i, pos);
      }
    }
    if (max_abs < 0) {
      for (int i = 1; i < n; ++i) {
        ans.emplace_back(i, i - 1);
      }
    } else {
      for (int i = n - 2; i >= 0; --i) {
        ans.emplace_back(i, i + 1);
      }
    }
  }
  assert(ans.size() <= 31);
  cout << ans.size() << '\n';
  for (auto [l, r] : ans) {
    cout << l + 1 << " " << r + 1 << "\n";
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