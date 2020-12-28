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
    ll val, locked_sum, unlocked_sum, len;
};
node op(node l, node r) {
    auto locked = min(l.locked_sum, r.locked_sum);
    auto unlocked = min(r.unlocked_sum, l.unlocked_sum);
    return node{min(locked, unlocked), locked, unlocked, l.len + r.len};
}
constexpr node e() { return node{1LL << 60, 1LL << 60, 1LL << 60, 1LL << 60}; }

node mapping(ll f, node x) {
    auto locked = x.locked_sum;
    auto unlocked = x.unlocked_sum + f;
    return node{min(locked, unlocked), locked, unlocked, x.len};
}

ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; };
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<node> a(n);
    for (ll i = 0; i < n; ++i) {
        a[i].val = 0;
        a[i].unlocked_sum = 0;
        a[i].locked_sum = 1LL << 60;
        a[i].len = 1;
    }
    // Prime: 2	3	5	7	11	13	17	19	23	29
    array<ll, 10> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    array<lazy_segtree<node, op, e, ll, mapping, composition, id>, 10> seg;
    for (ll i = 0; i < 10; ++i) {
        seg[i] = lazy_segtree<node, op, e, ll, mapping, composition, id>(a);
    }
    while (q--) {
        string s;
        cin >> s;
        if (s[0] == 'f') {
            ll x;
            cin >> x;
            x--;
            for (ll i = 0; i < 10; ++i) {
                auto pos = seg[i].get(x);
                swap(pos.locked_sum, pos.unlocked_sum);
                seg[i].set(x, pos);
            }
        } else if (s[0] == 'm') {
            ll l, r, x;
            cin >> l >> r >> x;
            for (ll i = 0; i < 10; ++i) {
                ll cnt = 0;
                while (x % prime[i] == 0) {
                    x /= prime[i];
                    cnt++;
                }
                seg[i].apply(l - 1, r, cnt);
            }
        } else {
            ll l, r, x;
            cin >> l >> r >> x;
            auto X = x;
            for (ll i = 0; i < 10; ++i) {
                ll cnt = 0;
                while (X % prime[i] == 0) {
                    x /= prime[i];
                    cnt++;
                }
                auto su = seg[i].prod(l - 1, r).val;
                if (su >= cnt) {
                    continue;
                } else {
                    x = 0;
                    break;
                }
            }
            if (x == 0) {
                cout << "NO\n";
                continue;
            } else {
                cout << "YES\n";
                cin >> l >> r >> x;
                for (ll i = 0; i < 10; ++i) {
                    ll cnt = 0;
                    while (x % prime[i] == 0) {
                        x /= prime[i];
                        cnt++;
                    }
                    seg[i].apply(l - 1, r, -cnt);
                }
            }
        }
    }
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}