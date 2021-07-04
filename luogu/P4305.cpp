#include <bits/stdc++.h>
using namespace std;
string s;
unordered_map<string, int> mp;
int _;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			if (mp[s] == 0) {
				mp[s] = 1;
				cout << s << " ";
			}
		}
		mp.clear();
		cout << "\n";
	}
}