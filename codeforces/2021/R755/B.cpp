#include <bits/stdc++.h>
using namespace std;
int t, m, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", (n * m) / 3 + ((n * m) % 3 == 0 ? 0 : 1));
	}
}