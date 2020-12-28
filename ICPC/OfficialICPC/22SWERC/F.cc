#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> deg(n);
  vector<pair<int, int>> edg(m);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
    deg[u]++;
    deg[v]++;
  }
  int min_deg = n, id = 0;
  for (int i = 0; i < n; ++i) {
    min_deg = min(min_deg, deg[i]);
    if (deg[i] == min_deg) {
      id = i;
    }
  }
  if (min_deg != n - 1) {
    cout << "2\n";
    for (auto [u, v] : edg) {
      if (u == id || v == id)
        cout << "2 ";
      else
        cout << "1 ";
    }
    cout << "\n";
  } else {
    bool flag = false;
    cout << "3\n";
    for (auto [u, v] : edg) {
      if (u == id || v == id) {
        if (flag) {
          cout << "2 ";
        } else {
          flag = true;
          cout << "3 ";
        }
      } else {
        cout << "1 ";
      }
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}