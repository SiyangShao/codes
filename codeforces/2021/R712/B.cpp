#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t;
string a, b;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		if (a == b) {
			printf("YES\n");
			continue;
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++)
			cnt1 += a[i] - '0';
		for (int i = 0; i < n; i++)
			cnt2 += b[i] - '0';
		bool flag = 1;
		bool opp = 0;
		if (cnt1 != cnt2) {
			printf("NO\n");
			continue;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (opp == 1) {
				if (a[i] == '0')
					a[i] = '1';
				else
					a[i] = '0';
			}
			if (a[i] != b[i]) {
				if (i % 2 == 0 || (cnt1 != (i + 1) / 2)) {
					flag = 0;
					break;
				}
				opp = !opp;
				if (a[i] == '0')
					a[i] = '1';
				else if (a[i] == '1')
					a[i] = '0';
			}
			if (a[i] == '1')
				cnt1--;
		}
		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}