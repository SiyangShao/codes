#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin>>n>>m;
  vector<int> a(m+1);
  vector<array<int, 2>> dp(m + 1, {-1, -1});
  for(int i = 1; i<=m; ++i){
    cin>>a[i];
  }
  vector<vector<pair<int,int>>> E(m + 1);
  vector<deque<pair<int, int>>> vec(n + 1);
  function<void(int)> update = [&](int u) {
    for (auto i : vec[a[u] + 1]) {
      // cout << u << " " << i.second << "\n";
      E[u].emplace_back(i);
    }
    // u can make points at a[u] larger
    if((int)vec[a[u]].size() >= 2){
      vec[a[u]].pop_back();
    }
    vec[a[u]].emplace_front(a[u] + 1, u);
    // u can make points at a[u] + 1 less
    if((int) vec[a[u]+1].size() >= 2){
      vec[a[u]+1].pop_back();
    }
    vec[a[u] + 1].emplace_front(a[u], u);
  };
  for(int i = m; i>=0; --i){
    update(i);
  }
  function<void(int, int)> dfs = [&](int u, int val) {
    dp[u][0] = val;
    for(auto [new_pos, v] : E[u]){
      dfs(v, new_pos);
    }
    if((int)E[u].size() == 1){
      dp[E[u][0].second][1] = val;
      dp[u][0] = dp[E[u][0].second][0];
    }else if((int) E[u].size() == 2){
      dp[u][0] = dp[E[u][0].second][0];
      dp[E[u][0].second][1] = dp[E[u][1].second][0];
      dp[E[u][1].second][1] = dp[E[u][0].first][0];
    }
  };
  dfs(0, 1);
  for (int i = 1; i <= m; ++i) {
    // cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    if(dp[i][1] == -1){
      cout << dp[0][0] << "\n";
    }else{
      cout << dp[i][1] << "\n";
    }
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