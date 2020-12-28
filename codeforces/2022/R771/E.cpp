// ODT
// Only 30 points
#include <bits/stdc++.h>
typedef long long ll;
#define int ll
using namespace std;
constexpr int N = 1e6 + 7;
int a[N], col[N];
int n, q;
// Here is Fenwick Tree
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, int k) {
	while (x <= N) {
		a[x] += k;
		x += lowbit(x);
	}
}
inline void update(int l, int r, int k) {
	add(l, k);
	add(r + 1, -k);
}
inline int find(int x) {
	int res = 0;
	while (x) {
		res += a[x];
		x -= lowbit(x);
	}
	return res;
}
// Here is ODT
struct Node_t {
	int l, r;
	mutable int v;
	Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}
	bool operator<(const Node_t &rhs) const { return l < rhs.l; }
};
set<Node_t> odt;
auto split(int x) {
	if (x > n)
		return odt.end();
	auto it = --odt.upper_bound((Node_t){x, 0, 0});
	if (it->l == x)
		return it;
	auto l = it->l, r = it->r, v = it->v;
	odt.erase(it);
	odt.insert(Node_t{l, x - 1, v});
	return odt.insert(Node_t(x, r, v)).first;
}
void assign(int l, int r, int v) {
	auto itr = split(r + 1), itl = split(l);
	for (auto i = itl; i != itr; ++i) {
		update(i->l, i->r, col[i->v] - col[v]);
	}
	odt.erase(itl, itr);
	odt.insert(Node_t(l, r, v));
}
int getcol(int x) {
	auto it = odt.lower_bound((Node_t){x, 0, 0});
	if (it != odt.end() && it->l == x)
		return it->v;
	else {
		--it;
		return it->v;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	odt.insert(Node_t(-100, n + 100, 1));
	while (q--) {
		string s;
		cin >> s;
		if (s[0] == 'C') {
			int l, r, c;
			cin >> l >> r >> c;
			assign(l, r, c);
		} else if (s[0] == 'Q') {
			int l;
			cin >> l;
			cout << find(l) + col[getcol(l)] << "\n";
		} else {
			int c, x;
			cin >> c >> x;
			col[c] += x;
		}
	}
}