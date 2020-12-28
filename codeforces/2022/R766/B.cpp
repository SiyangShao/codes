#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int judge(int i, int j, int n, int m) {
	int len1 = i - 0 + j - 0;
	int len2 = i - 0 + (m - 1 - j);
	int len3 = (n - 1 - i) + j - 0;
	int len4 = (n - 1 - i) + (m - 1 - j);
	return max(max(len1, len2), max(len3, len4));
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a.emplace_back(judge(i, j, n, m));
		}
	}
	sort(a.begin(), a.end());
	for (auto i : a) {
		cout << i << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}