#include <bits/stdc++.h>
using namespace std;
using ll = long long;
std::tuple<long long, long long, long long> extendedGCD(long long a,
                                                        long long b) {
  if (b == 0) {
    return std::make_tuple(a, 1, 0);
  }
  long long d, x, y;
  std::tie(d, x, y) = extendedGCD(b, a % b);
  return std::make_tuple(d, y, x - (a / b) * y);
}
std::pair<long long, long long>
chineseRemainderTheorem(const std::vector<long long> &remainders,
                        const std::vector<long long> &moduli) {
  long long a = remainders[0], m = moduli[0];
  for (int i = 1; i < (int)remainders.size(); ++i) {
    long long b = remainders[i], n = moduli[i];
    long long d, x, y;
    std::tie(d, x, y) = extendedGCD(m, n);
    if ((b - a) % d != 0) {
      return {-1, -1};
    }
    long long t = (b - a) / d * x % (n / d);
    a += m * t;
    m *= n / d;
  }
  if (a < 0) {
    a += m;
  }
  return {a, m};
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  vector<int> ida(n), idb(n), idc(n);
  for (auto &i : a)
    cin >> i, i--;
  for (auto &i : b)
    cin >> i, i--;
  for (auto &i : c)
    cin >> i, i--;

  vector<int> abc(n), bca(n), cab(n);
  for (int i = 0; i < n; ++i) {
    ida[a[i]] = idb[b[i]] = idc[c[i]] = i;
    abc[i] = a[b[c[i]]];
    bca[i] = b[c[a[i]]];
    cab[i] = c[a[b[i]]];
  }
  int lena = 0, lenb = 0, lenc = 0;
  vector<int> disa(n, -1), disb(n, -1), disc(n, -1);
  auto dis = [](vector<int> &vec, vector<int> &nxt, int &len) {
    int cur = 0;
    while (vec[cur] == -1) {
      vec[cur] = len++;
      cur = nxt[cur];
    }
  };
  dis(disa, abc, lena);
  dis(disb, bca, lenb);
  dis(disc, cab, lenc);
  // for (int i = 0; i < n; ++i) {
  //   cerr << disa[i] << " " << disb[i] << " " << disc[i] << "\n";
  // }
  auto cal = [&](int x, int y, int z) {
    if (x == -1 || y == -1 || z == -1)
      return -1LL;
    vector<ll> remainders = {x, y, z};
    vector<ll> mods = {lena, lenb, lenc};
    auto [ans, mod] = chineseRemainderTheorem(remainders, mods);
    return ans;
  };
  int Q;
  cin >> Q;
  while (Q--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--, z--;
    auto fi = cal(disa[x], disb[y], disc[z]);
    auto se = cal(disa[idc[z]], disb[ida[x]], disc[idb[y]]);
    auto th = cal(disa[idc[idb[y]]], disb[ida[idc[z]]], disc[idb[ida[x]]]);
    // cerr << fi << " " << se << " " << th << "\n";
    constexpr ll inf = 1e16;
    auto ans = min({fi == -1 ? inf : fi * 3, se == -1 ? inf : se * 3 + 1,
                    th == -1 ? inf : th * 3 + 2});
    cout << (ans == inf ? -1 : ans) << "\n";
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