#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, x;
  cin >> n >> x;
  if (n % x != 0) {
    cout << "-1\n";
    return;
  }
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  swap(a[0], a[n - 1]);
  a[0] = x;
  int add = n / x;
  priority_queue<int, vector<int>, greater<>> Q;
  for (int i = 2; i * 2 <= add; ++i) {
    if (add % i == 0) {
      while (add % i == 0) {
        add /= i;
        Q.emplace(i);
      }
    }
  }
  if (add != 1) {
    Q.emplace(add);
  }
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i] == x) {
      if (!Q.empty()) {
        a[i] *= Q.top();
        Q.pop();
        x = a[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != 0 && i != n - 1)
      assert(a[i] % (i + 1) == 0);
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
