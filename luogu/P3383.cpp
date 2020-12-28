#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 7;
bitset<N> vis;
vector<int> prime;
void Euler(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			prime.push_back(i);
		}
		for (auto j : prime) {
			if (1ll * j * i >= n) {
				break;
			}
			vis[j * i] = 1;
			if (i % j == 0) {
				break;
			}
		}
	}
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	Euler(n);
	while (q--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", prime[x - 1]);
	}
}