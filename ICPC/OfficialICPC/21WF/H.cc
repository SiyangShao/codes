#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> num(n);
  for (auto &i : s)
    cin >> i;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0;
    for (auto j : s[i]) {
      if (j == '(') {
        l++;
      } else {
        r++;
      }
      if (l < r) {
        num[i] = min(num[i], l - r);
      }
    }
    if (num[i] == 0) {
      num[i] = l - r;
    }
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int i, int j) { return num[i] > num[j]; });
  int l = 0, r = 0;
  for (auto i : id) {
    for (auto j : s[i]) {
      if (j == '(') {
        l++;
      } else {
        r++;
      }
      if (l < r) {
        cout << "impossible"
             << "\n";
        return 0;
      }
    }
  }
  if (l != r) {
    cout << "impossible"
         << "\n";
    return 0;
  }
  for (auto i : id) {
    cout << i + 1 << "\n";
  }
}