#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
    i = i % k;
    if (i == 0) {
      i = k;
    }
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    if (a[i] != a[j]) {
      return a[i] > a[j];
    } else {
      return i < j;
    }
  });
  for (auto i : id) {
    cout << i + 1 << " ";
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