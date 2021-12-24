#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, Q;
inline int max_(const int &x, const int &y) { return x > y ? x : y; }
const int maxn = 200010; //总结点数
int TREE[maxn << 2];	 //四倍空间线段树
int lazy[maxn << 2]; //懒惰标记数组,大小要开成与线段树一一对应
int POW[31];
struct E {
	int u, v, w;
} e[maxn << 1];						  //树不定形要存双向边
int first[maxn], nt[maxn << 1], ES;	  //邻接表
inline void addE(int u, int v, int w) //加边函数
{
	E nxt;
	nxt.u = u, nxt.v = v, nxt.w = w;
	e[++ES] = nxt;
	nt[ES] = first[u];
	first[u] = ES;
	return;
}
int sz[maxn] /*树大小*/, fa[maxn] /*直属父亲*/, top[maxn] /*链头结点*/;
int son[maxn] /*重儿子*/, depth[maxn] /*深度*/;
int id[maxn] /*结点->线段树编号*/, anti[maxn] /*线段树编号->结点*/;
int ix, A[maxn] /*在做点权树剖时的点权数组*/;
inline void DFS(int u) {
	int v;
	sz[u] = 1; //大小初始化
	for (int i = first[u]; i; i = nt[i]) {
		v = e[i].v;
		if (v != fa[u]) //不能死转圈
		{
			depth[v] = depth[u] + 1;
			fa[v] = u; // v的父亲是u
			A[v] = e[i].w; //转化关键代码1,将连向子节点的边权直接赋给子节点
			DFS(v);
			sz[u] += sz[v]; //维护大小
			if (sz[son[u]] < sz[v])
				son[u] = v; //重儿子
		}
	}
	return;
}
inline void dfs(int u, int tp) {
	id[u] = ++ix;
	anti[ix] = u; //建立正反映射
	top[u] = tp;  //链头
	if (son[u])
		dfs(son[u], tp); //优先遍历重儿子
	int v;
	for (int i = first[u]; i; i = nt[i]) {
		v = e[i].v;
		if (v == son[u] || v == fa[u])
			continue;
		dfs(v, v);
	}
	return;
}
#define mid (L + R >> 1)
#define L(i) (i << 1)
#define R(i) (i << 1 | 1) //涉及到优先级较低的位运算建议加括号
inline void Build(int L, int R, int i) {
	if (L == R) {
		TREE[i] = A[anti[L]]; //之前已经进行了转化可以不改变这里
		return;
	}
	Build(L, mid, L(i));
	Build(mid + 1, R, R(i));
	TREE[i] = TREE[L(i)] + TREE[R(i)];
	return;
}
inline void LAZY(int L, int R, int i) {
	if (!lazy[i])
		return;
	lazy[L(i)] += lazy[i];
	lazy[R(i)] += lazy[i];
	TREE[L(i)] += (mid - L + 1) * lazy[i];
	TREE[R(i)] += (R - mid) * lazy[i];
	lazy[i] = 0; //高频错点！！
	return;
}
inline void Update(int L, int R, int l, int r, int i, int k) {
	if (l <= L && R <= r) {
		TREE[i] += k * (R - L + 1);
		lazy[i] += k;
		return;
	}
	LAZY(L, R, i); //任何时候访问子节点都需要下传标记
	if (l <= mid)
		Update(L, mid, l, r, L(i), k);
	if (r > mid)
		Update(mid + 1, R, l, r, R(i), k);
	TREE[i] = TREE[L(i)] + TREE[R(i)];
	return;
}
inline int Query(int L, int R, int l, int r, int i) {
	if (l <= L && R <= r)
		return TREE[i];
	LAZY(L, R, i);
	int ans = 0;
	if (l <= mid)
		ans += Query(L, mid, l, r, L(i));
	if (r > mid)
		ans += Query(mid + 1, R, l, r, R(i));
	return ans;
}
inline void Update_Path(int x, int y, int k) {
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]])
			swap(x, y);
		Update(1, N, id[top[x]], id[x], 1, k);
		x = fa[top[x]];
	}
	if (depth[x] > depth[y])
		swap(x, y);
	Update(1, N, id[x], id[y], 1, k);
	Update(1, N, id[x], id[x], 1, -k); //核心代码2
	return;
}
inline int Query_Path(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]])
			swap(x, y);
		ans += Query(1, N, id[top[x]], id[x], 1);
		x = fa[top[x]];
	}
	if (depth[x] > depth[y])
		swap(x, y);
	ans += Query(1, N, id[x], id[y], 1);
	ans -= Query(1, N, id[x], id[x], 1); //核心代码3
	return ans;
}
// inline int Re() {
// 	char c;
// 	int re;
// 	while ((c = getchar()) > '9' || c < '0')
// 		;
// 	re = c - 48;
// 	while ((c = getchar()) >= '0' && c <= '9')
// 		re = re * 10 + c - 48;
// 	return re;
// }
// void SOLVE() {
// 	N = Re();
// 	Q = Re();
// 	int u, v, w;
// 	for (int i = 1; i < N; i++) {
// 		u = Re();
// 		v = Re();
// 		w = Re();
// 		addE(u, v, w);
// 		addE(v, u, w);
// 	}
// 	DFS(1);
// 	dfs(1, 1);
// 	Build(1, N, 1);
// 	int op;
// 	for (int i = 1; i <= Q; i++) {
// 		op = Re();
// 		if (op == 1) //路径更新
// 		{
// 			u = Re();
// 			v = Re();
// 			w = Re();
// 			Update_Path(u, v, w);
// 		} else if (op == 2) //子树更新
// 		{
// 			u = Re();
// 			w = Re();
// 			Update(1, N, id[u], id[u] + sz[u] - 1, 1, w);
// 		} else if (op == 3) //路径询问
// 		{
// 			u = Re();
// 			v = Re();
// 			printf("%d\n", Query_Path(u, v));
// 		} else //子树询问
// 		{
// 			u = Re();
// 			printf("%d\n", Query(1, N, id[u], id[u] + sz[u] - 1, 1));
// 		}
// 	}
// }
void solve() {
	memset(TREE, 0, sizeof(TREE));
	memset(lazy, 0, sizeof(lazy));
	memset(first, 0, sizeof(first));
	memset(nt, 0, sizeof(nt));
	vector<pair<int, pair<int, int>>> ASKING;
	bool flag = true;
	scanf("%lld", &N);
	scanf("%lld", &Q);
	int u, v, w;
	for (int i = 1; i < N; ++i) {
		scanf("%lld %lld %lld", &u, &v, &w);
		if (w == -1) {
			addE(u, v, 0);
			addE(v, u, 0);
			ASKING.push_back({-1, {u, v}});
		} else {
			int W = __builtin_popcount(w);
			addE(u, v, W);
			addE(v, u, W);
			ASKING.push_back({w, {u, v}});
		}
	}
	DFS(1);
	dfs(1, 1);
	Build(1, N, 1);
	for (int i = 1; i <= Q; ++i) {
		scanf("%lld%lld%lld", &u, &v, &w);
		int WN = Query_Path(u, v);
		// cout << "      " << u << " " << v << " " << WN << endl;
		if (WN % 2 == 0 && w == 1)
			Update_Path(u, v, WN + 1);
		else if (WN % 2 == 1 && w == 0)
			Update_Path(u, v, WN + 1);
	}
	for (auto i : ASKING) {
		if (i.first != -1) {
			if (__builtin_popcount(i.first) % 2 !=
				Query_Path(i.second.first, i.second.second) % 2) {
				flag = false;
				// cout << i.first << " "
				// 	 << Query_Path(i.second.first, i.second.second) << ":"
				// 	 << i.second.first << " " << i.second.second << endl;
				break;
			}
		}
	}
	if (!flag) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (auto i : ASKING) {
		printf("%lld %lld ", i.second.first, i.second.second);
		if (i.first != -1) {
			printf("%lld\n", i.first);
		} else {
			printf("%lld\n",
				   POW[Query_Path(i.second.first, i.second.second)] - 1);
		}
	}
}
signed main() {
	POW[0] = 1;
	for (int i = 1; i <= 30; ++i) {
		POW[i] = POW[i - 1] * 2;
	}
	int _ = 1;
	scanf("%lld",&_);
	while (_--) {
		solve();
	}
	// N = Re();
	// Q = Re();
	// int u, v, w;
	// for (int i = 1; i < N; i++) {
	// 	u = Re();
	// 	v = Re();
	// 	w = Re();
	// 	addE(u, v, w);
	// 	addE(v, u, w);
	// }
	// DFS(1);
	// dfs(1, 1);
	// Build(1, N, 1);
	// int op;
	// for (int i = 1; i <= Q; i++) {
	// 	op = Re();
	// 	if (op == 1) //路径更新
	// 	{
	// 		u = Re();
	// 		v = Re();
	// 		w = Re();
	// 		Update_Path(u, v, w);
	// 	} else if (op == 2) //子树更新
	// 	{
	// 		u = Re();
	// 		w = Re();
	// 		Update(1, N, id[u], id[u] + sz[u] - 1, 1, w);
	// 	} else if (op == 3) //路径询问
	// 	{
	// 		u = Re();
	// 		v = Re();
	// 		printf("%d\n", Query_Path(u, v));
	// 	} else //子树询问
	// 	{
	// 		u = Re();
	// 		printf("%d\n", Query(1, N, id[u], id[u] + sz[u] - 1, 1));
	// 	}
	// }
	// return 0;
}