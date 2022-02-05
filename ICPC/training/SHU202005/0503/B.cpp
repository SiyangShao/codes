#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200005;
vector<int> tree[maxn];
int n, K, dK;
int d[maxn];
void dfs(int u, int fa) {
	d[u] = 1;
	int maxSub = 0, size = tree[u].size();
	for (int i = 0; i < size; ++i) {
		int v = tree[u][i];
		if (v != fa) {
			dfs(v, u);
			d[u] += d[v];
			maxSub = max(maxSub, d[v]);
		}
	}
	maxSub = max(maxSub, n - d[u]);
	if (maxSub < dK) {
		K = u;
		dK = maxSub;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(tree, 0, sizeof(tree));
		memset(d, 0, sizeof(d));
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		K = 0;
		dK = 0x3f3f3f3f;
		dfs(1, 0);
		cout << K << " " << dK << "\n";
	}
	return 0;
}