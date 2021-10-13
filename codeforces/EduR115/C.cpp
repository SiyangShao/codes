#include <bits/stdc++.h>
using namespace std;
#define eps 1e-7
long long _, n, a[200010];
double average;
int main() {
	scanf("%lld", &_);
	while (_--) {
		scanf("%lld", &n);
		average = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			average += a[i];
		}
		average /= n;
		average *= 2;
		if (abs(average - (long long)(average)) > eps) {
			puts("0");
		} else {
			map<long long, long long> mp;
			long long ans = (long long)average;
			long long dd = 0;
			for (int i = 1; i <= n; ++i) {
				dd += mp[ans - a[i]];
				mp[a[i]]++;
			}
			printf("%lld\n", dd);
		}
	}
}