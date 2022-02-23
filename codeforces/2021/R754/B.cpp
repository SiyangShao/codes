#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s, t;
	vector<int> q;
	int _, n;
	cin >> _;
	while (_--) {
		cin >> n >> s;
		t = s;
		sort(t.begin(), t.end());
		q.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				q.push_back(i);
			}
		}
		if (q.size() == 0) {
			cout << 0 << "\n";
		} else {
			cout << 1 << "\n";
			cout << q.size();
			for (auto i : q) {
				cout << " " << i + 1;
			}
			cout << "\n";
		}
	}
}