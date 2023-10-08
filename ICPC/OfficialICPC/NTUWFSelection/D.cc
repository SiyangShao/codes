// 1. below use 32 bit int and double. check your data range and precision
// 2. ALWAYS round result by +-0.5 (+ 0.5 is pos; -0.5 if neg); this is how I
// fail in Seoul one
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define sz(x) (x).size()
#define rep(i, j, n) for (int(i) = (j); (i) < (n); ++(i))
#define all(x) (x).begin(), (x).end()
using ld = long double;
#define double ld
using C = complex<double>;
using vd = vector<double>;
using vi = vector<int>;
void fft(vector<C> &a) {
  int n = sz(a), L = 31 - __builtin_clz(n);
  static vector<complex<double>> R(2, 1);
  static vector<C> rt(2, 1); // (^ 10% faster if double)
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(1.0L, acos(-1.0L) / k);
    rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
  }
  vi rev(n);
  rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      rep(j, 0, k) {
        // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  ///
        // include-line
        auto x = (double *)&rt[j + k],
             y = (double *)&a[i + j + k]; /// exclude-line
        C z(x[0] * y[0] - x[1] * y[1],
            x[0] * y[1] + x[1] * y[0]); /// exclude-line
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
}
vd conv(const vd &a, const vd &b) {
  if (a.empty() || b.empty())
    return {};
  vd res(sz(a) + sz(b) - 1);
  int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
  vector<C> in(n), out(n);
  copy(all(a), begin(in));
  rep(i, 0, sz(b)) in[i].imag(b[i]);
  fft(in);
  for (C &x : in)
    x *= x;
  rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4 * n);
  return res;
}

using ll = long long;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v;
    w = 1;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }

  vector<int> siz(n), mx(n), vis(n), dis(n);
  int root = -1;
  function<void(int, int, int)> getRoot = [&](int u, int fa, int tot) {
    siz[u] = 1;
    mx[u] = 0;
    for (auto [v, w] : E[u]) {
      if (v == fa || vis[v])
        continue;
      getRoot(v, u, tot);
      siz[u] += siz[v];
      mx[u] = max(siz[v], mx[u]);
    }
    mx[u] = max(mx[u], tot - siz[u]);
    if (root == -1 || mx[u] < mx[root]) {
      root = u;
    }
  };
  getRoot(0, 0, n);
  vector<vector<int>> vec(n);
  function<void(int, int, ll, int)> get_dis = [&](int u, int fa, int d,
                                                  int from) {
    vec[from].emplace_back(d);
    dis[u] = d;
    for (auto [v, w] : E[u]) {
      if (v == fa || vis[v])
        continue;
      get_dis(v, u, d + w, from);
    }
  };
  vd ans(n + 1);
  vector<ll> mxd(n + 1);
  function<void(int)> cal = [&](int u) {
    dis[u] = 0;
    ll mx = 0;
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      vec[v].clear();
      get_dis(v, u, w, v);
      if (vec[v].empty())
        continue;
      mxd[v] = *max_element(vec[v].begin(), vec[v].end());
      mx = max(mx, mxd[v]);
    }
    vd allOther(mx + 1, 0);
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      ll d = mxd[v];
      // cerr << v << " " << d << endl;
      vd vvv(d + 1, 0);
      for (auto i : vec[v]) {
        vvv[i]++;
        ans[i]++;
      }
      // cout << "COV\n";
      // for (auto i : allOther) {
      //   cout << i << " ";
      // }
      // cout << "\n";
      // for (auto i : vvv) {
      //   cout << i << " ";
      // }
      // cout << "\n";
      auto tmp = conv(allOther, vvv);
      // for (auto i : tmp) {
      //   cout << i << " ";
      // }
      // cout << "\n";
      // cout<<"END\n";
      for (int i = 0; i < (int)tmp.size(); ++i) {
        ans[i] += tmp[i];
      }
      for (auto i : vec[v]) {
        allOther[i]++;
      }
    }
  };
  function<void(int)> dp = [&](int u) {
    vis[u] = 1;
    cal(u);
    for (auto [v, w] : E[u]) {
      if (vis[v])
        continue;
      root = -1;
      getRoot(v, 0, siz[v]);
      dp(root);
    }
  };
  dp(root);
  constexpr int MOD = 1e9 + 7;
  function<int(int, int)> qpow = [&](int x, int y) {
    int res = 1;
    while (y) {
      if (y & 1)
        res = res * x % MOD;
      x = x * x % MOD;
      y >>= 1;
    }
    return res;
  };
  int cnt = 1;
  for (int i = 1; i <= n; ++i) {
    cnt = cnt * i % MOD;
  }
  int sum = n;
  for (int i = 0; i <= n; ++i) {
    sum = sum + 2 * ((int)(ans[i] + 0.5)) * qpow(i + 1, MOD - 2) % MOD;
    sum %= MOD;
  }
  sum = sum * cnt % MOD;
  cout << sum << "\n";
}