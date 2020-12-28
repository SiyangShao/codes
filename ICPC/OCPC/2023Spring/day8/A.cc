#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
template <int P> struct MInt {
  int x;
  constexpr MInt() : x{} {}
  constexpr MInt(long long x) : x{norm(x % P)} {}

  constexpr int norm(int x) const {
    if (x < 0) {
      x += P;
    }
    if (x >= P) {
      x -= P;
    }
    return x;
  }
  constexpr int val() const { return x; }
  explicit constexpr operator int() const { return x; }
  constexpr MInt operator-() const {
    MInt res;
    res.x = norm(P - x);
    return res;
  }
  constexpr MInt inv() const {
    assert(x != 0);
    return power(*this, P - 2);
  }
  constexpr MInt &operator*=(MInt rhs) {
    x = 1LL * x * rhs.x % P;
    return *this;
  }
  constexpr MInt &operator+=(MInt rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  constexpr MInt &operator-=(MInt rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  constexpr MInt &operator/=(MInt rhs) { return *this *= rhs.inv(); }
  friend constexpr MInt operator*(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res *= rhs;
    return res;
  }
  friend constexpr MInt operator+(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res += rhs;
    return res;
  }
  friend constexpr MInt operator-(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res -= rhs;
    return res;
  }
  friend constexpr MInt operator/(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res /= rhs;
    return res;
  }
  friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
    long long v;
    is >> v;
    a = MInt(v);
    return is;
  }
  friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
    return os << a.val();
  }
  friend constexpr bool operator==(MInt lhs, MInt rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr bool operator!=(MInt lhs, MInt rhs) {
    return lhs.val() != rhs.val();
  }
};

template <int V, int P> constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;
using i64 = Z;
i64 MOD = 998'244'353;
int BIT = 25;
i64 MSK = (1LL << BIT) - 1;

std::array<i64, 55> qp;
i64 qpow(i64 x, long long y) { return qp[y]; }
int check(int val, int i, int j) {
  return ((val >> i) & 1) && ((val >> j) & 1);
};
int check2(int val, int i, int j) {
  return (!((val >> i) & 1)) && (!((val >> j) & 1));
};
int has(int val, auto k) { return ((val >> k) & 1); };
constexpr int N = 1e5 + 7;
std::array<int, N> in, out, vec;
std::array<std::array<std::array<long long, 2>, 2>, N> dp;
std::array<std::vector<int>, N> E;
Z rd = 0, out_rd = 0, xor_rd = 0;
void dfs(int u, int fa, int i, int j) {
  in[u] = out[u] = 0;
  in[u] = check(vec[u], i, j);
  out[u] = check2(vec[u], i, j);
  rd += in[u];
  out_rd += out[u];
  dp[u][0][0] = dp[u][0][1] = dp[u][1][0] = dp[u][1][1] = 0;
  dp[u][has(vec[u], i)][has(vec[u], j)] = 1;
  xor_rd += dp[u][1][1];
  for (auto v : E[u]) {
    if (v == fa)
      continue;
    dfs(v, u, i, j);
    if (in[u]) {
      rd += (i64)in[u] * in[v] * 2;
      in[u] += in[v];
    }
    if (out[u]) {
      out_rd += (Z)out[u] * out[v] * 2;
      out[u] += out[v];
    }
    for (int x = 0; x < 2; ++x) {
      for (int y = 0; y < 2; ++y) {
        xor_rd += dp[v][x][y] * dp[u][x ^ 1][y ^ 1] * 2;
      }
    }
    for (int x = 0; x < 2; ++x) {
      for (int y = 0; y < 2; ++y) {
        dp[u][x ^ has(vec[u], i)][y ^ has(vec[u], j)] += dp[v][x][y];
      }
    }
  }
  // dbg(u + 1, dp[u]);
};
auto solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  std::vector<long long> in(n), out(n);
  i64 A = 0, O = ((i64)n * n) * MSK * MSK, X = 0;
  // dbg(O);
  // O = 0;
  for (int i = 0; i < BIT; ++i) {
    for (int j = 0; j <= i; ++j) {
      rd = 0, out_rd = 0, xor_rd = 0;
      dfs(0, 0, i, j);
      // dbg(rd, i, j);
      A += rd * qpow(2, i + j + (i == j ? 0 : 1));
      // dbg(xor_rd, i, j);
      X += xor_rd * qpow(2, i + j + (i == j ? 0 : 1));
      // dbg(out_rd, i, j);
      // dbg(out);
      if (i == j) {
        O -= out_rd * (qpow(2, i) * (MSK * 2 - qpow(2, i)));
      } else {
        O += out_rd * qpow(2, i + j + 1);
      }
    }
  }
  std::cout << A << " " << O << " " << X << "\n";
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  qp[0] = 1;
  for (int i = 1; i < 55; ++i) {
    qp[i] = qp[i - 1] * (Z)2;
  }
  // std::cin >> _;
  while (_--) {
    solve();
  }
}