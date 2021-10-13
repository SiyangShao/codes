#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dp[510][510][15];
int mp[510][510][4];
// 0为上，1为下，2为左，3为右
// i行j列
int main() {
	cin >> n >> m >> k;
	memset(mp,0x3f,sizeof(mp));
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			cin >> tmp;
			mp[i][j][3] = tmp;
			mp[i][j + 1][2] = tmp;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tmp;
			mp[i][j][1] = tmp;
			mp[i + 1][j][0] = tmp;
		}
	}
	if (k % 2 == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << "-1 ";
			}
			cout << "\n";
		}
	} else {
		k /= 2;
		memset(dp, 0x3f, sizeof(dp));
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				dp[x][y][1] =
					min(mp[x][y][0],
						min(mp[x][y][1], min(mp[x][y][2], mp[x][y][3])));
			}
		}
		for (int i = 2; i <= k; i++) {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= m; y++) {
					dp[x][y][i] =
						min(dp[x][y][i], mp[x][y][0] + dp[x - 1][y][i - 1]);
					dp[x][y][i] =
						min(dp[x][y][i], mp[x][y][1] + dp[x + 1][y][i - 1]);
					dp[x][y][i] =
						min(dp[x][y][i], mp[x][y][2] + dp[x][y - 1][i - 1]);
					dp[x][y][i] =
						min(dp[x][y][i], mp[x][y][3] + dp[x][y + 1][i - 1]);
				}
			}
		}
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ;j<= m ; j++){
                cout<<dp[i][j][k]*2<<" ";
            }
            cout<<"\n";
        }
	}
}