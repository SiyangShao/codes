#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> c(n);
  for (auto &i : c)
    cin >> i;
  auto z = c;
  sort(z.begin(), z.end());
  z.erase(unique(z.begin(), z.end()), z.end());
  vector<int> id(n + 1), edg(z.size());
  for (int i = 0; i < (int)z.size(); ++i) {
    id[z[i]] = i;
    edg[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    u = id[c[u]], v = id[c[v]];
    edg[u] = max(edg[u], v);
    edg[v] = max(edg[v], u);
  }
  for (int i = 1; i < (int)z.size(); ++i) {
    edg[i] = max(edg[i], edg[i - 1]);
  }
  while (q--) {
    string s;
    cin >> s;
    int u, v;
    cin >> u >> v;
    u--, v--;
    u = id[c[u]], v = id[c[v]];
    int ans = 0;
    if (u >= v) {
      cout << "0\n";
    } else {
      while (u < v) {
        if (u == edg[u])
          break;
        u = edg[u];
        ans++;
      }
      if (u < v) {
        cout << "-1\n";
      } else {
        cout << ans << "\n";
      }
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  //  cin >> _;
  while (_--) {
    solve();
  }
}
