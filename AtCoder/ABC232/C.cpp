#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void solve() {
	int M, N;
	cin >> N >> M;
	vector<int> x(N + 10, 0), y(N + 10, 0);
	vector<int> ans(N * N, 0);
	for (int k = 0, i, j; k < M; ++k) {
		cin >> i >> j;
		i--, j--;
		x[i]++, x[j]++;
	}
	for (int k = 0, i, j; k < M; ++k) {
		cin >> i >> j;
		i--, j--;
		y[i]++, y[j]++;
	}
	for (int i = 0; i < N; ++i) {
		ans[x[i]]++;
	}
	for (int i = 0; i < N; ++i) {
		ans[y[i]]--;
		if (ans[y[i]] < 0) {
			cout << "No";
			return;
		}
	}
	cout << "Yes";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}