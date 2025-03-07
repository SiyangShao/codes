#include <bits/stdc++.h>
using namespace std;
using itr = vector<int>::reverse_iterator;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  string s;
  cin >> s;
  vector<vector<int>> ord(26);
  vector<int> lst(26, -1);
  for (auto &i : s) {
    i -= 'a';
  }
  for (int i = 0; i < s.size(); i++) {
    ord[s[i]].emplace_back(i);
  }
  vector<int> dp(s.size(), s.size());
  array<array<itr, 26>, 26> ptr;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      ptr[i][j] = ord[j].rbegin();
    }
  }
  for (int i = s.size() - 1; i >= 0; --i) {
    int c = s[i];
    if (lst[c] == -1) {
      lst[c] = 1;
      dp[i] = 1;
      continue;
    }
    dp[i] = 1 + dp[*ptr[c][c]];
    for (int j = 0; j < 26; j++) {
      if (j == c)
        continue;
      while (ptr[c][j] != ord[j].rend() && *ptr[c][j] > *ptr[c][c]) {
        ptr[c][j]++;
      }
      if (ptr[c][j] != ord[j].rend() && *ptr[c][j] > i) {
        dp[i] = min(dp[i], 1 + dp[*ptr[c][j]]);
      }
    }
    ptr[c][c]++;
  }

  // for (auto i : dp) {
  //   cout << i << " ";
  // }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
}
