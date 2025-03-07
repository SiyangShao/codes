#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in insert
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

#define int long long

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
// const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int P = 1181, D = 1523, N = 2500;
// const long long inf = 1e18 + 10;
int dp[mxn], col[mxn], br[mxn], is[mxn], dep[mxn], sp[mxn][21];
vector<int> g[mxn], d[mxn];

int par[mxn], siz[mxn];

int get(int x) {
	if(x == par[x]) return x;
	return par[x] = get(par[x]);
}

int getSize(int x) {
	return siz[get(x)];
}

void merge(int x, int y) {
	x = get(x), y = get(y);
	if(x == y) return;
	if(siz[x] < siz[y]) swap(x, y);
	siz[x] += siz[y];
	par[y] = x;
}

void bud(int to, int cl) {
	col[to] = cl;
	for(int x : g[to]) {
		if(col[x] == 0) bud(x, cl);
	}
	for(int x : d[to]) {
		if(col[x] == 0) bud(x, cl);
	}
}

void syn(int to) {
	is[to] = 1;
	for(int x : g[to]) {
		merge(to, x);
		if(is[x] == 0) syn(x);
	}
}

void bran(int to, int brn) {
	br[to] = brn;
	for(int x : d[to]) {
		sp[x][0] = to;
		dep[x] = dep[to] + 1;
		bran(x, brn);
	}
}

void go() {
	int n, m, q, mod;
	cin >> n >> m >> q >> mod;
	map<pair<int, int>, bool> mp;
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y; x++, y++;
		g[x].pb(y);
		d[y].pb(x);
		mp[make_pair(x, y)] = 1;
	}
	for(int i = 1; i <= n; i++) {
		par[i] = i;
		siz[i] = 1;
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		dp[i] = (1ll + dp[i - 1] * i) % mod;
	}
	for(int i = 1; i <= n; i++) {
		if(col[i] == 0) bud(i, i);
	}
	for(int i = 1; i <= n; i++) {
		if(!is[i] && g[i].size() > 1) {
			for(int x : g[i]) {
				if(!is[x]) syn(x);
			}
			for(int j = 1; j < (int)g[i].size(); j++) {
				merge(g[i][j - 1], g[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(g[i].empty()) is[i] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j : g[i]) {
			if(!is[i] && !is[j] && mp.count(make_pair(i, j)) && mp.count(make_pair(j, i))) {
				is[i] = is[j] = 1;
				merge(i, j);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(is[i]) {
			for(int x : d[i]) {
				if(br[x] == 0 && !is[x]) {
					bran(x, x);
				}
			}
		}
	}
	for(int j = 1; j < 20; j++) {
		for(int i = 1; i <= n; i++) {
			if(is[i]) continue;
			sp[i][j] = sp[sp[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(all(g[i]));
	}
	while(q--) {
		int x, y;
		cin >> x >> y; x++, y++;
		if(mod == 1) {
			cout << 0 << endl;
			continue;
		}
		if(x == y) {
			cout << 1 << endl;
			continue;
		}
		if(col[x] != col[y]) {
			cout << 0 << endl;
			continue;
		}
		if(br[x] != br[y] && !is[x] && !is[y]) {
			cout << 0 << endl;
			continue;
		}
		if(!is[x] && !is[y]) {
			if(dep[x] < dep[y]) {
				cout << 0 << endl;
			} else {
				int dis = dep[x] - dep[y]; 
				for(int j = 19; j >= 0; j--) {
					if((dis >> j) & 1) x = sp[x][j];
				}
				if(x == y) cout << 1 << endl;
				else cout << 0 << endl;
			}
			continue;
		}
		if(is[x] && is[y]) {
			cout << dp[getSize(x) - 2] << endl;
			continue;
		}
		if(is[x]) {
			cout << 0 << endl;
			continue;
		}
		x = br[x];
		int pos = lower_bound(all(g[x]), y) - g[x].begin();
		int ans = 0, mul = (int)g[x].size();
		if(pos < (int)g[x].size() && y == g[x][pos]) {
			ans++;
			mul--;
		}
		if(getSize(y) > 1) {
			ans = (ans + mul * dp[getSize(y) - 2] % mod) % mod;
		}
		cout << ans << endl;
	}
}

signed main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		go();
	}
	return 0;
}