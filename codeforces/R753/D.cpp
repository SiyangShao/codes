#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int x[200010];
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		cin >> s;
		priority_queue<int> b;
		priority_queue<int, vector<int>, greater<int>> a;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == 'B') {
				x[i] = min(n, x[i]);
				b.push(x[i]);
			} else {
				x[i] = max(1, x[i]);
				a.push(x[i]);
			}
		}
		// cout << b.size() << " " << a.size() << "\n";
		// cout << b.top() << " " << a.top() << "\n";
		// cout << n - b.top() << " " << a.size() << "\n";
		if (a.size() == 0) {
			if (b.top() == n) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else if (b.size() == 0) {
			if (a.top() == 1) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else if (b.top() < a.top()) {
			puts("NO");
		} else {
			if (((a.top() - 1) > b.size()) || ((n - b.top()) > a.size())) {
				puts("NO");
			} else {
				puts("YES");
			}
		}
	}
}