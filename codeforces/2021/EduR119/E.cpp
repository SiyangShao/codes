#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int q;
	cin >> q;
	vector<pair<int, int>> p(q);
	int a, x, y;
	for (auto &i : p) {
		cin >> a;
		if (a == 1) {
			cin >> x;
			i = {x, -1};
			mp[x] = x;
		} else {
			cin >> x >> y;
			i = {x, y};
			mp[x] = x;
			mp[y] = y;
		}
	}
	vector<int> ans;
	for (int i = q - 1; i >= 0; i--) {
		if (p[i].second == -1) {
			ans.push_back(mp[p[i].first]);
		} else {
			mp[p[i].first] = mp[p[i].second];
		}
	}
	for (auto i = ans.end() - 1; i >= ans.begin(); --i) {
		cout << *i << " ";
	}
}