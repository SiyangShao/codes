#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
constexpr int N = 1e5 + 7;
int n, k;
char c;
int a;
int ans[N]; // 1: added ; -1 : added init
void solve() {
	cin >> n >> k;
	bool flag = false;
	int first = -1, cnt = 0;
	for (int i = 1; i <= k; i++) {
		cin >> c >> a;
		if (i == 1) {
			first = a;
			flag = true;
		}
		if (c == '+') {
			if (a != first && ans[first] == -1)
				flag = false;
			ans[a] = 1;
			cnt++;
		} else {
			if (ans[a] == 1)
				cnt--;
			if (a != first && ans[a] == 0) {
				first = a;
				flag = true;
			}
			if (a == first && cnt)
				flag = false;
			ans[a] = -1;
		}
	}
	if (flag) {
		ans[first] = 0;
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (!ans[i])
			sum++;
	}
	cout << sum << "\n";
	for (int i = 1; i <= n; ++i) {
		if (!ans[i]) {
			cout << i << " ";
		}
	}
	if (sum)
		cout << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}