#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m), pre(n);
  for (auto &i : a)
    cin >> i;
  pre[0] = a[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  for (auto &i : b)
    cin >> i;
  vector<ll> rea, reb;
  for (int i = n - 1; i >= 0; --i) {
    if (rea.empty() || a[i] > a[rea.back()]) {
      rea.push_back(i);
    }
  }
  for (int i = m - 1; i >= 0; --i) {
    if (reb.empty() || b[i] > b[reb.back()]) {
      reb.push_back(i);
    }
  }
  reverse(rea.begin(), rea.end());
  reverse(reb.begin(), reb.end());
  ll sum = 0;
  for (int i = 0; i < (int)rea.size(); i++) {
    auto id = rea[i];
    auto pre = i == 0 ? -1 : rea[i - 1];
    auto len = id - pre;
    auto val = a[id];
    // binary search first element in reb >= val
    if (b[0] < val) {
      cout << "-1\n";
      return;
    }
    int l = 0, r = (int)reb.size() - 1;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (b[reb[mid]] >= val) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    auto cost = m - reb[ans] - 1;
    sum += cost * len;
  }
  cout << sum << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
