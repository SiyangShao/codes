#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> vis(m);
  vector<vector<int>> b(n), tag(n);
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    b[i].resize(p);
    for (auto &j : b[i]) {
      cin >> j;
      j--;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (auto j : b[i]) {
      if (!vis[j]) {
        tag[i].emplace_back(j);
        vis[j] = 1;
      }
    }
  }
  sort(b[0].begin(), b[0].end());
  int critical = -1;
  for (int i = 1; i < n; ++i) {
    sort(b[i].begin(), b[i].end());
    bool flag = true;
    for (auto j : tag[i]) {
      auto it = lower_bound(b[i - 1].begin(), b[i - 1].end(), j);
      if (it != b[i - 1].end() && *it == j) {
        flag = false;
        break;
      }
    }
    if (flag) {
      critical = i;
      break;
    }
  }
  if (critical == -1) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  for (int i = 0; i < critical - 1; ++i) {
    cout << i + 1 << " ";
  }
  cout << critical + 1 << " " << critical;
  for (int i = critical + 1; i < n; ++i) {
    cout << " " << i + 1;
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}