#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	bool flag = false;
	for (auto i : s1) {
		if (i < '0' || i > '9')
			flag = true;
	}
	for (auto i : s2) {
		if (i < '0' || i > '9')
			flag = true;
	}
	if (flag) {
		cout << "NaN"
			 << "\n";
		return 0;
	}
	int x = stoi(s1);
	int y = stoi(s2);
	cout << x - y << "\n";
}