#include <iostream>
using namespace std;

typedef long long int ll;
typedef long double ld;

const int MAXN = 100005;
ll n, p, a[MAXN], b[MAXN];
ll sum;

bool check(ld x) {
	ld tot = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] * x <= b[i])
			continue;
		tot += (a[i] * x - b[i]);
	}
	return tot <= p * x;
}

int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i], sum += a[i];
	if (sum <= p) {
		cout << -1;
		return 0;
	}
	ld star = 0, ed = 1e10, mid;
	while (ed - star > 0.0000001) {
		mid = (star + ed) / 2;
		if (check(mid))
			star = mid;
		else
			ed = mid;
	}
	printf("%.8llf", star);
	return 0;
}