#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, x, y, z;
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cin >> x >> y >> z;
		s = "";
		ll h = 0, i = 0, j = 0;
		while (i < n * 2 && j < n * 2 && h < n * 2) {
			if (x[i] == y[j]) {
				s += x[i];
				i++;
				j++;
			} else if (y[j] == z[h]) {
				s += y[j];
				j++;
				h++;
			} else if (x[i] == z[h]) {
				s += x[i];
				i++;
				h++;
			}
		}
		if (i == n * 2) {
			if (j > h) {
				for (j; j < n * 2; j++)
					s += y[j];
			} else {
				for (h; h < n * 2; h++)
					s += z[h];
			}
		} else if (j == n * 2) {
			if (i > h)
				for (i; i < n * 2; i++)
					s += x[i];
			else
				for (h; h < n * 2; h++)
					s += z[h];
		} else {
			if (i > j)
				for (i; i < n * 2; i++)
					s += x[i];
			else
				for (j; j < n * 2; j++)
					s += y[j];
		}
		cout << s << endl;
	}
}