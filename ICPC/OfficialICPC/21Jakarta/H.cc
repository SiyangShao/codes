#include <bits/stdc++.h>
// #define ONLINE_JUDGE
// #ifndef ONLINE_JUDGE
// #include "dbg.h"
// #else
// #define dbg(...) (__VA_ARGS__)
// #endif
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  vector<int> num(26);
  for (auto &i : mp) {
    cin >> i;
    for (auto j : i) {
      if (j >= 'a' and j <= 'z') {
        num[j - 'a']++;
      }
    }
  }
  int sum = accumulate(num.begin(), num.end(), 0);
  pair<int, int> ans = {sum, sum};
  std::vector<int> bst(n * m + 1);
  std::vector<int> fa(n * m + 1);
  bst[0] = 1;
  for (int i = 0; i < 26; ++i) {
    if (num[i] != 0) {
      for (int j = n * m - num[i]; j >= 0; --j) {
        if (bst[j]) {
          bst[j + num[i]] = 1;
          fa[j + num[i]] = fa[j] | (1 << i);
        }
      }
    }
  }
  int x1 = 0, x2 = 0;
  // for (int i = 0; i <= sum; ++i) {
  //     std::cerr << i << ' ' << bst[i] << ' ' << fa[i] << '\n';
  // }
  for (int i = 0; i <= sum; ++i) {
    if (bst[i]) {
      auto now = std::make_pair(max(i, sum - i), min(i, sum - i));
      if (ans >= now) {
        ans = now;
        if (i > sum - i) {
          x1 = fa[i];
          x2 = ~fa[i];
        } else {
          x1 = ~fa[i];
          x2 = fa[i];
        }
      }
    }
  }
  x1 &= (1 << 26) - 1;
  x2 &= (1 << 26) - 1;
  // cerr << ans.first << " " << ans.second << "\n";
  // std::cerr << x1 << ' ' << x2 << '\n';
  int ans_sum = n * m * 4;
  int r = n * 2, c = m * 2;
  for (int i = n; i <= n * 2; ++i) {
    for (int j = m; j <= m * 2; ++j) {
      int sum = i * j;
      pair<int, int> cur = {(sum + 1) / 2, sum / 2};
      if (cur.first >= ans.first && cur.second >= ans.second && sum < ans_sum) {
        ans_sum = sum;
        r = i;
        c = j;
      }
    }
  }
  queue<char> Large, Small;
  for (int i = 0; i < 26; ++i) {
    if ((x1 >> i) & 1) {
      if (num[i] != 0) {
        Large.emplace(i + 'a');
      }
    } else {
      if (num[i] != 0) {
        Small.emplace(i + 'a');
      }
    }
  }
  cout << r << " " << c << "\n";
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i % 2 == j % 2) {
        if (!Large.empty()) {
          auto c = Large.front();
          cout << c;
          num[c - 'a']--;
          if (num[c - 'a'] == 0) {
            Large.pop();
          }
        } else {
          cout << ".";
        }
      } else {
        if (!Small.empty()) {
          auto c = Small.front();
          cout << c;
          num[c - 'a']--;
          if (num[c - 'a'] == 0) {
            Small.pop();
          }
        } else {
          cout << ".";
        }
      }
    }
    cout<<"\n";
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