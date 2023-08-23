#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	int a, b, c;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << (a + c) % 2 << "\n";
	}
}