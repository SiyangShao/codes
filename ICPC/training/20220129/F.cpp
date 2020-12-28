#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define ROF(i, a, b) for (ll i = (a); i >= (b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
const ll maxn = 200005; // TODO
bool a[200005];
ll n;
struct segt {
	ll l, r;
	ll cnt, nl, nr; // TODO
} T[maxn << 2];

segt combine(segt l, segt r) {
	segt res;
	res.l = l.l, res.r = r.r, res.cnt = l.cnt + r.cnt;
	res.cnt +=
		l.nr * r.nl; // because the last one of l is for check if can connect
	if (l.nl == l.r - l.l + 1)
		res.nl = l.nl + r.nl;
	else
		res.nl = l.nl;

	if (r.nl == r.r - r.l + 1)
		res.nr = l.nr + r.nl;
	else
		res.nr = r.nr;
	return res;
}

void build(ll o, ll l, ll r) {
	T[o].l = l, T[o].r = r;
	if (l == r)
		T[o].cnt = T[o].nl = T[o].nr = (a[l] != a[l + 1]);
	else {
		ll m = l + r >> 1;
		build(o << 1, l, m), build(o << 1 | 1, m + 1, r);
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

void update(ll o, ll tx) { // singly update
	if (T[o].l == T[o].r) {
		T[o].cnt = !T[o].cnt;
		T[o].nl = !T[o].nl;
		T[o].nr = !T[o].nr;
	} else {
		ll m = T[o].l + T[o].r >> 1;
		if (tx <= m)
			update(o << 1, tx);
		else
			update(o << 1 | 1, tx);
		T[o] = combine(T[o << 1], T[o << 1 | 1]);
	}
}

void solve() {
	ll nP, q;
	cin >> nP >> q;
	n = nP - 1;
	FOR(i, 1, nP) cin >> a[i];
	build(1, 1, n);
	FOR(tq, 1, q) {
		ll mode, u, v;
		cin >> mode >> u >> v;
		if (mode == 1) {
			if (u - 1 >= 1)
				update(1, u - 1);
			if (v <= nP - 1)
				update(1, v);
		} else {
			cout << query(1, u, v - 1).cnt + (v - u + 1) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll T = 1;
	// cin >> T;
	while (T--)
		solve();
	return 0;
}
