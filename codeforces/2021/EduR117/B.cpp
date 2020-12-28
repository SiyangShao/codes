#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
	int _;
	scanf("%d", &_);
	while (_--) {
		scanf("%d%d%d", &n, &a, &b);
		vector<int> lef, rig;
		lef.push_back(a), rig.push_back(b);
		for (int i = n; i >= 1; --i) {
			if (i == a || i == b)
				continue;
			if (i > a && lef.size() != n / 2) {
				lef.push_back(i);
			} else {
				rig.push_back(i);
			}
		}
		if (lef.size() != n / 2) {
			printf("-1\n");
		} else {
			sort(lef.begin(), lef.end());
			sort(rig.begin(), rig.end(), [](int x, int y) { return x > y; });
			if (*lef.begin() != a || *rig.begin() != b) {
				printf("-1\n");
			} else {
				for (auto i : lef) {
					printf("%d ", i);
				}
				for (auto i : rig) {
					printf("%d ", i);
				}
				printf("\n");
			}
		}
	}
}