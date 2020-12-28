#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 100010;
int a[N];
int n, w;
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &w);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		priority_queue<int> h;
		int ans = 1;
		sort(a + 1, a + 1 + n);
		h.push(w - a[n]);
		for (int i = n - 1; i >= 1; i--) {
			int x = h.top();
			h.pop();
			if (a[i] <= x)
				h.push(x - a[i]);
			else {
				ans++;
				h.push(x);
				h.push(w - a[i]);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}