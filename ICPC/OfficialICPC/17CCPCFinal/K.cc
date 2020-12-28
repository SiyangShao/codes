#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array ans = {1, 9, 41, 109, 205, 325, 473, 649, 853, 1085, 1345};
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

auto solve() {
  int n;
  cin >> n;
  if (n < 10) {
    cout << ans[n] << "\n";
  } else {
    __int128 x = n;
    __int128 y = (__int128)1345 + 14 * (x + 11) * (x - 11 + 1) - 20 * (x - 10);
    cout << y << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  for (int i = 1; i <= _; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}