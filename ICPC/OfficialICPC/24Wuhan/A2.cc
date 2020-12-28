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

const int mxn = 2e5 + 10, MXLOG = 22, mod = 1e9 + 7;
const long long inf = 1e18 + 10;

int ask(int i, int j, int x) {
	cout << "? " << i << ' ' << j << ' ' << x << endl;
	int ret;
	cin >> ret;
	return ret;
}

int cal(int l, int r, int lc, int rc, int k) {
	if(l > r) return 0;
	int m = (l + r) / 2;
	int ll = lc, rr = rc;
	while(rr - ll > 1) {
		int mid = (ll + rr) / 2;
		if(ask(m, mid, k)) ll = mid;
		else rr = mid;
	}
	return ll + cal(l, m - 1, ll, rc, k) + cal(m + 1, r, lc, ll + 1, k);
}

void go() {
	int n, k;
	cin >> n >> k;
	int l = 1, r = n * n + 1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if(cal(1, n, 0, n + 1, m) >= k) r = m;
		else l = m;
	}
	cout << "! " << r << endl;
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