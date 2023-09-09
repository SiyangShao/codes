#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> vec(n);
  vector<int> num(n);
  for (auto &[str, v, k] : vec) {
    cin >> str >> v;
    if (str == "add") {
      continue;
    } else {
      cin >> k;
      k--;
    }
  }
  int reg = 0;
  for (int i = 0; i < n;) {
    num[i]++;
    if (num[i] > 256) {
      cout << "No\n";
      return;
    }
    auto [str, v, k] = vec[i];
    if (str == "add") {
      reg += v;
      reg %= 256;
      i++;
    } else {
      if (str == "beq") {
        if (reg == v) {
          i = k;
        } else {
          i++;
        }
      } else if (str == "bne") {
        if (reg != v) {
          i = k;
        } else {
          i++;
        }
      } else if (str == "blt") {
        if (reg < v) {
          i = k;
        } else {
          i++;
        }
      } else {
        if (reg > v) {
          i = k;
        } else {
          i++;
        }
      }
    }
  }
  cout << "Yes\n";
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