#include <bits/stdc++.h>
using namespace std;
int cnt;
unordered_map<string, int> mp;
unordered_map<int, string> rev;
int fa[50010];
inline void init() {
	for (int i = 1; i <= 50000; i++) {
		fa[i] = i;
	}
}
inline int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
inline void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string tmp;
	int an = 0;
	init();
	while (cin >> tmp) {
		if (tmp == "$") {
			break;
		}
		string now = "";
		for (int i = 1; i < tmp.length(); i++) {
			now += tmp[i];
		}
		if (mp[now] == 0) {
			mp[now] = ++cnt;
			rev[cnt] = now;
		}
		if (tmp[0] == '#') {
			an = mp[now];
		} else if (tmp[0] == '+') {
			unionSet(mp[now], an);
		} else {
			cout << now << " " << rev[find(mp[now])] << "\n";
		}
	}
}