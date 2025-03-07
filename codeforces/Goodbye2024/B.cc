#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> l(n), r(n);
  vector<ll> unq;
  map<ll, ll> cnt;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    if (l[i] == r[i]) {
      unq.emplace_back(l[i]);
      cnt[l[i]]++;
    }
  }
  sort(unq.begin(), unq.end());
  unq.erase(unique(unq.begin(), unq.end()), unq.end());
  for (int i = 0; i < n; i++) {
    if (l[i] == r[i]) {
      if (cnt[l[i]] == 1) {
        cout << "1";
      } else {
        cout << "0";
      }
    } else {
      // only if all l[i] to r[i] are unq
      if (unq.empty()) {
        cout << "1";
        continue;
      }
      auto lef = lower_bound(unq.begin(), unq.end(), l[i]);
      auto rig = lower_bound(unq.begin(), unq.end(), r[i]);
      if (lef != unq.end() && *lef == l[i] && rig != unq.end() &&
          *rig == r[i] && (rig - lef) == (*rig - *lef)) {
        cout << "0";
      } else {
        cout << "1";
      }
    }
  }
  cout << "\n";
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
