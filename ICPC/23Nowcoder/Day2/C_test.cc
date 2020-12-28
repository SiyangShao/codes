#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define chkmax(a, b) (a = max(a, b))

void solve() {
  ll n = 5;
  // cin >> n;
  vector<pair<ll, ll>> v;
  ll L = -1, R = -1;
  for (ll i = 1; i <= n; ++i) {
    while (L == R) {
      L = rand() % n, R = rand() % n;
    }
    v.emplace_back(L, R);
    // cout << L + 1 << " " << R + 1 << '\n';
    L = R = -1;
  }
  cout << n << " " << v.size() << "\n";
  for (auto [x, y] : v) {
    cout << x + 1 << " " << y + 1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  ll T = 1;
  // cin >> T;
  while (T--)
    solve();
  return 0;
}