#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, int>> a(n);
  vector<ll> b(n), val(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }
  sort(a.begin(), a.end());
  vector<ll> coup(n);
  for (int i = 0; i < m; ++i) {
    int id;
    cin >> id;
    ll w;
    cin >> w;
    coup[id - 1] += w;
  }
  for (int i = n - 2; i >= 0; --i) {
    coup[i] += coup[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    if (i == 0)
      val[i] = b[i] - coup[i];
    else
      val[i] = min(val[i - 1], b[i] - coup[i]);
  }
  ll sum = 0;
  int id = n;
  for (int i = 0; i < n; ++i) {
    ll cur = sum + a[i].first;
    id = min(id, a[i].second);
    if (id == 0) {
      cout << cur - coup[id] << " ";
    } else
      cout << min(cur - coup[id], sum + val[id - 1]) << " ";
    sum = cur;
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}