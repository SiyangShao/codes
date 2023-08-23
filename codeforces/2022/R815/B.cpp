#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(auto &i:a){
    cin>>i;
  } 
  sort(a.begin(),a.end());
  cout<<a[n-1] + a[n-2] - a[0] - a[1]<<"\n";
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