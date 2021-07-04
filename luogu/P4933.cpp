#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, h[1010], dp[1010][1010], ma;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j]++;
			for (int k = 1; k < j; k++) {
				if (h[i] - h[j] == h[j] - h[k]) {
					dp[i][j] += dp[j][k];
					dp[i][j] %= mod;
				}
			}
            //cout<<dp[i][j]<<" "<<h[i]<<" "<<h[j]<<"\n";
			ma+=dp[i][j];
            ma%=mod;
		}
	}
    cout<<ma;
}