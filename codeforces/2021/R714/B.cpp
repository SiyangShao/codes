#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int _, n, ans, an, tmp;
int a[200010];

signed main() {
	cin >> _;
	while (_--) {
		cin >> n;
		cin >> a[1];
		an = a[1];
		ans = 0;
		for (int i = 2; i <= n; i++) {
			cin >> a[i];
			an = (an & a[i]);
		}
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (an == a[i]) {
				ans++;
			}
			if ((an & a[i]) != an) {
				flag = false;
				break;
			}
		}
        if(ans<2) flag = false;
		if (flag) {
			tmp = ans * (ans - 1);
			for (int i = 1; i <= n - 2; i++) {
				tmp *= i;
				tmp %= mod;
			}
			cout << tmp << "\n";
		}else{
            cout<<"0\n";
        }
	}
}