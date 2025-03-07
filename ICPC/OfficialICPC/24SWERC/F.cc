#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in insert
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

// #define int long long

// typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
// typedef pair<int, int> P;

template<typename T, typename U>
ostream & operator << (ostream &out, const pair<T, U> &c) {
	out << c.first << ' ' << c.second;
	return out;
}

template<typename T>
ostream & operator << (ostream &out, vector<T> &v) {
	const int sz = v.size();
	for (int i = 0; i < sz; i++) {
		if (i) out << ' ';
		out << v[i];
	}
	return out;
}

template<typename T>
istream & operator >> (istream &in, vector<T> &v) {
	for (T &x : v) in >> x;
	return in;
}

template<typename T, typename U>
	istream & operator >> (istream &in, pair<T, U> &c) {
	in >> c.first;
	in >> c.second;
	return in;
}

template<typename T>
void mxx(T &a, T b){if(b > a) a = b;}
template<typename T>
void mnn(T &a, T b){if(b < a) a = b;}

const int mxn = 5e5 + 10, MXLOG = 19;
const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int P = 1181, D = 1523, N = 2500;
// const long long inf = (long long)2e18 + 10;
const int inf = (int)1e9 + 10;

struct DSU_rb {
	struct save {
		int u, v, rnku, rnkv, szu, szv;
		save() {}
		save(int _u, int _rnku, int _szu, int _v, int _rnkv, int _szv) :
			u(_u), v(_v), rnku(_rnku), rnkv(_rnkv), szu(_szu), szv(_szv) {}
	};
	vector<int> rnk, par, sz;
	vector<save> op;
	int n;

	DSU_rb() {}
	DSU_rb(int _n) : n(_n) {
		rnk.resize(n + 1, 0);
		par.resize(n + 1, 0);
		sz.resize(n + 1, 1);
		iota(all(par), 0);
		op.clear();
	}

	int find(int u) {
		return (par[u] == u ? u : find(par[u]));
	}

	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if(u == v) {
			return 0;
		}
		if(rnk[u] > rnk[v]) swap(u, v);
		op.eb(u, rnk[u], sz[u], v, rnk[v], sz[v]);
		par[u] = v;
		sz[v] += sz[u];
		rnk[v] += (rnk[v] == rnk[u]);
		return 1;
	}

	int getSize(int u) {
		return sz[find(u)];
	}

	int rbSize() {
		return (int)op.size();
	}

	void rollBack() {
		if(op.empty()) {
			return;
		}
		save tmp = op.back();
		op.pop_back();
		int u = tmp.u;
		int v = tmp.v;
		rnk[u] = tmp.rnku; sz[u] = tmp.szu;	par[u] = u;
		rnk[v] = tmp.rnkv; sz[v] = tmp.szv; par[v] = v;
	}
} ds;

vector<pair<int, int>> edges[mxn * 4];
vector<int> calc[mxn];
vector<int> solved[mxn];

void add(int l, int r, int i, int x, int y, int a, int b) {
	if(l >= x && r <= y) {
		edges[i].eb(a, b);
		return;
	}
	int m = (l + r) / 2;
	if(x <= m) add(l, m, i * 2, x, y, a, b);
	if(y > m) add(m + 1, r, i * 2 + 1, x, y, a, b);
}

void calculate(int l, int r, int i) {
	int T = ds.rbSize();
	for(auto [a, b] : edges[i]) {
		ds.unite(a, b);
	}
	if(l == r) {
		for(int que : calc[l]) {
			solved[que].pb(ds.getSize(que + 1));
		}
		while(ds.rbSize() > T) ds.rollBack();
		return;
	}
	int m = (l + r) / 2;
	calculate(l, m, i * 2);
	calculate(m + 1, r, i * 2 + 1);
	while(ds.rbSize() > T) ds.rollBack();
}

void go() {
	int a, n, m, e, t, b, k;
	cin >> a >> n >> m >> e >> t >> b;
	ds = DSU_rb(n);
	vector<int> bob(b);
	cin >> bob >> k;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		add(0, t - 1, 1, i, min(t - 1, i + m - 1), x + 1, y + 1);
		g[x].eb(y, i);
		g[y].eb(x, i);
	}
	for(int x : bob) {
		for(auto [y, i] : g[x]) {
			calc[i].pb(x);
		}
	}
	calculate(0, t - 1, 1);
	vector<int> mn(n, inf);
	priority_queue<pair<int, int>> q;
	for(int x : bob) {
		assert(g[x].size() == solved[x].size());
		for(int i = 0; i < (int)g[x].size(); i++) {
			int y, id;
			tie(y, id) = g[x][i];
			if(solved[x][i] > k) {
				mn[x] = id;
				q.emplace(-mn[x], x);
				break;
			}
		}
	}
	while(!q.empty()) {
		int c, x;
		tie(c, x) = q.top(); q.pop();
		c = -c;
		if(mn[x] < c) continue;
		for(auto [y, i] : g[x]) {
			if(i + m <= mn[x]) continue;
			int nxt = max(mn[x], i);
			if(nxt < mn[y]) {
				mn[y] = nxt;
				q.emplace(-mn[y], y);
			}
		}
	}
	for(int i = 0; i < a; i++) {
		if(mn[i] == 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<int> ans(n, inf);
		ans[i] = 0;
		assert(q.empty());
		q.emplace(-ans[i], i);
		while(!q.empty()) {
			int c, x;
			tie(c, x) = q.top(); q.pop();
			c = -c;
			if(ans[x] < c) continue;
			for(auto [y, id] : g[x]) {
				if(id + m <= ans[x]) continue;
				int nxt = max(ans[x], id);
				if(nxt < mn[x] && nxt < mn[y] && nxt < ans[y]) {
					ans[y] = nxt;
					q.emplace(-ans[y], y);
				}
			}
		}
		int res = inf;
		for(int j = n - e; j < n; j++) {
			mnn(res, ans[j]);
		}
		if(res == inf) cout << "IMPOSSIBLE\n";
		else cout << res << endl;
	}
}

signed main() {
	fast;
	int t = 1;
	// cin >> t;
	for(int _ = 1; _ <= t; _++) {
		// cout << "Case #" << _ << ": ";
		go();
	}
	return 0;
}
