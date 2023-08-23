#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, x;
  cin >> n >> x;
  auto get_bit = [&](ll y, ll i) { return ll((y >> i) & 1); };
  for (ll i = 60; i >= 0; --i) {
    if (((n >> i) & 1) == ((x >> i) & 1)) {
      continue;
    } else {
      if ((n >> i) & 1) {
        for (ll j = i; j >= 0; --j) {
          if ((x >> j) & 1) {
            cout << "-1\n";
            return;
          }
        }
        if(get_bit(n, i+1)){
          assert(get_bit(x, i+1));
          cout<<"-1\n";
          return;
        }
        for(ll j = i;j>=0;--j){
          if(get_bit(n, j)){
            n -= 1LL<<j;
          }
        }
        n += 1LL<<(i+1);
        cout<<n<<"\n";
        return;
      } else {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << n << "\n";
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
