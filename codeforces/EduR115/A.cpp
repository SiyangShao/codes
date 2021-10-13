#include <bits/stdc++.h>
using namespace std;
int _, n;
string s1, s2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> n >> s1 >> s2;
		bool flag = false;
		if (s1[0] == '1') {
			puts("NO");
		} else {
			for (int i = 0; i < n; ++i) {
				if (s1[i] == '1' && s2[i] == '1') {
					flag = true;
					break;
				}
			}
			if (flag) {
				puts("NO");
			} else {
				puts("YES");
			}
		}
	}
}