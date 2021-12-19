#include <bits/stdc++.h>
using namespace std;
int H, W, cnt = 0;
string mp[110];
int vis[110][110];
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		cin >> mp[i];
	}
	if (mp[0][0] == '.') {
		vis[0][0] = 1;
		cnt = 0;
	} else {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < W; ++i) {
		if (vis[0][i - 1] && mp[0][i] == '.') {
			vis[0][i] = 1;
			cnt = max(cnt, i);
		}
	}
	for (int i = 1; i < H; ++i) {
		if (vis[i - 1][0] && mp[i][0] == '.') {
			vis[i][0] = 1;
			cnt = max(cnt, i);
		}
	}
	for (int i = 1; i < H; ++i) {
		for (int j = 1; j < W; ++j) {
			if ((vis[i - 1][j] || vis[i][j - 1]) && mp[i][j] == '.') {
				vis[i][j] = 1;
				cnt = max(cnt, i + j);
			}
		}
	}
	cout << cnt + 1;
}