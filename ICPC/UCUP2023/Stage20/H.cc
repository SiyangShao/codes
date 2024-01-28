#include <algorithm>
#include <iostream>
#include <vector>

using LL = long long;

constexpr char FIRST_C = 'a' - 1;
static const int N = 1100005; // the length of the string

int ksm(int a, int b, int mod) {
  int ans = 1;
  for (; b; b >>= 1, a = (LL)a * a % mod) {
    if (b & 1) {
      ans = (LL)ans * a % mod;
    }
  }
  return ans;
}

int n;
char s[N];

struct SuffixArray {
  int n, m, cnt[N], sa[N], rk[N], id[N];

  void radixSort() {
    for (int i = 0; i < m; ++i) {
      cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      ++cnt[rk[i]];
    }
    for (int i = 1; i < m; ++i) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; ~i; --i) {
      sa[--cnt[rk[id[i]]]] = id[i];
    }
  }

  bool cmp(int x, int y, int l) {
    return id[x] == id[y] && id[x + l] == id[y + l];
  }

  template <typename T> void initSA(T first, T last) {
    n = last - first, m = 0;
    for (int i = 0; i < n; ++i) {
      rk[i] = *(first + i);
      m = std::max(m, rk[i] + 1);
      id[i] = i;
    }
    radixSort();
    for (int l = 1, p = 0; p < n && l < n; m = p, l <<= 1) {
      p = 0;
      for (int i = n - l; i < n; ++i) {
        id[p++] = i;
      }
      //            std::cout << "p = " << p << ' ' << l << std::endl;
      for (int i = 0; i < n; ++i) {
        if (sa[i] >= l && p < n) {
          id[p++] = sa[i] - l;
        }
      }
      radixSort();
      for (int i = 0; i < n; ++i)
        id[i] = rk[i];
      p = 1, rk[sa[0]] = 0;
      for (int i = 1; i < n; ++i) {
        if (!cmp(sa[i - 1], sa[i], l) && p < n)
          ++p;
        rk[sa[i]] = p - 1;
      }
    }
  }
} SA;

// struct StringHash {
//     int mod;
//     int hash[N];
//     int inv[N];
//
//     StringHash(int mod) : mod(mod) {}
//
//     void init(const char *begin, const char *end) {
//         auto len = end - begin;
//         hash[0] = begin[0] - FIRST_C;
//         auto inv27 = ksm(27, mod - 2, mod);
//         inv[0] = 1;
//         for (int i = 1; i < len; ++i) {
//             hash[i] = (hash[i - 1] * 27LL) % mod + s[i] - FIRST_C;
//             if (hash[i] >= mod) {
//                 hash[i] -= mod;
//             }
//             inv[i] = (LL) inv[i - 1] * inv27 % mod;
//         }
//     }
//
//     int get(const int l, const int r) {
//         if (l == 0) {
//             return hash[r];
//         } else {
//             int ans = hash[r] - hash[l - 1];
//             if (ans >= mod) {
//                 ans -= mod;
//             } else if (ans < 0) {
//                 ans += mod;
//             }
//             ans = (LL) ans * inv[l] % mod;
//             return ans;
//         }
//     }
// } hash1(998244353), hash2(1000000007);

using ll = long long;

struct strHash {
  std::vector<ll> h, p;
  ll base, MOD;
  strHash() : h(N), p(N) {}

  void init(std::string &s, ll _base, ll _p) {
    base = _base, MOD = _p;
    int n = s.size() + 1;
    // h = std::vector<ll>(n), p = std::vector<ll>(n);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
      p[i] = p[i - 1] * base % MOD;
      h[i] = (h[i - 1] * base % MOD + s[i - 1]) % MOD;
    }
  }
  ll get(ll l, ll r) {
    r++;
    return ((h[r] - h[l] * p[r - l] % MOD) + MOD) % MOD;
  }
} hash1, hash2;

bool same(int l1, int r1, int l2, int r2) {
  if (r1 - l1 != r2 - l2) {
    return false;
  }
  return hash1.get(l1, r1) == hash1.get(l2, r2) &&
         hash2.get(l1, r1) == hash2.get(l2, r2);
}

int next_c[N];

int get_same(int x, int y) {
  int l = 0, r = std::min(n - x, n - y);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (same(x, x + mid - 1, y, y + mid - 1)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int m;
  std::cin >> m;
  std::string _s;
  for (int i = 1; i <= m; ++i) {
    std::string s_now;
    std::cin >> s_now;
    _s += s_now;
    _s.push_back(FIRST_C);
  }
  hash1.init(_s, 233, 998244353);
  hash2.init(_s, 111, 1000000007);
  n = (int)_s.length();
  std::cerr << "hahaha" << std::endl;
  //   for (int i = 0; i < n; ++i) {
  //     s[i] = _s[i];
  //   }
  //   SA.initSA(s, s + n);
  //   std::cerr << hash1.get(0, 0) << ' ' << hash1.get(5, 5) << std::endl;
  //   std::cout << s << std::endl;
  //   for (int i = 0; i < n; ++i) {
  //     std::cout << SA.sa[i] << ' ';
  //   }
  //   std::cout << std::endl;
  //   for (int i = n - 1; i >= 0; --i) {
  //     if (s[i] == '`') {
  //       next_c[i] = i;
  //     } else {
  //       next_c[i] = next_c[i + 1];
  //     }
  //   }
  //   LL ans = 0;
  //   std::cout << "s = " << s << std::endl;
  //   for (int i = 1; i < n; ++i) {
  //     int now = SA.sa[i];
  //     int lst = SA.sa[i - 1];
  //     if (s[now] == '`') {
  //       continue;
  //     }
  //     int same_l = get_same(now, lst);
  //     if (i + 1 < n) {
  //       int nxt = SA.sa[i + 1];
  //       int same_l2 = get_same(now, nxt);
  //       same_l = std::max(same_l, same_l2);
  //     }
  //     int same_pos = now + same_l - 1;
  //     std::cout << now << ' ' << lst << ' ' << get_same(now, lst) <<
  //     std::endl; ans += std::max(0, next_c[now] - same_pos - 1);
  //   }
  //   std::cout << ans << '\n';
  //   return 0;
}
