#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline bool isPalindrome(const string &s) {
	for (auto i = s.begin(), j = s.end() - 1; i < j; i++, j--) {
		if (*i != *j)
			return false;
	}
	return true;
}
void solve() {
	int n;
	cin >> n;
	set<string> setOf2;
	set<string> setOf3;
	string s;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (flag) {
			continue;
		}
		if (isPalindrome(s)) {
			flag = 1;
			continue;
		}
		string reverseS = s;
		reverse(reverseS.begin(), reverseS.end());
		if (s.length() == 2) {
			if (setOf2.find(reverseS) != setOf2.end()) {
				flag = 1;
				continue;
			}
			if (setOf3.find(reverseS) != setOf3.end()) {
				flag = 1;
				continue;
			}
			setOf2.insert(s);
		} else if (s.length() == 3) {
			if (setOf3.find(reverseS) != setOf3.end()) {
				flag = 1;
				continue;
			}
			if (setOf2.find(reverseS.substr(0, 2)) != setOf2.end()) {
				flag = 1;
				continue;
			}
			setOf3.insert(s.substr(0, 2));
			setOf3.insert(s);
		}
	}

	if (flag) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}
