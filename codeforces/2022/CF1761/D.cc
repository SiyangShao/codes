#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll qpow(ll a, ll b){
  ll res = 1;
  while(b){
    if(b&1){
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b>>=1;
  }
  return res;
}
auto solve() {
  vector<int> dif(5 + 1);
  for(int i = 0 ; i < qpow(2, 5); ++i){
    for(int j = 0; j < qpow(2, 5); ++j){
      int d = __builtin_popcount(i) + __builtin_popcount(j) -
              __builtin_popcount(i + j);
      dif[d]++;
    }
  }
  for(int i = 0 ; i <= 5; ++i){
    cout << dif[i] << " \n"[i == 5];
  }
  cout<<accumulate(dif.begin(), dif.end(), 0)<<"\n";
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
