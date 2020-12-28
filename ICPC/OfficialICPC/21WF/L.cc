#include <bits/stdc++.h>
using namespace std;
int cal_dis(int i, int j, int x, int y) {
  if (i == x && j == y)
    return 0;
  int len = max(abs(i - x), abs(j - y));
  len = len * 2 - 1;
  int base = len * len - 1;
  // cout << base << " ";
  len = max(abs(i - x), abs(j - y));
  // cout << len << " ";
  int edge = len * 2;
  if (x == i - len && y >= j - len + 1 && y <= j + len) {
    return base + (y - (j - len));
  }
  if (x == i + len && y >= j - len && y <= j + len - 1) {
    return base + edge * 2 + (j + len - y);
  }
  if (y == j + len && x >= i - len + 1 && x <= i + len) {
    return base + edge + (x - (i - len));
  }
  if (y == j - len && x >= i - len && x <= i + len - 1) {
    return base + edge * 3 + (i + len - x);
  }
  assert(false);
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // for (int i = -3; i <= 3; ++i) {
  //   for (int j = -3; j <= 3; ++j) {
  //     cout << cal_dis(0, 0, i, j) << " ";
  //   }
  //   cout << "\n";
  // }
  int n, m;
  cin >> m >> n;
  vector<string> mp(n);
  for (auto &i : mp)
    cin >> i;
  vector<pair<int, int>> cross;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == 'X') {
        cross.emplace_back(i, j);
      }
    }
  }
  vector<vector<vector<int>>> E(n, vector<vector<int>>(m));
  vector<vector<int>> Same(n, vector<int>(m, -1));
  vector<pair<int, int>> process;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      process.emplace_back(i, j);
      vector<int> tmp;
      tmp.reserve(cross.size());
      for (auto [x, y] : cross) {
        tmp.emplace_back(cal_dis(i, j, x, y));
      }
      // tmp.emplace_back(-1);
      ranges::sort(tmp);
      E[i][j] = tmp;
      // for (auto i : tmp)
      //   cout << i << " ";
      // cout << "\n";
    }
  }
  sort(process.begin(), process.end(), [&](auto a, auto b) {
    return E[a.first][a.second] < E[b.first][b.second];
  });
  for (int i = 0; i + 1 < (int)process.size(); ++i) {
    auto [ax, ay] = process[i];
    auto [bx, by] = process[i + 1];
    // check their same prefix
    for (int j = 0; j < (int)cross.size(); ++j) {
      if (E[ax][ay][j] != E[bx][by][j]) {
        Same[ax][ay] = max(Same[ax][ay], min(E[ax][ay][j], E[bx][by][j]) - 1);
        Same[bx][by] = max(Same[bx][by], min(E[ax][ay][j], E[bx][by][j]) - 1);
        break;
      }
    }
  }
  double average = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // cout << Same[i][j] + 1 << " ";
      average += Same[i][j] + 1;
      cnt = max(cnt, Same[i][j] + 1);
    }
    // cout << "\n";
  }
  average /= (double)(n * m);
  cout << fixed << setprecision(10) << average << "\n";
  cout << cnt << "\n";
  vector<pair<int, int>> node;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (Same[i][j] + 1 == cnt)
        node.emplace_back(j + 1, n - i);
    }
  }
  ranges::sort(node, [&](auto a, auto b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
  });
  for (auto &[x, y] : node)
    cout << "(" << x << "," << y << ") ";
  cout << "\n";
}