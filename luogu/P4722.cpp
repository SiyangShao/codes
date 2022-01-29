#include <bits/stdc++.h>
#define up(l, r, i) for (int i = l; i <= r; ++i)
#define ergv(u) for (auto p = head[u].begin(); p != head[u].end(); ++p)
#define ergl(u) for (auto p = lst[u].begin(); p != lst[u].end(); ++p)
constexpr int INF = 2147483647;
constexpr int MAXN = 1200 + 3, MAXM = 120000 + 3;
int n, m, s, t, mxflow, hst, nwh;
std::vector<int> lft, gap, ht, q, mlst[MAXN];
struct edge { //边
	int ver, nxt, flw;
	edge(int _ver, int _flw, int _nxt) : ver(_ver), flw(_flw), nxt(_nxt) {}
};
std::vector<edge> head[MAXN];
std::list<int> lst[MAXN];
std::vector<std::list<int>::iterator> it;
const int SIZ = 100000 + 3;
char buf1[SIZ];
char *p1 = buf1, *p2 = buf1;
inline char readchar() { //快速读入字符
	if (p1 == p2)
		p1 = buf1, p2 = buf1 + fread(buf1, 1, SIZ, stdin);
	return p1 == p2 ? EOF : *p1++;
}
inline int qread() { //快读
	int ret, c;
	while ((c = readchar()) > '9' || c < '0')
		;
	ret = c - '0';
	while ((c = readchar()) >= '0' && c <= '9')
		ret = ret * 10 + c - '0';
	return ret;
}
inline void add() { //连边
	int u = qread(), v = qread(), k = qread();
	head[u].push_back(edge(v, k, head[v].size()));
	head[v].push_back(edge(u, 0, head[u].size() - 1));
}
inline void rlb() { //全局冲贴标签
	ht.assign(n + 3, n), gap.assign(n + 3, 0), ht[t] = 0;
	q.clear(), q.resize(n + 3);
	int front = 0, rear = 0, u;
	for (q[rear++] = t; front < rear;) {
		u = q[front++];
		ergv(u) if (ht[p->ver] == n &&
					head[p->ver][p->nxt].flw)++ gap[ht[p->ver] = ht[u] + 1],
			q[rear++] = p->ver;
	}
	up(1, n, i) mlst[i].clear(), lst[i].clear();
	up(1, n, i) if (ht[i] < n) {
		it[i] = lst[ht[i]].insert(lst[ht[i]].begin(), i);
		if (lft[i] > 0)
			mlst[ht[i]].push_back(i);
	}
	hst = (nwh = ht[q[rear - 1]]);
}
inline void psh(int u, edge &e) { //推流子函数
	int v = e.ver, df = std::min(lft[u], e.flw);
	e.flw -= df, head[v][e.nxt].flw += df, lft[u] -= df, lft[v] += df;
	if (lft[v] > 0 && lft[v] <= df)
		mlst[ht[v]].push_back(v);
}
inline void psh(int u) { //真正的推流
	int nh = n, htu = ht[u];
	ergv(u) if (p->flw) if (ht[u] == ht[p->ver] + 1) {
		psh(u, *p);
		if (lft[u] <= 0)
			return;
	}
	else {
		nh = std::min(nh, ht[p->ver] + 1);
	}
	if (gap[htu] == 1) { //断层
		up(htu, hst, i) {
			ergl(i)-- gap[ht[*p]], ht[*p] = n;
			lst[i].clear();
		}
		hst = htu - 1;
	} else {
		--gap[htu], it[u] = lst[htu].erase(it[u]), ht[u] = nh;
		if (nh == n)
			return;
		gap[nh]++, it[u] = lst[nh].insert(lst[nh].begin(), u);
		hst = std::max(hst, nwh = nh), mlst[nh].push_back(u);
	}
}
inline int HLPP() {
	nwh = hst = 0, ht.assign(n + 3, 0), ht[s] = n, it.resize(n + 3);
	up(1, n, i) if (i != s) it[i] = lst[ht[i]].insert(lst[ht[i]].begin(), i);
	gap.assign(n + 3, 0), gap[0] = n - 1, lft.assign(n + 3, 0), lft[s] = INF,
						  lft[t] = -INF;
	ergv(s) psh(s, *p);
	rlb();
	for (int u; nwh;) {
		if (mlst[nwh].empty())
			nwh--;
		else
			u = mlst[nwh].back(), mlst[nwh].pop_back(), psh(u);
	}
	return lft[t] + INF;
}
int main() {
	n = qread(), m = qread(), s = qread(), t = qread();
	up(1, m, i) add();
	std::printf("%d\n", HLPP());
	return 0;
}