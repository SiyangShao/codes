#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005] ;
signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int tmp = 0, t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			if (i > j) {
				tmp += t * min(a[i], a[j]);
			}
		}
	}
	cout << tmp;
}