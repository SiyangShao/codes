#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[110], ans;
int dp[2000010];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	if (ans % 2 == 1) {
		cout << "0\n";
	} else {
        dp[0]=1;
        for(int i = 1 ; i<= n ; i++){
            for(int j = ans ; j>= a[i] ; j--){
                dp[j]+=dp[j-a[i]];
            }
        }
        if(!dp[ans/2]){
            cout<<"0";
            return 0;
        }
		//cout << ans << " ";
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 1) {
				cout << "1\n" << i << "\n";
				return 0;
			}
		}
		while (a[n] % 2 == 0) {
			ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] % 2 == 1) {
					cout << "1\n" << i << "\n";
					return 0;
				} else {
					a[i] /= 2;
					ans += a[i];
				}
			}
			if (ans % 2 == 1) {
				cout << "0\n";
				return 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 1) {
				cout << "1\n" << i << "\n";
				return 0;
			}
		}
	}
}