#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
int fa[maxn], po[maxn], siz[maxn];
int _;
inline void init() {
	for (int i = 1; i < maxn; i++) {
		fa[i] = i;
		po[i] = 0;
		siz[i] = 1;
	}
}
int find(int x) {
	if (x != fa[x]) {
		int fn = find(fa[x]);
		po[x] += po[fa[x]];
		fa[x] = fn;
	}
	return fa[x];
}
inline void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
    po[x]+=siz[y];
	siz[y] += siz[x];
	siz[x] = 0;
}
int main() {
	cin >> _;
	init();
	while (_--) {
		char a;
		int x, y;
		cin >> a >> x >> y;
		if (a == 'M') {
			unionSet(x, y);
		} else {
			int fx = find(x);
			int fy = find(y);
			if (fx != fy) {
				cout << "-1\n";
			} else {
				cout << abs(po[x] - po[y]) - 1 << "\n";
			}
		}
	}
}