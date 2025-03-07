#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  vector<int> a_unq, b_unq;
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  for (auto i : a) {
    if (i > a[0])
      a_unq.push_back(i);
  }
  for (auto i : b) {
    if (i > a[0])
      b_unq.push_back(i);
  }
  sort(a_unq.begin(), a_unq.end());
  sort(b_unq.begin(), b_unq.end());
  vector<int> b_val(b_unq.size());
  for (int i = 0; i < (int)b_unq.size(); i++) {
    int win =
        (int)(a_unq.end() - lower_bound(a_unq.begin(), a_unq.end(), b_unq[i]));
    b_val[i] = win;
    if (i != 0) {
      assert(b_val[i] <= b_val[i - 1]);
    }
  }
  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i < m; i++) {
  //   cout << b[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i < (int)b_unq.size(); i++) {
  //   cout << b_unq[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i < (int)b_val.size(); i++) {
  //   cout << b_val[i] << " ";
  // }
  // cout << "\n";
  for (int k = 1; k <= m; k++) {
    ll ans = m / k;
    int not_take = m % k;
    for (int i = not_take; i < (int)b_unq.size(); i += k) {
      ans += b_val[i];
    }
    cout << ans << " ";
  }
  cout << "\n";
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
