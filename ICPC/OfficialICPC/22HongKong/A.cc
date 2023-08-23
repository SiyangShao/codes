#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(){
  int n;
  cin>>n;
  vector<int> p(n);
  for(auto &i: p) cin>>i;
  vector<vector<int>> E(n);
  int rt = -1;
  for(int i = 0 ; i < n; ++i){
    p[i]--;
    if(p[i] == -1){
      rt = i;
    }else{
      E[p[i]].emplace_back(i);
    }
  }
  vector<int> dp(n);
  function<void(int)> dfs = [&](int u) {
    dp[u] = 1;
    vector<int> tmp;
    for(auto v: E[u]){
      dfs(v);
      tmp.emplace_back(dp[v]);
    }
    if(!tmp.empty()){
      sort(tmp.begin(), tmp.end(), greater<>());
      dp[u] = tmp[0] - 1;
      for(int i = 1; i < (int) E[u].size(); ++i){
        dp[u] = max(dp[u], tmp[i]);
      }
      dp[u]++;
    }
  };
  dfs(rt);
  cout << dp[rt] << "\n";
}
auto main()->int{
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin>>_;
  while(_--){
    solve();
  }
}