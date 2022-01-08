#include <bits/stdc++.h>
using namespace std;
long long a[4];
bool cmp(long long x, long long y) { return x > y; }
int main() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4, cmp);
	if (a[0] == a[1] && a[2] == a[3]) {
		cout << "YES\n";
	} else {
		if (a[0] - a[1] == a[2] - a[3]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}