#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100005;
int n, k[N], m;
bool u[N], vis[N];
vector<bool> ans[N];
vector<int> to[N];
struct num {
	int v, id, p;
	bool operator<(const num &j) const { return v < j.v; }
} a[N << 1];

void dfs(int i) {
	while (!to[i].empty()) {
		int x = to[i].back();
		to[i].pop_back();
		if (u[x >> 1])
			continue;
		u[x >> 1] = 1, ans[a[x].id][a[x].p] = 1;
		dfs(a[x].id);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		ans[i].resize(k[i]);
		for (int j = 0; j != k[i]; j++) {
			int x;
			cin >> x;
			a[m++] = num{x, i, j};
		}
	}

	sort(a, a + m);
	for (int i = 0; i != m; i += 2) {
		if (a[i].v != a[i + 1].v) {
			cout << "NO\n";
			return 0;
		}
		to[a[i].id].emplace_back(i + 1);
		to[a[i + 1].id].emplace_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j != k[i]; j++)
			cout << (ans[i][j] ? "R" : "L");
		cout << "\n";
	}
}