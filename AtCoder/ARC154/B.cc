#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool subsequence(string_view s, string_view t) {
  int i = 0;
  for (auto j : t) {
    if (i == s.length())
      return true;
    if (j == s[i]) {
      i++;
    }
  }
  return i == s.length();
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> num(26, 0);
  for (auto i : s) {
    num[i - 'a']++;
  }
  for (auto i : t) {
    num[i - 'a']--;
  }
  for (auto i : num) {
    if (i != 0) {
      cout << "-1\n";
      return 0;
    }
  }
  int l = 0, r = n;
  int ans = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (subsequence(s.substr(mid, n), t)) {
      r = mid - 1;
      ans = min(ans, mid);
    } else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
}