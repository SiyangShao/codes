#include <bits/stdc++.h>
using namespace std;
const int mx = 10010;
const int mm = 100010;
const int inf = 0x3f3f3f3f;
struct e {
	int t, nxt, w;
} edge[mm];
int cnt;
int head[mx];
int n, m, hp;
int f[mx];
int u[mx];
int dist[mx];
bool v[mx];
bool check(int top) {
	memset(dist, inf, sizeof(dist));
	memset(v, 0, sizeof(v));
	queue<int> q;
	v[1] = true;
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		v[temp] = false;
		for (int i = head[temp]; i != 0; i = edge[i].nxt) {
			int to = edge[i].t;
			int wr = edge[i].w;
			if (dist[to] > dist[temp] + wr &&
				f[to] <= top /*过滤掉点权过大的点*/) {
				dist[to] = dist[temp] + wr;
				if (v[to] == false) {
					v[to] = true;
					q.push(to);
				}
			}
		}
	}
	if (dist[n] <= hp) {
		return true;
	} else {
		return false;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &hp);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		u[i] = f[i];
	}
	for (int i = 1; i <= m; i++) {
		static int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		cnt++;
		edge[cnt].t = b;
		edge[cnt].w = c;
		edge[cnt].nxt = head[a];
		head[a] = cnt;
		cnt++;
		edge[cnt].t = a;
		edge[cnt].w = c;
		edge[cnt].nxt = head[b];
		head[b] = cnt;
	}
	sort(u + 1, u + n + 1);
	//这里做一个判断：如果点权大小在不受限制的情况下，依然无法出现损血量小于hp的路径，直接结束程序
	if (check(inf) == false) {
		printf("AFK\n");
		return 0;
	}
	int l = 1, r = n;  //得到点权集合的区间
	int mid;
	int ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(u[mid]) == true) {
			ans = u[mid];
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (ans != 0)
		printf("%d\n", ans);
	else {
		printf("AFK\n");
	}
	return 0;
}