#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int x,y,n;
  cin >> x >> y >> n;
  int num = n/(x+y);
  int rec = n%(x+y);
  if(rec > x) rec = x;
  cout << (num*x + rec)*3 << "\n";

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