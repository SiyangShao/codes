#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n + 1), y(n + 1), a(n + 1), b(n + 1), c(n + 1);
  int tx, ty, l, r, u, d, lu, ld, ru, rd;
  u = l = tx = ty = lu = ru = ld = rd = 0;
  d = r = n + 1;
  auto L = [&](int k) {
    auto t = l - k + ty;
    if (t >= 1)
      ty -= k;
    else {
      int tl = l;
      l -= t - 1;
      if (l > r)
        l = r;
      ty = 1 - l;
      for (int i = tl + 1; i <= l - (l == r ? 1 : 0); i++)
        lu += a[i], ld += b[i];
    }
  };

  auto R = [&](int k) {
    auto t = r + k + ty - n;
    if (t <= 0)
      ty += k;
    else {
      int tr = r;
      r -= t;
      if (l > r)
        r = l;
      ty = n - r;
      for (int i = tr - 1; i >= r + (l == r ? 1 : 0); i--)
        ru += a[i], rd += b[i];
    }
  };

  auto U = [&](int k) {
    int t = u - k + tx;
    if (t >= 1)
      tx -= k;
    else {
      int tu = u;
      u -= t - 1;
      if (u > d)
        u = d;
      tx = 1 - u;
      for (int i = tu + 1; i <= u - (u == d ? 1 : 0); i++) {
        if (c[i] >= r)
          ru++;
        else if (c[i] > l)
          a[c[i]] = 1;
        else
          lu++;
      }
    }
  };

  auto D = [&](int k) {
    int t = d + k + tx - n;
    if (t <= 0)
      tx += k;
    else {
      int td = d;
      d -= t;
      if (d < u)
        d = u;
      tx = n - d;
      for (int i = td - 1; i >= d + (d == u ? 1 : 0); i--) {
        if (c[i] >= r)
          rd++;
        else if (c[i] > l)
          b[c[i]] = 1;
        else
          ld++;
      }
    }
  };

  auto CA = [&](int size) { return (ll)size * ((ll)size - 1LL) / 2LL; };

  auto cal = [&]() {
    if (u == d && l == r)
      cout << CA(n);
    else if (u == d)
      cout << CA(lu + ld) + CA(ru + rd);
    else if (l == r)
      cout << CA(lu + ru) + CA(ld + rd);
    else
      cout << CA(lu) + CA(ru) + CA(ld) + CA(rd);
    cout << "\n";
  };

  auto query = [&](int idx) {
    int nowx = x[idx];
    int nowy = y[idx];
    nowx = max(min(nowx, d), u);
    nowy = max(min(nowy, r), l);
    nowx += tx, nowy += ty;
    cout << nowx << " " << nowy << "\n";
  };

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    c[x[i]] = y[i];
    a[i] = b[i] = 0;
  }
  while (q--) {
    string op;
    cin >> op;
    if (op[0] == '!')
      cal();
    else {
      int k;
      cin >> k;
      if (op[0] == 'L')
        L(k);
      if (op[0] == 'R')
        R(k);
      if (op[0] == 'U')
        U(k);
      if (op[0] == 'D')
        D(k);
      if (op[0] == '?')
        query(k);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
}
