#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		if ((x + y) & 1) {
			printf("-1 -1\n");
		} else {
			if (x & 1)
				x++;
			if (y & 1)
				y--;
			printf("%d %d\n", x / 2, y / 2);
		}
	}
}