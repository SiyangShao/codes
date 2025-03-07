#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }
  int cnt = 0;
  string ans;
  for (auto &[s, c] : mp) {
    if (c > cnt) {
      cnt = c;
      ans = s;
    }
  }
  cout << ans << "\n";
}
