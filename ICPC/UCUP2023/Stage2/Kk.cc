#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  std::vector c(n, std::vector<int>(k + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      std::cin >> c[i][j];
    }
    c[i][k] = 1E9 + 1;
  }

  std::vector<int> a(k + 1);
  for (int i = 0; i < k; i++) {
    std::cin >> a[i];
  }
  i64 ans = i64(1E9 + 1) * n;
  std::vector f(k + 1, std::vector(k + 1, std::set<std::pair<int, int>>{}));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      f[j][k].insert({c[i][j] - c[i][k], i});
    }
  }

  constexpr i64 inf = 1E18;
  for (int t = 0; t < n; t++) {
    std::vector<i64> d(k + 1, inf);
    std::queue<int> q;
    std::vector<bool> inq(k + 1);
    std::vector<int> lst(k + 1, -1);
    for (int i = 0; i < k; i++) {
      if (a[i] > 0) {
        q.push(i);
        inq[i] = true;
        d[i] = 0;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      inq[x] = false;

      for (int y = 0; y <= k; y++) {
        if (!f[x][y].empty()) {
          i64 v = d[x] + f[x][y].begin()->first;
          std::cout << x << " " << y << " "
                    << (1E9 + 1) + f[x][y].begin()->first << " " << d[x] << " "
                    << d[y] << "\n";
          if (v < d[y]) {
            d[y] = v;
            lst[y] = x;
            if (!inq[y]) {
              inq[y] = true;
              q.push(y);
            }
          }
        }
      }
    }
    std::cerr << (1E9 + 1) + d[k] << "\n";
    for (int i = 0; i <= k; ++i) {
      std::cout << d[i] << " ";
    }
    std::cout << "\n";
    ans += d[k];
    for (int i = k; lst[i] != -1; i = lst[i]) {
      int j = lst[i];
      int s = f[j][i].begin()->second;
      std::cout << "Before: " << s << " " << i << "\n";
      std::cout << "Now: " << s << " " << j << "\n";
      for (int x = 0; x <= k; x++) {
        if (x != i) {
          f[x][i].erase({c[s][x] - c[s][i], s});
        }
      }
      for (int x = 0; x <= k; x++) {
        if (x != j) {
          f[x][j].insert({c[s][x] - c[s][j], s});
        }
      }
      a[j]--;
      a[i]++;
    }
    for (int i = 0; i < k; ++i) {
      std::cout << a[i] << " \n"[i + 1 == k];
    }
    std::cout << "\n";
  }
  std::cout << ans << "\n";

  return 0;
}
