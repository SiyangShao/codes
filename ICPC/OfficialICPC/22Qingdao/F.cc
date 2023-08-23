#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1024;
using bst = bitset<N>;
void impossible() { cout << "Impossible\n"; }
auto solve() {
  int n, k;
  cin >> n >> k;
  int tmp = n, cnt = 0;
  while (tmp % 2 == 0) {
    tmp /= 2;
    cnt++;
  }
  int real_n = 1 << cnt;
  if (k >= real_n) {
    impossible();
    return;
  }
  vector<bst> cur(n);
  for (int i = 0; i < n; ++i) {
    cur[i].set();
    cur[i][i] = false;
    if (i % 2 == 0) {
      cur[i][i + 1] = false;
      cout << (i + 1) + 1;
    } else {
      cur[i][i - 1] = false;
      cout << (i + 1) - 1;
    }
    if (i + 1 == n) {
      cout << "\n";
    } else {
      cout << " ";
    }
  }
  for (int i = 0; i < k - 1; ++i) {
    bst mex;
    mex.set();
    vector<int> mp(n, -1);
    for (int j = 0; j < n; ++j) {
      if (mex[j]) {
        mex[j] = false;
        bst can = mex & cur[j];
        int pos = (int)can._Find_first();
        mex[pos] = false;
        cur[j][pos] = cur[pos][j] = false;
        mp[j] = pos;
        mp[pos] = j;
      }
    }
    for (int j = 0; j < n; ++j) {
      assert(mp[j] != -1 && mp[mp[j]] == j);
      cout << mp[j] + 1 << " \n"[j + 1 == n];
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << " \n"[i == n];
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