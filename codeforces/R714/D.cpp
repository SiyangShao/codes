#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int _;
int n, a[200010], p;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> n >> p;
		int ans = 0, le = 0;
		// vector<pair<int,int>>q;
		int qr = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 2; i <= n; i++) {
			if (max(a[i], a[i - 1]) % min(a[i], a[i - 1]) == 0) {
				int tmp = min(a[i], a[i - 1]);
				int r = i;
				for (r = i; r <= n; r++) {
					if (a[r] % tmp == 0) {
					} else if (tmp % a[r] == 0) {
						tmp = a[r];
					} else {
						r--;
						break;
					}
				}
				int l = i - 1;
				for (l = i - 1; l >= 1; l--) {
					if (a[l] % tmp == 0) {
					} else if (tmp % a[l] == 0) {
						tmp = a[l];
					} else {
						l++;
						break;
					}
				}
				l = max(ll(1), l);
				r = min(r, n);
				i = r + 1;
				// q.push_back(make_pair(l,r));
				ans++;
				le += r - l + 1;
				qr += (r - l) * min(tmp, p);
			}
		}
		ans = n - le + ans;
		// cout<<ans<<"\n";
		qr += (ans - 1) * p;
		cout << qr << "\n";
	}
}