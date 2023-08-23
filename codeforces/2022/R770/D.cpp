#include <bits/stdc++.h>
using namespace std;
inline int get(const vector<int> &x) {
	cout << "? " << x[0] + 1 << " " << x[1] + 1 << " " << x[2] + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}
void solve() {
	int n;
	cin >> n;
	pair<int, int> possible = {0, 1};
	for (int i = 2; i < n - 1; i += 2) {
		vector<pair<int, int>> ch(4);
		vector<int> now = {possible.first, possible.second, i, i + 1};
		for (int j = 0; j < 4; j++) {
			vector<int> x = now;
			x.erase(x.begin() + j);
			ch[j] = {get(x), now[j]};
		}
		sort(ch.begin(), ch.end());
		possible = {ch[0].second, ch[1].second};
	}
	if (n % 2 == 1) {
		int other = 0;
		while (possible.first == other || possible.second == other) {
			other++;
		}
		vector<pair<int, int>> ch(4);
		vector<int> now = {possible.first, possible.second, n - 1, other};
		for (int j = 0; j < 4; j++) {
			vector<int> x = now;
			x.erase(x.begin() + j);
			ch[j] = {get(x), now[j]};
		}
		sort(ch.begin(), ch.end());
		possible = {ch[0].second, ch[1].second};
	}
	cout << "! " << possible.first + 1 << " " << possible.second + 1 << endl;
}
signed main() {

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}