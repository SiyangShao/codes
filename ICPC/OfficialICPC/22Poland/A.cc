#include <bits/stdc++.h>
using namespace std;
int log_10(int x) {
  int ans = 0;
  while (x) {
    ans++;
    x /= 10;
  }
  return ans;
}
auto solve() {
  int n;
  cin >> n;
  vector<pair<string, string>> mp(n);
  for (auto &[u, v] : mp) {
    cin >> u >> v;
  }
  if(n == 1){
    cout<<"0 0 1\n";
    return;
  }
  int mx = log_10(n - 1);
  tuple<int, int, int> ans = {0, 0, mx};
  map<string, int> t;
  for (int i = 0; i <= log_10(n); ++i) {
    for (int j = 0; j <= log_10(n) - i; ++j) {
      if (i == 0 && j == 0)
        continue;
      int x = 0;
      t.clear();
      for (auto &[u, v] : mp) {
        string cur = u.substr(0, min((int)u.size(), i)) +
                     v.substr(0, min((int)v.size(), j));
        t[cur]++;
        x = max(x, t[cur]);
      }
      x = log_10(x - 1);
      // cout << i << " " << j << " " << x << "\n";
      if (i + j + x < mx) {
        mx = i + j + x;
        ans = {i, j, x};
      }
    }
  }
  auto [a, b, c] = ans;
  cout << a << " " << b << " " << c << "\n";
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