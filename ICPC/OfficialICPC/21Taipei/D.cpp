#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

const ll Amx = 65535;
ll dp[Amx + 2][202];
ll a[18];

/*
  - dp[msk][k] := the largest permutation using only msk digits, with remainder k.
    dp[msk][k] --> dp[msk ^ (1ll << notbit)][(k * 10 + newNum) % k]

*/

void solve() {
  ll d, k; cin >> d >> k;
  ll A = (1ll << d) - 1;
  FOR(i, 1, d) cin >> a[i];

  queue<pair<ll, ll>> q; // there are only 2**16 (msk, k) state pairs.
  FOR(i, 1, d) chkmax(dp[1ll << (i - 1)][a[i] % k], a[i]), q.emplace((1ll << (i - 1)), a[i] % k);
  while (!q.empty()) {
    auto [msk, tk] = q.front(); q.pop();
    FOR(nb, 1, d) {
      ll nbase = 1ll << (nb - 1); 
      if ((nbase & msk) != 0) continue;
      else {
        chkmax(dp[msk ^ nbase][(tk * 10 + a[nb]) % k], dp[msk][tk] * 10 + a[nb]);
        q.emplace((msk ^ nbase), (tk * 10 + a[nb]) % k);
      }
    } 
  }
  for (ll rem = k - 1; rem >= 0; rem--) if (to_string(dp[A][rem]).size() == d) {
    cout << dp[A][rem] << endl;
    return;
  }
  assert(false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
