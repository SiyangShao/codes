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

const int mxn = 2e5 + 10, MXLOG = 19;
const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int P = 1181, D = 1523, N = 2500;
const long long inf = (long long)2e18 + 10;
int n;

string get(int x) {
	string ret;
	for(int i = 0; i < n; i++) {
		if(x & (1 << i)) {
			if(ret.empty()) ret = string(1, 'a' + i);
			else ret = "(" + ret + "&" + string(1, 'a' + i) + ")";
		}
	}
	return ret;
}

string solve(vector<int> &a) {
	if(a.empty()) return "F";
	int val = a.back();
	a.pop_back();
	if(a.empty()) return get(val);
	return "(" + solve(a) + "|" + get(val) + ")";
}

void go() {
	cin >> n;
	string str;
	cin >> str;
	if(count(all(str), '1') == (1 << n)) {
		cout << "Yes\n";
		cout << "T\n";
		return;
	}
	vector<vector<int>> par((1 << n));
	for(int i = 1; i < (1 << n); i++) {
		for(int j = i; j; j = (i & (j - 1))) {
			par[j].pb(i);
		}
	}
	vector<bool> is((1 << n), 1);
	is[0] = 0;
	for(int i = 1; i < (1 << n); i++) {
		if(is[i] == 0) continue;
		for(int x : par[i]) {
			if(str[x] == '0') {
				is[i] = 0;
				break;
			}
		}
		if(is[i]) {
			for(int x : par[i]) {
				if(x == i) continue;
				is[x] = 0;
			}
		}
	}
	vector<int> v;
	for(int i = 0; i < (1 << n); i++) {
		if(is[i]) v.pb(i);
		if(str[i] == '0') continue;
		bool check = 0;
		for(int j = i; j; j = (i & (j - 1))) {
			if(is[j]) check = 1;
		}
		if(!check) {
			cout << "No\n";
			return;
		}
	}
	auto ans = solve(v);
	cout << "Yes\n";
	cout << ans << endl;
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
