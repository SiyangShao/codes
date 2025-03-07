#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
vector<int> prefix_function(const string &s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> find_occurrences(const string &text, const string &pattern) {
  string cur = pattern + '#' + text;
  int sz1 = (int)text.size(), sz2 = (int)pattern.size();
  vector<int> v;
  vector<int> lps = prefix_function(cur);
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (lps[i] == sz2)
      v.push_back(i - 2 * sz2);
  }
  return v;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  int n = (int)s.length(), m = (int)t.length();
  auto v = find_occurrences(s, t);
  vector<int> sp(n + 1);
  for (auto i : v) {
    sp[i + m] = 1;
  }
  int prec = -1;
  vector<ll> dp(n + 1), s1(n + 1), s2(n + 1);
  dp[0] = s1[0] = s2[0] = 1;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (sp[i])
      prec = i - m;
    if (~prec)
      dp[i] = s2[prec];
    s1[i] = (s1[i - 1] + dp[i]) % MOD;
    s2[i] = (s2[i - 1] + s1[i]) % MOD;
    ans = (ans + dp[i]) % MOD;
  }
  cout << ans << endl;
}
