#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 2e5 + 7;
vector<ll> dp(N, 0), su(N, 0);
ll n, p;
vector<ll> a;
unordered_map<ll, ll> vis, app;

inline bool judge(ll x) {
	auto tmp = x;
	while (x) {
		if (x % 4 == 0) {
			x /= 4;
			if (app[x])
				return false;
		} else if (x % 2 == 1) {
			x /= 2;
			if (app[x])
				return false;
		} else {
			break;
		}
	}
	//    cout << x << " " << tmp << "\n";
	return true;
}

void pre() {
	dp[1] = 1;
	dp[2] = 2;
	su[1] = 1;
	su[2] = 3;
	for (int i = 3; i < N; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		su[i] = (dp[i] + su[i - 1]) % MOD;
	}
}

inline ll BIT(ll x) {
	ll res = 0;
	while (x) {
		x >>= 1;
		res++;
	}
	return res;
}

void solve() {
	cin >> n >> p;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		app[a[i]] = 1;
	}
	sort(a.begin(), a.end());
	ll res = 0;
	for (auto i : a) {
		if (judge(i)) {
			//            cout << i << "\n";
			auto b = BIT(i);
			auto dif = p - b;
			if (dif >= 0) {
				//                cout << i << " " << b << " " << dif << " " <<
				//                dp[dif] << " " << su[dif] << "\n";
				res = (res + su[dif] + 1) % MOD;
			} else {
				break;
			}
		}
	}
	cout << res << "\n";
}

int main() {
	//    ios::sync_with_stdio(false);
	//    cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	//    cin >> _;
	pre();
	while (_--) {
		solve();
	}
}