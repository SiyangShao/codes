#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int _;
string s, answer;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> answer >> s;
		int ans = 0;
		map<char, int> mp;
		for (int i = 0; i < 26; ++i) {
			mp[answer[i]] = i + 1;
		}
		for (int i = 1; i < s.length(); ++i) {
			ans += abs(mp[s[i]] - mp[s[i - 1]]);
		}
		cout << ans << "\n";
	}
}