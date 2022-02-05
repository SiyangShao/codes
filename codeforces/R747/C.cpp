#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
char c;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> c >> s;
		if (s[n - 1] == c) {
			bool flag = false;
			for (auto i : s) {
				if (i != c) {
					flag = true;
					break;
				}
			}
			if (flag) {
				printf("1\n%d\n", n);
			} else {
				printf("0\n");
			}
		} else {
			bool flag = false;
			for (auto i : s) {
				if (i != c) {
					flag = true;
					break;
				}
			}
			if (flag) {
				flag = false;
				for (int i = n / 2; i < n; ++i) {
					if (s[i] == c) {
						flag = true;
						printf("1\n%d\n", i+1);
						flag = true;
						break;
					}
				}
				if (!flag)
					printf("2\n%d %d\n", n, n - 1);
			} else {
				printf("1\n");
				printf("%d\n", n - 1);
			}
		}
	}
}