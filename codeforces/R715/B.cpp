#include <bits/stdc++.h>
using namespace std;
int _, n;
string s;
int main() {
	cin >> _;
	while (_--) {
		cin >> n >> s;
		int t = 0, m = 0;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'T') {
				t++;
			} else {
				if (t <= 0) {
					flag = false;
					break;
				} else {
					t--;
					m++;
				}
			}
		}
		if (t != m) {
			flag = false;
		}
		if (flag) {
            t = 0 , m = 0;
			for (int i = n-1; i >= 0; i--) {
				if (s[i] == 'T') {
					t++;
				} else {
					if (t <= 0) {
						flag = false;
						break;
					} else {
						t--;
						m++;
					}
				}
			}
			if (t != m) {
				flag = false;
			}
		}
		if (!flag) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}