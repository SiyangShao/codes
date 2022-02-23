#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> siz(N, 1);
vector<int> fa(N, 1);

int find(int x) {
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}

bool unionSet(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx == yy)
		return true;
	if (siz[xx] > siz[yy])
		swap(xx, yy);
	fa[xx] = yy;
	siz[yy] += siz[xx];
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, d, xi, yi;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	int any = 0;
	while (d--) {
		cin >> xi >> yi;
		if (unionSet(xi, yi)) {
			any++;
		}
		vector<int> a;
		for (int i = 1; i <= n; ++i) {
			if (i == find(i)) {
				a.push_back(siz[i]);
			}
		}
		sort(a.begin(), a.end(), greater<int>());
		int res = 0;
		for (int i = 0; i < min(int(a.size()), any + 1); ++i) {
			res += a[i];
		}
		cout << res - 1 << "\n";
	}
}