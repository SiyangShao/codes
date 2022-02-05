#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, pair<int, int>> PII;
constexpr int N = 1010;
int a[N], b[N];
int n, m;
void solve() {
	cin >> n >> m;
	vector<PII> e(m);
	for (auto &i : e) {
		cin >> i.f >> i.s.f >> i.s.s;
	}
	sort(e.begin(), e.end(), [](PII x, PII y) { return x.f > y.f; });
	auto index = m;
	for (int i = 0; i < m; ++i) {
		auto now = e[i];
		if (now.f == 1) {
			a[now.s.f]++;
			a[now.s.s]--;
		} else {
			index = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i])
			a[i] = 1;
		b[i] = b[i - 1] + a[i];
	}
	bool flag = false;
	for (int i = index; i < m; ++i) {
		auto l = e[i].s.f, r = e[i].s.s;
		if (r - l <= b[r - 1] - b[l - 1]) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "NO";
	} else {
		cout << "YES\n";
		int begin = 1010;
		cout << 1010;
		for (int i = 1; i < n; ++i) {
			if (a[i]) {
				cout << " " << ++begin;
			} else {
				cout << " " << --begin;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}