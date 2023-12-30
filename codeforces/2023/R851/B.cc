#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cal_dig(int x){
  int ans = 0;
  while(x){
    ans += x%10;
    x/=10;
  }
  return ans;
}
pair<int,int> sol(int x){
  if(x % 2 == 0){
    return {x/2, x/2};
  }else{
    int y = x / 2;
    if(y % 10 == 9){
      assert(x % 10 == 9);
      x/=10;
      assert(x % 2 == 1);
      auto [l,r] = sol(x);
      if (cal_dig(l) < cal_dig(r))
        swap(l, r);
      return {l * 10 + 4, r * 10 + 5};
    }else{
      return {y, y + 1};
    }
  }
}
auto solve() {
  int n;
  cin >> n;
  auto [l,r] = sol(n);
  cout << l << " " << r << "\n";
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