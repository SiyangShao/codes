#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> odd(3, 0), even(3, 0);
  for (int i = 0; i < n; ++i) {
    int j = s[i] - '0';
    if (i % 2 == 0) {
      even[j]++;
    } else {
      odd[j]++;
    }
  }
  int base0 = min(odd[0], even[0]);
  odd[0] -= base0, even[0] -= base0;
  int base1 = min(odd[1], even[1]);
  odd[1] -= base1, even[1] -= base1;
  int ans = base0 + base1;
  int base2 = min(odd[0] + odd[1], even[2]);
  even[2] -= base2;
  int base3 = min(odd[2], even[0] + even[1]);
  odd[2] -= base3;
  ans += base2 + base3 + min(even[2], odd[2]);
  cout << n - ans * 2 << "\n";
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
