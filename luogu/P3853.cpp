#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int ll, n, k;
bool judge(int mid) {
	int m = 0;
	for (int i = 2; i <= n; i++)
		if (a[i] - a[i - 1] >= mid) {
			m += (a[i] - a[i - 1]) / mid;
			if ((a[i] - a[i - 1]) % mid == 0) m--;
		}
	if (m > k) return false;
	return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>ll>>n>>k;
	for (int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	int l = 0;
	int r = ll;
	while (l < r) {
		int mid = (l + r) / 2;
		if (judge(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout<<l<<"\n";
	return 0;
}