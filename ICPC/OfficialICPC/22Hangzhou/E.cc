#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> mp(2 * n - 1);
  for (auto &i : mp) {
    cin >> i;
  }
  auto ans = mp;
  auto dis = [&](int i, int j) {
    int d = min(i, j);
    int d2 = min(n * 2 - 2 - i, m * 2 - j - 2);
    return min(d, d2);
  };
  vector<vector<int>> x(100), y(100), val(100);
  for (int i = 0; i < n * 2 - 1; ++i) {
    for (int j = 0; j < m * 2 - 1; ++j) {
      if (dis(i, j) % 2 == 1) {
        ans[i][j] = '#';
      } else if (mp[i][j] != '.') {
        x[dis(i, j) / 2].emplace_back(i);
        y[dis(i, j) / 2].emplace_back(j);
        if (mp[i][j] == '7' || mp[i][j] == '8') {
          mp[i][j]++;
        }
        val[dis(i, j) / 2].emplace_back((mp[i][j] - '0') % 2);
      }
    }
  }
  auto between = [&](int x1, int y1, int x2, int y2) {
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    assert((x1 == x2 && abs(y1 - y2) == 2) || (y1 == y2 && abs(x1 - x2) == 2));
    if (x1 == x2) {
      return pair<int, int>{x1, (y1 + y2) / 2};
    } else {
      return pair<int, int>{(x1 + x2) / 2, y1};
    }
  };
  for (int ii = 0; ii < 100; ++ii) {
    if (x[ii].empty())
      continue;
    int sz = (int)x[ii].size();
    vector<int> id(sz);
    iota(id.begin(), id.end(), 0);
    auto nxt = [&](int j) { return (j + 1) % sz; };
    auto pre = [&](int j) { return (j - 1 + sz) % sz; };
    vector<int> gap(sz, -1);
    // 顺
    bool flag = true;
    for (int j = 0; j < sz; ++j) {
      if (val[i][j]) {
        if (gap[j] == 0 || gap[pre(j)] == 0) {
          flag = false;
          break;
        }
        gap[pre(j)] = gap[j] = 1;
      } else {
        if (j == pre(j)) {
          flag = false;
          break;
        }
        if (gap[j] == 1 && gap[pre(j)] == 1) {
          flag = false;
          break;
        }
        if (gap[pre(j)] == 0 && gap[j] == 0) {
          flag = false;
          break;
        }
        if (gap[pre(j)] == -1) {
          assert(gap[j] == -1);
          gap[pre(j)] = 1, gap[j] = 0;
        } else {
          if (gap[pre(j)] == 0) {
            gap[j] = 1;
          } else {
            gap[j] = 0;
          }
        }
      }
    }
    if (!flag) {
      fill(gap.begin(), gap.end(), -1);
      for (int j = 0; j < sz; ++j) {
        if (val[i][j]) {
          if (gap[j] == 0 || gap[pre(j)] == 0) {
            flag = false;
            break;
          }
          gap[pre(j)] = gap[j] = 1;
        } else {
          if (j == pre(j)) {
            flag = false;
            break;
          }
          if (gap[j] == 1 && gap[pre(j)] == 1) {
            flag = false;
            break;
          }
          if (gap[pre(j)] == 0 && gap[j] == 0) {
            flag = false;
            break;
          }
          if (gap[pre(j)] == -1) {
            assert(gap[j] == -1);
            gap[pre(j)] = 0, gap[j] = 1;
          } else {
            if (gap[pre(j)] == 0) {
              gap[j] = 1;
            } else {
              gap[j] = 0;
            }
          }
        }
      }
    }
    if (flag) {
      for (int j = 0; j < sz; ++j) {
        int x1 = x[i][j], y1 = y[i][j];
        int x2 = x[i][nxt(j)], y2 = y[i][nxt(j)];
        int vv = gap[j];
        auto [u, v] = between(x1, y1, x2, y2);
        ans[u][v] = (vv ? '#' : '.');
      }
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (auto &i : ans) {
    cout << i << "\n";
  }
}