#include <bits/stdc++.h>
using namespace std;
int n, q;
int pos, ans;
char i;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q >> s;
	for (int i = 0; i < n - 2; ++i) {
		if (s[i] == 'a') {
			if (s[i + 1] == 'b' && s[i + 2] == 'c') {
				ans++;
			}
		}
	}
	while (q--) {
		cin >> pos >> i;
		pos--;
		if (s[pos] == i) {
			cout << ans << "\n";
		} else {
			if (s[pos] == 'a') {
				if (pos + 2 < n && s[pos + 1] == 'b' && s[pos + 2] == 'c') {
					ans--;
				}
			} else if (s[pos] == 'b') {
				if (pos - 1 >= 0 && pos + 1 < n && s[pos - 1] == 'a' &&
					s[pos + 1] == 'c') {
					ans--;
				}
			} else if (s[pos] == 'c') {
				if (pos - 2 >= 0 && s[pos - 1] == 'b' && s[pos - 2] == 'a') {
					ans--;
				}
			}
			if (i == 'a') {
				if (pos + 2 < n && s[pos + 1] == 'b' && s[pos + 2] == 'c') {
					ans++;
				}
			} else if (i == 'b') {
				if (pos - 1 >= 0 && pos + 1 < n && s[pos - 1] == 'a' &&
					s[pos + 1] == 'c') {
					ans++;
				}
			} else if (i == 'c') {
				if (pos - 2 >= 0 && s[pos - 1] == 'b' && s[pos - 2] == 'a') {
					ans++;
				}
			}
			s[pos] = i;
			cout << ans << "\n";
		}
	}
}