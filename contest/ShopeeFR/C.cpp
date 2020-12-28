#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define ROF(i, a, b) for (ll i = (a); i >= (b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
const ll maxn = 150002; // TODO
ll a[maxn];
ll n;
struct segt {
    ll l, r;
    ll val;
} T[maxn << 2];
// dp[i][x] = the maximum points he get for time from [1, i] flames, when he
// eventually arrives at x.
ll curdp[150002];
ll pts[302], pos[302], starttime[302];

segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r;
    res.val = max(l.val, r.val);
    return res;
}

void build(ll i, ll o, ll l, ll r) {
    T[o].l = l, T[o].r = r;
    if (l == r)
        T[o].val = curdp[l];
    else {
        ll m = l + r >> 1;
        build(i, o << 1, l, m), build(i, o << 1 | 1, m + 1, r);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
}

segt query(ll o, ll l, ll r) {
    if (T[o].l == l && T[o].r == r)
        return T[o];
    else {
        ll m = T[o].l + T[o].r >> 1;
        if (r <= m)
            return query(o << 1, l, r);
        else if (l >= m + 1)
            return query(o << 1 | 1, l, r);
        return combine(query(o << 1, l, m), query(o << 1 | 1, m + 1, r));
    }
}

void update(ll o, ll tx, ll nx) { // singly update
    if (T[o].l == T[o].r)
        T[o].val = nx;
    else {
        ll m = T[o].l + T[o].r >> 1;
        if (tx <= m)
            update(o << 1, tx, nx);
        else
            update(o << 1 | 1, tx, nx);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
}

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<tuple<ll, ll, ll>> v;
    ll tpts = 0;
    FOR(i, 1, m) {
        ll pos, pts, time;
        cin >> pos >> pts >> time;
        tpts += pts;
        v.emplace_back(time, pos, pts);
    }
    sort(all0(v));
    FOR(i, 0, m - 1) {
        const auto &[ttime, tpos, tpts] = v[i];
        pos[i + 1] = tpos, pts[i + 1] = tpts, starttime[i + 1] = ttime;
    }
    FOR(x, 1, n) curdp[x] = tpts;

    FOR(i, 1, m) {
        build(i - 1, 1, 1, n);
        FOR(x, 1, n)
        curdp[x] = query(1, max(1, x - d * (starttime[i] - starttime[i - 1])),
                         min(n, x + d * (starttime[i] - starttime[i - 1])))
                       .val -
                   abs(x - pos[i]);
    }
    ll ans = 0;
    FOR(x, 1, n) chkmax(ans, curdp[x]);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> T;
    solve();
    return 0;
}