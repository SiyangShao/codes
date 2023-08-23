#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int H, W;
  cin >> H >> W;
  vector<string> S(W, ""), T(W, "");
  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < W; ++j) {
      S[j] += s[j];
    }
  }
  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < W; ++j) {
      T[j] += s[j];
    }
  }
  sort(S.begin(), S.end());
  sort(T.begin(), T.end());
  if (S == T) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}