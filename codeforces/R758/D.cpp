#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll W_l, W_r, B_l, B_r, C_l, C_r;
inline ll cal(ll m_start, ll m_end) {
	ll L = 1, R = 1;
	for (ll i = 1; i <= C_l; ++i) {
		L = L * i % mod;
	}
	for (ll i = 1; i <= C_r; ++i) {
		R = R * i % mod;
	}
	ll M = 1, N_M = 1, T_M = 1;
	for (ll i = 1; i < m_start; ++i) {
		M = M * i % mod;
	}
	for (ll i = 1; i <= C_l - m_start; ++i) {
		N_M = N_M * i % mod;
	}
	for (ll i = 1; i <= C_r - m_start; ++i) {
		T_M = T_M * i % mod;
	}
	ll ans = 0;
	for (ll i = m_start; i <= m_end; ++i) {
		if (i)
			M = M * i % mod;
		cout << L << " " << R << " " << M << " " << T_M << " " << N_M <<
		"\n";
		ans += ((L * R) % mod) / ((M * M % mod) * (T_M * N_M % mod));
		ans %= mod;
		if (N_M < C_l - i) {
			N_M += mod;
		}
		if (T_M < C_r - i) {
			T_M += mod;
		}
		if (!C_l - i)
			N_M = 1;
		else
			N_M /= (C_l - i);
		if (!C_r - i)
			T_M = 1;
		else
			T_M /= (C_r - i);
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0), cout.tie(0);
	ll n;
	string tmp;
	cin >> n;
	W_l = 0, W_r = 0, B_l = 0, B_r = 0, C_l = 0, C_r = 0;
	while (n--) {
		cin >> tmp;
		if (tmp[0] == '?') {
			C_l++;
		} else if (tmp[0] == 'B') {
			B_l++;
		} else if (tmp[0] == 'W') {
			W_l++;
		}
		if (tmp[1] == '?') {
			C_r++;
		} else if (tmp[1] == 'B') {
			B_r++;
		} else if (tmp[1] == 'W') {
			W_r++;
		}
	}
	ll mi = max(B_r - W_l, 0ll);
	ll ma = min(mi + C_l, mi + C_r - max(B_l - W_r, 0ll));
	cout << cal(mi, ma);
}