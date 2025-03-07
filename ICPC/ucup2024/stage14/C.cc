#include <bits/stdc++.h>
using namespace std;
auto check_dir(string &cur, string &nxt) {
  if (cur == "E" && nxt == "S") {
    return "R";
  } else if (cur == "E" && nxt == "N") {
    return "L";
  } else if (cur == "W" && nxt == "S") {
    return "L";
  } else if (cur == "W" && nxt == "N") {
    return "R";
  } else if (cur == "N" && nxt == "E") {
    return "R";
  } else if (cur == "N" && nxt == "W") {
    return "L";
  } else if (cur == "S" && nxt == "E") {
    return "L";
  } else if (cur == "S" && nxt == "W") {
    return "R";
  }
  assert(false);
  return "X";
}
auto solve() {
  int n;
  cin >> n;
  vector<pair<string, int>> a(n);
  for (auto &[d, x] : a) {
    cin >> d >> x;
  }
  vector<pair<string, int>> ans;
  string pre_dir = a[0].first;
  ans.emplace_back("Z", a[0].second);
  for (int i = 1; i < n; i++) {
    assert(a[i].first != a[i - 1].first);
    auto dir = check_dir(a[i - 1].first, a[i].first);
    ans.emplace_back(dir, -1);
    ans.emplace_back("Z", a[i].second);
  }
  cout << ans.size() << " " << pre_dir << "\n";
  for (auto &[x, y] : ans) {
    if (y == -1) {
      cout << x << "\n";
    } else {
      cout << x << " " << y << "\n";
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
