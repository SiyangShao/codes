#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef string str;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<iii> viii;
typedef vector<vector<iii>> vviii;
typedef vector<str> vs;
typedef vector<vector<str>> vvs;

// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> pbds;

#define LSOne(S) ((S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i, v) for (auto i : v)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)
#define repn(i, a, b) for (int i = (a); i <= (b); i++)
#define repin(i, a, b, x) for (int i = (a); i < (b); i += x)
#define repnin(i, a, b, x) for (int i = (a); i <= (b); i += x)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(), v.end()
#define FILL(arr, x) memset(arr, x, sizeof arr);

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

ll __lcm(ll x, ll y) { return x * y / (__gcd(x, y)); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	ll dp[2 * n + 3][2 * n + 3];
	FILL(dp, 0);
	ll arr[2 * n + 1];
	rep(i, 0, n) {
		cin >> arr[i];
		arr[n + i] = arr[i];
	}
	if (n == 1) {
		cout << arr[0];
		return 0;
	}

	rep(i, 0, 2 * n) {
		rrep(j, i - 1, max(0, i - n)) {
			rep(k, j + 1, i) {
				// cout << " " << i<< " " << j << endl;
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] +
											 arr[i] * arr[j] * arr[k] +
											 ((i - j == n) ? arr[i] : 0));
			}
		}
	}
	ll maxv = 0;
	rep(i, 0, n) { maxv = max(maxv, dp[i][i + n]); }

	cout << maxv;

	return 0;
}

/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/