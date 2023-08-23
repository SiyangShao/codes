#include <bits/stdc++.h>
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve2(int n, int k, vector<pair<int,int>>& edg, vector<ll>& w) {
  vector<vector<int>> E(n);

  // vector<ll> w(n - 1);
  // int cnt = 0;
  // for(auto &[u,v] : edg){
  //   cin >> u >> v;
  //   u--, v--;
  //   cin >> w[cnt++];
  // }
  for(int i = 0; i < n-1; ++i){
    auto [u,v] = edg[i];
    E[u].emplace_back(i);
    E[v].emplace_back(i);
  }
  
  vector<pair<ll,int>> dp(n);
  using node = tuple<ll,int,int>;
  node ans = {-1, -1, -1};
  function<void(int, int)> dfs = [&](int u, int fa) {
    pair<ll,int> fi, se;
    fi = se = dp[u] = {0, u};
    for(auto id : E[u]){
      auto [x, y] = edg[id];
      int v = x ^ y ^ u;
      if(v == fa)
        continue;
      dfs(v, u);
      pair<ll,int> cur = {dp[v].first + w[id], dp[v].second};
      if(fi < cur){
        se = fi;
        fi = cur;
      }else if(se < cur){
        se = cur;
      }
    }
    dp[u] = fi;
    tuple<ll,int,int> cur;
    cur = {fi.first + se.first, fi.second, se.second};
    ans = max(ans, cur);
  };
  dfs(0, 0);
  dbg(dp);
  auto [len, l, r] = ans;
  // cout << len << " " << l << " " << r << "\n";
  vector<int> pa(n, -1);
  vector<ll> pa_len(n,-1);
  function<void(int,int)> tree_build = [&](int u, int fa){
    dp[u] = {0, u};
    pa[u] = fa;
    for(auto id: E[u]){
      auto [x,y] = edg[id];
      int v= x^y^u;
      if (v == fa)
        continue;
      pa_len[v] = w[id];
      tree_build(v, u);
      pair<ll,int> cur = {dp[v].first + w[id], dp[v].second};
      dp[u] = max(dp[u], cur);
    }
  };
  tree_build(l, l);
  vector<int> vis(n,0);
  vis[l] = 1;
  while(r!=l){
    vis[r] = 1;
    r = pa[r];
  }
  dbg(vis);
  set<tuple<ll, int, int>> st;
  for(int i = 0 ; i < n; ++i){
    if(!vis[i] && vis[pa[i]]){
      dbg(i);
      st.emplace(pa_len[i] + dp[i].first, i, dp[i].second);
    }
  }
  function<void(int)> upd = [&](int i){
    for(auto id: E[i]){
      auto [x,y] = edg[id];
      int j = x ^ y ^ i;
      if(vis[j] || j == pa[i]) continue;
      st.emplace(pa_len[j] + dp[j].first, j, dp[j].second);
    }
  };
  while(k--){
    if(st.empty()){
      cout<<len<<" ";
      continue;
    }
    auto [add, u, v] = *st.rbegin();
    st.erase(prev(st.end()));
    len += add;
    while(v!=u){
      vis[v] = 1;
      upd(v);
      v = pa[v];
    }
    vis[u] = 1;
    upd(u);
    cout<<len<<" ";
  }
  cout << "\n";
}
// auto main() -> int {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr), cout.tie(nullptr);
//   int _ = 1;
//   // cin >> _;
//   while (_--) {
//     solve();
//   }
// }
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<set<int>> E(n);
  vector<pair<int,int>> edg(n-1);
  vector<ll> w(n - 1);
  int cnt = 0;
  for(auto &[u,v] : edg){
    cin >> u >> v;
    u--, v--;
    cin >> w[cnt++];
  }
  for(int i = 0; i < n-1; ++i){
    auto [u,v] = edg[i];
    E[u].emplace(i);
    E[v].emplace(i);
  }
  vector<pair<ll, int>> dp(n);
  pair<ll, pair<int, int>> len = {-1, {-1, -1}};
  function<void(int, int)> cal_len = [&](int u, int fa_id) {
    dp[u] = {0, u};
    pair<ll,int> fi, se;
    fi = se = dp[u];
    for(auto id : E[u]){
      if(id == fa_id){
        continue;
      }
      auto [x,y] = edg[id];
      int v = x ^ y ^ u;
      cal_len(v, id);
      pair<ll,int> cur = {dp[v].first + w[id], dp[v].second};
      dp[u] = max(dp[u], cur);
      if(cur > fi){
        se = fi;
        fi = cur;
      }else if(cur > se){
        se = cur;
      }
    }
    len = max(len, {fi.first + se.first, {fi.second, se.second}});
  };
  auto sol = [&](){
    tuple<ll, int, int, int ,int, int> ans;
    ans = {-1, 0, 0, 0, 0, 0};
    len = {-1, {-1, -1}};
    for (int id = 0; id < n - 1; ++id) {
      auto [u, v] = edg[id];
      len = {-1,{-1,-1}};
      cal_len(u, id);
      auto len1 = len;
      len = {-1,{-1,-1}};
      cal_len(v,id);
      auto len2 = len;
      auto cur =
          tuple<ll, int, int, int, int, int>{len1.first + len2.first + w[id],
                                                  len1.second.first,
                                                  len1.second.second,
                                                  len2.second.first,
                                                  len2.second.second,
                                                  id};
      ans = max(ans, cur);
    }
    auto [l, a, b, c, d, id] = ans;
    cout << l << " ";
    auto [u,v] = edg[id];
    E[u].erase(id), E[v].erase(id);
    E[b].emplace(id), E[c].emplace(id);
    edg[id] = {b, c};
  };
  cal_len(0,-1);
  cout << get<0>(len) << " ";
  if (k >= 1) {
    sol();
  } 
  if (k > 1) {
    solve2(n, k - 1, edg, w);
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