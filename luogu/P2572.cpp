// ODT
// Only 30 points
#include <bits/stdc++.h>
using namespace std;
int n, q;
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
	odt.erase(itl, itr);
	odt.insert(Node_t(l, r, v));
}
void change(int l, int r) {
	auto itr = split(r + 1), itl = split(l);
	for (; itl != itr; ++itl) {
		itl->v = 1 - itl->v;
	}
}
int query(int l, int r) {
	auto itr = split(r + 1), itl = split(l);
	auto ans = 0;
	for (; itl != itr; ++itl) {
		ans += itl->v * (itl->r - itl->l + 1);
	}
	return ans;
}
int mx(int l, int r) {
	auto itr = split(r + 1), itl = split(l);
	auto ans = 0, tmp = 0;
	for (; itl != itr; ++itl) {
		if (itl->v == 0) {
			tmp = 0;
		} else {
			tmp += itl->r - itl->l + 1;
			ans = max(ans, tmp);
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		odt.insert(Node_t(i, i, x));
	}
	odt.insert(Node_t(n, n, 0));
	while (q--) {
		int op, l, r;
		cin >> op >> l >> r;
		switch (op) {
		case 0:
			assign(l, r, 0);
			break;
		case 1:
			assign(l, r, 1);
			break;
		case 2:
			change(l, r);
			break;
		case 3:
			cout << query(l, r) << "\n";
			break;
		case 4:
			cout << mx(l, r) << "\n";
			break;
		default:
			break;
		}
	}
}