#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		int x = 1, y = 1;
		reverse(s.begin(), s.end());
		for (auto i : s) {
			if (i == 'L' && y < m)
				y++;
			if (i == 'R' && y > 1)
				y--;
			if (i == 'U' && x < n)
				x++;
			if (i == 'D' && x > 1)
				x--;
		}
		cout << x << " " << y << endl;
	}
}
