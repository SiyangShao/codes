#include <bits/stdc++.h>
using namespace std;
const int N = 200, V = 600;
int n, m, d;
vector<pair<int, pair<int, int>>> e[N]; // destination, speed, distance
int vis[N][V];
double dis[N][V];
pair<int, int> from[N][V];
void output(int nxt, int v) {
	if (nxt == 1) {
		cout << nxt - 1;
	} else {
		output(from[nxt][v].first, from[nxt][v].second);
		cout << " " << nxt - 1;
	}
}
void dijkstra() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < V; ++j) {
			dis[i][j] = 1e9 + 7;
		}
	}
	priority_queue<pair<double, pair<int, int>>> q; // time, point, speed
	q.push({0, {1, 70}});
	dis[1][70] = 0, vis[1][70] = 1;
	while (!q.empty()) {
		auto point = q.top();
		vis[point.second.first][point.second.second] = 0;
		q.pop();
		for (auto i : e[point.second.first]) {
			auto v = i.second.first;
			auto len = i.second.second;
			if (v != 0) {
				if (dis[i.first][v] >
					dis[point.second.first][point.second.second] +
						double(len) / double(v)) {
					dis[i.first][v] =
						dis[point.second.first][point.second.second] +
						double(len) / double(v);
					from[i.first][v] = {point.second.first,
										point.second.second};
					if (vis[i.first][v])
						continue;
					vis[i.first][v] = 1;
					q.push({-dis[i.first][v], {i.first, v}});
				}
			} else {
				v = point.second.second;
				if (dis[i.first][v] >
					dis[point.second.first][point.second.second] +
						double(len) / double(v)) {
					dis[i.first][v] =
						dis[point.second.first][point.second.second] +
						double(len) / double(v);
					from[i.first][v] = {point.second.first,
										point.second.second};
					if (vis[i.first][v])
						continue;
					vis[i.first][v] = 1;
					q.push({-dis[i.first][v], {i.first, v}});
				}
			}
		}
	}
	int _min = 0;
	dis[d][_min] = 1e9 + 7;
	for (int i = V; i > 0; --i) {
		if (dis[d][_min] > dis[d][i]) {
			_min = i;
		}
	}
	output(d, _min);
}
void solve() {
	cin >> n >> m >> d;
	d++;
	for (int i = 1, a, b, v, l; i <= m; ++i) {
		cin >> a >> b >> v >> l;
		a++, b++;
		e[a].push_back({b, {v, l}});
	}
	dijkstra();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
}