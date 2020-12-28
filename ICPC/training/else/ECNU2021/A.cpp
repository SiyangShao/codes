#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
inline void solve() {
	if (c == 0) {
		if (a == 1) {
			printf("1\n");
			printf("A %d\n", b);
		} else {
			printf("2\n");
			printf("B 2\nA %d\n", -b);
		}
	} else if (a == 0) {
		if (c == 1) {
			printf("2\n");
			printf("B -1\n");
			printf("A %d\n", d);
		} else {
			printf("2\n");
			printf("B 1\n");
			printf("A %d\n", -d);
		}
	} else if (b == 0) {
		if (-d == 1) {
			printf("3\n");
			printf("B -1\n");
			printf("A %d\n", c);
			printf("B -1\n");
		}else{
            printf("3\n");
			printf("B 1\n");
			printf("A %d\n", -c);
			printf("B -1\n");
        }
	}else{
        if(-b == 1){
            printf("2\n");
            printf("A %d\n",a);
            printf("B -1\n");
        }else{
            printf("3\n");
            printf("B 2\n");
            printf("A %d\n",-a);
            printf("B -1\n");
        }
    }
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		solve();
	}
}