#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
void solve() {
	string s;
	cin >> s;
	int N = s.length();
	if (N == 1) {
		cout << s;
		return;
	} else if (N == 2) {
		cout << s;
		return;
	}
	auto dif = s[1] - s[0];
	bool flag = true, can = true;
	for (int i = 2; i < N; ++i) {
		if (s[i] > s[0] + dif * i) {
			flag = false;
		}
		if (s[0] + dif * i > '9' || s[0] + dif * i < '0') {
			can = false;
		}
	}
	if (can) {
		if (flag) {
			for (int i = 1; i <= N; ++i) {
				cout << s[0];
				s[0] += dif;
			}
		} else {
			dif++;
			if (dif * (N - 1) + s[0] <= '9' && dif * (N - 1) + s[0] >= '0') {
				for (int i = 1; i <= N; ++i) {
					cout << s[0];
					s[0] += dif;
				}
			} else {
				if (dif - 1 < 0) {
					dif = (s[0] - '0') / (N - 1);
					for (int i = 0; i < N; ++i) {
						cout << s[0];
						s[0] -= dif;
					}
				} else if (s[0] == '9') {
					for (int i = 0; i <= N; ++i) {
						cout << 1;
					}
				} else {
					s[0]++;
					auto dif = (s[0] - '0') / (N - 1);
					for (int i = 0; i < N; ++i) {
						cout << s[0];
						s[0] -= dif;
					}
				}
			}
		}
	} else {
		if (s[0] == '9') {
			for (int i = 0; i <= N; ++i) {
				cout << 1;
			}
		} else {
			s[0]++;
			auto dif = (s[0] - '0') / (N - 1);
			for (int i = 0; i < N; ++i) {
				cout << s[0];
				s[0] -= dif;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}