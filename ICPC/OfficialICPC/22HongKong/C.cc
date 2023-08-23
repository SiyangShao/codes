#include <bits/stdc++.h>
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
auto cal(int n, int m) {
  vector mp(n, vector<int>(m));
  assert(n >= m);
  if (n == m) {
    vector<int> x(n);
    for (int i = 0; i < n / 2; ++i) {
      x[i] = 1;
    }
    set<vector<int>> st;

    for (int i = 0; i < n; ++i) {
      do {
        shuffle(x.begin(), x.end(), std::mt19937(std::random_device()()));
      } while (st.count(x));
      st.emplace(x);
      mp[i] = x;
    }
  } else {
    vector cur(m + 1, vector<int>(m, 0));
    set<vector<int>> st;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j < i)
          mp[i][j] = 1;
        else
          mp[i][j] = 0;
      }
      cur[i] = mp[i];
      st.emplace(cur[i]);
    }
    int u = 1;

    for (int i = m + 1; i < n; ++i) {
      if (i + 1 == n || u == m - u) {
        u = m / 2;
        auto x = cur[u];
        do {
          shuffle(x.begin(), x.end(), std::mt19937(std::random_device()()));
        } while (st.count(x));
        st.emplace(x);
        mp[i] = x;
      } else {
        next_permutation(cur[u].begin(), cur[u].end());
        if (st.count(cur[u])) {
          u++;
          i--;
        } else {
          mp[i] = cur[u];
          st.emplace(mp[i]);
          i++;
          mp[i] = cur[u];
          st.emplace(mp[i]);
          for (int j = 0; j < m; ++j) {
            mp[i][j] = 1 ^ mp[i][j];
          }
          reverse(mp[i].begin(), mp[i].end());
        }
      }
    }
  }
  return mp;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  if (n * m % 2 == 1) {
    cout << "NO\n";
    return;
  }
  int N = min(n, m), M = max(n, m);
  if ((N <= 10) && ((1 << N) < M)) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  bool flag = false;
  if (n < m) {
    swap(n, m);
    flag = true;
  }
  auto ans = cal(n, m);
  if (flag) {
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        cout << ans[i][j];
      }
      cout << "\n";
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j];
      }
      cout << "\n";
    }
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