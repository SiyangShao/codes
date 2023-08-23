#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
long double c[100010], a[100010], b[100010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n, m, l, r;
    cout << fixed<<setprecision(6);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + (a[i] - b[i]) * (a[i] - b[i]);
	}
	cin >> m;
	while (m--) {
		cin >> l >> r;
		cout<<sqrt(c[r] - c[l - 1]) << "\n";
	}
}