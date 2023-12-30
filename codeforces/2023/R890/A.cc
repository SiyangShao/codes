#include <bits/stdc++.h>
#include <queue>
using namespace std;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  priority_queue<int> Q;
  for (auto &i : a) {
    cin >> i;
    Q.emplace(i);
  }
  for (auto i : a | views::reverse) {
    if (i == Q.top()) {
      Q.pop();
    } else {
      cout << Q.top() << "\n";
      return;
    }
  }
  cout << "0\n";
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