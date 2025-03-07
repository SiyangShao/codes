#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  reverse(a.begin(), a.end());
  // if a[i] == i, we can add |a| - i 0s in the beginning
  map<ll, vector<ll>> ans;
  set<ll> vis;
  for (int i = 0; i < n; ++i) {
    // goal: a[i] == i + 1
    if (a[i] < i + 1) { 
      continue;
    }
    ll to_add = a[i] - i - 1;
    ll new_n = n + to_add;
    ll benefit = new_n - a[i];
    ans[new_n].emplace_back(benefit);
    // cerr << i << " " << a[i] << " " << new_n << ' ' << benefit << '\n';
  }
  vis.emplace(n);
  for (auto &[i, vec] : ans) {
    if (vis.contains(i))
      continue;
    for (auto nxt : vec) {
      vis.emplace(i + nxt);
    }
  }
  cout << *vis.rbegin() << '\n';
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
