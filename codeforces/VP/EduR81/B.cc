#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  int zero = 0, one = 0;
  map<int, int> mp;
  int mi = 0, mx = 0;
  for (auto i : s) {
    if (i == '0')
      zero++;
    else
      one++;
    mp[zero - one]++;
    mi = min(mi, zero - one);
    mx = max(mx, zero - one);
  }
  // cout << mi << " " << mx << " ";
  if (zero - one == 0) {
    if (mp[x] == 0 && x != 0) {
      cout << "0\n";
    } else {
      cout << "-1\n";
    }
  } else {
    int sum = 0;
    if (x == 0)
      sum++;
    if(x < mi && zero - one < 0){
      int dif = abs(mi - x);
      dif /= abs(zero - one);
      x += dif * abs(zero - one);
    }
    while (x < mi && zero - one < 0) {
      x -= zero - one;
    }
    if (x > mx && zero - one > 0) {
      int dif = abs(x - mx);
      dif /= abs(zero-one);
      x -= dif * abs(zero - one);
    }
    while (x > mx && zero - one > 0) {
      x -= zero - one;
    }
    while (x >= mi && x <= mx) {
      sum += mp[x];
      x -= zero - one;
    }
    cout << sum << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}