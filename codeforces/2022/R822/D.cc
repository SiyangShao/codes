#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<ll> dpl(n + 1), dpr(n + 1);
  ll cnt = 0;
  for (ll i = 1; i <= n; ++i) {
    cnt += a[i];
    dpl[i] = min(cnt, a[i]);
  }
  cnt = 0;
  for (ll i = n; i >= 1; --i) {
    cnt += a[i];
    dpr[i] = min(cnt, a[i]);
  }
  ll L = k - 1, R = k + 1;
  if (L == 0 || R == n + 1) {
    cout << "YES\n";
    return;
  }
  if (a[k] < 0) {
    cout << "NO\n";
    return;
  }
  ll bs = a[k], mx = 0;
  ll cur_bs = a[k], cur_L = L;
  ll sum = 0;
  while (cur_L > 0 && bs + sum >= 0) {
    sum += a[cur_L];
    mx = max(mx, sum);
    cur_L--;
  }
  for (ll i = R; i <= n; ++i) {
    if (bs + mx + dpr[i] >= 0) {
      cout << "YES\n";
      return;
    }
    bs += a[i];
    if (bs + mx < 0) {
      break;
    }
    if (bs > cur_bs) {
      cur_bs = bs;
      while (cur_L > 0 && bs + sum >= 0) {
        sum += a[cur_L];
        mx = max(mx, sum);
        cur_L--;
      }
    }
  }
  bs = a[k], mx = 0;
  cur_bs = a[k];
  ll cur_R = R;
  sum = 0;
  while (cur_R <= n && bs + sum >= 0) {
    sum += a[cur_R];
    mx = max(mx, sum);
    cur_R++;
  }
  for (ll i = L; i > 0; --i) {
    if (bs + mx + dpl[i] >= 0) {
      cout << "YES\n";
      return;
    }
    bs += a[i];
    if (bs + mx < 0) {
      break;
    }
    if (bs > cur_bs) {
      cur_bs = bs;
      while (cur_R <= n && bs + sum >= 0) {
        sum += a[cur_R];
        mx = max(mx, sum);
        cur_R++;
      }
    }
  }
  cout << "NO\n";
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