// Tarjan (Cut Point)
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> e[20010];
set<int> ans;
int dfn[20010], low[20010], tim;
// dfn means time when first meet
// low means time when first meet the point in this tree
void tag(int x, int fa) {
	// here fa different from fa in normal dfs
	// fa means the initial point of the tree
	dfn[x] = low[x] = ++tim;
	int child = 0;
	for (auto nxt : e[x]) {
		if (!dfn[nxt]) { // haven't meet, dfs
			tag(nxt, fa);
			low[x] = min(low[x], low[nxt]);
			// in the same tree, low must be same
			if (low[nxt] >= dfn[x] && x != fa) {
				// means that it's child was first meet
				// should be cut
				ans.insert(x);
			}
			if (x == fa) {
				child++;
			}
		}
		low[x] = min(low[x], dfn[nxt]);
	}
	if (child > 1 && x == fa) {
		ans.insert(x);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i])
			tag(i, i);
	}
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
}