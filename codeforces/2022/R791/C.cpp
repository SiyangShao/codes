#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    [[nodiscard]] S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    [[nodiscard]] S prod(int l, int r) const {
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

    [[nodiscard]] S all_prod() const { return d[1]; }

    template <bool (*f)(S)> [[nodiscard]] int max_right(int l) const {
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

    template <bool (*f)(S)> [[nodiscard]] int min_left(int r) const {
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
using namespace atcoder;
inline auto mmax(ll x, ll y) { return x + y; }
inline auto emax() { return 0LL; }
auto solve() {
    ll n, q;
    cin >> n >> q;
    segtree<ll, mmax, emax> col(n), rol(n);
    vector<ll> c(n), r(n);
    c.assign(n, 0), r.assign(n, 0);
    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            c[x]++, r[y]++;
            if (c[x] == 1)
                col.set(x, 1);
            if (r[y] == 1)
                rol.set(y, 1);
        } else if (op == 2) {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            c[x]--, r[y]--;
            if (c[x] == 0)
                col.set(x, 0);
            if (r[y] == 0)
                rol.set(y, 0);
        } else {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, x2--, y1--, y2--;
            // cout<<col.prod(x1,x2+1)<<" "<<rol.prod(y1,y2+1)<<"\n";
            if (col.prod(x1, x2 + 1) == x2 - x1 + 1 ||
                rol.prod(y1, y2 + 1) == y2 - y1 + 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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