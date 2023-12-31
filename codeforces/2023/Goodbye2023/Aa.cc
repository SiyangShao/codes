#include <bits/stdc++.h>
using namespace std;
// #define int long long
int gcd(int b, int a) { return a ? gcd(a, b % a) : b; }
void solve() {
  int n, k;
  cin >> n >> k;
  bool flag = false;
  int sum = 1;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    sum *= t;
    int tt = 2023;
    if (gcd(sum, tt) != sum) {
      flag = true;
    }
  }
  if (flag) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << 2023 / sum << " ";
  for (int i = 1; i < k; i++)
    cout << "1 ";
  cout << "\n";
  return;
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}