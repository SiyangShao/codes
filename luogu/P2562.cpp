#include <bits/stdc++.h>
using namespace std;
void solve(string::iterator begin, string::iterator end) {
	if (end == begin + 1) {
		if (*begin == '0') {
			cout << "A";
		} else {
			cout << "B";
		}
	} else {
		bool flag = false;
		for (auto i = begin + 1; i < end; ++i) {
			if (*i != *begin) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "C";
			solve(begin, begin + (end - begin) / 2);
			solve(begin + (end - begin) / 2, end);
		} else {
			if (*begin == '0') {
				cout << "A";
			} else {
				cout << "B";
			}
		}
	}
}
int main() {
	string s;
	cin >> s;
	solve(s.begin(), s.end());
}