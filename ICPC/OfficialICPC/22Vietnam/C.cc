#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define lb_pos(arr, key) (lower_bound(all(arr), (key)) - (arr).begin())
#define ub_pos(arr, key) (upper_bound(all(arr), (key)) - (arr).begin())

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
 
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ld EPS = 1e-8;
ll MOD = 998'244'353;
// ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vvl a;
vl build(ll x, ll p1, ll p2) {
    // dbg(x, p1, p2);
    vl ret(12);
    ret[2] = ret[5] = ret[8] = ret[11] = a[1][x];
    ret[0] = ret[3] = ret[6] = a[1][p1];
    ret[4] = ret[7] = ret[10] = a[1][p2];
    ret[1] = a[0][p1];
    ret[9] = a[0][p2];
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int T = 1;
    // scanf("%lld", &T);
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        if (n%2 == 0) cout << -1 << endl;
        else if (n == 1) {
            ll a, b; cin >> a >> b;
            cout << 1 << endl;
            cout << 1;
        }
        else {
            a = vvl(2, vl(n, 0));
            REP(i, 2) REP(j, n) cin >> a[i][j];

            ll x, y;
            REP(i, 2) REP(j, n) if (a[i][j] == 0) x = i, y = j;
            // dbg(x, y);

            vvl ans;
            for (ll i = y+1; i < y+n; i+=2) {
                ll p1 = i%n, p2 = (i+1)%n;
                ans.eb(build(y, p1, p2));
            }

            ll k = ans.size();
            cout << k * 12 - 1 << endl;
            REP(i, k) {
                if (i == k-1) {
                    REP(j, 10) cout << ans[i][j] << ' ';
                    cout << ans[i][11];
                } else REP(j, 12) cout << ans[i][j] << ' '; 
            };
        }
    }
    return 0;
}
