// 补题目 并查集启发式合并
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1010;
int num[maxn][maxn], n, m, q, que[maxn][maxn], ans[maxn * maxn];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct Point {
	int x, y, va;
	bool operator<(const Point &p) const { return va < p.va; }
};
struct Node {
	int fa;
	set<int> se;
} node[maxn * maxn];
vector<Point> ve;
inline int Hash(int x, int y) { return (x - 1) * m + y; }
inline bool checke(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m)
		return true;
	return false;
}
int find(int x) {
	if (x == node[x].fa)
		return x;
	else
		return node[x].fa = find(node[x].fa);
}
inline void merge(int x, int y, int Ans) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)
		return;
	int cnt1 = node[fx].se.size(), cnt2 = node[fy].se.size();
	if (cnt1 <= cnt2) {
		for (auto i : node[fx].se) {
			auto j = node[fy].se.find(i);
			if (j == node[fy].se.end()) {
				node[fy].se.insert(i);
			} else {
				ans[i] = Ans;
				node[fy].se.erase(j);
			}
		}
		node[fx].fa = node[fy].fa;
	} else {
		for (auto i : node[fy].se) {
			auto j = node[fx].se.find(i);
			if (j == node[fx].se.end()) {
				node[fx].se.insert(i);
			} else {
				ans[i] = Ans;
				node[fx].se.erase(j);
			}
		}
		node[fy].fa = node[fx].fa;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &num[i][j]);
			ve.push_back({i, j, num[i][j]});
			node[Hash(i, j)].fa = Hash(i, j);
		}
	}
	sort(ve.begin(), ve.end());
	for (int i = 1; i <= q; i++) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2 && y1 == y2) {
			ans[i] = num[x1][y1];
			continue;
		}
		que[x1][y1] = i;
		que[x2][y2] = i;
		node[Hash(x1, y1)].se.insert(i);
		node[Hash(x2, y2)].se.insert(i);
	}
	for (int i = 0; i < ve.size(); i++) {
		Point now = ve[i];
		int va = now.va;
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = now.x + dir[i][0];
			ny = now.y + dir[i][1];
			if (checke(nx, ny))
				continue;
			if (num[nx][ny] > num[now.x][now.y])
				continue;
			int num1 = Hash(now.x, now.y);
			int num2 = Hash(nx, ny);
			merge(num1, num2, va);
		}
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", ans[i]);
	}
}