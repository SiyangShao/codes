#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
struct DSU {
  int n;
  std::vector<int> fa;
  DSU(int _n) : n(_n), fa(_n) { std::iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> mp(n);
  for (auto &i : mp) {
    std::cin >> i;
  }
  auto work = [&]() {
    std::vector<int> min_r(n, m), max_r(n, -1), min_c(m, n), max_c(m, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == '#') {
          min_r[i] = std::min(min_r[i], j);
          max_r[i] = std::max(max_r[i], j);
          min_c[j] = std::min(min_c[j], i);
          max_c[j] = std::max(max_c[j], i);
        }
      }
    }
    dbg(min_r, max_r, min_c, max_c);
    std::function<void(int, int)> fill = [&](int x, int y) {
      mp[x][y] = '#';
      {
        int i = x, j = y;
        min_r[i] = std::min(min_r[i], j);
        max_r[i] = std::max(max_r[i], j);
        min_c[j] = std::min(min_c[j], i);
        max_c[j] = std::max(max_c[j], i);
      }
      for (int j = min_r[x]; j <= max_r[x]; ++j) {
        if (mp[x][j] == '.')
          fill(x, j);
      }
      for (int i = min_c[y]; i <= max_c[y]; ++i) {
        if (mp[i][y] == '.')
          fill(i, y);
      }
    };
    for (int i = 0; i < n; ++i) {
      for (int j = min_r[i]; j <= max_r[i]; ++j) {
        if (mp[i][j] == '.')
          fill(i, j);
      }
    }
    for (int j = 0; j < m; ++j) {
      for (int i = min_c[j]; i <= max_c[j]; ++i) {
        if (mp[i][j] == '.')
          fill(i, j);
      }
    }
  };
  work();
  dbg(mp);
  DSU dsu(n * m);
  auto cal = [&](int i, int j) { return i * m + j; };
  auto valid = [&](int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and mp[x][y] == '#';
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '#') {
        for (auto [dx, dy] : std::vector<std::pair<int, int>>{
                 {-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
          int x = i + dx, y = j + dy;
          if (valid(x, y)) {
            dsu.merge(cal(i, j), cal(x, y));
          }
        }
      }
    }
  }
  std::vector<std::pair<int, int>> offset;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '#' and dsu.find(cal(i, j)) == cal(i, j)) {
        offset.emplace_back(i, j);
      }
    }
  }

  auto output = [&]() {
    for (int i = 0; i < n; ++i) {
      std::cout << mp[i] << "\n";
    }
    std::cout << "\n";
  };
  if ((int)offset.size() == 1) {
    output();
    return;
  } else {
    assert((int)offset.size() == 2);
    auto [lx, ly] = offset[0];
    auto [rx, ry] = offset[1];
    dbg(lx, ly, rx, ry);
    if (ly < ry) {
      int la = lx, lb = ly, ra = rx, rb = ry;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (mp[i][j] == '#' && dsu.find(cal(i, j)) == dsu.find(cal(lx, ly))) {
            la = std::max(la, i);
            lb = std::max(lb, j);
          } else if (mp[i][j] == '#' &&
                     dsu.find(cal(i, j)) == dsu.find(cal(rx, ry))) {
            ra = std::min(ra, i);
            rb = std::min(rb, j);
          } else {
            assert(mp[i][j] == '.');
          }
        }
      }
      for (int i = lb; i <= rb; ++i) {
        mp[la][i] = '#';
      }
      for (int i = la; i <= ra; ++i) {
        mp[i][rb] = '#';
      }
    } else {
      int la = lx, lb = ly, ra = rx, rb = ry;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (mp[i][j] == '#' && dsu.find(cal(i, j)) == dsu.find(cal(lx, ly))) {
            la = std::max(la, i);
            lb = std::min(lb, j);
          } else if (mp[i][j] == '#' &&
                     dsu.find(cal(i, j)) == dsu.find(cal(rx, ry))) {
            ra = std::min(ra, i);
            rb = std::max(rb, j);
          } else {
            assert(mp[i][j] == '.');
          }
        }
      }
      for (int i = rb; i <= lb; ++i) {
        mp[la][i] = '#';
      }
      for (int i = la; i <= ra; ++i) {
        mp[i][rb] = '#';
      }
    }
    work();
    output();
  }
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  while (_--) {
    solve();
  }
}