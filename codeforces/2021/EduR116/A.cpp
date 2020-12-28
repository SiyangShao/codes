#include <bits/stdc++.h>
using namespace std;
int _, ab, ba;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> s;
		s[0] = s[s.length() - 1];
		cout << s << "\n";
	}
}