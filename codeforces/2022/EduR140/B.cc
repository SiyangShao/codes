#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  ll x;
  cin >> x;
  vector<ll> b(n - 1);
  for (auto &i : b)
    cin >> i;
  sort(b.begin(), b.end());
  for (auto i : b) {
    if (i <= x)
      continue;
    ll dif = i - x;
    x += dif / 2;
    i -= dif / 2;
    if (x < i) {
      x++;
      i--;
    }
  }
  cout << x << "\n";
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
