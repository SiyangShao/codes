#include <bits/stdc++.h>
using namespace std;
int _, m, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> m >> n;
		if (m > n)
			swap(m, n);
		if (m == 1 && n == 1) {
			cout << "0\n";
		} else if (m == 1) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}