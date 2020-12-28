#include <bits/stdc++.h>

using namespace std;
int n, m, l, r, t;
string s[110], nxt[110];

inline bool judge(int x, int y) {
	int num = 0;
	if (y - 1 >= 0) {
		for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); ++i) {
			if (s[y - 1][i] == '*') {
				num++;
			}
		}
	}
	for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); ++i) {
		if (i == x)
			continue;
		if (s[y][i] == '*') {
			num++;
		}
	}
	if (y + 1 < n) {
		for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); ++i) {
			if (s[y + 1][i] == '*') {
				num++;
			}
		}
	}
	if (num >= l && num <= r)
		return true;
	return false;
}

int main() {
	//	ios::sync_with_stdio(false);
	//	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> l >> r >> t;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		nxt[i] = s[i];
	}
	cout << "\n";
	for (int T = 1; T < t; ++T) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (judge(j, i)) {
					nxt[i][j] = '*';
				} else {
					nxt[i][j] = '.';
				}
			}
			//            cout << nxt[i] << "\n";
		}
		swap(nxt, s);
	}
	for (int i = 0; i < n; ++i) {
		cout << s[i] << "\n";
	}
}