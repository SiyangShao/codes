#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200010], b[200010];
bool cmp(int x, int y) { return x > y; }
signed main() {
	cin >> n;
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i] - i;
		if (b[i] < 0)
			break;
		tmp = max(tmp, b[i]);
	}
	cout << tmp;
}