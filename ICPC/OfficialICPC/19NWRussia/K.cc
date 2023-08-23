#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  // int dp[n][m];

  vector<tuple<char, ll, ll>> locations;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A')
        locations.emplace_back(a[i][j], i, j);
    }
  }
  auto paint = [&](ll u, ll d, ll l, ll r, char c) {
    for (ll i = u; i < d; ++i) {
      for (ll j = l; j < r; ++j) {
        if (a[i][j] == '.') {
          a[i][j] = c;
        }
      }
    }
  };
  auto work = [&](ll u, ll d, ll l, ll r) {
    vector<pair<ll, ll>> s;
    for (ll i = u; i < d; ++i) {
      for (ll j = l; j < r; ++j) {
        if (a[i][j] != '.') {
          s.emplace_back(i, j);
        }
      }
    }
    for (int i = 0, j; i < int(s.size()); i = j) {
      for (j = i; j < int(s.size()) && s[i].first == s[j].first; ++j)
        ;
      for (int k = i; k < j; ++k)
        paint(i == 0 ? u : s[i].first, j == int(s.size()) ? d : s[j].first,
              k == i ? l : s[k].second, k == j - 1 ? r : s[k + 1].second,
              std::tolower(a[s[k].first][s[k].second]));
    }
  };
  // 1. brute force find largest A
  for (auto [currChar, ai, aj] : locations) {
    ll mxArea = -1;
    ll u1, u2, v1, v2;
    for (int u = 0; u <= aj; ++u) {
      ll upper = ai, lower = ai;
      for (int v = m - 1; v >= aj; --v) {
        // edge case: impossible
        bool ok = true;
        for (int t = u; t <= v; ++t)
          if (a[ai][t] != '.' && a[ai][t] != currChar) {
            ok = false;
            break;
          }
        if (!ok)
          continue;

        // extend upwards
        while (true) {
          bool ok = true;
          for (int t = u; t <= v; ++t)
            if (upper == 0 || a[upper - 1][t] != '.') {
              ok = false;
              break;
            }
          if (ok)
            upper--;
          else
            break;
        }
        // extend downwards
        while (true) {
          bool ok = true;
          for (int t = u; t <= v; ++t)
            if (lower == n - 1 || a[lower + 1][t] != '.') {
              ok = false;
              break;
            }
          if (ok)
            lower++;
          else
            break;
        }
        ll area = (lower - upper + 1) * (v - u + 1);
        if (area >= mxArea)
          mxArea = area, u1 = upper, u2 = lower, v1 = u, v2 = v;
      }
    }
    u2++, v2++;
    paint(u1, u2, v1, v2, 'a');
    work(0, u1, 0, m);
    work(u1, u2, 0, v1);
    work(u1, u2, v2, m);
    work(u2, n, 0, m);
  }
  // 2. output answer

  for (auto &i : a) {
    cout << i << "\n";
  }
}