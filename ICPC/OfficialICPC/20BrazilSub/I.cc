#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)

ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}

vector<ll> g[100005];
ll dp[100005][2];
const ll P = 1'000'000'007;
void dfs(ll o, ll p = -1) {
  ll prod = 1; ll nZero = 0, prodWithoutZero = 1;
  for (auto e: g[o]) if (e != p) {
    dfs(e, o);
    ll add = (dp[e][0] + dp[e][1]) % P;
    prod = (prod * add) % P;
    if (add != 0) prodWithoutZero = prodWithoutZero * add % P;
    else nZero++;
  } 
  if (g[o].size() == 1 && o != 1) dp[o][0] = 0, dp[o][1] = 1;
  else {
    dp[o][0] = prod;
    dp[o][1] = 0; // just in case
    for (auto e: g[o]) if (e != p) {
      ll invProd = 0, tsum = (dp[e][0] + dp[e][1]) % P;
      if (tsum != 0) invProd = prod * inv(tsum, P) % P;
      else {
        assert(nZero >= 1); 
        if (nZero == 1) invProd = prodWithoutZero;
        else invProd = 0; 
      }
      dp[o][1] = (dp[o][1] + invProd * dp[e][1] % P) % P;
    }
  }
}

int main() {
  ll n; cin >> n;
  FOR(i, 1, n - 1) {
    ll t; cin >> t;
    g[t].emplace_back(i + 1), g[i + 1].emplace_back(t);
  }
  FOR(i, 1, n) FOR(t, 0, 1) dp[i][t] = 0; // cannot
  FOR(i, 2, n) if (g[i].size() == 1) dp[i][1] = 1;

  dfs(1); 
  cout << (dp[1][0] + dp[1][1]) % P << endl;
}