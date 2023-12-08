#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  vector<map<int, int>> vec(n + 5);
  vec[0][0] = 0;
  function<void(int, int, int)> nxt = [&](int yt, int xt, int cur) {
    // 1 step: take cur
    yt += b[cur];
    xt = max(xt, yt);
    xt += a[cur];
    // 2 step: goto next
    if (vec[cur + 1].contains(yt)) {
      vec[cur + 1][yt] = min(vec[cur + 1][yt], xt);
    } else {
      vec[cur + 1][yt] = xt;
    }
  };
  function<void(int, int, int)> nxtJump = [&](int yt, int xt, int cur) {
    // 1 step: take cur
    yt += b[cur];
    xt = max(xt, yt);
    xt += a[cur];
    // 2 step: jump next
    xt = max(xt, yt);
    xt += a[cur + 1];
    // 3 step: goto next nexxt
    if (vec[cur + 2].contains(yt)) {
      vec[cur + 2][yt] = min(vec[cur + 2][yt], xt);
    } else {
      vec[cur + 2][yt] = xt;
    }
  };
  for (int i = 0; i < n; ++i) {
    for (auto [yt, xt] : vec[i]) {
      // cout << i << " " << yt << " " << xt << "\n";
      nxt(yt, xt, i);
      if (i < n - 2) {
        nxtJump(yt, xt, i);
      }
    }
  }
  int ans = INT_MAX;
  for (auto [yt, xt] : vec[n]) {
    ans = min(ans, max(yt, xt));
  }
  cout << ans << "\n";
}