#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), c(m), dish(n);
  for (auto &i : a) {
    cin >> i;
    i--;
    dish[i]++;
  }
  priority_queue<int> guest, table;
  for (auto &i : c) {
    cin >> i;
    table.emplace(i);
  }
  for (auto i : dish) {
    if (i) {
      guest.emplace(i);
    }
  }
  ll ans = 0;
  while (!guest.empty() && !table.empty()) {
    int l = guest.top(), r = table.top();
    guest.pop(), table.pop();
    if (l <= r) {
      ans += l;
    } else {
      ans += r;
      l -= r;
      guest.emplace(l);
    }
  }
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