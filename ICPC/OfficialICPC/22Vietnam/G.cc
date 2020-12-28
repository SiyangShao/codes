#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, r, x1, x2;
  cin >> n >> r >> x1 >> x2;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto mid : a) {
    int L = mid - r, R = mid + r;
    if (x1 > x2) {
      if (L >= x1 && R >= x1 && mid >= x1) {
        cout << "GOAL\n";
        return;
      }
    } else {
      if (L <= x1 && R <= x1 && mid <= x1) {
        cout << "GOAL\n";
        return;
      }
    }
  }
  cout << "NO GOAL\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}