#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> ans;
	for (auto &i : a) {
		scanf("%d", &i);
	}
	for (auto i : a) {
		if (ans.empty()) {
			ans.push_back(i);
		} else {
			if (i > *(ans.end() - 1)) {
				ans.push_back(i);
			} else {
				auto j = lower_bound(ans.begin(), ans.end(), i);
				*j = i;
			}
		}
	}
	printf("%d", n - ans.size());
}