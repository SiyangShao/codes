#include <bits/stdc++.h>
#include "dbg.h"

using u64 = unsigned long long;
const int N = 5005;

namespace poly {
  const int N = 2100000;
  const int Mod = 998244353, g = 3;
  using Poly = std::vector<int>;
  int pow(int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = 1ull * a * a % Mod)
      if (b & 1) c = 1ull * c * a % Mod;
    return c;
  }

  namespace Pol {
    int add(int a, int b) { return (a += b) >= Mod ? a -= Mod : a; }
    int sub(int a, int b) { return (a -= b) < 0 ? a += Mod : a; }
    void inc(int &a, int b) { (a += b) >= Mod ? a -= Mod : a; }
    void dec(int &a, int b) { (a -= b) < 0 ? a += Mod : a; }
    int &reduce(int &x) { return x += x >> 31 & Mod; }
    void init_Poly();
    void DIT(int *A, int lim);
    void DIF(int *A, int lim);
    Poly mult(const Poly &A, int n, const Poly &B, int m);
    u64 tmp[N];
    int gw[N];
    void DIT(int *A, int lim, bool flag) {
      for (int i = 0; i < lim; ++i)
        tmp[i] = A[i];
      for (int l = 1; l < lim; l <<= 1) {
        u64 *k = tmp;
        for (int i = 0; i < lim; i += (l << 1), k += (l << 1)) {
          u64 *x = k;
          for (int j = 0, *g = gw + l; j < l; ++j, ++x, ++g) {
            u64 o = x[l] * *g % Mod;
            x[l] = *x + Mod - o, *x += o;
          }
        }
      }
      int iv = pow(lim, Mod - 2);
      for (int i = 0; i < lim; ++i)
        A[i] = tmp[i] % Mod * iv % Mod;
      std::reverse(A + 1, A + lim);
    }
    void DIF(int *A, int lim, bool flag) {
      for (int i = 0; i < lim; ++i)
        tmp[i] = A[i];
      for (int l = lim / 2; l >= 1; l >>= 1) {
        u64 *k = tmp;
        for (int i = 0; i < lim; i += (l << 1), k += (l << 1)) {
          u64 *x = k;
          for (int j = 0, *g = gw + l; j < l; ++j, ++x, ++g) {
            u64 o = x[l] % Mod;
            x[l] = (*x + Mod - o) * *g % Mod, *x += o;
          }
        }
      }
      for (int i = 0; i < lim; ++i)
        A[i] = tmp[i] % Mod;
    }
    Poly mult(const Poly &A, int n, const Poly &B, int m) {
      int lim = 1;
      while (lim < (n + m - 1))
        lim <<= 1;
      static int tA[N], tB[N];
      std::copy_n(A.begin(), n, tA), std::fill(tA + n, tA + lim, 0);
      std::copy_n(B.begin(), m, tB), std::fill(tB + m, tB + lim, 0);
      DIF(tA, lim, false), DIF(tB, lim, false);
      for (int i = 0; i < lim; ++i)
        tA[i] = 1ll * tA[i] * tB[i] % Mod;
      DIT(tA, lim, true);
      Poly ans(n + m - 1);
      std::copy_n(tA, n + m - 1, ans.begin());
      return ans;
    }
    void init_Poly() {
      for (int l = 1; l < (1 << 21); l <<= 1) {
        gw[l] = 1;
        int gn = pow(g, (Mod - 1) / (l << 1));
        for (int j = 1; j < l; ++j) {
          gw[l | j] = 1ll * gw[l | (j - 1)] * gn % Mod;
        }
      }
    }
  }  // namespace Pol

  Poly dmul(const Poly &a, const Poly &b, int p) {
    std::vector<int> c = Pol::mult(a, p, b, p), res(p);
    dbg(a);
    dbg(b);
    dbg(c);
    for (int i = 0; i < c.size(); ++i) (res[i % p] += c[i]) %= Mod;
    dbg(res);
    return res;
  }
} // namespace poly

char s[1024];
int lens;
u64 p, nx, pw[N], ipw[N], id[N];

inline u64 qpow(u64 x, u64 y) {
  u64 z = 1;
  for (; y; y >>= 1, x = x * x % p)
    if (y & 1) z = z * x % p;
  return z;
}

inline u64 binom(int x, int y) {
  if (x < y) return 0;
  return (u64)pw[x] * ipw[y] % p * ipw[x - y] % p;
}

bool sdiv2() {
  int tmp = 0;
  for (int i = 1; i <= lens; ++i) {
    tmp = tmp * 10 + s[i];
    s[i] = tmp / 2;
    tmp %= 2;
  }
  for (int i = 1; i <= lens; ++i)
    if (s[i]) return true;
  return false;
}

u64 getG() {
  std::vector<u64> ps;
  u64 lft=p-1;
  for(u64 i=2;i*i<=lft;++i) if(lft%i==0) {
    ps.push_back(i);
    while (lft % i == 0) lft /= i;
  }
  if (lft > 1) ps.push_back(lft);
  for (auto &j : ps) j = (p - 1) / j;
  for (u64 i = 2;; ++i) {
    bool ok = true;
    for (auto j : ps)
      if (qpow(i, j) == 1) { ok = false; break; }
    if (ok) return i;
  }
}

int main() {
  scanf("%s%llu%llu", s + 1, &p, &nx);
  lens = strlen(s + 1);
  for (int i = 1; i <= lens; ++i) s[i] -= '0';
  pw[0] = 1;
  for (u64 i = 1; i < p; ++i) pw[i] = (u64)pw[i - 1] * i % p;
  ipw[p - 1] = qpow(pw[p - 1], p - 2);
  for (int i = (int)p - 2; ~i; --i) ipw[i] = (u64)ipw[i + 1] * (i + 1) % p;
  u64 g = getG();
  for (u64 i = 0, t = 1; i < p; ++i, t = t * g % p) id[t] = i;
  printf("%llu\n", g);
  for (u64 i = 0; i < p; ++i) printf("%llu ", id[i]);
  puts("");
  std::vector<int> a(p), b(p);
  for (int i = 0; i < p; ++i)
    for (int j = 0; j < p; ++j) {
      ++a[id[binom(i, j)]];
      //printf("%d %d %llu\n", i, j, binom(i, j));
    }
  a[0] = 0;
  for (int i = 0; i < p; ++i) a[i] %= 998244353;
  b[0] = 1;
  poly::Pol::init_Poly();
  while (1) {
    if (s[lens] & 1) b = poly::dmul(a, b, p);
    a = poly::dmul(a, a, p);
    if (!sdiv2()) break;
  }
  printf("%d\n", b[id[nx]]);
  return 0;
}