#include <bits/stdc++.h>
using namespace std;
int n, k, las;
int f[1000];
int main() {
	cin >> n >> k;
	las = 0;
	for (int j = 2; j <= n; j++) {
		cout << char(las + 'a');
		int tmp = 0x3f3f3f3f , d=-1;
		for (int i = 0; i < k; i++) {
			if (tmp >= f[las * 26 + i]) {
				tmp = f[las * 26 + i];
				d = i;
			}
		}
        f[las*26+d]++;
        las=d;
	}
	cout << char(las + 'a');
}