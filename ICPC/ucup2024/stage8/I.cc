#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> x(m, vector<ll>(n));
  vector<ll> sum(m, 0);
  for (auto &i : x) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  for (int i = 0; i < m; ++i) {
    sum[i] = accumulate(x[i].begin(), x[i].end(), 0LL);
  }
  if (sum[0] == sum[1]) {
    for (int i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  int tot = n;
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
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
