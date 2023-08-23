#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

const ll Amx = 65535;
ll dp[Amx + 2][202];
ll a[18];
ll bs[201];
/*
  - dp[msk][k] := the largest permutation using only msk digits, with remainder k.
    dp[msk][k] --> dp[msk ^ (1ll << notbit)][(k * 10 + newNum) % k]

*/

void solve() {
  ll d, k; cin >> d >> k;
  for(ll i = 0; i <=k; ++i){
    bs[i] = i * 10 % k;
    // cout<<bs[i]<<" ";
  }
  // cout<<"\n";
  function<ll(ll,ll)> add = [&](ll a, ll b){
    a = bs[a];
    if(a + b >= k){
      return a + b - k;
    }
    return a+b;
  };
  ll A = (1ll << d) - 1;
  FOR(i, 1, d) cin >> a[i];
  if(k == 1){
    sort(a+1, a+d+1, greater<>());
    for(ll i = 1; i <= d; ++i){
      cout<<a[i];
    }
    return;
  }
  vector< vector<ll>> hamming(20);
  FOR(i, 0, A) hamming[__builtin_popcountll(i)].emplace_back(i);
  FOR(i, 1, d) chkmax(dp[1ll << (i - 1)][a[i] % k], a[i]);
  FOR(ham, 1, d - 1) for (auto msk: hamming[ham]) FOR(tk, 0, k - 1) FOR(nb, 1, d) {
    ll nbase = 1ll << (nb - 1); 
    if ((nbase & msk) != 0) continue;
    else {
      chkmax(dp[msk ^ nbase][add(tk, a[nb])], dp[msk][tk] * 10 + a[nb]);
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
