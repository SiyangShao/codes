#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
	cin >> n;
	for (int i = 2; i <= n + 1; ++i) {
		cout << i << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}