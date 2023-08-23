#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<ll, ll>> pos(n);
  for (auto &[u, v] : pos) {
    cin >> u >> v;
    u *= 2, v *= 2;
  }
  sort(pos.begin(), pos.end());
  function<bool(ll)> judge = [&](ll x) {
    ll up = 0;
    ll mi = 0, mx = 0;
    for (auto &[_, i] : pos) {
      ll pre = mi;
      mx = max(mx, i);
      mi = min(mi, i);
      if ((up == 0 && mx - mi > x) || (up >= 1 && (mx - mi) > 2 * x)) {
        if (pre > mi) { // mi == i
          return false;
        }
        up++;
        mx = mi = i;
      }
    }
    if (up <= 2)
      return true;
    else
      return false;
  };
  ll L = 0, R = INF, ans = INF;
  if (pos[0].first == 0) {
    L = pos[0].second;
  }
  while (L <= R) {
    ll mid = (L + R) / 2;
    if (judge(mid)) {
      ans = min(ans, mid);
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  cout << ans / 2;
  if (ans % 2 == 1) {
    cout << ".5\n";
  } else {
    cout << ".0\n";
  }
}