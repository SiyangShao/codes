#include <bits/stdc++.h>
using namespace std;
template <typename val> struct LCT {
  int n;
  vector<int> rev, fa;
  vector<val> s, a;
  vector<array<int, 2>> ch;
  LCT(int _n)
      : n(_n), rev(_n + 1), fa(_n + 1), s(_n + 1), a(_n + 1), ch(_n + 1){};
  bool nroot(int x) { return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
  // TODO: edit push up
  void pushup(int x) { s[x] = s[ch[x][0]] + s[ch[x][1]] + 1; }
  void reverse(int x) {
    swap(ch[x][0], ch[x][1]);
    rev[x] ^= 1;
  }
  void pushdown(int x) {
    if (rev[x]) {
      if (ch[x][0])
        reverse(ch[x][0]);
      if (ch[x][1])
        reverse(ch[x][1]);
      rev[x] = 0;
    }
  }
  void rotate(int x) {
    int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
    if (nroot(y))
      ch[z][ch[z][1] == y] = x;
    ch[x][!k] = y;
    ch[y][k] = w;
    if (w)
      fa[w] = y;
    fa[y] = x;
    fa[x] = z;
    pushup(y);
  }
  void pushall(int x) {
    if (nroot(x))
      pushall(fa[x]);
    pushdown(x);
  }
  void splay(int x) {
    // pushall(x);
    while (nroot(x)) {
      int y = fa[x], z = fa[y];
      if (nroot(y))
        rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
      rotate(x);
    }
    pushup(x);
  }
  void access(int x) {
    int y = 0;
    while (x) {
      splay(x);
      ch[x][1] = y;
      pushup(x);
      y = x;
      x = fa[x];
    }
  }
  void makeroot(int x) {
    access(x);
    splay(x);
    reverse(x);
  }
  int findroot(int x) {
    access(x);
    splay(x);
    while (ch[x][0]) {
      pushdown(x);
      x = ch[x][0];
    }
    splay(x);
    return x;
  }
  void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
  }
  void link(int x, int y) {
    // makeroot(x);
    // if (findroot(y) != x)
    // access(x);
    // splay(x);
    fa[x] = y;
    // pushup(x);
  }
  void cut(int x, int y) {
    access(x);
    splay(x);
    ch[x][0] = fa[ch[x][0]] = 0;
    // makeroot(x);
    // if (findroot(y) == x && fa[y] == x && !ch[y][0]) {
    // fa[y] = ch[x][1] = 0;
    // pushup(x);
    // }
  }
  int query(int x, int y) {
    split(x, y);
    return s[y];
  }
  void update(int x, int v) {
    splay(x);
    a[x] = v;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  LCT<int> G(n);
  for (int i = 1; i <= n; ++i) {
    G.a[i] = 1;
    if (i + a[i] >= 1 && i + a[i] <= n)
      G.fa[i] = i + a[i];
  }

  int m;
  cin >> m;
  while (m--) {
    int op, i;
    cin >> op >> i;
    i++;
    if (op == 2) {
      int k;
      cin >> k;
      a[i] = k;
      G.cut(i, 0);
      if (i + a[i] >= 1 && i + a[i] <= n)
        G.link(i, i + a[i]);
    } else {
      G.access(i);
      G.splay(i);
      cout << G.s[i] << "\n";
    }
  }
}