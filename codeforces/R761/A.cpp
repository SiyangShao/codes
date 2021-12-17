#include <bits/stdc++.h>
using namespace std;
inline void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	if (s1.size() < s2.size()) {
		cout << s1 << "\n";
		return;
	}
	int a = 0, b = 0, c = 0;
	auto d = s1.end();
	for (auto i = s1.begin(); i < s1.end(); ++i) {
		if (*i == 'a')
			a++;
		else if (*i == 'b')
			b++;
		else if (*i == 'c')
			c++;
		else {
			d = i;
			break;
		}
	}
	if (s2 != "abc" || !a || !b || !c) {
		cout << s1 << "\n";
		return;
	}
	for (int i = 0; i < a; ++i) {
		cout << "a";
	}
	for (int i = 0; i < c; ++i) {
		cout << "c";
	}
	for (int i = 0; i < b; ++i) {
		cout << "b";
	}
	for (auto i = d; i < s1.end(); ++i) {
		cout << *i;
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}