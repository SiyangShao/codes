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
int dir[4][2] = {{1, 0}, {0, -1}, {1, 0}, {0, 1}};
ll ksm(ll a, ll n, ll mod) {
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1)
            (t *= a) %= mod;
    return t;
}

int n, m;
char arr[15][15];
int sx, sy, ex, ey;
int yuejie(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m || arr[x][y] == '#')
        return 1;
    return 0;
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
                sx = i, sy = j;
            if (arr[i][j] == 'G')
                ex = i, ey = j;
        }
    }
    int mark = 1;
    if (ey == sy) {
        for (int i = sx; i <= ex; i++) {
            if (yuejie(i, sy))
                mark = 0;
        }
        if (mark) {
            cout << 1 << endl;
            cout << "FORWARD" << endl;
            return 0;
        }
    } else {
        for (int i = sx; i <= ex; i++) {
            if (yuejie(i, sy))
                mark = 0;
        }
        if (sy > ey) {
            for (int i = ey; i <= sy; i++)
                if (yuejie(ex, i))
                    mark = 0;
            if (mark) {
                cout << 3 << endl;
                cout << "RIGHT" << endl;
                cout << "FOWARD" << endl;
                cout << "GOTO 3" << endl;
                return 0;
            }
        } else {
            for (int i = sy; i <= ey; i++)
                if (yuejie(ex, i))
                    mark = 0;
            if (mark) {
                cout << 3 << endl;
                cout << "LEFT" << endl;
                cout << "FOWARD" << endl;
                cout << "GOTO 3" << endl;
                return 0;
            }
        }
        mark = 1;
        for (int i = min(sy, ey); i <= max(sy, ey); i++) {
            if (yuejie(sx, i))
                mark = 0;
        }
        for (int i = sx; i <= ex; i++)
            if (yuejie(i, ey))
                mark = 0;
        if (mark) {
            cout << 4 << endl;
            cout << (sx < ex ? "RIGHT" : "LEFT") << endl;
            cout << (sx < ex ? "RIGHT" : "LEFT") << endl;
            cout << "FORWARD" << endl;
            cout << "GOTO 2" << endl;
            return 0;
        }
    }
    cout << 5 << endl;
    cout << "LEFT" << endl;
    cout << "IF-OPEN 5" << endl;
    cout << "RIGHT" << endl;
    cout << "GOTO 2" << endl;
    cout << "FORWARD" << endl;

    return 0;
}
