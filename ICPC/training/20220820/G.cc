#include <bits/stdc++.h>
using namespace std;
constexpr int MAXLEN = 1000010;
constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);
array<uint64_t, MAXLEN> base_pow;
int64_t modmul(uint64_t a, uint64_t b) {
  uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret =
      (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return ret - 1;
}
void init() {
  base_pow[0] = 1;
  for (int i = 1; i < MAXLEN; i++) {
    base_pow[i] = modmul(base_pow[i - 1], base);
  }
}
struct PolyHash {
  /// Remove suff vector and usage if reverse hash is not required for more
  /// speed
  vector<int64_t> pref, suff;

  PolyHash() = default;

  PolyHash(const string &ar) {
    if (!base_pow[0])
      init();

    int n = ar.length();
    assert(n < MAXLEN);
    pref.resize(n + 3, 0), suff.resize(n + 3, 0);

    for (int i = 1; i <= n; i++) {
      pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
      if (pref[i] >= mod)
        pref[i] -= mod;
    }

    for (int i = n; i >= 1; i--) {
      suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
      if (suff[i] >= mod)
        suff[i] -= mod;
    }
  }
  uint64_t get_hash(int l, int r) {
    int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
    return h < 0 ? h + mod : h;
  }

  uint64_t rev_hash(int l, int r) {
    int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
    return h < 0 ? h + mod : h;
  }
};
auto solve() {
  string s;
  cin >> s;
  int l = 1, r = s.length();
  s = "_" + s;
  PolyHash H = PolyHash(s);
  while (s[l] == s[r] && l < r) {
    l++;
    r--;
  }
  if (l >= r) {
    cout << 1 << " " << s.length() - 1 << "\n";
    return;
  }
  auto Equal = [&](int l1, int r1, int l2, int r2) {
    return H.get_hash(l1, r1) == H.get_hash(l2, r2);
  };
  auto judge = [&](int l1, int r1) {
    if (l1 == r1 + 1)
      return true;
    return H.get_hash(l1, r1) == H.rev_hash(l1, r1);
  };
  // S1 S1 S2
  for (int i = l; i <= r; i++) {
    // s1 = [l, i]
    int l2 = i + 1;
    int r2 = l2 + (i - l);
    if (r2 > r) {
      break;
    }
    if (Equal(l, i, l2, r2) && judge(r2 + 1, r)) {
      cout << l2 << " " << r << "\n";
      return;
    }
  }
  // S2 S1 S1
  for (int i = l - 1; i <= r; ++i) {
    int l1 = i + 1;
    int len_all = (r - l1 + 1);
    if (len_all % 2 == 1)
      continue;
    len_all /= 2;
    int r1 = l1 + len_all - 1;
    if (judge(l, i) && Equal(l1, r1, r1 + 1, r)) {
      cout << l << " " << r1 << "\n";
      return;
    }
  }
  // S1 s2 s1
  for (int i = l; i <= r; ++i) {
    int len = i - l + 1;
    int l2 = r - len + 1;
    if (l2 <= i) {
      break;
    }
    if (Equal(l, i, l2, r) && judge(i + 1, l2 - 1)) {
      cout << l << " " << i << "\n";
      return;
    }
  }
  cout << "-1 -1\n";
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