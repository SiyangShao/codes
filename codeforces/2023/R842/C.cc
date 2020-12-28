#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), p(n, -1), q(n, -1);
  set<int> pos_p, pos_q;
  for (int i = 0; i < n; ++i) {
    pos_p.emplace(i), pos_q.emplace(i);
  }
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  for (int i = 0; i < n; ++i) {
    if (pos_p.contains(a[i])) {
      pos_p.erase(a[i]);
      p[i] = a[i];
    } else {
      if (!pos_q.contains(a[i])) {
        cout << "NO\n";
        return;
      }
      pos_q.erase(a[i]);
      q[i] = a[i];
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   assert(p[i] == -1 || q[i] == -1);
  //   cout << p[i] << " " << q[i] << "\n";
  // }
  // cout << "\n";
  for (int i = 0; i < n; ++i) {
    if (p[i] != -1) {
      swap(p, q);
      swap(pos_p, pos_q);
    }
    auto it = pos_p.upper_bound(q[i]);
    if (it == pos_p.begin()) {
      cout << "NO\n";
      return;
    }
    it = prev(it);
    p[i] = *it;
    pos_p.erase(it);
  }
  cout << "YES\n";
  for (auto i : p) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  for (auto i : q) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; ++i) {
    assert(max(p[i], q[i]) == a[i]);
  }
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
