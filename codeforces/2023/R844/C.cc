#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> num(26, 0);
  for (auto i : s) {
    num[i - 'a']++;
  }
  vector<int> ch(26);
  iota(ch.begin(), ch.end(), 0);
  sort(ch.begin(), ch.end(), [&](int x, int y) { return num[x] > num[y]; });
  vector<string> ans(26);
  constexpr int inf = 1e9;
  vector<int> id(26), modi(26, inf);
  iota(id.begin(), id.end(), 0);
  for (int i = 1; i <= 26; ++i) {
    // There has i characters finally
    if (n % i != 0) {
      continue;
    }
    modi[i - 1] = 0;
    int average = n / i;
    ans[i - 1] = s;
    vector<int> mp(26, 0);
    for (int j = 0; j < i; ++j) {
      mp[ch[j]] = num[ch[j]] - average;
    }
    for (int j = i; j < 26; ++j) {
      mp[ch[j]] = num[ch[j]];
    }

    vector<int> Lpos;
    vector<char> Rpos;
    for (int j = 0; j < 26; ++j) {
      if (mp[j] > 0) {
        modi[i - 1] += mp[j];
      } else if (mp[j] < 0) {
        for (int k = 0; k < abs(mp[j]); ++k) {
          Rpos.emplace_back(j + 'a');
        }
      }
    }
    assert(accumulate(mp.begin(), mp.end(), 0) == 0);
    for (int k = 0; k < n; ++k) {
      auto j = ans[i - 1][k];
      if (mp[j - 'a'] == 0)
        continue;
      else if (mp[j - 'a'] > 0) {
        mp[j - 'a']--;
        Lpos.emplace_back(k);
      } else {
        mp[j - 'a']++;
        // Lpos.emplace_back(k);
      }
    }
    int siz = (int)Lpos.size();
    assert(Lpos.size() == Rpos.size());
    for (int j = 0; j < siz; ++j) {
      ans[i - 1][Lpos[j]] = Rpos[j];
    }
  }
  sort(id.begin(), id.end(), [&](int x, int y) { return modi[x] < modi[y]; });
  cout << modi[id[0]] << "\n";
  cout << ans[id[0]] << "\n";
  // for(int i = 0 ; i < 26; ++i){
  //   if(modi[id[i]] >= inf) continue;
  //   auto ss = ans[id[i]];
  //   vector<int> mp(26, 0);
  //   for(auto j : ss){
  //     mp[j - 'a']++;
  //   }
  //   int mx = 0, mi = n;
  //   for(int j = 0 ; j <26; ++j){
  //     if(mp[j] == 0) continue;
  //     mx = max(mx, mp[j]);
  //     mi = min(mi, mp[j]);
  //   }
  //   assert(mx == mi);
  // }
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