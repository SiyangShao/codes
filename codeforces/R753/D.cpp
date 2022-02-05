#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		string s;
		cin >> s;
		vector<ll> red, blue;
		for (auto i = 0; i < n; ++i) {
			if (s[i] == 'R') {
				red.push_back(a[i]);
			} else {
				blue.push_back(a[i]);
			}
		}
		sort(red.begin(), red.end());
		sort(blue.begin(), blue.end());
		ll cnt = 1;
		auto i = red.begin(), j = blue.begin();
		auto flag = true;
		for (auto cnt = 1ll; cnt <= n; ++cnt) {
			if (j < blue.end() && *j >= cnt) {
				j++;
			} else if (i < red.end() && *i <= cnt) {
				i++;
			} else {
				flag = false;
				break;
			}
		}
		if (flag) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}