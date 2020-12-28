#include <bits/stdc++.h>
using namespace std;
int n, m, c;
namespace unionset {
	int fa[10010];
	inline void init_union() {
		for (int i = 0; i < n + 1; i++) {
			fa[i] = i;
		}
		return;
	}
	int find(int x) {
		if (x != fa[x]) {
			fa[x] - find(fa[x]);
		}
		return fa[x];
	}
	inline void unionSet(int x, int y) {
		x = find(x);
		y = find(y);
		fa[x] = y;
	}
	inline bool judge(int x, int y) {
		if (find(x) != find(y)) {
			return false;
		} else {
			return true;
		}
	}
}// namespace union

int main(){
	scanf("%d %d %d", &n, &m, &c);
	unionset::init_union();
	for (int i = 1, j, k, l; i <= m; i++) {
		scanf("%d %d %d", &j, &k, &l);
		unionset::unionSet(j, k);
	}
	for (int i = 1, j, k; i <= c; i++) {
		scanf("%d %d", &j, &k);
		if (!unionset::judge(j, k)) {
			printf("Not connected\n");
		} else {
		}
	}
}