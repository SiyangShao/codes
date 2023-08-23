// Segement Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MAXN = 1e5 + 7;
ll n, m;
ll ans[MAXN << 2], a[MAXN], tag[MAXN << 2];
inline ll ls(ll p) {
	return p << 1; // left son
}
inline ll rs(ll p) {
	return p << 1 | 1; // right son
}
inline void push_up(ll p) { ans[p] = ans[ls(p)] + ans[rs(p)]; }
void build(ll p = 1, ll l = 1, ll r = n) {
	if (l == r) {
		ans[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	push_up(p);
}
inline void change(ll p, ll l, ll r, ll k) {
	tag[p] = tag[p] + k;
	ans[p] = ans[p] + k * (r - l + 1);
}
inline void push_down(ll p, ll l, ll r) {
	ll mid = (l + r) >> 1;
	change(ls(p), l, mid, tag[p]);
	change(rs(p), mid + 1, r, tag[p]);
	tag[p] = 0;
}
inline void update(ll nl, ll nr, ll k, ll l = 1, ll r = n, ll p = 1) {
	if (nl <= l && r <= nr) {
		ans[p] += k * (r - l + 1);
		tag[p] += k;
		return;
	}
	push_down(p, l, r);
	ll mid = (l + r) >> 1;
	if (nl <= mid)
		update(nl, nr, k, l, mid, ls(p));
	if (nr > mid)
		update(nl, nr, k, mid + 1, r, rs(p));
	push_up(p);
}
ll query(ll q_x, ll q_y, ll l = 1, ll r = n, ll p = 1) {
	ll res = 0;
	if (q_x <= l && r <= q_y)
		return ans[p];
	ll mid = (l + r) >> 1;
	push_down(p, l, r);
	if (q_x <= mid)
		res += query(q_x, q_y, l, mid, ls(p));
	if (q_y > mid)
		res += query(q_x, q_y, mid + 1, r, rs(p));
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build();
	ll op, x, y, k;
	while (m--) {
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> k;
			update(x, y, k);
		} else {
			cin >> x >> y;
			cout << query(x, y) << "\n";
		}
	}
}