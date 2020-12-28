#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<vector<ll>> vec(n);
  vector<ll> mex(n), semex(n);
  map<ll, vector<int>> fi, se;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    vec[i].resize(l);
    for (int j = 0; j < l; ++j) {
      cin >> vec[i][j];
    }
    sort(vec[i].begin(), vec[i].end());
    vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    bool flag = false;
    mex[i] = semex[i] = -1;
    for (int j = 0; j < (int)vec[i].size(); ++j) {
      if (!flag) {
        if (vec[i][j] != j) {
          mex[i] = j;
          flag = true;
        } else {
          continue;
        }
      }
      if (flag) {
        if (vec[i][j] != j + 1) {
          semex[i] = j + 1;
          break;
        }
      }
    }
    if (mex[i] == -1) {
      mex[i] = vec[i].back() + 1;
      semex[i] = mex[i] + 1;
    } else if (semex[i] == -1) {
      semex[i] = vec[i].back() + 1;
    }
    dbg(vec[i], mex[i], semex[i]);
    fi[mex[i]].emplace_back(i);
    se[semex[i]].emplace_back(i);
  }
  auto max_semex = *max_element(semex.begin(), semex.end());
  auto max_mex = *max_element(mex.begin(), mex.end());
  // all larger than max_mex and smaller than max_semex are discussable
  vector<ll> ans(max_semex + 1);
  for (int i = 0; i <= max_mex; ++i) {
    ans[i] = max_mex;
  }
  for (ll i = max_mex + 1; i <= max_semex; ++i) {
    ans[i] = i;
  }
  dbg(ans);
  vector<int> cnt(n);
  iota(cnt.begin(), cnt.end(), 0);
  sort(cnt.begin(), cnt.end(),
       [&](int i, int j) { return semex[i] > semex[j]; });
  dbg(cnt);
  vector<int> vis(n);
  function<bool(int)> check = [&](int i) {
    if (vis[i])
      return false;
    vis[i] = 1;
    assert(mex[i] <= semex[i]);
    assert(ans[mex[i]] <= ans[semex[i]]);
    ans[mex[i]] = max(ans[mex[i]], ans[semex[i]]);
    if (fi[mex[i]].size() >= 2) {
      for (int j = 0; j <= max_semex; ++j) {
        ans[j] = max(ans[j], ans[semex[i]]);
      }
      return true;
    }
    for (auto j : se[mex[i]]) {
      if (check(j))
        return true;
    }
    return false;
  };
  for (auto i : cnt) {
    if (check(i)) {
      break;
    }
  }
  ll sum = 0;
  for (ll i = 0; i <= min(m, max_semex); ++i) {
    sum += ans[i];
  }
  if (m > max_semex) {
    sum += (max_semex + 1 + m) * (m - max_semex) / 2;
  }
  cout << sum << "\n";
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