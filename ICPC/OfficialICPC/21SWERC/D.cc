#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string u, v;
  cin >> u >> v;
  if (u.length() % 2 != v.length() % 2) {
    cout << "NO\n";
    return;
  }
  stack<char> l, r;
  int num_l = 0, num_r = 0;
  for (auto &i : u) {
    if (i == 'B') {
      num_l++;
    } else {
      if (!l.empty() && l.top() == i) {
        l.pop();
      } else {
        l.push(i);
      }
    }
  }
  for (auto &i : v) {
    if (i == 'B') {
      num_r++;
    } else {
      if (!r.empty() && r.top() == i) {
        r.pop();
      } else {
        r.push(i);
      }
    }
  }

  if (num_l % 2 != num_r % 2 || l != r) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}