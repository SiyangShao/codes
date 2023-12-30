#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using ll = long long;
ll get_digit(ll x) {
  ll ret = 0;
  while (x) {
    x /= 10;
    ret++;
  }
  return ret;
}
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) {
      ret *= a;
    }
    a *= a;
    b >>= 1;
  }
  return ret;
}
ll cal(ll x){
  ll mx = 0, mi = 9;
  while(x){
    mx = max(mx, x%10);
    mi = min(mi, x%10);
    x/=10;
  }
  return mx - mi;
}
ll get_ith_digit(ll x, ll i) {
  ll ret = 0;
  while (i--) {
    ret = x % 10;
    x /= 10;
  }
  return ret;
}
auto solve() {
  ll l, r;
  cin >> l >> r;
  if (get_digit(r) != get_digit(l)) {
    for (int i = 0; i < get_digit(l); ++i) {
      cout << 9;
    }
    cout << "\n";
    return;
  }
  ll dig = get_digit(l);
  if (get_ith_digit(l, dig) + 2 <= get_ith_digit(r, dig)) {
    for(ll j = 0;  j < dig;++j){
      cout << get_ith_digit(l, dig) + 1;
    }
    cout<<"\n";
  }else{
    ll L = get_ith_digit(l, dig), R = get_ith_digit(r, dig);
    if(L == R){

    }else{
      // L case
      bool flag = false;
      ll ans = 0;
      for(ll i = dig-1; i>=1; --i){
        if(flag || get_ith_digit(l, i)<= L){
          ans = ans * 10 + L;
          flag = true;
        }else{
          ans = ans * 10 + get_ith_digit(l, i);
          L = get_ith_digit(l, i);
        }
      }
      dbg(ans);
      ll valx = ans + qpow(10, dig-1) * get_ith_digit(l, dig);
      pair<ll,ll> x = {cal(valx), valx};
      flag = false;
      ans = 0; 
      for(ll i = dig-1; i>=1; --i){
        if(flag || get_ith_digit(r,i) >= R){
          ans = ans * 10 + R;
          flag = true;;
        }else{
          ans = ans * 10 + get_ith_digit(r, i);
          R = get_ith_digit(r, i);
        }
      }
      dbg(ans);
      ll valy = ans + qpow(10, dig-1) * get_ith_digit(r, dig);
      
      cout << min(x, y).second << "\n";
    }
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