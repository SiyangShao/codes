#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int mp[maxn][maxn];
int dic[maxn][maxn];
int h, w;
int main() {
	cin >> h >> w;
	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < w + 2; j++) {
			cin >> dic[i][j];
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (dic[i - 1][j - 1] != 0) {
				mp[i][j] = 1;
				dic[i - 1][j - 1]--;
				dic[i - 1][j]--;
				dic[i - 1][j + 1]--;
				dic[i][j]--;
				dic[i][j - 1]--;
				dic[i][j + 1]--;
				dic[i + 1][j - 1]--;
				dic[i + 1][j]--;
				dic[i + 1][j + 1]--;
			}
		}
	}
	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < w + 2; j++) {
			if (dic[i][j] != 0) {
				cout << "impossible";
				return 0;
			}
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (mp[i][j] == 1) {
				cout << "X";
			} else {
				cout << ".";
			}
		}
		cout << "\n";
	}
}