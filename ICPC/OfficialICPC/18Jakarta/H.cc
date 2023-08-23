#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

/*
    - N, K <= 1e5
    - scanline. we always fill -1 as long as all rest condition are not violated in best case
    - segt maintains (seg best cases sum) - (min. val)
    - so "all cond are satisfied" becomes "min of segt >= 0"
    - activate condition only if currently inside.
    
    - for each element:
        - activate all new segment (set into len - mval)
        - deactivate all old segment (set into 1e16)
        
        - check if min >= 2
*/

const ll sz = 100005;
struct segt {
    ll l, r;
    ll ans;
    ll tag;
} T[sz << 2];

segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r, res.tag = 0;
    res.ans = min(l.ans, r.ans);
    return res;
}

void pushTag(ll o) {
    ll& tg = T[o].tag;
    if (T[o].l != T[o].r) {
        T[o << 1].tag += tg, T[o << 1].ans += tg;
        T[o << 1 | 1].tag += tg, T[o << 1 | 1].ans += tg;
    }
    tg = 0;
}

void build(ll o, ll l, ll r) {
    T[o].l = l, T[o].r = r, T[o].tag = 0;
    T[o].ans = 1e16;
    if (l == r) return;
    else {
        ll m = (l + r) >> 1;
        build(o << 1, l, m), build(o << 1 | 1, m + 1, r);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
}

segt query(ll o, ll l, ll r) {
    pushTag(o);
    if (T[o].l == l && T[o].r == r)
        return T[o];
    else {
        ll m = (T[o].l + T[o].r) >> 1;
        if (r <= m)
            return query(o << 1, l, r);
        else if (l >= m + 1)
            return query(o << 1 | 1, l, r);
        return combine(query(o << 1, l, m), query(o << 1 | 1, m + 1, r));
    }
}

void updateRange(ll o, ll l, ll r, ll dx) {
    pushTag(o);
    if (T[o].l == l && T[o].r == r)
        T[o].ans += dx, T[o].tag = dx;
    else {
        ll m = T[o].l + T[o].r >> 1;
        if (r <= m)
            updateRange(o << 1, l, r, dx);
        else if (l >= m + 1)
            updateRange(o << 1 | 1, l, r, dx);
        else
            updateRange(o << 1, l, m, dx), updateRange(o << 1 | 1, m + 1, r, dx);
        T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
}

void update(ll o, ll tx, ll nx) { // singly update
    pushTag(o);
	if (T[o].l == T[o].r) T[o].ans = nx;
	else {
		ll m = T[o].l + T[o].r >> 1;
		if (tx <= m) update(o << 1, tx, nx);
		else update(o << 1 | 1, tx, nx);
		T[o] = combine(T[o << 1], T[o << 1 | 1]);
	}
}

ll a[sz];
vector<tuple<ll, ll, ll>> cst;
vector<ll> begs[sz];
vector<ll> theEnd[sz];
void solve() {
    ll n, k; cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    vector<ll> pf(n + 1); FOR(i, 1, n) pf[i] = pf[i - 1] + (a[i] == 0 ? 1 : a[i]);

    build(1, 1, k);
    cst.emplace_back(0, 0, 0); // pad into 1-index
    FOR(t, 1, k) {
        ll u, v, w; cin >> u >> v >> w;
        cst.emplace_back(u, v, w);
        begs[u].emplace_back(cst.size() - 1);
        theEnd[v + 1].emplace_back(cst.size() - 1);
    }

    FOR(i, 1, n) {
        for (auto e: theEnd[i]) update(1, e, 1e16);
        for (auto e: begs[i]) {
            auto [u, v, w] = cst[e];
            update(1, e, pf[v] - pf[u - 1] - w);
        } if (query(1, 1, k).ans >= 2) {
            updateRange(1, 1, k, -2);
            a[i] = -1;
        } else {
            if (query(1, 1, k).ans < 0) {
                cout << "Impossible" << endl;
                return;
            }
            a[i] = 1;
        }
    }

    FOR(i, 1, n) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}