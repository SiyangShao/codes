#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}