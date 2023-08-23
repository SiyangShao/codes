#include <bits/stdc++.h>
using namespace std;
int _, n, m;
int x[300010], ans[300010], dir[300010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		memset(ans, -1, sizeof(ans));
		vector<int> odd;
		vector<int> even;
		map<int, int> mp;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			mp[x[i]] = i;
			if (x[i] % 2 == 0) {
				even.push_back(x[i]);
			} else {
				odd.push_back(x[i]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			char tmp;
			cin >> tmp;
			if (tmp == 'L') {
				dir[i] = -1;
			} else {
				dir[i] = 1;
			}
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		stack<int> left, right;
		for (int i = 0; i < even.size(); i++) {
			int I = even[i];
			if (dir[mp[I]] == -1) {
				if (right.size() == 0) {
					left.push(I);
				} else {
					int J = right.top();
					right.pop();
					ans[mp[I]] = ans[mp[J]] = (I - J) / 2;
				}
			} else {
				right.push(I);
			}
		}
		int L = 0, R = 0;
		if (left.size() % 2 == 0) {
			while (left.size()) {
				int I = left.top();
				left.pop();
				int J = left.top();
				left.pop();
				ans[mp[I]] = ans[mp[J]] = (I + J) / 2;
			}
		} else {
			L = left.top();
			left.pop();
			while (left.size()) {
				int I = left.top();
				left.pop();
				int J = left.top();
				left.pop();
				ans[mp[I]] = ans[mp[J]] = (I + J) / 2;
			}
		}
		if (right.size() % 2 == 0) {
			while (right.size()) {
				int I = right.top();
				right.pop();
				int J = right.top();
				right.pop();
				ans[mp[I]] = ans[mp[J]] = (m - I + m - J) / 2;
			}
		} else {
			while (right.size()) {
				int I = right.top();
				right.pop();
				if (right.size() == 0) {
					R = I;
					break;
				}
				int J = right.top();
				right.pop();
				ans[mp[I]] = ans[mp[J]] = (m - I + m - J) / 2;
			}
		}
		if (R != 0 && L != 0) {
			ans[mp[R]] = ans[mp[L]] = ((m - R) * 2 + L * 2 + (R - L)) / 2;
		}
		for (int i = 0; i < odd.size(); i++) {
			int I = odd[i];
			if (dir[mp[I]] == -1) {
				if (right.size() == 0) {
					left.push(I);
				} else {
					int J = right.top();
					right.pop();
					ans[mp[I]] = ans[mp[J]] = (I - J) / 2;
				}
			} else {
				right.push(I);
			}
		}
		L = 0, R = 0;
		if (left.size() % 2 == 0) {
			while (left.size()) {
				int I = left.top();
				left.pop();
				int J = left.top();
				left.pop();
				ans[mp[I]] = ans[mp[J]] = (I + J) / 2;
			}
		} else {
			L = left.top();
			left.pop();
			while (left.size()) {
				int I = left.top();
				left.pop();
				int J = left.top();
				left.pop();
				ans[mp[I]] = ans[mp[J]] = (I + J) / 2;
			}
		}
		if (right.size() % 2 == 0) {
			while (right.size()) {
				int I = right.top();
				right.pop();
				int J = right.top();
				right.pop();
				ans[mp[I]] = ans[mp[J]] = (m - I + m - J) / 2;
			}
		} else {
			while (right.size()) {
				int I = right.top();
				right.pop();
				if (right.size() == 0) {
					R = I;
					break;
				}
				int J = right.top();
				right.pop();
				ans[mp[I]] = ans[mp[J]] = (m - I + m - J) / 2;
			}
		}
		if (R != 0 && L != 0) {
			ans[mp[R]] = ans[mp[L]] = ((m - R) * 2 + L * 2 + (R - L)) / 2;
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}
// 码农题目
// 纯sb