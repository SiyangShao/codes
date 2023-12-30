#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e6;
auto solve() {
  string s;
  cin >> s;
  s = "_" + s;
  vector<array<int, 10>> nxt(s.length());
  vector<int> pos(s.length(), 100);
  for (int i = (int)s.length() - 1; i >= 0; --i) {
    if (i == (int)s.length() - 1) {
      fill(nxt[i].begin(), nxt[i].end(), inf);
    } else {
      nxt[i] = nxt[i + 1];
      nxt[i][s[i + 1] - '0'] = i + 1;
    }
  }
  int m;
  cin >> m;
  string l, r;
  cin >> l >> r;
  int index = 0;
  for (int i = 0; i < m; ++i) {
    int nxt_index = 0;
    for (int j = l[i] - '0'; j <= r[i] - '0'; ++j) {
      nxt_index = max(nxt_index, nxt[index][j]);
    }
    if (nxt_index == inf) {
      cout << "YES\n";
      return;
    }
    index = nxt_index;
  }
  cout << "NO\n";
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