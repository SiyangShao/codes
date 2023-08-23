#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep(i, a, b) for (auto i = (a); i >= (b); i--)

const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 3 * 1e5 + 2;

#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else
#define LOG(message)
#endif

ll mod(ll x, ll y = MOD) { return ((x % y) + y) % y; }

ll addm(ll x) { return x; }

template <typename... Ts> ll addm(ll x, Ts... ys) {
	return mod(x + addm(ys...));
}

ll mulm(ll x) { return x; }

template <typename... Ts> ll mulm(ll x, Ts... ys) {
	return mod(x * mulm(ys...));
}

void solve(ll matrix[5][5], ll f[5], ll ans[5]) {
	for (ll i = 0; i < 5; i++) {
		ll temp = 0;
		for (ll j = 0; j < 5; j++) {
			temp += matrix[i][j] * f[j];
		}
		ans[i] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	ll matrix[5][5] = {{1, -4, 6, -4, 1},
					   {-14, 52, -72, 44, -10},
					   {71, -236, 294, -164, 35},
					   {-154, 428, -468, 244, -50},
					   {120, -240, 240, -120, 24}};

	ll f[5];
	ll ans[5];
	bool found = false;
	while (t--) {
		cin >> f[0] >> f[1] >> f[2] >> f[3] >> f[4];

		rep(i0, -1, 2) {
			rep(i1, -1, 2) {
				rep(i2, -1, 2) {
					rep(i3, -1, 2) {
						rep(i4, -1, 2) {
							f[0] += i0;
							f[1] += i1;
							f[2] += i2;
							f[3] += i3;
							f[4] += i4;
							memset(ans, 0, sizeof(ans));
							// cout << f[0] << " " << f[1] << " "<< f[2] << " "
							// << f[3] << " " << f[4] <<endl;
							solve(matrix, f, ans);
							f[0] -= i0;
							f[1] -= i1;
							f[2] -= i2;
							f[3] -= i3;
							f[4] -= i4;
							bool can = true;
							rep(i, 0, 5) {
								if (abs(ans[i]) % 24 != 0) {
									can = false;
									break;
								}
								ans[i] /= 24;
								if (ans[i] < -100 || ans[i] > 100) {
									can = false;
									break;
								}
							}
							if (can) {
								goto end;
							}
						}
					}
				}
			}
		}
	end:
		rrep(i, 4, 0) cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}
