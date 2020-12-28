#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
tuple<char, char, bool> judge() {
	for (auto i = s.begin(), j = s.end() - 1; i <= j; i++, j--) {
		if (*i != *j) {
			return make_tuple(*i, *j, false);
		}
	}
	return make_tuple('0', '0', true);
}
int judge2(char x) {
	int ans = 0;
	auto i = s.begin(), j = s.end() - 1;
	while (i < j) {
		if (*i == *j) {
			i++;
			j--;
		} else {
			if (*i == x) {
				i++;
				ans++;
			} else if (*j == x) {
				j--;
				ans++;
			} else {
				return -1;
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> s;
		auto ans = judge();
		if (get<2>(ans)) {
			cout << 0 << "\n";
		} else {
			auto x = get<0>(ans);
			auto y = get<1>(ans);
			auto xa = judge2(x);
			auto ya = judge2(y);
			if (xa == -1) {
				cout << ya << "\n";
			} else if (ya == -1) {
				cout << xa << "\n";
			} else {
				cout << min(xa, ya) << "\n";
			}
		}
	}
}