#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	int p1, p2;
	double x1, x2;
	while (_--) {
		cin >> x1 >> p1 >> x2 >> p2;
		while (x1 >= 10.0) {
			x1 /= 10.0;
			p1++;
		}
		while (x2 >= 10.0) {
			x2 /= 10.0;
			p2++;
		}
		if (p1 > p2) {
			cout << ">\n";
		} else if (p1 == p2) {
			if (x1 > x2) {
				cout << ">\n";
			} else if (x1 < x2) {
				cout << "<\n";
			} else {
				cout << "=\n";
			}
		} else {
			cout << "<\n";
		}
	}
}