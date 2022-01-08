#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<pair<int, char>> a[N];
int n, m, dis[N] , vis[N] , f[N];
queue<pair<int, int>> q;
vector<int> tmp , ans;
void bfs() {
	q.push({n, 0});
	memset(dis, -1, sizeof(dis));
	while (q.size()) {
		auto cd = q.front();
		q.pop();
		if (dis[cd.first] != -1)
			continue;
        dis[cd.first] = cd.second;
		for (auto it : a[cd.first]) {
			int to = it.first;
			q.push({to, cd.second + 1});
		}
	}
}
void path(int x) {
	if (x == 0)
		return;
	path(f[x]);
	printf("%d ", x);
}

void solve() {
    for (int i = 1; i <= dis[1]; i++) {
        int mi = 0x3f3f3f3f;
        vector<int> v;
        for (auto j : tmp) {
            for (auto k : a[j]) {
                int to = k.first;
                int toto = (int)k.second;
                if (dis[to] + 1 == dis[j])
mi = min(mi, toto);
            }
        }
        for (auto j : tmp) {
            for (auto k : a[j]) {
                int to = k.first;
                int toto = (int)k.second;
                if (dis[to] + 1 == dis[j]) {
                    if (toto == mi && vis[to] == 0) {
                        v.push_back(to);
f[to] = j;
                        vis[to] = 1;
                    }
                }
            }
        }
        ans.push_back(mi);
        tmp.clear();
        for (auto j : v) {
            tmp.push_back(j);
        }
    }
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		char w;
		scanf("%d %d %c", &u, &v, &w);
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	bfs();
	tmp.push_back(1);
    solve();
    printf("%d\n", (int)ans.size());
	path(n);
	printf("\n");
	for (int i : ans) {
		printf("%c", (char)i);
	}
}