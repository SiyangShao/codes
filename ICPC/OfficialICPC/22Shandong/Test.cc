#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5;
vector<string> ans;
string cur = "00000";
void dfs(int i) {
  if (i >= N) {
    ans.emplace_back(cur);
    return;
  }
  cur[i] = '0';
  dfs(i + 1);
  cur[i] = '1';
  dfs(i + 1);
  cur[i] = '?';
  dfs(i + 1);
}
int main() {
  dfs(0);
  cout << ans.size() * 5 << endl;
  for (auto &s : ans) {
    for (int i = 0; i < 5; ++i) {
      cout << s.length() << " " << i << "\n";
      cout << s << "\n";
    }
  }
}