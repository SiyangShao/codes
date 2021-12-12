#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int s[105], ans[105];
void add(int a[], int b[]) {
	for (int i = 0; i <= 55; i++)
		a[i] += b[i];
	for (int i = 0; i <= 55; i++)
		a[i + 1] += a[i] / 10, a[i] %= 10;
}
void mul(int a[], int k) {
	for (int i = 0; i <= 55; i++)
		a[i] *= k;
	for (int i = 0; i <= 55; i++)
		a[i + 1] += a[i] / 10, a[i] %= 10;
}
int main() {
	ll i, j, k, p, l = 100;
	cin >> k >> p;
	s[0] = 1;
	while (p) {
		if (p % 2 == 1)
			add(ans, s);
		p /= 2;
		mul(s, k);
	}
	while (ans[l] == 0)
		l--;
	for (i = l; i >= 0; i--)
		cout << ans[i];
	return 0;
}
