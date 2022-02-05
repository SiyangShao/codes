#include <bits/stdc++.h>
using namespace std;
string s;
int _, n, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> n >> s;
		ans = 0x3f3f3f3f;
		for (auto i = s.begin(); i < s.end(); ++i) {
			if (*i == 'a') {
				if (i + 1 < s.end()) {
					if (*(i + 1) == 'a') {
						ans = 2;
					}
				}
				if (i + 2 < s.end()) {
					if (*(i + 2) == 'a') {
						ans = ans < 3 ? ans : 3;
					}
				}
				if (i + 3 < s.end()) {
					if (*(i + 3) == 'a' && *(i + 1) != *(i + 2)) {
						ans = ans < 4 ? ans : 4;
					}
				}
				if (i + 6 < s.end()) {
					if (*(i + 6) == 'a' && *(i + 1) == *(i + 2) &&
						*(i + 4) == *(i + 5) && *(i + 3) == 'a' &&
						*(i + 1) != *(i + 4)) {
						ans = ans < 7 ? ans : 7;
					}
				}
			}
		}
		cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
	}
}