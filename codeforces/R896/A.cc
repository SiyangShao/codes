#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  /*
  4 0 1 2 3 ...
  3 4 0 1 2 ...
  2 3 4 0 1 ...
  1 2 3 4 0 ...
  */
  if (m == 1) {
    cout << "0\n";
    for (int i = 1; i <= n; ++i) {
      cout << "0\n";
    }
    return;
  } else if (m == 2) {
    cout << "2\n";
    for (int i = 1; i <= n; ++i) {
      cout << "0 1\n";
    }
    return;
  }
  if (n == 1) {
    cout << "2\n";
  } else if (n >= m - 1) {
    cout << m << "\n";
  } else {
    cout << n + 1 << "\n";
  }
  for (int i = 0; i < n; ++i) {
    int offset = (i % (m - 1)) + 1;
    for (int j = 0; j < m; ++j) {
      cout << (j + offset) % m << " ";
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