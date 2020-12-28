#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int _;
	ll u, v, x, y;
	scanf("%d", &_);
	while (_--) {
		scanf("%lld%lld", &u, &v);
		x = v * v;
		y = u * u;
		printf("%lld %lld\n", -y, x);
	}
}