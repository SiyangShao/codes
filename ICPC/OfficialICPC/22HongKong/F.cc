#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>, string> mp2;
string add(string s1, string s2) {
  // string s1 = string(s11);
  // string s2 = string(s22);
  if (s1 == "INF" || s2 == "INF")
    return "INF";
  if (s1.length() > s2.length())
    swap(s1, s2);
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  while (s1.length() < s2.length()) {
    s1 += "0";
  }
  assert(s1.length() == s2.length());
  string ans = "";
  int c = 0;
  for (int i = 0; i < s1.length(); ++i) {
    c = c + s1[i] - '0' + s2[i] - '0';
    ans += char('0' + (c % 10));
    c /= 10;
    assert(c < 10);
  }
  if (c) {
    ans += char('0' + (c % 10));
  }
  reverse(ans.begin(), ans.end());
  // cout << string(ans) << "\n";
  return ans;
}
string mymin(string s1, string s2) {
  if (s1 == "INF")
    return s2;
  if (s2 == "INF")
    return s1;
  if (s1.length() > s2.length()) {
    return s2;
  } else if (s1.length() < s2.length()) {
    return s1;
  }
  assert(s1.length() == s2.length());
  for (int i = 0; i < s1.length(); ++i) {
    if (s1[i] < s2[i])
      return s1;
    if (s1[i] > s2[i])
      return s2;
  }
  return s1;
}
string dfs(const string &s, int n, int cur, int k, int len) {
  auto it = mp2.find({cur, k});
  if (it != mp2.end())
    return it->second;
  if (k == 1 && cur >= n)
    return "INF";
  if (k == 1 && n - cur > 0) {
    return s.substr(cur, n - cur);
  } else if (k == 1) {
    return "INF";
  }
  k--;
  string ans = "INF";
  for (int l = len - 2; l <= len + 1; ++l) {
    if (cur + l < n && l > 0) {
      auto nxt = add(s.substr(cur, l), dfs(s, n, cur + l, k, len));
      // cout<<string(ans)<<" "<<string(nxt)<<" ";
      auto lst = mymin(ans, nxt);
      // cout << string(lst) << "\n";
      ans = lst;
    }
  }
  mp2[{cur, k + 1}] = ans;
  // cout << n << " " << cur << " " << k << "\n";
  return ans;
}
auto solve() {
  mp2.clear();
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int len = n / (k + 1) + (n % (k + 1) == 0 ? 0 : 1);
  k++;
  string ans = dfs(s, n, 0, k, len);
  assert(ans != "INF");
  cout << ans << "\n";
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
