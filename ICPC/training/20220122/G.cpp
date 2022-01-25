#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int dpl[100010];
int dpm[100010];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		for (int j = 1; j <= m; j++) {
			if (a[j] > i)
				break;
			if (dpm[i - a[j]] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag)
			dpl[i] = 1;
		flag = 0;
		for (int j = 1; j <= m; j++) {
			if (b[j] > i)
				break;
			if (dpl[i - b[j]] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag)
			dpm[i] = 1;
	}
	if (dpl[n])
		cout << "Long Long nb!";
	else
		cout << "Mao Mao nb!";
	return 0;
}
