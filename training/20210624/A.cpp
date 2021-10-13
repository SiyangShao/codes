#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define rep(i, l, r) for (ll i = l, i##end = r; i <= i##end; i++)
#define repo(i, l, r) for (ll i = l, i##end = r; i < i##end; i++)
#define per(i, l, r) for (ll i = l, i##end = r; i >= i##end; i--)
#define pero(i, l, r) for (ll i = l, i##end = r; i > i##end; i--)
#define mm1(a) memset(a, -1, sizeof(a))
#define mm2(a) memset(a, 0, sizeof(a))
#define mm3(a) memset(a, inf, sizeof(a))
#define mm4(a) memset(a, INF, sizeof(a))
#define swap(x, y) x ^= y ^= x ^= y
#define debug(x) cerr << #x << " : " << x << " " << endl
#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
ll ksm(ll a, ll n, ll mod) {
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1)
            (t *= a) %= mod;
    return t;
}

int n;
string tmp1[110];
string tmp2[110];
string tmp3[110];
int vis[110][110][110];

int main() {
    cin >> n;
    for (int i = n; i >= 1; i--) {
        cin >> tmp1[i];
        for (int j = 1; j <= n; j++) {
            if (tmp1[i][j - 1] == '0') {
                for (int k = 1; k <= n; k++) {
                    vis[k][j][i]++;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        cin >> tmp2[i];
        for (int j = 1; j <= n; j++) {
            if (tmp2[i][j - 1] == '0') {
                for (int k = 1; k <= n; k++) {
                    vis[i][k][j]++;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        cin >> tmp3[i];
        for (int j = 1; j <= n; j++) {
            if (tmp3[i][j - 1] == '0') {
                for (int k = 1; k <= n; k++) {
                    vis[j][i][k]++;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (tmp1[i][j - 1] == '1') {
                bool flag = true;
                for (int k = 1; k <= n; k++) {
                    if (vis[k][j][i] == 0)
                        flag = false;
                }
                if (flag) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (tmp2[i][j - 1] == '1') {
                bool flag = true;
                for (int k = 1; k <= n; k++) {
                    if (vis[i][k][j] == 0)
                        flag = false;
                }
                if (flag) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (tmp3[i][j - 1] == '1') {
                bool flag = true;
                for (int k = 1; k <= n; k++) {
                    if (vis[j][i][k] == 0)
                        flag = false;
                }
                if (flag) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";

    return 0;
}
