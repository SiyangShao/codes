#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
struct edge {
	int u, v;
	double w;
} a[maxn];
bool cmp(edge x, edge y) { return x.w < y.w; }
int x[501], y[501], p, s, n, fx[501];
void init() {
	for (int i = 1; i <= p; i++) {
		fx[i] = i;
	}
}
int find(int x) {
	if (x != fx[x]) {
		fx[x] = find(fx[x]);
	}
	return fx[x];
}
void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	fx[x] = y;
}
int main() {
	cin >> s >> p;
	for (int i = 1; i <= p; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= p; i++) {
		for (int j = i + 1; j <= p; j++) {
			a[n].u = i, a[n].v = j;
			a[n].w = sqrt((x[i] - x[j]) * (x[i] - x[j]) +
						  (y[i] - y[j]) * (y[i] - y[j]));
			n++;
		}
	}
	sort(a, a + n, cmp);
	vector<double> q;
	init();
	for (int i = 0; i < n; i++) {
		int x = a[i].u;
		int y = a[i].v;
		if (find(x) != find(y)) {
			unionSet(x, y);
			q.push_back(a[i].w);
		}
	}
	cout << fixed << setprecision(2) << q[q.size() - s] << "\n";
}