#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n), x(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (n == 1) {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    x[i] = a[i] - a[(i - 1 + n) % n];
  }
  // --d[i-1], ++d[i+1] -> apply on i, i+2, i+4... i-3
  vector<ll> op(n);
  for (int i = 0, k = 0; k < 2 * n; k++) {
    int j = (i + 2) % n;
    if (x[i] > 0) {
      if (i < n - 1) {
        op[i % 2] += x[i];
        op[i] -= x[i];
        op[i + 1] += x[i];
      } else {
        op[0] += x[i];
        op[n - 1] -= x[i];
      }
      x[j] += x[i];
      x[i] = 0;
    }
    i = j;
  }
  for (int i = 2; i < n; i++) {
    op[i] += op[i - 2];
  }
  rotate(op.begin(), op.end() - 1, op.end());
  for (auto i : op) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
