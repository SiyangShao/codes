#include <bits/stdc++.h>
using namespace std;
int n;
int h[1001], v[1001];
inline bool judge(int x) {
	for (int i = 2; i <= n; i++) {
		if (h[i] + x > v[i]) {
			return true;
		} else if (h[i] + x < v[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if (h[1] > v[1]) {
		cout << "0\n";
	} else {
		int tmp = v[1] - h[1];
		for (int i = 2; i <= n; i++) {
			if (h[i] + tmp > v[i]) {
				cout << tmp << "\n";
				return 0;
			} else if (h[i] + tmp < v[i]) {
				cout << tmp + 1 << "\n";
                return 0;
			}
		}
		cout << tmp << "\n";
	}
}