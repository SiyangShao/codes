#include <bits/stdc++.h>
using namespace std;

int i, t, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> i;
		int begin = 1, pre = i;
		n--;
		if (i == 1)
			begin++;
		while (n--) {
			pre = i;
			cin >> i;
			if (begin == -1)
				continue;
			if (i == pre) {
				if (pre == 0) {
					begin = -1;
				} else {
					begin += 5;
				}
			} else {
				if (i == 1)
					begin++;
			}
		}
		cout << begin << "\n";
	}
}