#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> a, b;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0')
			a.push_back(i);
		if (t[i] == '0')
			b.push_back(i);
	}

	if (a.size() != b.size()) {
		cout << -1 << endl;
		return 0;
	}

	int res = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i])
			res++;
	}
	cout << res << endl;
}