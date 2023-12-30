#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int u = a[n - 1], p = n - 1;
  map<int, int> vis;
  for (int i = 0; i < k; ++i) {
    if (vis[p])
      break;
    vis[p] = 1;
    if (u > n) {
      cout << "No\n";
      return;
    }
    // now u is at a[n]
    // u should be at a[u]
    // when u at a[u], a[n] is a[n - u + n]
    int new_p = (p + n - u) % n;
    u = a[new_p];
    p = new_p;
  }
  cout << "Yes\n";
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
