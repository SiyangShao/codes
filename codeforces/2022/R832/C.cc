#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> ans(n);
  for (auto &i : ans) {
    cin >> i;
  }
  ll mi1 = *min_element(ans.begin(), ans.end());
  if (mi1 == ans[0]) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}