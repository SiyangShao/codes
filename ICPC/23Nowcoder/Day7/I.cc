#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll p = 998244353;
ll fpm(ll a, ll n) {
  if (a == 0)
    return 0ll;
  if (n == 0)
    return 1ll;

  ll ans = fpm(a, n / 2);
  ans = (ans * ans) % p;
  if (n % 2 == 1)
    ans = (ans * a) % p;
  return ans;
}
int main() {
  ll n2;
  cin >> n2;
  map<ll, vector<string>> s;
  for (ll i = 0; i < n2; ++i) {
    string t;
    cin >> t;
    s[t.length()].emplace_back(t);
  }
  ll ret = 0;
  for (auto &[u, v] : s) {
    ll strNum = v.size(), slen = u;
    if (strNum <= 20) {
      vector<ll> by_cnt(strNum + 1);
      for (ll msk = 0; msk < (1ll << strNum); msk++) {
        ll cnt = __builtin_popcountll(msk);
        string cur = "";
        bool gg = false;
        for (ll i = 0; i < slen; ++i)
          cur += '?';
        for (ll idx = 0; idx < strNum; ++idx)
          if (msk & (1ll << idx)) { // match idx th string
            for (ll t = 0; t < slen; ++t) {
              if (cur[t] == '?') {
                if (v[idx][t] == '?')
                  continue;
                else
                  cur[t] = v[idx][t];
              } else {
                if (v[idx][t] == '?')
                  continue;
                else if (v[idx][t] == cur[t])
                  continue;
                else {
                  gg = true;
                  break;
                }
              }
            }
            if (gg)
              break;
          }
        if (gg)
          continue;
        ll nQn = 0;
        for (ll t = 0; t < slen; ++t)
          if (cur[t] == '?')
            nQn++;
        by_cnt[cnt] = (by_cnt[cnt] + fpm(2, nQn)) % p;
      }
      ll ans = 0;
      for (ll i = 1; i <= strNum; ++i) {
        ll mod = (i % 2 == 1) ? 1 : -1;
        ans = (ans + mod * by_cnt[i]) % p;
      }
      ret = (ret + ans) % p;
    } else {
      for (ll x = 0; x < (1ll << slen); ++x) {
        ll cntMatch = 0;
        for (ll tS = 0; tS < strNum; ++tS) { // check x matches v[tS]
          bool gg = false;
          for (ll i = 0; i < slen; ++i)
            if (v[tS][i] != '?') {
              ll xi = (x & (1ll << i)) != 0;
              if (v[tS][i] - '0' != xi)
                gg = true;
            }
          if (!gg)
            cntMatch++;
        }
        if (cntMatch)
          ret = (ret + 1) % p;
      }
    }
  }
  cout << (ret % p + p) % p << endl;
}