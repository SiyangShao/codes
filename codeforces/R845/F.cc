#include <bits/stdc++.h>
using namespace std;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int size) : n(size), fa(size) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (fa[u] != u)
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
struct Trie {
  int tot{0};
  vector<array<int, 2>> ch;
  Trie() { ch.push_back({0, 0}); };
  void add(int x) {
    for (int i = 30, u = 0; i >= 0; --i) {
      int c = ((x >> i) & 1);
      if (!ch[u][c])
        ch[u][c] = ++tot, ch.push_back({0, 0});
      u = ch[u][c];
    }
  }
  int ask(int x) {
    int res = 0;
    for (int i = 30, u = 0; i >= 0; --i) {
      int c = ((x >> i) & 1);
      if (ch[u][c ^ 1]) {
        u = ch[u][c ^ 1];
        res |= (1 << i);
      } else {
        u = ch[u][c];
      }
    }
    return res;
  }
};
auto solve() {
  int n;
  cin >> n;
  DSU dsu(n + 1);
  vector<int> a(n + 1);
  vector<Trie> trie(n + 1);
  vector<int> id(n + 1);
  iota(id.begin(), id.end(), 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(id.begin() + 1, id.end(), [&](int x, int y) { return a[x] < a[y]; });
  for (int i = 1; i <= n; ++i) {
    a[i] ^= a[i - 1];
  }
  set<pair<int, int>> s;
  int res = 0;
  auto add = [&](int x) {
    auto r = s.upper_bound({x, 0});
    auto l = r;
    int l1 = -1, r1 = -1;
    int l2 = -1, r2 = -1;
    if (l != s.begin()) {
      l--;
      l1 = (l->first);
      r1 = (l->second);
    }
    if (r != s.end()) {
      l2 = (r->first);
      r2 = (r->second);
    }
    int L = x;
    int R = x;
    int ll = 0;
    if (r1 == x - 1) {
      s.erase(l);
      L = l1;
      ll = 1;
      res = max(res, trie[dsu.find(l1)].ask(a[r1]));
    }
    int rr = 0;
    if (l2 == x + 1) {
      s.erase(r);
      R = r2;
      rr = 1;
      res = max(res, trie[dsu.find(l2)].ask(a[l2 - 1]));
    }
    s.insert({L, R});
    if (ll == 0 && rr == 0)
      trie[dsu.find(x)].add(a[x]), trie[dsu.find(x)].add(a[x - 1]);
    else if (ll == 0 && rr == 1)
      trie[dsu.find(l2)].add(a[x - 1]), dsu.merge(x, l2);
    else if (ll == 1 && rr == 0)
      trie[dsu.find(l1)].add(a[x]), dsu.merge(x, l1);
    else {
      if (r1 - l1 < r2 - l2) {
        for (int i = l1 - 1; i <= r1; i++)
          res = max(res, trie[dsu.find(l2)].ask((a[x] ^ a[x - 1]) ^ a[i]));
        for (int i = l1 - 1; i <= r1; i++)
          trie[dsu.find(l2)].add(a[i]);
        dsu.merge(l1, l2);
        trie[dsu.find(l2)].add(a[x]);
      } else {
        for (int i = l2 - 1; i <= r2; i++)
          res = max(res, trie[dsu.find(l1)].ask((a[x] ^ a[x - 1]) ^ a[i]));
        for (int i = l2 - 1; i <= r2; i++)
          trie[dsu.find(l1)].add(a[i]);
        dsu.merge(l2, l1);
        trie[dsu.find(l1)].add(a[x]);
      }
    }
  };
  for (int i = 1; i <= n; i++)
    add(id[i]);
  cout << res << '\n';
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