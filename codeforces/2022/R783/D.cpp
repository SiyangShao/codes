#include <bits/stdc++.h>
using namespace std;
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
using ll = long long;
constexpr ll INF = 1e18;
inline auto mmax(ll x, ll y) { return max(x, y); }
inline auto emax() { return -INF; }
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    // vector<ll> dp(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     dp[i] = -1e9;
    //     for (int j = 0; j < i; j++) {
    //         if (a[i] > a[j]) {
    //             dp[i] = max(dp[i], dp[j] + i - j);
    //         } else if (a[i] == a[j]) {
    //             dp[i] = max(dp[i], dp[j] + 0);
    //         } else if (a[i] < a[j]) {
    //             dp[i] = max(dp[i], dp[j] - (i - j));
    //         }
    //     }
    //      // take maximum dp[j] -j for a[j] < a[i], maximum dp[j] + j for a[j] > a[i], and dp[j] for a[j] == a[i]
    // }
    // cout << dp[n] << "\n";
    auto discrete = a;
    sort(discrete.begin(), discrete.end());
    discrete.erase(unique(discrete.begin(), discrete.end()), discrete.end());
    unordered_map<ll, ll> mp, same;
    for (int i = 0; i < discrete.size(); ++i) {
        mp[discrete[i]] = i;
        same[discrete[i]] = -INF;
    }
    segtree<ll, mmax, emax> lef(discrete.size());
    segtree<ll, mmax, emax> rig(discrete.size());
    lef.set(mp[0], 0);
    rig.set(mp[0], 0);
    same[0] = 0;
    ll cnt = -INF;
    for (int i = 1; i <= n; ++i) {
        cnt = -INF;
        auto l = lef.prod(0, mp[a[i]]);
        cnt = max(cnt, l + i);
        auto r = rig.prod(mp[a[i]] + 1, discrete.size());
        cnt = max(cnt, r - i);
        cnt = max(cnt, same[a[i]]);
        // cout << l + i << " " << r - i << " " << same[a[i]] << " " << cnt
        //      << endl;
        if (same[a[i]] < cnt)
            same[a[i]] = cnt;
        if (lef.get(mp[a[i]]) < cnt - i)
            lef.set(mp[a[i]], cnt - i);
        if (rig.get(mp[a[i]]) < cnt + i)
            rig.set(mp[a[i]], cnt + i);
    }
    cout << cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}