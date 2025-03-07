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

const int mxn = 3e5 + 10, MXLOG = 19;
// const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int P = 1181, D = 1523, N = 2500;
// const long long inf = 1e18 + 10;
vector<vector<int>> g;

void go() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int root = -1;
	for(int i = 1; i <= n; i++) {
		if((int)g[i].size() > 1) {
			root = i;
		}
	}
	if(root == -1) {
		cout << -1 << endl;
		return;
	}
	vector<pair<int, int>> ans;
	vector<int> dep(n + 1), dp(n + 1, -1);
	function<void(int, int)> dfs = [&](int to, int fr) {
		dep[to] = dep[fr] + 1;
		if((int)g[to].size() == 1) {
			dp[to] = to;
			return;
		}
		vector<int> tmp;
		for(int x : g[to]) {
			if(x == fr) continue;
			dfs(x, to);
			if(dp[x] != -1) tmp.pb(dp[x]);
		}
		sort(all(tmp), [&](int x, int y) {
			return dep[x] < dep[y];
		});
		int sz = (int)tmp.size();
		for(int i = 1; i < sz; i += 2) {
			ans.eb(tmp[i], tmp[i - 1]);
		}
		if(sz % 2 == 1) dp[to] = tmp.back();
		else dp[to] = to;
	};
	dfs(root, 0);
	if(dp[root] != root) {
		if(dep[dp[root]] == 2) {
			cout << -1 << endl;
			return;
		}
		ans.eb(root, dp[root]);
	}
	cout << ans.size() << endl;
	for(auto it : ans) {
		cout << it << endl;
	}
}

signed main() {
	fast;
	int t = 1;
	cin >> t;
	for(int _ = 1; _ <= t; _++) {
		// cout << "Case #" << _ << ": ";
		go();
	}
	return 0;
}
