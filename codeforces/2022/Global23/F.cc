#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
template <class T> struct FenwickTree {
public:
  FenwickTree() : _n(0) {}
  explicit FenwickTree(int n) : _n(n), data(n) {}
  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += x;
      p += p & -p;
    }
  }
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

private:
  int _n;
  std::vector<T> data;
  T sum(int r) {
    T s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};

constexpr int T = 30;
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> p;
  for (auto &i : a) {
    cin >> i;
    p.emplace_back(i);
  }
  vector<tuple<int, int, int, int>> op(q);
  for (auto &[t, l, r, k] : op) {
    cin >> t;
    if (t == 1) {
      cin >> l >> r;
      p.emplace_back(r);
    } else {
      cin >> l >> r >> k;
    }
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  const int m = (int)p.size();
  vector<FenwickTree<int>> seg(T, FenwickTree<int>(n));
  vector<vector<bool>> rdn(T, vector<bool>(m));
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1);
  for (int i = 0; i < T; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dist(gen)) {
        rdn[i][j] = true;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(p.begin(), p.end(), a[i]);
    assert(it != p.end() && *it == a[i]);
    int idx = (int)(it - p.begin());
    for (int j = 0; j < T; ++j) {
      if (rdn[j][idx]) {
        seg[j].add(i, 1);
      }
    }
  }
  for (auto tp : op) {
    auto [t, l, r, k] = tp;
    if (t == 1) {
      auto it = lower_bound(p.begin(), p.end(), r);
      assert(it != p.end() && *it == r);
      int idx = (int)(it - p.begin());
      it = lower_bound(p.begin(), p.end(), a[l - 1]);
      int idx2 = (int)(it - p.begin());
      if (idx == idx2)
        continue;
      for (int i = 0; i < T; ++i) {
        int p = rdn[i][idx], c = rdn[i][idx2];
        if (p == c)
          continue;
        if (p) {
          seg[i].add(l - 1, 1);
        } else {
          seg[i].add(l - 1, -1);
        }
      }
      a[l - 1] = r;
    } else {
      bool flag = true;
      for (int i = 0; i < T; ++i) {
        int sum = seg[i].sum(l - 1, r);
        if (sum % k != 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}