#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e9;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
struct SegmentTree {
  struct segt {
    ll l, r;
    ll sum;
  };
  vector<segt> T;

  SegmentTree(ll n) { T.resize(n << 2); }

  segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r;
    res.sum = l.sum + r.sum;
    return res;
  }
  void clear(){
    for(auto & seg: T){
      seg.sum = 0;
    }
  }
  void build(ll l, ll r, ll o = 1) {
    T[o].l = l, T[o].r = r;
    if (l == r)
      T[o].sum = 0;
    else {
      ll m = (l + r) >> 1;
      build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
      T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
  }

  segt query(ll l, ll r, ll o = 1) {
    segt e;
    e.sum = 0;
    if (l > r)
      return e;
    if (T[o].l == l && T[o].r == r)
      return T[o];
    else {
      ll m = (T[o].l + T[o].r) >> 1;
      if (r <= m)
        return query(l, r, o << 1);
      else if (l >= m + 1)
        return query(l, r, o << 1 | 1);
      return combine(query(l, m, o << 1), query(m + 1, r, o << 1 | 1));
    }
  }

  void update(ll tx, ll nx, ll o = 1) { // singly update
    if (T[o].l == T[o].r)
      T[o].sum += nx;
    else {
      ll m = (T[o].l + T[o].r) >> 1;
      if (tx <= m)
        update(tx, nx, o << 1);
      else
        update(tx, nx, o << 1 | 1);
      T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
  }
};

auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector rev(n + 1, vector<ll>(n + 1, 0));
  // discretize input
  vector<ll> disc = a;
  map<ll, ll> iv;
  sort(disc.begin() + 1, disc.end());
  FOR(i, 1, n) iv[disc[i]] = i; // any if dup
  vector<ll> nwmp(n+1);
  FOR(i,1,n) nwmp[i] = iv[a[i]];
  SegmentTree t(n + 1);
  t.build(1, n);
  FOR(i, 1, n) {
    t.clear();
    FOR(j, i, n) {
      rev[i][j] = t.query(nwmp[j] + 1, n).sum + rev[i][j - 1];
      t.update(nwmp[j], 1);
    }
  }
  vector dp(k + 1, vector<ll>(n + 1, inf));
  function<void(ll, ll, ll, ll, ll)> dfs = [&](ll l, ll r, ll L, ll R, ll x) {
    if (l > r || L > R)
      return;
    ll mid = (l + r) / 2;
    ll pos = L;
    for (ll i = L; i <= min(R, mid); ++i) {
      if (dp[x][mid] > dp[x - 1][i - 1] + rev[i][mid]) {
        dp[x][mid] = dp[x - 1][i - 1] + rev[i][mid];
        pos = i;
      }
    }
    dfs(l, mid - 1, L, pos, x);
    dfs(mid + 1, r, pos, R, x);
  };
  dp[0][0] = 0;
  for (ll i = 1; i <= n; ++i) {
    dp[0][i] = rev[1][i];
  }
  for (ll x = 1; x <= k; ++x) {
    dp[x][0] = 0;
    dfs(1, n, 1, n, x);
  }
  cout << dp[k][n] << "\n";
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