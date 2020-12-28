#include <bits/stdc++.h>
using namespace std;
int n;
auto ask1(int x) {
  cout << "? " << x << " ";
  for (int i = 1; i <= n; ++i) {
    if (i == x) {
      cout << "0";
    } else {
      cout << "1";
    }
  }
  cout << endl;
  int y;
  cin >> y;
  return y;
}
auto ask(int x, vector<int> &y) {
  cout << "? " << x << " ";
  for (int i = 1; i <= n; ++i) {
    cout << y[i];
  }
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}
auto solve() {
  cin >> n;
  vector<int> val(n + 1);
  for (int i = 1; i <= n; ++i) {
    val[i] = ask1(i);
  }
  vector<int> x(n), need_ask(n + 1, 0);
  iota(x.begin(), x.end(), 1);
  sort(x.begin(), x.end(), [&](int a, int b) { return val[a] > val[b]; });
  vector<vector<int>> lst(n + 1);
  for (int i = 0; i < n; ++i) {
    if (val[x[i]] == val[x[0]]) {
      need_ask[x[i]] = 1;
    }
    lst[val[x[i]]].emplace_back(x[i]);
  }
  vector<int> res;
  for (int i = val[x[0]] - 1; i >= 0; --i) {
    if (lst[i].empty())
      continue;
    bool flag = false;
    for (auto j : lst[i]) {
      auto y = ask(j, need_ask);
      if (y != 0) {
        flag = true;
        break;
      }
    }
    for (auto j : lst[i]) {
      res.emplace_back(j);
    }
    if (flag) {
      for (auto j : res) {
        need_ask[j] = 1;
      }
      res.clear();
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << need_ask[i];
  }
  cout << endl;
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
