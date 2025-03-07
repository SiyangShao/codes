#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  if ((1 + n) % 2 == 1 && k % 2 == 1) {
    cout << "NO\n";
    return;
  }
  // (1 + n) * k / 2;
  vector<vector<ll>> ans(k, vector<ll>(n));
  if (k % 2 == 0) {
    int start = 0;
    for (int i = 0; i < k; i += 2) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = (j + start) % n;
        ans[i + 1][j] = n - 1 - ((j + start) % n);
      }
      start++;
    }
  } else {
    if (n != k) {
      cout << "NO\n";
      return;
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = (j + i) % n;
      }
    }
  }
  cout << "YES\n";
  for (auto &i : ans) {
    for (auto &j : i) {
      cout << j + 1 << " ";
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
