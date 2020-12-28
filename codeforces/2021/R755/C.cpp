#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<int> a(n), b(n);
		for (auto &i : a) {
			scanf("%d", &i);
		}
		for (auto &i : b) {
			scanf("%d", &i);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i] && a[i] != b[i] - 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}