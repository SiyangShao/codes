#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto query(int i, int j) {
  cout << "? " << i + 1 << " " << j + 1 << "\n";
  cout.flush();
  int x;
  cin >> x;
  return x;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (auto &i : x)
    cin >> i, i--;
  for (auto &i : y)
    cin >> i, i--;
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
