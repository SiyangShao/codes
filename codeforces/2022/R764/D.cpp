#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
string s;
vector<ll> cnt(26);
void solve() {
	cin >> n >> k >> s;
	for (auto i : s) {
		cnt[i - 'a']++;
	}
	auto sum = 0;
	auto du = 0;
	for (auto &i : cnt) {
		du += i % 2;
		sum += i - (i % 2);
		i = 0;
	}
	// cout << du << " " << sum << " ";
	auto ans = sum / k;
	du += sum % k;
	if (ans % 2) {
		cout << ans << "\n";
	} else {
		if (du >= k)
			ans++;
		cout << ans << "\n";
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