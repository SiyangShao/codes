#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  // ll a, b, d;
  // cin >> a >> b >> d;
  for(ll i = 0 ;i  < 100; i+=5){
    ll cnt = i;
    while(cnt){
      if(cnt&1){
        cout<<"1";
      }else{
        cout<<"0";
      }
      cnt/=2;
    }
    cout<<"\n";
  }
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