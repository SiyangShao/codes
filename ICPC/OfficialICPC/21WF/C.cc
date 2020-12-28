#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

using LL = long long;

__int128 ksm(__int128 a, __int128 b) {
  __int128 res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  LL n, m;
  std::cin >> n >> m;
  for (LL v = 1; v <= 5000; ++v) {
    for (LL u = v - 1; u >= 1; --u) {
      if (std::gcd(u, v) != 1) {
        continue;
      }
      __int128 vv = ksm(v, n);
      __int128 uu = ksm(u, n);
      if (vv == -1 || uu == -1) {
        continue;
      }
      auto x = (__int128)m * (v - u) / (vv - uu);
      if ((__int128)m * (v - u) == x * (vv - uu) && x >= 1) {
        std::cout << (v - u) << " " << v << '\n';
        return 0;
      }
    }
  }
  std::cout << "impossible" << std::endl;
  return 0;
}