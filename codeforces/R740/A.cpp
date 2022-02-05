#include <bits/stdc++.h>
using namespace std;
const int maxn = 1002;
int a[maxn];
int b[maxn];
int t, n;
bool check() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
		for (int k = 1;; k++) {
			if (check()) {
				cout << --k << endl;
				break;
			}
			if (k % 2) {
				for (int i = 1; i < n; i += 2) {
					if (a[i] > a[i + 1])
						swap(a[i], a[i + 1]);
				}
			} else {
				for (int i = 2; i < n; i += 2) {
					if (a[i] > a[i + 1])
						swap(a[i], a[i + 1]);
				}
			}
		}
	}
	return 0;
}