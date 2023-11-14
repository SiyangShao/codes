#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += abs(a[i] - a[i - 1]);
  }
  vector<ll> b(m);
  for (auto &i : b) {
    cin >> i;
  }
  for (int i = 1; i < m; ++i) {
    ans += abs(b[i] - b[i - 1]);
  }
  cout << ans << "\n";
}