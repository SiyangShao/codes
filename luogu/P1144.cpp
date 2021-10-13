#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[1000001];
const int mod = 100003;
int vis[1000001], cnt[1000001], dep[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	queue<int> Q;
	dep[1] = 0;
	vis[1] = 1;
	Q.push(1);
	cnt[1] = 1;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int t = a[x][i];
			if (!vis[t]) {
				vis[t] = 1;
				dep[t] = dep[x] + 1;
				Q.push(t);
			}
			if (dep[t] == dep[x] + 1) {
				cnt[t] = (cnt[t] + cnt[x]) % mod;
			}
		}
	}
    for(int i = 1 ; i<= n ; i++){
        cout<<cnt[i]<<"\n";
    }
}