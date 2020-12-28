#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n, num, val, pre, len, sum;
vector<int> t, ans;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	t.resize(n + 1), ans.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> num >> val >> pre;
		t[num] = val;
		len = ans[pre];
		while (pre != 0) {
			cin >> pre;
			len = max(len, ans[pre]);
		}
		ans[num] = len + val;
		sum = max(sum, ans[num]);
	}
	cout << sum;
}