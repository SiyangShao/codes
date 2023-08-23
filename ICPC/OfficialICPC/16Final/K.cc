#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  auto sum = accumulate(a.begin(), a.end(), 0);
  if (sum % 2 != 0) {
    cout << "no quotation\n";
    return;
  }
  if (sum == 2) {
    cout << 1 << '\n';
    return;
  }
  for (int i = 100; i > 1; --i) {
    if (i * (i + 1) > sum)
      continue;
    int cur = i;
    auto b = a;
    for (int j = 0; cur;) {
      while (b[j] == 0)
        j++;
      if (b[j] < cur)
        break;
      b[j] -= cur;
      cur--;
    }
    if (cur != 0)
      continue;
    cur = i;
    for (int j = n - 1; cur;) {
      while (b[j] == 0)
        j--;
      if (b[j] < cur)
        break;
      b[j] -= cur;
      cur--;
    }
    if (cur != 0)
      continue;
    cout << i << '\n';
    return;
  }
  cout << "no quotation\n";
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