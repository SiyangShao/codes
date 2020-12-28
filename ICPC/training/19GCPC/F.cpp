#include <bits/stdc++.h>
using namespace std;
int m[100010];
vector<int> q[1000010];
int main() {
	int n;
	cin >> n;
	int a = 1, b = 1;
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		maxn = max(m[i], maxn);
		q[m[i]].push_back(i);
	}
	int t = 0;
	while (a <= maxn && b <= maxn) {
		if (a == b) {
			if (q[a].size() >= 2) {
				cout << q[a][0] << " " << q[a][1];
				return 0;
			}
		} else {
			if (q[a].size() > 0 && q[b].size() > 0) {
				if (t % 2 == 0)
					cout << q[b][0] << " " << q[a][0];
				else
					cout << q[a][0] << " " << q[b][0];
				return 0;
			}
		}
		if (t % 2 == 0) {
			b += a;
		} else {
			a += b;
		}
        t++;
	}
    cout<<"impossible";
}