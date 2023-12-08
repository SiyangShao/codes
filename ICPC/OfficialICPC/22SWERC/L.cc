#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int add = 0, del = 0;
  for (auto i : s) {
    if (i == '+') {
      add++;
    } else {
      del++;
    }
  }
  if (add < del) {
    swap(add, del);
  }
  add -= del;
  int q;
  cin >> q;
  while (q--) {
    ll a, b;
    cin >> a >> b;
    ll x = min(a, b), y = max(a, b);
    ll sum = x * add;
    if (y == x) {
      if (sum == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (sum % (y - x) == 0) {
        ll nd = sum / (y - x);
        if (nd <= del) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    }
  }
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