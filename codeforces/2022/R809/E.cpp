#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace atcoder {
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
            std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int> &v) { return v.empty(); }),
                     result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};
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
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++)
            d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r)
            return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }

        S sml = e(), smr = e();
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

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r)
            return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1)
                    all_apply(l++, f);
                if (r & 1)
                    all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l)
                update(l >> i);
            if (((r >> i) << i) != r)
                update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n)
            return _n;
        l += size;
        for (int i = log; i >= 1; i--)
            push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0)
                l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0)
            return 0;
        r += size;
        for (int i = log; i >= 1; i--)
            push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size)
            lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

} // namespace atcoder
using namespace atcoder;
struct node {
    ll mx;
    ll len;
};
node op(node l, node r) { return node{max(l.mx, r.mx), l.len + r.len}; }
node e() { return node{0, 0}; }
struct F {
    ll st;
};
node mapping(F f, node x) { return node{min(x.mx, f.st), x.len}; }
F composition(F f, F g) {
    // f(g())
    return F{min(f.st, g.st)};
}
constexpr ll N = 2e5;
F id() { return F{N}; }
class heavy_light_decomposition {
  public:
    ll n = 0, m = 0, s = 0, tot = 0;
    lazy_segtree<node, op, e, F, mapping, composition, id> seg;
    vector<vector<pair<ll, ll>>> E;
    vector<ll> fa, dep, siz, son, top, dfn, rnk;
    auto init() {
       
    }
    heavy_light_decomposition(ll _n) : n(_n) {
        init();
        seg = lazy_segtree<node, op, e, F, mapping, composition, id>(
            vector<node>(n, {N, 1}));
    }
    auto tree_build(ll u) -> ll {
        siz[u] = 1;
        for (auto [v, id] : E[u]) {
            if (v == fa[u])
                continue;
            fa[v] = u;
            dep[v] = dep[u] + 1;
            siz[u] += tree_build(v);
            if (siz[v] > siz[son[u]]) {
                son[u] = v;
            }
        }
        return siz[u];
    }
    auto tree_decomposition(ll u, ll tp) -> void {
        top[u] = tp;
        dfn[u] = ++tot;
        rnk[tot] = u;
        if (son[u]) {
            tree_decomposition(son[u], tp);
            for (auto [v, id] : E[u]) {
                if (v == son[u] || v == fa[u]) {
                    continue;
                }
                tree_decomposition(v, v);
            }
        }
    }
    auto dfs(ll u, ll fa) -> void {
        if (u == 1) {
            seg.set(dfn[u], {0, 1});
        }
        for (auto [v, id] : E[u]) {
            if (v == fa)
                continue;
            seg.set(dfn[v], {id, 1});
            dfs(v, u);
        }
    }
    auto get_comp(ll u) {
        ll L = top[u];
        // cout << "From " << L << "to " << u << " \n";
        assert(dfn[L] != 0 && dfn[u] != 0 && dfn[L] <= n && dfn[u] <= n);
        assert(dfn[L] <= dfn[u]);
        return seg.prod(dfn[L], dfn[u] + 1).mx;
    }
    auto lca(int u, int v) -> ll {
        ll ans = 0;
        // cout << u << " " << v << " " << top[u] << " " << top[v] << "\n";
        // cout << dfn[u] << " " << dfn[v] << "\n";
        while (top[u] != top[v]) {
            // cout<<fa[top[u]]<<" "<< fa[top[v]]<< " "<< u<<" "<<v<<"\n";
            if (dep[top[u]] > dep[top[v]]) {
                ans = max(ans, get_comp(u));
                u = fa[top[u]];

            } else {
                ans = max(ans, get_comp(v));
                v = fa[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            ans = max(ans, seg.prod(dfn[v] + 1, dfn[u] + 1).mx);
        } else {
            ans = max(ans, seg.prod(dfn[u] + 1, dfn[v] + 1).mx);
        }
        return ans;
    }
};
auto solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    heavy_light_decomposition hld(n + 1);
    dsu DSU(n + 1);
    for (ll i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        if (DSU.same(u, v))
            continue;
        DSU.merge(u, v);
        hld.E[u].emplace_back(v, i);
        hld.E[v].emplace_back(u, i);
    }
    hld.tree_build(1);
    hld.tree_decomposition(1, 1);
    hld.dfs(1, 1);
    lazy_segtree<node, op, e, F, mapping, composition, id> seg(
        vector<node>(n, {N, 1}));
    for (ll i = 1; i < n; ++i) {
        seg.set(i, {hld.lca(i, i + 1), 1});
    }
    while (q--) {
        ll L, R;
        cin >> L >> R;
        cout << seg.prod(L, R).mx << " ";
        // cout << hld.lca(L, R) << " ";
    }
    cout << "\n";
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