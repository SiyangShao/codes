#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct node {
	int x, y;
} point[MAXN];
double ans, dis[MAXN];
bool vis[MAXN];
int n;
double calc(int a, int b) {
	return sqrt((double)(point[a].x - point[b].x) * (point[a].x - point[b].x) +
				(double)(point[a].y - point[b].y) * (point[a].y - point[b].y));
}
int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		point[i].x = read(), point[i].y = read();
		dis[i] = 1e8;
	}
	int pos;
	dis[1] = 0;
	for (int i = 1; i <= n; ++i) {
		double minn = 1e8;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && dis[j] < minn) {
				minn = dis[j];
				pos = j;
			}
		ans += minn;
		vis[pos] = true;
		for (int j = 1; j <= n; ++j) {
			double d = calc(pos, j);
			if (d < dis[j])
				dis[j] = d;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}