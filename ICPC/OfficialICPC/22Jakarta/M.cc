#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] + b[i] < 0)
      flag = true;
  }
  ll sumb = accumulate(b.begin(), b.end(), 0LL);
  if (accumulate(a.begin(), a.end(), 0LL) < 0 ||
      accumulate(b.begin(), b.end(), 0LL) < 0) {
    flag = true;
  }
  if (flag) {
    while (q--) {
      ll x, y;
      cin >> x >> y;
      cout << "flawed\n";
    }
    return;
  }
  vector<ll> x(2 * n + 1), y(2 * n + 1);
  for (int i = 0; i < n; ++i) {
    x[i] = a[i], x[i + n] = a[i];
    y[i] = b[i], y[i + n] = b[i];
  }
  for (int i = 1; i < 2 * n; ++i) {
    x[i] += x[i - 1];
    y[i] += y[i - 1];
  }
  auto get_sum = [](int l, int r, const std::vector<ll> &v) {
    if (l == 0) {
      return v[r];
    }
    return v[r] - v[l - 1];
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (l == r) {
      std::cout << 0 << '\n';
    } else if (l < r) {
      ll ans1 = get_sum(l, r - 1, x);
      ll ans2 = sumb - get_sum(l, r - 1, y);
      std::cout << min(ans1, ans2) << '\n';
    } else {
      r += n;
      ll ans1 = get_sum(l, r - 1, x);
      ll ans2 = sumb - get_sum(l, r - 1, y);
      std::cout << min(ans1, ans2) << '\n';
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