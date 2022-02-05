#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int check(int x) {
	int num = 0;
	while (x) {
		x >>= 1;
		num++;
	}
	return num;
}
int qpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans *= x;
		}
		x *= x;
		y >>= 1;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	int num = check(n - 1);
	int dif = qpow(2, num - 1);
	for (int i = n - 1; i >= dif; --i) {
		cout << i << " ";
	}
	cout << "0";
	for (int i = dif - 1; i > 0; --i) {
		cout << " " << i;
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}