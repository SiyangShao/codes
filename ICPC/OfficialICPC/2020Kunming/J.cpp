#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001], vis[100001];
vector<int> swa;
vector<vector<int>> turn;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] || a[i] == i)
			continue;
		if (a[a[i]] == i) {
			swa.push_back(i);
			swa.push_back(a[i]);
			vis[i] = 1;
			vis[a[i]] = 1;
		} else {
			int k = i;
			turn.push_back({});
			do {
				turn[turn.size() - 1].push_back(k);
				vis[k] = 1;
				k = a[k];
			} while (k != i);
			vis[a[k]] = 1;
		}
	}
	if (swa.size() == 0 && turn.size() == 0) {
		cout << "0\n";
		return 0;
	}
	if (swa.size() != 0 && turn.size() == 0) {
		cout << "1\n";
		cout << swa.size() / 2;
		for (auto i : swa) {
			cout << " " << i;
		}
		cout << "\n";
		return 0;
	}
	cout << "2\n";
	int num = 0;
	for (auto i : turn) {
		num += (i.size() - 1) / 2;
	}

	cout << num + swa.size() / 2;
	for (auto i : swa) {
		cout << " " << i;
	}
	for (auto i : turn) {
		for (int j = 0, k = i.size() - 2; j < k; j++, k--) {
			cout << " " << i[j] << " " << i[k];
		}
	}
	cout << "\n";
	num = 0;
	for (auto i : turn) {
		num += i.size() / 2;
	}
	cout << num;
	for (auto i : turn) {
		for (int j = 0, k = i.size() - 1; j < k; j++, k--) {
			cout << " " << i[j] << " " << i[k];
		}
	}
	cout << "\n";
}