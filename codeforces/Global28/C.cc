#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  int z_pos = -1;
  int n = (int)s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      z_pos = i;
      break;
    }
  }
  if (z_pos == -1) {
    cout << "1 " << n << " 1 1\n";
    return;
  }
  // len is must from z_pos to end
  const int len = n - z_pos;
  string cur = "";
  int l = -1, r = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] != '1')
      continue;
    if (i + len > n) {
      break;
    }
    string ans = s;
    for (int j = i; j < i + len; j++) {
      int p = j - i + z_pos;
      ans[p] = ((s[p] - '0') ^ (s[j] - '0')) + '0';
    }
    if (l == -1 || ans > cur) {
      cur = ans;
      l = i;
      r = i + len - 1;
    }
  }
  cout << "1 " << n << " " << l + 1 << " " << r + 1 << "\n";
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
