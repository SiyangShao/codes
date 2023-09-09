#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << n << " 1\n";
    return;
  }
  vector<int> deg(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int i, int j) { return deg[i] > deg[j]; });
  vector<int> flag(n);
  int size = 0, ans = 1;
  for (auto i : id) {
    if (deg[i] >= size) {
      size++;
      flag[i] = true;
    } else if (deg[i] == size - 1) {
      ans++;
    } else {
      break;
    }
  }
  cout << ans << " ";
  int large = 0, equal = 0;
  for (int i = 0; i < n; ++i) {
    if (flag[i]) {
      if (deg[i] == size - 1) {
        large++;
      } else if (deg[i] == size) {
        equal++;
      }
    }
  }
  if (large != 0) {
    cout << large << "\n";
  } else if (equal != 0) {
    cout << equal + 1 << "\n";
  } else {
    cout << 1 << "\n";
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