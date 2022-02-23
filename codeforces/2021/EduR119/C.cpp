#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	while (T--) {
		ll n, k, x;
		cin >> n >> k >> x;
		string str;
		cin >> str;
		vector<ll> vec;
		for (ll i = 0; i < n; i++) {
			ll cnt = 0;
			if (str[i] == '*') {
				while (i < n && str[i] == '*')
					cnt += k, i++;
				vec.push_back(cnt + 1);
			}
		}
		x--;
		int V = vec.size();
		for (ll i = V - 1; i >= 0; i--) {
			int tmp = x % vec[i];
			x /= vec[i];
			vec[i] = tmp;
		}
		ll idx = 0;
		for (ll i = 0; i < n; i++) {
			ll cnt = 0;
			if (str[i] == '*') {
				while (str[i] == '*')
					i++;
				i--;
				if (idx > V)
					continue;
				else
					for (ll j = 1; j <= vec[idx]; j++)
						cout << 'b';
				idx++;
			} else
				cout << 'a';
		}
		cout << "\n";
	}
	return 0;
}