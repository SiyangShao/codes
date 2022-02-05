#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main() {
	int n, k;
	cin >> n >> k;
	int num = 1;
	for (int i = 0; i < n; ++i) {
		num *= 2;
	}
	num /= 2;
	bool flag = false;
	while (n) {
		if (!flag) {
			if (k < num)
				cout << 0;
			else {
				cout << 1;
				k -= num;
				flag = true;
			}
		} else {
			if (k < num) {
				cout << 1;
				flag = false;
			} else {
				cout << 0;
				k -= num;
			}
		}
		n--;
		num /= 2;
	}
}