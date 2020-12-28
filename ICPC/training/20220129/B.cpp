#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZ = 100000 + 3;
char buf1[SIZ];
char *p1 = buf1, *p2 = buf1;
inline char readchar() { //快速读入字符
	if (p1 == p2)
		p1 = buf1, p2 = buf1 + fread(buf1, 1, SIZ, stdin);
	return p1 == p2 ? EOF : *p1++;
}
inline int qread() { //快读
	int ret, c;
	while ((c = readchar()) > '9' || c < '0')
		;
	ret = c - '0';
	while ((c = readchar()) >= '0' && c <= '9')
		ret = ret * 10 + c - '0';
	return ret;
}
int main() {

	int _ = 1;
	_ = qread();
	while (_--) {
		ll x;
		x = qread();
		// judge x is abundant numbers, deficient numbers, and perfect numbers
		if (x != 1) {
			ll sum = 1;
			for (ll i = 2; i <= sqrt(x); i++) {
				if (i == sqrt(x)) {
					sum += i;
				} else if (x % i == 0) {
					sum += i + (x / i);
				}
			}
			if (sum == x) {
				puts("perfect");
			} else if (sum > x) {
				puts("abundant");
			} else {
				puts("deficient");
			}
		} else {
			puts("deficient");
		}
	}
}