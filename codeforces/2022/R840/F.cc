#include <bits/stdc++.h>
using namespace std;
struct Tarjan_BCC {
  int n, _t, edg_id;
  vector<vector<int>> E, child;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, fa;
  vector<bool> cut;
  Tarjan_BCC(int _n)
      : n(_n), E(n), child(n), dfn(n, -1), low(n), fa(n, -1), cut(n, false) {
    edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id),
        E[v].emplace_back(edg_id);
    edg_id++;
  }
  void dfs(int u, int fa_id) {
    low[u] = dfn[u] = _t++;
    for (auto id : E[u]) {
      auto v = edges[id].first ^ edges[id].second ^ u;
      if (id == fa_id)
        continue;
      if (dfn[v] != -1) {
        low[u] = min(low[u], dfn[v]);
      } else {
        fa[v] = u;
        dfs(v, id);
        child[u].emplace_back(v), low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u])
          cut[u] = true;
      }
    }
    if (fa_id == -1)
      cut[u] = child[u].size() > 1;
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1)
        dfs(i, -1);
    }
  }
  bool is_cut(int u) { return cut[u]; }
  vector<vector<int>> BCC_point() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    stack<int> st;
    function<void(int)> dfs = [&](int u) {
      st.emplace(u), vis[u] = true;
      for (auto v : child[u]) {
        dfs(v);
        if (low[v] >= dfn[u]) {
          tmp.clear();
          while (!st.empty() && st.top() != v) {
            tmp.emplace_back(st.top());
            st.pop();
          }
          tmp.emplace_back(st.top());
          st.pop(), tmp.emplace_back(u);
          BCC.emplace_back(tmp);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        if (child[i].empty())
          BCC.emplace_back(vector{i});
        dfs(i);
      }
    }
    return BCC;
  }
  bool is_bridge(int id) {
    return is_bridge(edges[id].first, edges[id].second);
  }
  bool is_bridge(int u, int v) { // assert there's an edge u-v
    if (dfn[u] > dfn[v])
      swap(u, v);
    return low[v] > dfn[u];
  }
  vector<vector<int>> BCC_edge() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
      vis[u] = true, tmp.emplace_back(u);
      for (auto id : E[u]) {
        auto v = edges[id].first ^ edges[id].second ^ u;
        if (!is_bridge(u, v) && !vis[v])
          dfs(v);
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        tmp.clear();
        dfs(i);
        BCC.emplace_back(tmp);
      }
    }
    return BCC;
  }
};

namespace atcoder {
namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
  int x = 0;
  while (!(n & (1 << x)))
    x++;
  return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

} // namespace internal
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() const { return d[1]; }

  template <bool (*f)(S)> int max_right(int l) const {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F> int max_right(int l, F f) const {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n)
      return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)> int min_left(int r) const {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F> int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0)
      return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

private:
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

} // namespace atcoder
using ll = long long;
ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }
constexpr ll NNN = 4e5;
atcoder::segtree<ll, op, e> seg(NNN);
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), E(_n) {
    tot = -1;
  }
  void add_edge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u]) {
        continue;
      }
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) {
          continue;
        }
        tree_decomposition(v, v);
      }
    }
  }
  auto lca(int u, int v) {
    ll ans = 0;
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        ans += seg.prod(dfn[top[u]], dfn[u] + 1);
        u = fa[top[u]];
      } else {
        ans += seg.prod(dfn[top[v]], dfn[v] + 1);
        v = fa[top[v]];
      }
    }
    if (dep[u] > dep[v]) {
      ans += seg.prod(dfn[v], dfn[u] + 1);
    } else {
      ans += seg.prod(dfn[u], dfn[v] + 1);
    }
    // return dep[u] > dep[v] ? v : u;
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  Tarjan_BCC G(n);
  vector<pair<int, int>> edg;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edg.emplace_back(u, v);
    G.addEdge(u, v);
  }
  G.solve();
  auto ans = G.BCC_point();
  int N = (int)ans.size();
  heavy_light_decomposition E(N + n);
  vector<ll> contri(N), st(n);
  vector<set<ll>> in_st(n);
  for (int i = 0; i < N; ++i) {
    for (auto j : ans[i]) {
      E.add_edge(j, i + n);
      // cout<<"a"<<j+1<<"--"<<"a"<<i+n+1<<"\n";
      st[j]++;
      in_st[j].emplace(i);
      // cout<<j+1<<" ";
    }
    assert(ans[i].size() >= 2);

    // cout<<"\n";
    // cout<<contri[i]<<"\n";
  }

  for (auto &[u, v] : edg) {
    for (auto i : in_st[u]) {
      if (in_st[v].contains(i)) {
        contri[i]++;
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!G.is_cut(i)) {
      assert(st[i] == 1);
    }
  }
  E.tree_build(0);
  E.tree_decomposition(0, 0);
  for (int i = 0; i < N; ++i) {
    if (ans[i].size() == 2)
      contri[i] = 0;
    seg.set(E.dfn[i + n], contri[i]);
    // cout << contri[i] << " ";
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    // cout<<E.dfn[a]<<" "<<E.dfn[b]<<"\n"
    cout << E.lca(a, b) << "\n";
  }
}