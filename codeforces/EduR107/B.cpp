#include <bits/stdc++.h>
using namespace std;
int _, a, b, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> a >> b >> c;
		if (a >= b) {
			cout << 1;
			for (int i = 2; i <= a; i++) {
				cout << 0;
			}
			cout << " ";
			for (int i = 1; i <= b-c+1; i++) {
				cout << 1;
			}
			for (int i = b-c+1; i < b; i++) {
				cout << 0;
			}
			cout << "\n";
		} else {
			for (int i = 1; i <= a-c+1; i++) {
				cout << 1;
			}
			for (int i = a-c+1; i < a; i++) {
				cout << 0;
			}
			cout << " ";
			cout << 1;
			for (int i = 2; i <= b; i++) {
				cout << 0;
			}
			cout << "\n";
		}
	}
}