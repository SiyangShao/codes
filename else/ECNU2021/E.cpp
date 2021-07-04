#include <bits/stdc++.h>
using namespace std;
#define ms(x, n) memset(x, n, sizeof(x));
typedef long long LL;
const int inf = 1 << 30;
const int MAXN = 1e5+10;

int par[MAXN];
int findr(int u) {
	if (par[u] == u)
		return u;
	return par[u] = findr(par[u]);
}
void unite(int u, int v) {
	u = findr(u);
	v = findr(v);
	if (u != v)
		par[v] = u;
}
bool vis[MAXN];
struct G {
	int to, next, w;
} G[MAXN * 2];
int head[MAXN], ecnt;
void addEdge(int u, int v, int w) {
	G[ecnt].to = v;
	G[ecnt].w = w;
	G[ecnt].next = head[u];
	head[u] = ecnt++;
}
struct Query {
	int q, next;
	int id;
} query[MAXN * 2];
int h[MAXN], qcnt, Q;
void addQuery(int u, int v, int id) {
	query[qcnt].q = v;
	query[qcnt].next = h[u];
	query[qcnt].id = id;
	h[u] = qcnt++;
}
int lca[MAXN]; //询问边对应的最近公共祖先
int dis[MAXN]; //根节点到每个点的距离
int l[MAXN], r[MAXN];
void LCA(int u) {
	vis[u] = true;
	for (int i = head[u]; i != -1; i = G[i].next) {
		int v = G[i].to;
		if (vis[v])
			continue;
		dis[v] = dis[u] + G[i].w;
		LCA(v);
		unite(u, v);
	}
	for (int i = h[u]; i != -1; i = query[i].next) {
		int v = query[i].q;
		if (vis[v])
			lca[query[i].id] = findr(v);
	}
}
void init(int N) {
	for (int i = 0; i <= N; ++i)
		par[i] = i;
	ecnt = qcnt = 0;
	memset(head, -1, sizeof(head));
	memset(h, -1, sizeof(h));
	memset(vis, 0, sizeof(vis));
}
int main() {
	int T, u, v, w, N, M;
	T=1;
	while (T--) {
		cin >> N;
		init(N);
		for (int i = 1; i < N; ++i) {
			cin >> u >> v;
			w=1;
			addEdge(u, v, w);
			addEdge(v, u, w);
		}
		for (int i = 1; i <= 1; ++i) {
			cin >> l[i] >> r[i];
			addQuery(l[i], r[i], i);
			addQuery(r[i], l[i], i);
		}
		dis[1] = 0;
		LCA(1);
		for (int i = 1; i <= 1; ++i)
			if((dis[l[i]] + dis[r[i]] - 2 * dis[lca[i]])%2==0){
				cout<<"No\n";
			}else{
				cout<<"Yes\n";
			}
	}
	return 0;
}