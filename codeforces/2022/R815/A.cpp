#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll l = a*d, r = b*c;
  if(l == r){
    cout<<"0\n";
    return;
  } 
  if(l==0 || r== 0 || l%r == 0 || r%l == 0){
    cout<<"1\n";
  }else{
    cout<<"2\n";
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