#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll k = accumulate(s.begin(), s.end(), 0) - '0' * n;
  for (ll x = 1LL << k; x <= (1LL << n) - (1LL << (n - k)) + 1; ++x) {
    cout << x << " ";
  }
  cout << "\n";
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
