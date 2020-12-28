#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	int a, b, c;
	c = n % 10;
	n /= 10;
	b = n % 10;
	n /= 10;
	a = n % 10;
	cout << (a + b + c) * 111;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}