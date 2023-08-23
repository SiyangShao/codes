#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  map<pair<ll,ll>, ll> mp;
  mp.clear();
  ll mod1 = 0, mod2= 0 ;
  ll ans = 0;
  for(auto &i: a){
    cin>>i;
    if(i%3==1){
      mod1++;
    }else if(i%3==2){
      mod2++;
    }
    mod1%=3, mod2%=3;
    mp[{mod1, mod2}]++;
    ans += mp[{mod1, mod2}];
    ans += mp[{mod1, (mod2 - 1 + 3)%3}];
    ans += mp[{(mod1 - 1 + 3)%3 , mod2}];
  }
  cout<<ans<<"\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}