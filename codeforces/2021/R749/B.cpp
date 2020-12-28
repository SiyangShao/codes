#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1, a, b, c; i <= m; ++i) {
			cin >> a >> b >> c;
			vis[b] = 1;
		}
		int root = 0;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				root = i;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			vis[i] = 0;
			if (i == root)
				continue;
			cout << root << " " << i << "\n";
		}
	}
}