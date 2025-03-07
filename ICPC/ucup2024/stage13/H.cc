#include <bits/stdc++.h>
using namespace std;
auto ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  string s;
  cin >> s;
  return s;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> red, blue;
  vector<pair<int, int>> rd, bl;
  for (int i = 2; i <= n; ++i) {
    auto c = ask(1, i);
    if (c == "R") {
      red.push_back(i);
      rd.emplace_back(1, i);
    } else {
      blue.push_back(i);
      bl.emplace_back(1, i);
    }
  }
  while (!red.empty() && !blue.empty()) {
    auto c = ask(red.back(), blue.back());
    if (c == "R") {
      rd.emplace_back(red.back(), blue.back());
      blue.pop_back();
    } else {
      bl.emplace_back(red.back(), blue.back());
      red.pop_back();
    }
  }
  assert(rd.size() == n - 1 || bl.size() == n - 1);
  if (rd.size() == n - 1) {
    cout << "!" << endl;
    for (auto [u, v] : rd) {
      cout << u << " " << v << endl;
    }
  } else {
    cout << "!" << endl;
    for (auto [u, v] : bl) {
      cout << u << " " << v << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
