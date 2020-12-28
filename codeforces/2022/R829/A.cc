#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<ll>> divide;
  vector<ll> cnt;
  ll dif = 0;
  for(auto &i: a){
    if(i == 0){
      cnt.emplace_back(i);
    }else{
      dif++;
      cnt.emplace_back(i);
      if(dif == 2){
        divide.emplace_back(cnt);
        cnt.clear();
        dif = 0;
      }
    }
  }
  if(dif != 0){
    cout<<"-1\n";
    return;
  }
  if (!cnt.empty())
    divide.emplace_back(cnt);
  vector<pair<ll,ll>> ans;
  ll pre = 0;
  for(auto &cur : divide){
    ll fi = -1, se = -1;
    for(ll i = 0 ; i < cur.size(); ++i){
      if(cur[i] != 0){
        if(fi!=-1){
          se = i;
          break;
        }else{
          fi = i;
        }
      }
    }
    if(fi == -1){
      // all zero
      ans.emplace_back(pre, pre + cur.size() - 1);
    }else{
      assert(fi != -1 && se != -1);
      if (cur[fi] == cur[se]) {
        if (fi % 2 != se % 2) {
          ans.emplace_back(pre, pre + cur.size() - 1);
        } else {
          if (fi % 2 == 0) {
            ans.emplace_back(pre, pre + fi);
          } else {
            ans.emplace_back(pre, pre);
            ans.emplace_back(pre + 1, pre + fi);
          }
          ans.emplace_back(pre + fi + 1, pre + cur.size() - 1);
        }
      } else {
        if (fi % 2 == se % 2) {
          ans.emplace_back(pre, pre + cur.size() - 1);
        } else {
          if (fi % 2 == 0) {
            ans.emplace_back(pre, pre + fi);
          } else {
            ans.emplace_back(pre, pre);
            ans.emplace_back(pre + 1, pre + fi);
          }
          ans.emplace_back(pre + fi + 1, pre + cur.size() - 1);
        }
      }
    }
    pre += (ll)cur.size();
  }
  cout << ans.size() << "\n";
  for(auto &[l, r]: ans){
    cout << l + 1 << " " << r + 1 << "\n";
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