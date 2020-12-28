#include <algorithm>
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
inline auto mmax(ll x, ll y) { return max(x, y); };
inline auto emax() { return 0LL; }
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    map<ll, vector<ll>> mp;
    mp.clear();
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].emplace_back(i);
    }
    segtree<ll, mmax, emax> st(n);
    for (ll i = 0; i < n; ++i) {
        st.set(i, i);
    }
    vector<pair<ll, ll>> segment;
    for (ll i = 0; i < m; ++i) {
        ll L, R;
        cin >> L >> R;
        L--, R--;
        segment.emplace_back(L, R);
        R = max(R, st.get(L));
        st.set(L, R);
    }
    auto L = n - 1;
    set<ll> s;
    vector<ll> minL(n);
    minL.assign(n, 0);
    for (auto R = n - 1; R >= 0; --R) {
        while (L >= 0 && !s.count(a[L])) {
            s.insert(a[L]);
            L--;
        }
        minL[R] = L + 1;
        s.erase(a[R]);
    }
    auto maxR = -1LL;
    for (auto [L, R] : segment) {
        if (minL[R] <= L)
            continue;
        maxR = max(maxR, minL[R] - 1);
    }
    if (maxR == -1) {
        cout << "0\n";
        return;
    }
    auto ans = maxR + 1, R = maxR;
    for (ll L = 0; L < n; ++L) {
        auto &lst = mp[a[L]];
        if (lst.front() != L) {
            auto pos = lower_bound(lst.begin(), lst.end(), L);
            pos--;
            if (st.prod(0, *pos + 1) >= L) {
                break;
            }
        }
        auto pos = upper_bound(lst.begin(), lst.end(), R);
        if (pos != lst.end()) {
            if (st.prod(0, L + 1) >= *pos) {
                R = *pos;
            }
        }
        R = max(R, L + 1);
        ans = min(ans, R - L);
    }
    cout << ans << "\n";
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