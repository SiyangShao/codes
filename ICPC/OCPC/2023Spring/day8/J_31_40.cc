
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array dx = {1, 1, -1, -1, 3, 3, -3, -3}, dy = {3, -3, 3, -3, 1, -1, 1, -1};
auto solve(int n) {
  vector<pair<int, int>> pos;
  vector<int> visx(n + 1, 0), visy(n + 1, 0);
  function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
    if (k == 0)
      return true;
    if (i < 1 || i > n || j < 1 || j > n)
      return false;
    if (visx[i] || visy[j])
      return false;
    visx[i] = visy[j] = 1;
    for (int stp = 0; stp < 8; ++stp) {
      int x = i + dx[stp], y = j + dy[stp];
      if (dfs(x, y, k - 1)) {
        pos.emplace_back(i, j);
        return true;
      }
    }
    visx[i] = visy[j] = 0;
    return false;
  };
  for(int i = 1; i<=n;++i){
    for(int j = 1;j<=n; ++j){
      auto ans = dfs(i, j, n);
      if(!ans){
        assert(true);
        fill(visx.begin(),visx.end(),0);
        fill(visy.begin(), visy.end(), 0);
      }else{
        cout<<"{";
        for(int k = 0 ; k < (int) pos.size(); ++k){
          if(k!=0) cout<<",";
          cout<<pos[k].first<<","<<pos[k].second;
        }
        cout<<"}";
        cout<<",";
        return;
      }
    }
  }

}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  for (int i = 51; i <= 55; ++i) {
    solve(i);
  }
  // cin >> ;
}