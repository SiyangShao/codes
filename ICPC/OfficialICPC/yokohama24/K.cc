#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ll cnt = 0;
    for (auto j : s) {
      if (j == 'N')
        cnt = cnt * 2;
      else
        cnt = cnt * 2 + 1;
    }
    a[i] = cnt;
  }
  vector<pair<int, int>> dp((1LL << m), {-1, -1});
  for (int i = 0; i < n; i++) {
    auto contri = pair<int, int>{popcount<unsigned long long>(a[i]), -i};
    dp[a[i]] = max(dp[a[i]], contri);
  }
  for (ll i = (1LL << m) - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i & (1LL << j))
        continue;
      ll nxt = i | (1LL << j);
      dp[i] = max(dp[i], dp[nxt]);
    }
  }
  vector<int> all_one;
  auto ans = tuple<int, int, int>{-1, -1, -1};
  for (int i = 0; i < n; i++) {
    if (a[i] == (1LL << m) - 1) {
      // everyone is ok
      // just choose the one with the most 1s
      all_one.emplace_back(i);
      continue;
    }
    ll need = ((1LL << m) - 1) ^ a[i];
    if (dp[need].first == -1)
      continue;
    int x = min(i, -dp[need].second);
    int y = max(i, -dp[need].second);
    assert(x != y);
    auto result =
        tuple<int, int, int>{popcount<unsigned long long>(a[x] & a[y]), -x, -y};
    ans = max(ans, result);
  }
  if (all_one.size() > 1) {
    cout << all_one[0] + 1 << " " << all_one[1] + 1 << "\n";
    return;
  }
  auto [r, lef, rig] = ans;
  if (r == -1) {
    cout << "No\n";
    return;
  }
  lef = -lef;
  rig = -rig;
  cout << lef + 1 << " " << rig + 1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
