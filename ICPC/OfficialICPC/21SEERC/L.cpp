#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int cnta, cntb, cntc;

inline bool judge0() {
	cnta = 0, cntb = 0, cntc = 0;
	for (auto i : s) {
		if (i == 'A')
			cnta++;
		else if (i == 'B')
			cntb++;
		else
			cntc++;
	}
	return cnta == n && cntb == n && cntc == n;
}
bool judge1(char tar) {
	int req[3] = {cnta - n, cntb - n, cntc - n};
	req[tar - 'A'] = 3 * n;

	int cur[3] = {0, 0, 0};
	int l = 0;
	for (int i = 0; i < 3 * n; i++) {
		cur[s[i] - 'A']++;
		cur[tar - 'A'] = req[tar - 'A'];
		if (cur[0] == req[0] && cur[1] == req[1] && cur[2] == req[2]) {
			cout << "1\n";
			cout << l+1 << " " << i +1<< " " << tar << "\n";
			return true;
		}

		while (cur[0] > req[0] || cur[1] > req[1] || cur[2] > req[2]) {
			cur[s[l] - 'A']--;
			l++;
		}
	}
	return false;
}
void judge2() {
	cout << "2\n";
	int a = 0, b = 0, c = 0;
	int i;
	for (i = 0; i < n * 3; ++i) {
		if (a == n) {
			cout << i + 1 << " " << i + (n - b) << " B\n";
			cout << i + 1 + (n - b) << " " << n * 3 << " C\n";
			return;
		} else if (b == n) {
			cout << i + 1 << " " << i + (n - a) << " A\n";
			cout << i + 1 + (n - a) << " " << n * 3 << " C\n";
			return;
		} else if (c == n) {
			cout << i + 1 << " " << i + (n - a) << " A\n";
			cout << i + 1 + (n - a) << " " << n * 3 << " B\n";
			return;
		}
		if (s[i] == 'A') {
			a++;
		} else if (s[i] == 'B') {
			b++;
		} else if (s[i] == 'C') {
			c++;
		}
	}
}
int main() {
	cin >> n >> s;
	if (judge0()) {
		cout << "0\n";
		return 0;
	}
	int cnt = 0;
	char tar;
	if (cnta < n) {
		cnt++;
		tar = 'A';
	}
	if (cntb < n) {
		cnt++;
		tar = 'B';
	}
	if (cntc < n) {
		cnt++;
		tar = 'C';
	}
    // cout << tar << " ";
	if (cnt == 2) {
		judge2();
		return 0;
	}

	if (judge1(tar)) {
		return 0;
	}
	judge2();
}