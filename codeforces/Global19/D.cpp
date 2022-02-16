#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	vector<ll> dif(n);
	ll sum = 0, cnt = 0;
	for (auto &i : a) {
		cin >> i;
		sum += (n - 2) * i * i;
		cnt += i;
	}
	for (auto &i : b) {
		cin >> i;
		sum += (n - 2) * i * i;
		cnt += i;
	}
	if (n == 1) {
		cout << "0" << endl;
	} else {
		ll M = 0;
		for (int i = 0; i < n; ++i) {
			dif[i] = 2 * abs(a[i] - b[i]);
			M += dif[i];
		}
		M /= 2;
		vector<ll> f(M * 2, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = M * 2 - 1; j >= dif[i]; j--) {
				f[j] = max(f[j], f[j - dif[i]] + dif[i]);
			}
		}
		ll ans = M;
		for (auto i : f) {
			ans = min(ans, abs(i - M));
		}
		ll L = (cnt + ans) / 2, R = (cnt - ans) / 2;
		sum += L * L + R * R;
		cout << sum << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}