#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll ans, x1, y1;

ll exgcd(ll a, ll b, ll &x1, ll &y1) {
	if (!b) {
		x1 = 1;
		y1 = 0;
		return a;
	}
	ans = exgcd(b, a % b, x1, y1);
	ll t = x1;
	x1 = y1;
	y1 = t - a / b * y1;
	return ans;
}

int main() {
	ll n, m, x, y, l;
	cin >> x >> y >> m >> n >> l;
	ll b = n - m, a = x - y;
	if (b < 0) {
		b = -b;
		a = -a;
	}
	exgcd(b, l, x1, y1);
	if (a % ans != 0)
		cout << "Impossible";
	else
		cout << ((x1 * (a / ans)) % (l / ans) + (l / ans)) % (l / ans);
}