#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 2 == 0) {
			if (n % 4 == 0) {
				cout << "Even\n";
			} else {
				cout << "Same\n";
			}
		} else {
			cout << "Odd\n";
		}
	}
}