#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 7;

ll n, k;

void solve() {
	cin >> n >> k;
	vector<ll> N, P;
	ll sumN = 0, maxN = 0, sumP = 0, maxP = 0;
	for (int i = 1, tmp; i <= n; ++i) {
		cin >> tmp;
		if (tmp < 0) {
			N.push_back(-tmp);
		} else {
			P.push_back(tmp);
		}
	}
	sort(N.begin(), N.end(), greater<ll>());
	sort(P.begin(), P.end(), greater<ll>());
	for (auto i = N.begin(); i < N.end(); i += k) {
		sumN += *i * 2ll;
		maxN = max(maxN, *i);
	}
	for (auto i = P.begin(); i < P.end(); i += k) {
		sumN += *i * 2ll;
		maxN = max(maxN, *i);
	}
	cout << sumN + sumP - max(maxN, maxP) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}
