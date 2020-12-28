#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int>> mp[100010];
inline void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> mp;
	vector<int> num(n + 1);
	vector<int> fulfill(n + 1);
	for (auto &i : a) {
		cin >> i;
		mp[i]++;
	}
	cout << mp[0];
	int flag = n + 1;
	priority_queue<int> q;
	for (int j = 1; j < mp[0]; ++j) {
		q.push(0);
	}
	for (int i = 1; i <= n; ++i) {
		num[i] = num[i - 1] + mp[i - 1];
		if (num[i] < i) {
			flag = i;
			break;
		}
		if (mp[i] == 0) {
			if (q.empty()) {
				flag = i + 1;
				break;
			}
			fulfill[i] = fulfill[i - 1] + (i - q.top());
			q.pop();
		} else {
			fulfill[i] = fulfill[i - 1];
			for (int j = 1; j < mp[i]; ++j) {
				q.push(i);
			}
		}
	}
	int op = 0;
	for (int i = 1; i < flag; ++i) {
		if (mp[i] == 0) {
			cout << " " << fulfill[i - 1];
		} else {
			cout << " " << fulfill[i-1] + mp[i];
		}
	}
	for (int i = flag; i <= n; ++i) {
		cout << " -1";
	}
	cout << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}