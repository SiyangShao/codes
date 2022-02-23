#include <bits/stdc++.h>
using namespace std;
vector<int> judge(vector<int> q, int skip, int n) {
	for (auto i = 0, j = n - 1; i < j; ++i, --j) {
		while (i < j && q[i] == skip) {
			i++;
		}
		while (i < j && q[j] == skip) {
			j--;
		}
		if (q[i] != q[j]) {
			return {q[i], q[j]};
		}
	}
	return {};
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		int n;
		cin >> n;
		vector<int> q(n);
		for (auto &i : q) {
			cin >> i;
		}
		int skip;
		vector<int> ans = judge(q, 0, n);
		if (ans.size() == 0) {
			cout << "YES\n";
		} else {
			if (judge(q, ans[0], n).size() == 0 ||
				judge(q, ans[1], n).size() == 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}